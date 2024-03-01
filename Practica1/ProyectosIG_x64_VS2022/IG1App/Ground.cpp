#include "Ground.h"
Ground::~Ground() {
	delete mMesh;
	mMesh = nullptr;
}
void Ground::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 18 
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//APARTADO 19
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			glColor4d(1.0, 1.0, 1.0, 1.0);
		}
		//renderizar suelo
		mMesh->render();

		//desactivar la textura si se habia activado
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->unbind();
		}
	}
}