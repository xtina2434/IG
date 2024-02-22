#ifndef _H_RGBCube_H_
#define _H_RGBCube_H_
#include <vector>
#include "Entity.h"
class RGBCube : public Abs_Entity
{
private:
	char ejeRot;

public:
	RGBCube(GLdouble length) : Abs_Entity() {
		mMesh = Mesh::generateRGBCubeTriangles(length);
		ejeRot = 'x';
	}
	virtual ~RGBCube();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	virtual void update() override;

};

#endif //_H_RGBCube_H_
#pragma once
