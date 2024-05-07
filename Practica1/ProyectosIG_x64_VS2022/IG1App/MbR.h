#pragma once
#include "IndexMesh.h"

class MbR : public IndexMesh
{
protected:
	GLuint n;
	GLuint m;
	glm::dvec3* perfil;
public:
	MbR(GLuint _n, GLuint _m, glm::dvec3* _perfil) : n(_n), m(_m), perfil(_perfil) {}
	static MbR* generaIndexMbR(int mm, int nn, glm::dvec3* perfil);
	virtual ~MbR();
};