#include "Star3D.h"
#include <iostream>

Star3D::~Star3D() {
	delete mMesh;
	mMesh = nullptr;
}
void Star3D::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {

		//APARTADO 26
		//color negro para todos los vertices
		/*
		
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(0.0, 0.0, 0.0, 1.0)););
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		*/

		//APARTADO 28
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}

		//primera estrella
		glm::dmat4 aMat1 = modelViewMat * mModelMat;
		upload(aMat1);
		mMesh->render();

		//segunda estrella
		//primero se traslada en el eje z, y luego se rota 180 grados sobre el eje y

		static double angle = 3.1416;
		glm::dmat4 rotY(1);
		rotY = glm::rotate(mModelMat, angle, glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 aMat2 = modelViewMat * rotY;
		upload(aMat2);
		mMesh->render();

	}
}

void Star3D::update()
{
	static double angle = 0.05;
	glm::dmat4 rotZ(1);
	rotZ = glm::rotate(mModelMat, angle, glm::dvec3(0.0, 0.0, 1.0));
	glm::dmat4 rotY(1);
	rotY = glm::rotate(glm::dmat4(1.0f), angle, glm::dvec3(0.0, 1.0, 0.0));
	setModelMat(rotY * rotZ);
}
