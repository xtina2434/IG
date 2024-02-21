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
	std::cout << "update ";

	static double angle = 0.05; //angulo inicial

	////glm::dmat4 rotate = glm::rotate(mModelMat, angle, glm::dvec3(0.0, 0.0, 1.0)); //rotacion sobre si mismo

	////angulo de rotacion en radianes para la rotacion en sentido antihorario
	////double angleAntiHor = angle;
	////angulo de rotacion en radianes para la rotacion en sentido horario sobre si mismo
	//////double angleHor = -angle;
	//////nueva matriz de modelado con ambas rotaciones
	////newModelMat = glm::rotate(mModelMat, angle, glm::dvec3(0.0, 0.0, 1.0)); //rotacion sobre la circunferencia
	////newModelMat = glm::rotate(newModelMat, angle, glm::dvec3(0.0, 0.0, -1.0)); //rotacion sobre si mismo

	//////establecer nueva matriz de modelado

	/////////////////////////////////////////////////////////////////////////
	//////obtener mModelMat actual
	//glm::dmat4 currentModelMat = ;

	//////centro triangulo
	////glm::dvec3 centerTriangle = glm::dvec3(currentModelMat * glm::dvec4(0.0, 0.0, 0.0, 1.0));
	//////trasladar la matriz al origen
	////glm::dmat4 translateToOrigin = glm::translate(glm::dmat4(1.0), -centerTriangle);
	//glm::dmat4 mT =  glm::translate(currentModelMat, glm::dvec3(-260, 0, 0));

	//////rotar sobre si mismo (horario)
	////glm::dmat4 rotationHor = glm::rotate(mT, angle, glm::dvec3(0.0, 0.0, 1.0));

	//////trasladar a la posicion original
	//glm::dmat4 translateOriginalPos = glm::translate(mT, glm::dvec3(260, 0, 0));

	//////rotar sobre circunferencia (antihorario)
	//glm::dmat4 rotationAntiHor = glm::rotate(translateOriginalPos, angle, glm::dvec3(0.0, 0.0, 1.0));

	////rotationAntiHor = glm::rotate(translateOriginalPos, -angle, glm::dvec3(0.0, 0.0, 1.0));



	////glm::dmat4 rotationHor = glm::rotate(rotationAntiHor, -angle, glm::dvec3(0.0, 0.0, 1.0));

	//////combinar transformaciones
	////glm::dmat4 newModelMat = translateOriginalPos * rotationHor * rotationAntiHor * translateToOrigin;

	//////establecer nueva matriz
	//setModelMat(newModelMat);

	setModelMat(glm::rotate(glm::dmat4(1), angle, glm::dvec3(0.0, 0.0, 1.0)) * (glm::rotate(modelMat(), -angle*2, glm::dvec3(0.0, 0.0, 1.0))));
}