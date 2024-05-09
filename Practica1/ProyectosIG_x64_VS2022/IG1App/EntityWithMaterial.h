#pragma once
#ifndef _H_EntityWithMaterial_H_
#define _H_EntityWithMaterial_H_
#include "Entity.h"
#include "Material.h"
class EntityWithMaterial : public Abs_Entity {
public:
	EntityWithMaterial() : Abs_Entity() { };
	virtual ~EntityWithMaterial() { };
	void setMaterial(Material* matl) { material = matl; };
protected:
	Material* material = nullptr;
};

#endif