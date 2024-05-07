#include "SphereR.h"

SphereR::~SphereR() {
	delete mMesh;
	mMesh = nullptr;
}
void SphereR::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), mColor));
		//glColor3f(mColor.r, mColor.g, mColor.b);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mMesh->render();

		//restablecer el modo de poligono
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//restablecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
	}
}