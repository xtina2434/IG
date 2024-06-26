#include "SphereR.h"

SphereR::~SphereR() {
	delete mMesh;
	mMesh = nullptr;
}
void SphereR::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glLineWidth(100);
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), mColor));
		mMesh->render();

		//restablecer el modo de poligono
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//restablecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
	}
}