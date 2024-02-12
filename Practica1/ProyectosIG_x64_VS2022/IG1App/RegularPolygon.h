#ifndef _H_RegularPolygon_H_
#define _H_RegularPolygon_H_

#include "Entity.h"
class RegularPolygon : public Abs_Entity
{
public:
	RegularPolygon(GLuint numSides, GLdouble radius) : Abs_Entity() {
		mMesh = Mesh::generateRegularPolygon(numSides, radius);
	}
	RegularPolygon(GLdouble width, GLdouble height) : Abs_Entity() {
		mMesh = Mesh::generateRectangle(width, height);
	}
	virtual ~RegularPolygon();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	
};

#endif //_H_RegularPolygon_H_
