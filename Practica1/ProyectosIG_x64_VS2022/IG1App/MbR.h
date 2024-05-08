#pragma once
#include "IndexMesh.h"

class MbR : public IndexMesh
{
protected:
	GLuint n;	// n�mero de rotaciones (muestras) que se toman al girar el perfilalrededor del eje Y
	GLuint m;	//n�mero de puntos del perfil
	glm::dvec3* perfil; // para el array de v�rtices que define el perfil que va a hacerse girar alrededor del eje Y
public:
	MbR(GLuint _n, GLuint _m, glm::dvec3* _perfil) : n(_n), m(_m), perfil(_perfil) {}
	static MbR* generaIndexMbR(int mm, int nn, glm::dvec3* perfil);
	virtual ~MbR();
};