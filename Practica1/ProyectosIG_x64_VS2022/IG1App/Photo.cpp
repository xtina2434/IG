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
		
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_DEPTH);
		//verificar si se ha cargado una textura
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->bind(GL_REPLACE);
		}
		else {
			//si no hay textura, rendereizar el ground con color blanco
			//mMesh->size() devuelve el num de vertices de mesh, se necesita para al aplicar el color que se garantice que haya un color para cada vertice
			mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		//renderizar foto
		mMesh->render();

		//desactivar la textura si se habia activado
		if (mTexture != nullptr) {
			//activar la textura
			mTexture->unbind();
		}
		glDisable(GL_DEPTH);
		glEnable(GL_DEPTH_TEST);
		//restablecer color y modo
		mMesh->setColor(std::vector<glm::dvec4>(mMesh->size(), glm::dvec4(1.0, 1.0, 1.0, 1.0)));
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
void Photo::update() {
	//cargar textura mas reciente del buffer
	if (mTexture != nullptr) {
		mTexture->loadColorBuffer(800, 600, GL_FRONT);
	}
}
