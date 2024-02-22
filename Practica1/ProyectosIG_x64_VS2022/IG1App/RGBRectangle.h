#ifndef _H_RGBRectangle_H_
#define _H_RGBRectangle_H_
#include <vector>
#include "Entity.h"
class RGBRectangle : public Abs_Entity
{
public:
	RGBRectangle(GLdouble width, GLdouble height) : Abs_Entity() {
		mMesh = Mesh::generateRGBRectangle(width, height);

	}
	virtual ~RGBRectangle();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_RGBTriangle_H_

#pragma once
