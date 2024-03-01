#include "Star3D.h"
#include <iostream>

Star3D::~Star3D() {
	delete mMesh;
	mMesh = nullptr;
}
void Star3D::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 26
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glColor4d(0.0, 0.0, 0.0, 0.0); 

		mMesh->render();
	}
}