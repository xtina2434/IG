#ifndef _H_GlassParapet_H_
#define _H_GlassParapet_H_
#include <vector>
#include "Entity.h"
class GlassParapet : public Abs_Entity
{
public:
	GlassParapet(GLdouble length, Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateBoxOutlineTexCor(length);
		setTexture(myText);
	}
	virtual ~GlassParapet();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_GlassParapet_H_
#pragma once
