#include "PartialDisk.h"

PartialDisk::PartialDisk(GLdouble IR, GLdouble OR, GLdouble SA, GLdouble WA){
	innerRadius = IR; outerRadius = OR; startAngle = SA; sweepAngle = WA;
}

void PartialDisk::render(glm::dmat4 const& modelViewMat) const {
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	// Aquí se puede fijar el color de la esfera así:
	//glEnable ( GL_COLOR_MATERIAL );
	glColor3f(mColor.r, mColor.g, mColor.b);
	// Aquí se puede fijar el modo de dibujar la esfera :
	gluQuadricDrawStyle (q, GLU_FILL);
	gluPartialDisk(q, innerRadius, outerRadius, 50, 50, startAngle, sweepAngle);
	// Aquí se debe recuperar el color :
	glColor3f (1.0 , 1.0 , 1.0);
	//glDisable(GL_COLOR_MATERIAL);
}
