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
		//establecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), mColor));

		glPolygonMode(GL_BACK, GL_POINT);
		glPointSize(5);
		mMesh->render();

		//restablecer el modo de poligono
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//restablecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
	}
}