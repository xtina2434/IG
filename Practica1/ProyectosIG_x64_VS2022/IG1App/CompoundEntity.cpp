#include "CompoundEntity.h"

CompoundEntity::~CompoundEntity()
{
	for (Abs_Entity* e : gObjects) {
		delete(e);
	}
}

void CompoundEntity::addEntity(Abs_Entity* ae)
{
	gObjects.push_back(ae);
}

void CompoundEntity::render(glm::dmat4 const& modelViewMat) const
{
	for (Abs_Entity* e : gObjects) {
		e->render(modelViewMat);
	}
}

