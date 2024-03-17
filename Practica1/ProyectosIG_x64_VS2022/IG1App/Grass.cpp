#include "Grass.h"
Grass::~Grass() {
	delete mMesh;
	mMesh = nullptr;
}
void Grass::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		//activar blending
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0);
		//GL_SRC_ALPHA:se utiliza la componente alfa(transparencia) de la malla que se renderiza como factor de la ponderacion para la mezcla
		//GL_ONE_MINUS_SRC_ALPHA: se utiliza el complemento del valor alfa de la malla como factor de mezcla para los frames que ya estan en el framebuffer
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //alfa blending: configurar como vamos a mezclar los colores nuevos con los colores que ya hay en el framebuffer
		//ej: si alfa es 0.5, va a ser semitransparente
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_ADD);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		//renderizar hierba
		mMesh->render();
		aMat = glm::rotate(aMat, glm::radians(60.0), glm::dvec3(0, 1, 0));
		upload(aMat);
		mMesh->render();
		aMat = glm::rotate(aMat, glm::radians(60.0), glm::dvec3(0, 1, 0));
		upload(aMat);
		mMesh->render();
		//desactivar blending
		glDisable(GL_ALPHA_TEST);
		//desactivar la textura si se habia activado
		if (mTexture != nullptr) {
			mTexture->unbind();
		}
		//restablecer color y modo
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}