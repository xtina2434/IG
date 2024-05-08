#pragma once
#include "Entity.h"
#include "MbR.h"
class SphereR : public Abs_Entity
{
public:
	SphereR(GLuint r, GLuint p, GLuint m) : Abs_Entity() {
		glm::dvec3* perfil = new glm::dvec3[p];
		for (int i = 0; i < p; i++) {
			//GLdouble theta = i * 180 / p;
			GLdouble theta = (3, 14 / (p - 1)) * i;
			perfil[i] = { r * sin(glm::radians(theta)), r * cos(glm::radians(theta)), 0};
		}
		mMesh = MbR::generaIndexMbR(p, m, perfil);
	}
	virtual ~SphereR();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
};