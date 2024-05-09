#pragma once
#ifndef _H_DirLight_H_
#define _H_DirLight_H_

#include "Light.h"
class DirLight : public Light { 
public:
	virtual void upload(glm::dmat4 const& modelViewMat) const;
	void setPosDir(glm::fvec3 dir);
};
#endif