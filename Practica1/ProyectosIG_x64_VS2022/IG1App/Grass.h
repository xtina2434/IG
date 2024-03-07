#pragma once

#ifndef _H_Grass_H_
#define _H_Grass_H_
#include <vector>
#include <iostream>
#include "Entity.h"

class Grass : public Abs_Entity
{
public:
	Grass(GLdouble width, GLdouble height, Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateRectangleTexCor(width, height, 1, 1);

		//aplicar la textura
		setTexture(myText);
	}
	virtual ~Grass();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Grass_H_


