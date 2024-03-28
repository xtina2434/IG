#pragma once

#ifndef _H_Ground_H_
#define _H_Ground_H_
#include <vector>
#include <iostream>
#include "Entity.h"

class Ground : public Abs_Entity
{
public:
	Ground(GLdouble width, GLdouble height, Texture* myText, GLuint rw, GLuint rh) : Abs_Entity() {
		//18
		//mMesh = Mesh::generateRGBRectangle(width, height);
		//19 Y 20
		mMesh = Mesh::generateRectangleTexCor(width, height, rw, rh);

		//aplicar la textura (19 Y 20)
		setTexture(myText);
		//suelo en posicion horizontal en el plano Y=0
		static double angleRot = 3.14/2; //90 grados en radianes
		glm::dmat4 rot = glm::rotate(glm::dmat4(1.0), angleRot, glm::dvec3(1.0, 0.0, 0.0));
		setModelMat(rot);
	
	}
	virtual ~Ground();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_Ground_H_


