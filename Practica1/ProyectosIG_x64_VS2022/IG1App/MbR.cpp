#include "MbR.h"

MbR* MbR::generaIndexMbR(int mm, int nn, glm::dvec3* perfil)
{
	MbR* mesh = new MbR(mm, nn, perfil);
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = nn * mm;
	// Usar un vector auxiliar de vértices
	mesh->vVertices.reserve(mesh->mNumVertices);
	glm::dvec3* vs = new glm::dvec3[mesh->mNumVertices];
	mesh->nNumIndices = nn * mm * 6;
	mesh->vIndices = new GLuint[nn * mm * 6];
	//int indice = 0; //indice para rastrear la posicion en vs
	for (int i = 0; i < nn; i++) {
		// Generar la muestra i- ésima de vértices
		GLdouble theta = i * 360 / nn;
		GLdouble c = cos(glm::radians(theta));
		GLdouble s = sin(glm::radians(theta));
		for (int j = 0; j < mm; j++) {
			GLdouble z = -s * perfil[j].x + c * perfil[j].z;
			GLdouble x = c * perfil[j].x + -s * perfil[j].z;
			//GLdouble x = c * perfil[j].x + s * perfil[j].z;
			vs[(i * mm) + j] = glm::dvec3(x, perfil[j].y, z);
			//indice++;
		}
	}

	for (int i = 0; i < mesh->mNumVertices; i++) {
		mesh->vVertices.emplace_back(vs[i]);
	}

	int indiceMayor = 0;
	// El contador i recorre las muestras alrededor del eje Y
	for (int i = 0; i < nn; i++) {
		// El contador j recorre los vértices del perfil ,
		// de abajo arriba . Las caras cuadrangulares resultan
		// al unir la muestra i- ésima con la (i +1)% nn - ésima
		for (int j = 0; j < mm - 1; j++) {
			// El contador indice sirve para llevar cuenta
			// de los índices generados hasta ahora . Se recorre
			// la cara desde la esquina inferior izquierda
			int indice = i * mm + j;
		// Los cuatro índices son entonces :
		//indice, (indice + mm) % (nn * mm), (indice + mm + 1) % (nn * mm), indice + 1

		mesh->vIndices[indiceMayor] = indice;
		indiceMayor++;
		mesh->vIndices[indiceMayor] = (indice + mm) % (nn * mm);
		indiceMayor++;
		mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
		indiceMayor++;
		// Y análogamente se añaden los otros tres índices
	/*	mesh->vIndices[indiceMayor] = (indice + 1) % (nn * mm);
		indiceMayor++;
		mesh->vIndices[indiceMayor] = indice;
		indiceMayor++;
		mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
		indiceMayor++;*/
		/*mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
		indiceMayor++;
		mesh->vIndices[indiceMayor] = indice + 1;
		indiceMayor++;
		mesh->vIndices[indiceMayor] = indice;
		indiceMayor++;*/
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