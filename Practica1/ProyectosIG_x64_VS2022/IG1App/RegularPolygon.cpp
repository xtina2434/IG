#include "RegularPolygon.h"

RegularPolygon::~RegularPolygon() {
	delete mMesh;
	mMesh = nullptr;
}
void RegularPolygon::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		//establecer color
		glColor4d(mColor.r, mColor.g, mColor.b, mColor.a);
		mMesh->render();
		//restablecer el color por defecto
		glColor4d(1.0, 1.0, 1.0, 1.0);
	}
}