#pragma once
#ifndef _H_PosLight_H_
#define _H_PosLight_H_

#include "Light.h"
class PosLight : public Light { 
protected:
	// Factores de atenuación
	GLfloat kc = 1, kl = 0, kq = 0;
public:
	using Light::uploadL;
	virtual void upload(glm::dmat4 const& modelViewMat) const;
	void setPosDir(glm::fvec3 dir);
	void setAtte(GLfloat _kc, GLfloat _kl, GLfloat _kq) {
		kc = _kc;
		kl = _kl;
		kq = _kq;
	};
};
#endif