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
		std::vector<glm::dvec4> black(mMesh->size(), glm::dvec4(0.0, 0.0, 0.0, 1.0));
		mMesh->setColor(black);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//primera estrella
		glm::dmat4 aMat1 = modelViewMat * mModelMat;
		upload(aMat1);
		mMesh->render();

		//segunda estrella
		//primero se traslada en el eje z, y luego se rota 180 grados sobre el eje y
		glm::dmat4 modelMat2 = glm::translate(glm::dmat4(1.0), glm::dvec3(0.0, 0.0, 1.0)) *
							   glm::rotate(glm::dmat4(1.0), glm::radians(180.0), glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 aMat2 = modelViewMat * modelMat2;
		upload(aMat2);
		mMesh->render();

	}
}