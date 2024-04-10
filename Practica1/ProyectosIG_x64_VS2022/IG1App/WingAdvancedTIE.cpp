#include "WingAdvancedTIE.h"
#include <iostream>

WingAdvancedTIE::~WingAdvancedTIE() {
	delete mMesh;
	mMesh = nullptr;
}
void WingAdvancedTIE::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glEnable(GL_BLEND);
		//GL_SRC_ALPHA:se utiliza la componente alfa(transparencia) de la malla que se renderiza como factor de la ponderacion para la mezcla
		//GL_ONE_MINUS_SRC_ALPHA: se utiliza el complemento del valor alfa de la malla como factor de mezcla para los frames que ya estan en el framebuffer
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		////APARTADO 60
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}

		////primera estrella
		glm::dmat4 aMat= modelViewMat * mModelMat;
		upload(aMat);
		mMesh->render();


		//desactivar textura (28)
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->unbind();
		}
		//desactivar blending
		glDisable(GL_BLEND);
		//restablecer color y modo
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

