#pragma once

#ifndef _H_Photo_H_
#define _H_Photo_H_
#include <vector>
#include "Entity.h"

class Photo : public Abs_Entity
{
public:
	Photo(GLdouble width, GLdouble height) :  Abs_Entity() {
		mMesh = Mesh::generateRectangleTexCor(width, height, 1, 1); 
		//aplicar la textura
		mTexture = new Texture();
		mTexture->loadColorBuffer(width, height, GL_BACK);
		//suelo en posicion horizontal en el plano Y=0
		static double angleRot = 3.14 / 2;
		glm::dmat4 rot = glm::rotate(glm::dmat4(1.0), angleRot, glm::dvec3(1.0, 0.0, 0.0));
		setModelMat(rot);
	}
	virtual ~Photo();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	virtual void update() override;
};

#endif //_H_Photo_H_
#pragma once