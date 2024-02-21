#include "RGBTriangle.h"

RGBTriangle::~RGBTriangle() {
	delete mMesh;
	mMesh = nullptr;
}
void RGBTriangle::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//std::vector<glm::dvec4> myRGBcolors;
		//// X axis color: red  (Alpha = 1 : fully opaque)
		//myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
		//// Y axis color: green
		//myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		//// Z axis color: blue
		//myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
		//mMesh->setColor(myRGBcolors);
		//mMesh->setPrimitive(GL_TRIANGLES);
		//mMesh->render();

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

		/*glPolygonMode(GL_FRONT, GL_POINT);
		glPointSize(10);*/
		mMesh->render();
	}
}
void RGBTriangle::update() {
	static double angle = 0.05; //angulo inicial

	//angulo de rotacion en radianes para la rotacion en sentido antihorario
	//double angleAntiHor = angle;
	//angulo de rotacion en radianes para la rotacion en sentido horario sobre si mismo
	////double angleHor = -angle;
	////nueva matriz de modelado con ambas rotaciones
	glm::dmat4 newModelMat = glm::rotate(mModelMat, angle, glm::dvec3(0.0, 0.0, 1.0)); //rotacion sobre la circunferencia
	//newModelMat = glm::rotate(newModelMat, angle, glm::dvec3(0.0, 0.0, -1.0)); //rotacion sobre si mismo

	////establecer nueva matriz de modelado
	setModelMat(newModelMat);

}