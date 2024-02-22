#include "RGBCube.h"

RGBCube::~RGBCube() {
	delete mMesh;
	mMesh = nullptr;
}

void RGBCube::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//no hace falta esta linea de código ya que por default se establece así
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		mMesh->render();
	}
}


void RGBCube::update() {
	static double angle = 0.05; //angulo giro
	glm::dmat4 rot(1);
	switch (ejeRot)
	{
	case 'x':
		rot = glm::rotate(glm::dmat4(1.0f), angle, glm::dvec3(1.0, 0.0, 0.0));
		break;
	case 'y':
		rot = glm::rotate(glm::dmat4(1.0f), angle, glm::dvec3(0.0, 1.0, 0.0));
		break;
	case 'z':
		rot = glm::rotate(glm::dmat4(1.0f), angle, glm::dvec3(0.0, 0.0, 1.0));
		break;
	default:
		break;
	}

	//no hemos podido conseguir el cambio de eje

	setModelMat(rot*mModelMat);
}