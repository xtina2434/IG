#ifndef _H_QuadricEntity_H_
#define _H_QuadricEntity_H_
#include <vector>
#include "Entity.h"

class QuadricEntity : public Abs_Entity {
public:
	QuadricEntity();
	~QuadricEntity() { gluDeleteQuadric(q); };
protected:
	GLUquadricObj* q;
};
#endif //_H_QuadricEntity_H_
//gluQuadricTexture (q, GL_TRUE );
