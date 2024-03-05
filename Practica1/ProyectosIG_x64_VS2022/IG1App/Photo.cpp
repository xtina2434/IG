#include "Photo.h"

Photo::~Photo() {
	delete mMesh;
	mMesh = nullptr;
}

void Photo::render(glm::dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		
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
		//mMesh->render();

		//desactivar la textura si se habia activado
		if (mTexture != nullptr) {
			//activar la textura
			//mTexture->unbind();
		}
		
		
		//activar blending
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //alfa blending: configurar como vamos a mezclar los colores nuevos con los colores que ya hay en el framebuffer
		
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->loadColorBuffer(1, 1, GL_READ_BUFFER);
			mTexture->bind(GL_ADD);
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

		//glDisable(GL_BLEND);
	}
}

void Photo::update()
{
}
