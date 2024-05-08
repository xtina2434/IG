#include "MbR.h"

MbR* MbR::generaIndexMbR(int mm, int nn, glm::dvec3* perfil)
{
	MbR* mesh = new MbR(mm, nn, perfil);
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = nn * mm;
	// Usar un vector auxiliar de v�rtices
	mesh->vVertices.reserve(mesh->mNumVertices);
	glm::dvec3* vs = new glm::dvec3[mesh->mNumVertices];
	mesh->nNumIndices = nn * mm * 6;
	mesh->vIndices = new GLuint[nn * mm * 6];
	//int indice = 0; //indice para rastrear la posicion en vs
	for (int i = 0; i < nn; i++) {
		// Generar la muestra i- �sima de v�rtices
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
		// El contador j recorre los v�rtices del perfil ,
		// de abajo arriba . Las caras cuadrangulares resultan
		// al unir la muestra i- �sima con la (i +1)% nn - �sima
		for (int j = 0; j < mm - 1; j++) {
			// El contador indice sirve para llevar cuenta
			// de los �ndices generados hasta ahora . Se recorre
			// la cara desde la esquina inferior izquierda
			int indice = i * mm + j;
		// Los cuatro �ndices son entonces :
		//indice, (indice + mm) % (nn * mm), (indice + mm + 1) % (nn * mm), indice + 1

		mesh->vIndices[indiceMayor] = indice;
		indiceMayor++;
		mesh->vIndices[indiceMayor] = (indice + mm) % (nn * mm);
		indiceMayor++;
		mesh->vIndices[indiceMayor] = (indice + mm + 1) % (nn * mm);
		indiceMayor++;
		// Y an�logamente se a�aden los otros tres �ndices
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
		�ndice0 , �ndice1 , �ndice2 ,
		�ndice2 , �ndice3 , �ndice0
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