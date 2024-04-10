#ifndef _H_WingAdvancedTIE_H_
#define _H_WingAdvancedTIE_H_

#include "Entity.h"
class WingAdvancedTIE : public Abs_Entity
{
public:
	WingAdvancedTIE(GLdouble w, GLdouble h, GLdouble re,Texture* myText) : Abs_Entity() {
		mMesh = Mesh::generateWingText(w, h,re);
		setTexture(myText);
	}
	virtual ~WingAdvancedTIE();
	virtual void render(glm::dmat4 const& modelViewMat) const override;

};

#endif //_H_RegularPolygon_H_
