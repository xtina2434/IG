#ifndef _H_Star3D_H_
#define _H_Star3D_H_
#include <vector>
#include "Entity.h"
class Star3D : public Abs_Entity
{
public:
	Star3D(GLdouble re, GLuint np, GLdouble h) : Abs_Entity() {
		mMesh = Mesh::generateStar3D(re, np, h);
	}
	virtual ~Star3D();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Star3D_H_
#pragma once