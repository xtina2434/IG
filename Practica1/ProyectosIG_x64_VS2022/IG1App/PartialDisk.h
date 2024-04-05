#pragma once
#include "QuadricEntity.h"

class PartialDisk : public QuadricEntity {
public:
	PartialDisk(GLdouble innerRadius, GLdouble outerRadius, GLdouble startAngle, GLdouble sweepAngle); // r es el radio de la esfera
	void render(glm::dmat4 const& modelViewMat) const;
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
	GLdouble startAngle;
	GLdouble sweepAngle;
};