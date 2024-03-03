#include "GlassParapet.h"
#include <iostream>

GlassParapet::~GlassParapet() {
	delete mMesh;
	mMesh = nullptr;
}
void GlassParapet::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//activar blending
		glEnable(GL_BLEND);
		//GL_SRC_ALPHA:se utiliza la componente alfa(transparencia) de la malla que se renderiza como factor de la ponderacion para la mezcla
		//GL_ONE_MINUS_SRC_ALPHA: se utiliza el complemento del valor alfa de la malla como factor de mezcla para los frames que ya estan en el framebuffer
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //alfa blending: configurar como vamos a mezclar los colores nuevos con los colores que ya hay en el framebuffer
		//ej: si alfa es 0.5, va a ser semitransparente
		//APARTADO 31
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar la caja de color blanco
			std::vector<glm::dvec4> white(mMesh->size(), glm::dvec4(1.0,1.0, 1.0, 1.0));
			mMesh->setColor(white);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		mMesh->render();
		if (mTexture != nullptr) {
			mTexture->unbind();
			
		}
		//desactivar blending
		glDisable(GL_BLEND);
	}
}