#pragma once
#include "QuadricEntity.h"

class Sphere : public QuadricEntity {
public:
	Sphere(GLdouble r); // r es el radio de la esfera
	void render(glm::dmat4 const& modelViewMat) const;

protected:
	GLdouble r;
};
