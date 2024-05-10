#pragma once
#include "Entity.h"
#include "MbR.h"
# define M_PI           3.14159265358979323846  /* pi */

class Toroid : public Abs_Entity
{
public:
	Toroid(GLuint r, GLuint R, GLuint p, GLuint m) : Abs_Entity() {
		glm::dvec3* perfil = new glm::dvec3[p];
		for (int i = 0; i < p; i++) {
			GLdouble theta = ((M_PI*2) / (p - 1)) * i;
			perfil[i] = {R + (r * sin(theta)), -(r * cos(theta)), 0 };
		}
		mMesh = MbR::generaIndexMbR(p, m, perfil);
	}
	virtual ~Toroid();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
};