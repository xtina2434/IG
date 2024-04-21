#pragma once
#include "Entity.h"
class IndexedBox : public Abs_Entity
{
public:
	IndexedBox(GLdouble length) : Abs_Entity() {
		mMesh = IndexMesh::generateIndexedBox(length);
	}
	virtual ~IndexedBox();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
};

