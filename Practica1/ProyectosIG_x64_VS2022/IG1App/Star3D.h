#ifndef _H_Star3D_H_
#define _H_Star3D_H_
#include <vector>
#include "Entity.h"
class Star3D : public Abs_Entity
{
public:
	Star3D(GLdouble re, GLuint np, GLdouble h, Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateStar3DTexCor(re, np, h);
		setTexture(myText);
	}
	virtual ~Star3D();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	virtual void update() override;
};

#endif //_H_Star3D_H_
#pragma once