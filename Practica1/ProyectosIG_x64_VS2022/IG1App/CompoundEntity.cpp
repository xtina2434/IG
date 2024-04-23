#include "CompoundEntity.h"

CompoundEntity::CompoundEntity() {

}
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
	//lo comento pq ni idea si es asi
	for (Abs_Entity* e : gObjects) {
		e->update();
	}
	setModelMat(glm::rotate(modelMat(), glm::radians(180.0), glm::dvec3(0, 0, 1)));
}
