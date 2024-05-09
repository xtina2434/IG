#include "Cylinder.h"

Cylinder::Cylinder(GLdouble BR, GLdouble TR, GLdouble H) 
{ baseRadius = BR; topRadius = TR; height = H; }

void Cylinder::render(glm::dmat4 const& modelViewMat) const {
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aqu� se puede fijar el color de la esfera as�:
	//glEnable ( GL_COLOR_MATERIAL );
	glColor3f(mColor.r, mColor.g, mColor.b);
	// Aqu� se puede fijar el modo de dibujar la esfera :
	gluQuadricDrawStyle (q, GLU_FILL);
	gluCylinder(q, baseRadius, topRadius, height, 50, 50);
	// Aqu� se debe recuperar el color :
	glColor3f (1.0 , 1.0 , 1.0);
	//glDisable(GL_COLOR_MATERIAL);
}
