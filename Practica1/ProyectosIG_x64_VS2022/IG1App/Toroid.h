#pragma once
#include "Entity.h"
#include "MbR.h"
class Toroid : public Abs_Entity
{
public:
	Toroid(GLuint r, GLuint R, GLuint p, GLuint m) : Abs_Entity() {
		glm::dvec3* perfil = new glm::dvec3[p];
		for (int i = 0; i < p; i++) {
			GLdouble theta = ((3.14*2) / (p - 1)) * i;
			perfil[i] = {R + (r * sin(theta)), r * cos(theta), 0 };
		}
		mMesh = MbR::generaIndexMbR(p, m, perfil);
	}
	virtual ~Toroid();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
};