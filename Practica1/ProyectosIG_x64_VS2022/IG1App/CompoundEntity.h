#ifndef _H_CompoundEntity_H_
#define _H_CompoundEntity_H_
#include <vector>
#include "Entity.h"

class CompoundEntity : public Abs_Entity {
public:
	CompoundEntity();
	~CompoundEntity();

	void addEntity(Abs_Entity* ae);
	void render(glm::dmat4 const& modelViewMat) const;
protected:
	std::vector<Abs_Entity*> gObjects;
};
#endif //_H_CompoundEntity_H_
#pragma once