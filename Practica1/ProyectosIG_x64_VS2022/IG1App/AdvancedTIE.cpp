#include "AdvancedTIE.h"

AdvancedTIE::AdvancedTIE()
{
	tieSpotLight = new SpotLight();
	tieSpotLight->setAmb(glm::fvec4(0.0, 0.0, 0.0, 1.0));
	tieSpotLight->setDiff(glm::fvec4(1.0, 1.0, 1.0, 1.0));
	tieSpotLight->setSpec(glm::fvec4(0.5, 0.5, 0.5, 1.0));
	tieSpotLight->setPosDir(glm::fvec3(0.0, 900.0, 0.0)); //posicion inicial foco
	
}
AdvancedTIE::~AdvancedTIE() {
	delete tieSpotLight;
}

void AdvancedTIE::render(glm::dmat4 const& modelViewMat) const
{
	for (Abs_Entity* e : gObjects) {
		e->render(modelViewMat * mModelMat);
	}
	//actualizar foco
	glm::dvec3 tiePos = glm::dvec3(mModelMat * glm::dvec4(0.0, 0.0, 0.0, 1.0));
	tieSpotLight->setPosDir(glm::fvec3(tiePos));
	tieSpotLight->upload(modelViewMat);
}
