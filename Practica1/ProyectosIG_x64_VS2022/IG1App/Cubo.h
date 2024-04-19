#pragma once
#include "Entity.h"
class Cubo : public Abs_Entity
{
public:
	Cubo(GLdouble length) : Abs_Entity() {
		mMesh = IndexMesh::generateIndexedBox(length);
	}
	virtual ~Cubo();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
};

