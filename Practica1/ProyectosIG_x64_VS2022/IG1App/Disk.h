#pragma once
#include "QuadricEntity.h"

class Disk : public QuadricEntity {
public:
	Disk(GLdouble innerRadius, GLdouble outerRadius); // r es el radio de la esfera
	void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
};