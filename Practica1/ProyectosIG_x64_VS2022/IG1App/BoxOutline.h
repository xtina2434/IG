#ifndef _H_BoxOutline_H_
#define _H_BoxOutline_H_
#include <vector>
#include "Entity.h"
class BoxOutline : public Abs_Entity
{
public:
	BoxOutline(GLdouble length, Texture* myText, Texture* backText) : Abs_Entity() {
		mMesh = Mesh::generateBoxOutlineTexCor(length);

		setTexture(myText);
		setBackTexture(backText);

	}
	virtual ~BoxOutline();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_BoxOutline_H_
#pragma once
