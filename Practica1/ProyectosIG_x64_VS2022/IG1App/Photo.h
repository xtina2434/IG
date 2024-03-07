#pragma once

#ifndef _H_Photo_H_
#define _H_Photo_H_
#include <vector>
#include "Entity.h"

class Photo : public Abs_Entity
{
public:
	Photo(GLdouble width, GLdouble height, Texture* myText) : mWidth(width), mHeight(height), Abs_Entity() {
		mMesh = Mesh::generateRectangleTexCor(width, height, 4, 4); 
		//aplicar la textura
		setTexture(myText);
		//suelo en posicion horizontal en el plano Y=0
		static double angleRot = 3.14 / 2;
		glm::dmat4 rot = glm::rotate(glm::dmat4(1.0), angleRot, glm::dvec3(1.0, 0.0, 0.0));
		setModelMat(rot);
	}
	virtual ~Photo();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	virtual void update() override;
private:
	GLdouble mWidth;
	GLdouble mHeight;
};

#endif //_H_Photo_H_
#pragma once