#include "RegularPolygon.h"

RegularPolygon::~RegularPolygon() {
	delete mMesh;
	mMesh = nullptr;
}
void RegularPolygon::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		//Multiplica la matriz de vista del modelo (modelViewMat) con la matriz de modelo (mModelMat) para obtener la matriz de transformación final (aMat).
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		//establecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), mColor));
		//establecer polygonmode
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		//restablecer polygonmode
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//restablecer color
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
	}
}