#ifndef _H_RGBTriangle_H_
#define _H_RGBTriangle_H_
#include <vector>
#include "Entity.h"
class RGBTriangle : public Abs_Entity
{
public:
	RGBTriangle(GLuint numSides, GLdouble radius) : Abs_Entity() {
		mMesh = Mesh::generateRegularPolygon(numSides, radius);
	}
	virtual ~RGBTriangle();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_RGBTriangle_H_

