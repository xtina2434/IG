#pragma once
#include "QuadricEntity.h"
#include "EntityWithMaterial.h"
class Sphere : public EntityWithMaterial/*QuadricEntity*/ {
public:
	Sphere(GLdouble r); // r es el radio de la esfera
	void render(glm::dmat4 const& modelViewMat) const override;

protected:
	GLdouble r;
	GLUquadricObj* q = nullptr;
	~Sphere();
};
