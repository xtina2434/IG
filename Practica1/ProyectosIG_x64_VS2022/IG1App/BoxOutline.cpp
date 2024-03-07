#include "BoxOutline.h"
#include <iostream>

BoxOutline::~BoxOutline() {
	delete mMesh;
	mMesh = nullptr;
}
void BoxOutline::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//APARTADO 22
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//std::vector<glm::dvec4> black(mMesh->size(), glm::dvec4(0.0, 0.0, 0.0, 1.0));
		//mMesh->setColor(black);

		//APARTADO 23
		//verificar si se ha cargado una textura
		/*
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		*/

		//APARTADO 24
		glEnable(GL_CULL_FACE);
		if (mTexture != nullptr) {
			mTexture->bind(GL_REPLACE);
			glCullFace(GL_BACK);
			mMesh->render();
		}
		else {
			//si no hay textura, rendereizarlo con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}

		if (backTexture != nullptr) {
			backTexture->bind(GL_REPLACE);
			glCullFace(GL_FRONT);
			mMesh->render();
		}
		else {
			//si no hay textura, rendereizarlo con color blanco
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}

		//desactivar la textura si se habia activado
		if (mTexture != nullptr) {
			mTexture->unbind();
		}
		if (backTexture != nullptr) {
			backTexture->unbind();
		}

		glDisable(GL_CULL_FACE);
	}
}