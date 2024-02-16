#include "RGBCube.h"

RGBCube::~RGBCube() {
	delete mMesh;
	mMesh = nullptr;
}
void RGBCube::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor4d(0.0, 0.0, 0.0, 0.0);
		mMesh->render();
	}
}