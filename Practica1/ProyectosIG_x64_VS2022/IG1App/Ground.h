#ifndef _H_Ground_H_
#define _H_Ground_H_
#include <vector>
#include <iostream>
#include "Entity.h"
class Ground : public Abs_Entity
{
public:
	Ground(GLdouble width, GLdouble height, Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateRectangleTexCor(225, 225);

		static double angleAntiHor = 3.14/2;
		glm::dmat4 rotAntiHor = glm::rotate(glm::dmat4(1.0), angleAntiHor, glm::dvec3(1.0, 0.0, 0.0));
		setModelMat(rotAntiHor);

		setTexture(myText);		
	}
	virtual ~Ground();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Ground_H_

#pragma once
