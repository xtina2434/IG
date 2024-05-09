#include "Sphere.h"

Sphere::Sphere(GLdouble rr) : r(rr) {
	q = gluNewQuadric();
}
Sphere::~Sphere() {
	gluDeleteQuadric(q);
}
void Sphere::render(glm::dmat4 const& modelViewMat) const {
	glm::dmat4 aMat = modelViewMat * mModelMat;
	upload(aMat);
	glEnable(GL_COLOR_MATERIAL);
	if (material != nullptr) {
		glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
		material->upload();
	}
	else {
		// Aqu� se puede fijar el color de la esfera as�:
		glColor3f(mColor.r, mColor.g, mColor.b);
	}
	// Aqu� se puede fijar el modo de dibujar la esfera :
	gluQuadricDrawStyle(q, GLU_FILL);
	gluSphere(q, r, 50, 50);

	// Aqu� se debe recuperar el color :
	if (material == nullptr) {
		glColor3f(1.0, 1.0, 1.0);

	}
	glDisable(GL_COLOR_MATERIAL);
}
