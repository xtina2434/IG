#ifndef _H_CompoundEntity_H_
#define _H_CompoundEntity_H_
#include <vector>
#include "Entity.h"

class CompoundEntity : public Abs_Entity {
public:
	CompoundEntity();
	virtual ~CompoundEntity();

	void addEntity(Abs_Entity* ae);
	virtual void render(glm::dmat4 const& modelViewMat) const override;
	virtual void update() override;
	void setColor(glm::dvec4 const& col) override;

protected:
	std::vector<Abs_Entity*> gObjects;
};
#endif //_H_CompoundEntity_H_