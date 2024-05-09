#include "MbR.h"
#include <iostream>

MbR* MbR::generaIndexMbR(int mm, int nn, glm::dvec3* perfil)
{
	MbR* mesh = new MbR(mm, nn, perfil);
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = nn * mm;
	mesh->vVertices.reserve(mesh->mNumVertices);
	// Usar un vector auxiliar de vértices
	glm::dvec3* vs = new glm::dvec3[mesh->mNumVertices];
	//CREO QUE FALLA EL NUMERO DE INDICES A RESERVAR
	mesh->nNumIndices = 6 * nn * mm;
	mesh->vIndices = new GLuint[mesh->nNumIndices];
	mesh->vNormals.reserve(mesh->mNumVertices);
	//int indice = 0; //indice para rastrear la posicion en vs
	for (int i = 0; i < nn; i++) {
		// Generar la muestra i- ésima de vértices
		GLdouble theta = i * 360 / nn;
		GLdouble c = cos(glm::radians(theta));
		GLdouble s = sin(glm::radians(theta));
		for (int j = 0; j < mm; j++) {
			GLdouble z = -s * perfil[j].x + c * perfil[j].z;
			GLdouble x = c * perfil[j].x + s * perfil[j].z;
			//GLdouble x = c * perfil[j].x + s * perfil[j].z;
			int ind = (i * mm) + j;
			glm::dvec3 pos = glm::dvec3(x, perfil[j].y, z);
			vs[ind] = pos;
		}
	}
	for (int i = 0; i < mesh->mNumVertices; i++) {
		mesh->vVertices.emplace_back(vs[i]);
	}

	// El contador i recorre las muestras alrededor del eje Y
	int indiceMayor = 0;
	for (int i = 0; i < nn; i++) {
		
		// El contador j recorre los vértices del perfil ,
		// de abajo arriba . Las caras cuadrangulares resultan
		// al unir la muestra i- ésima con la (i +1)% nn - ésima
		for (int j = 0; j < mm; j++) {
			// El contador indice sirve para llevar cuenta
			// de los índices generados hasta ahora . Se recorre
			// la cara desde la esquina inferior izquierda
			int indice = (i * mm) + j;
		// Los cuatro índices son entonces :
		//indice, (indice + mm) % (nn * mm), (indice + mm + 1) % (nn * mm), indice + 1
			mesh->vIndices[indiceMayor] = indice;
			indiceMayor++;
			int n = (indice + mm) % (nn * mm);
			mesh->vIndices[indiceMayor] = n;
			indiceMayor++;
			mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
			indiceMayor++;
			mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
			indiceMayor++;
			n = (indice + 1) % (nn * mm);
			mesh->vIndices[indiceMayor] = n;
			indiceMayor++;
			mesh->vIndices[indiceMayor] = indice % (nn * mm);
			indiceMayor++;
			/*
			índice0 , índice1 , índice2 ,
			índice2 , índice3 , índice0
			*/
		}
	}

	mesh->buildNormalVectors();
	delete[] vs;
	return mesh;
}

MbR::~MbR() {
	delete[] perfil;
}