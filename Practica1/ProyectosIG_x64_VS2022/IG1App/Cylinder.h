#pragma once
#include "QuadricEntity.h"

class Cylinder : public QuadricEntity {
public:
	Cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height); // r es el radio de la esfera
	void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble height;
};