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
		glColor4d(mColor.r, mColor.g, mColor.b, mColor.a);
		mMesh->render();
		//restablecer el color por defecto
		glColor4d(1.0, 1.0, 1.0, 1.0);
	}
}