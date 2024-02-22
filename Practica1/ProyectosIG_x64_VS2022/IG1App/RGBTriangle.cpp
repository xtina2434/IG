#include "RGBTriangle.h"
#include <iostream>

RGBTriangle::~RGBTriangle() {
	delete mMesh;
	mMesh = nullptr;
}
void RGBTriangle::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 7
		//glPolygonMode(GL_FRONT, GL_FILL);
		////glPolygonMode(GL_BACK, GL_LINE);
		//glPolygonMode(GL_BACK, GL_POINT);
		//glPointSize(10);
		//APARTADO 6
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		std::vector<glm::dvec4> myRGBcolors;
		// X axis color: red  (Alpha = 1 : fully opaque)
		myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
		// Y axis color: green
		myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		// Z axis color: blue
		myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
		mMesh->setColor(myRGBcolors);
		mMesh->setPrimitive(GL_TRIANGLES);

		mMesh->render();
	}
}
void RGBTriangle::update() {

	static double angleAntiHor = 0.05; //angulo giro anti horario
	static double angleHor = -0.2; //angulo giro horario

	//rotacion sobre el eje z y en sentido antihorario alrededor de la circunferencia
	glm::dmat4 rotAntiHor= glm::rotate(glm::dmat4(1.0), angleAntiHor, glm::dvec3(0.0, 0.0, 1.0));
	//rotacion horaria alrededor del mismo eje
	glm::dmat4 rotHor= glm::rotate(mModelMat, angleHor, glm::dvec3(0.0, 0.0, 1.0));
	//combinar las dos transformaciones
	setModelMat(rotAntiHor * rotHor);
}