#include "Ground.h"
Ground::~Ground() {
	delete mMesh;
	mMesh = nullptr;
}
void Ground::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 8
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glPolygonMode(GL_BACK, GL_FILL);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();
	}
}