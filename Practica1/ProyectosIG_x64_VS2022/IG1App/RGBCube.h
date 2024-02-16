#ifndef _H_RGBCube_H_
#define _H_RGBCube_H_
#include <vector>
#include "Entity.h"
class RGBCube : public Abs_Entity
{
public:
	RGBCube(GLdouble length) : Abs_Entity() {
		mMesh = Mesh::generateRGBCubeTriangles(length);

	}
	virtual ~RGBCube();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_RGBCube_H_
#pragma once
