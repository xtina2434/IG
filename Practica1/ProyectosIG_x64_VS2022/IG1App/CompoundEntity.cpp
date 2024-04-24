#include "CompoundEntity.h"

CompoundEntity::CompoundEntity() {

}
CompoundEntity::~CompoundEntity()
{
	for (Abs_Entity* e : gObjects) {
		delete(e);
		e = nullptr;
	}
}

void CompoundEntity::addEntity(Abs_Entity* ae)
{
	gObjects.push_back(ae);
}

void CompoundEntity::render(glm::dmat4 const& modelViewMat) const
{
	for (Abs_Entity* e : gObjects) {
		e->render(modelViewMat * mModelMat);
	}
}

void CompoundEntity::setColor(glm::dvec4 const& col)
{
	for (Abs_Entity* e : gObjects) {
		e->setColor(col);
	}
}
void CompoundEntity::update() {
	for (Abs_Entity* e : gObjects) {
		e->update();
	}
	//rotacion sentido antihorario
	setModelMat(glm::rotate(modelMat(), glm::radians(3.0), glm::dvec3(0, 0, 1)));
}
