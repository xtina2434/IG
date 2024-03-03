#include "GlassParapet.h"
#include <iostream>

GlassParapet::~GlassParapet() {
	delete mMesh;
	mMesh = nullptr;
}
void GlassParapet::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glColor4f(1.0, 1.0, 1.0, 0.3);
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 23
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_MODULATE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			glColor4d(1.0, 1.0, 1.0, 1.0);
		}
		mMesh->render();
	}
}