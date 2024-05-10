#pragma once
#include "CompoundEntity.h"
#include "SpotLight.h"

class AdvancedTIE : public CompoundEntity {
public:
	AdvancedTIE();
	virtual ~AdvancedTIE();
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	SpotLight* getTieSL() { return tieSpotLight; }

protected:
	SpotLight* tieSpotLight;
};