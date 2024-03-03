#pragma once

#ifndef _H_Ground_H_
#define _H_Ground_H_
#include <vector>
#include <iostream>
#include "Entity.h"
class Ground : public Abs_Entity
{
public:
	Ground(GLdouble width, GLdouble height, Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateRectangleTexCor(width, height, 4, 4);

		//aplicar la textura
		setTexture(myText);
		//suelo en posicion horizontal en el plano Y=0
		static double angleRot = 3.14/2;
		glm::dmat4 rot = glm::rotate(glm::dmat4(1.0), angleRot, glm::dvec3(1.0, 0.0, 0.0));
		setModelMat(rot);
	
	}
	virtual ~Ground();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Ground_H_


