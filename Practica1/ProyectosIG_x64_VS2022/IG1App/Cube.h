#ifndef _H_Cube_H_
#define _H_Cube_H_
#include <vector>
#include "Entity.h"
class Cube : public Abs_Entity
{
public:
	Cube(GLdouble length) : Abs_Entity() {
		mMesh = Mesh::generateCube(length);

	}
	virtual ~Cube();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Cube_H_
#pragma once
