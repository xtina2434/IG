#include "Cube.h"

Cube::~Cube() {
	delete mMesh;
	mMesh = nullptr;
}
void Cube::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		glPolygonMode(GL_FRONT, GL_LINE);
		glColor4d(0.0, 0.0, 0.0, 0.0);

		glPolygonMode(GL_BACK, GL_POINT);
		glPointSize(5);
		mMesh->render();
	}
}