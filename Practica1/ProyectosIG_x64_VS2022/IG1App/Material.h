#pragma once
#ifndef _H_Material_H_
#define _H_Material_H_
#include <GL/freeglut.h> // OpenGL Utility Toolkit
#include <glm/glm.hpp>   // OpenGL Mathematics
#include <glm/gtc/type_ptr.hpp>
class Material {
protected:
	// Coeficientes de reflexi�n
	glm::fvec4 ambient = { 0.2 , 0.2 , 0.2 , 1.0 };
	glm::fvec4 diffuse = { 0.8 , 0.8 , 0.8 , 1.0 };
	glm::fvec4 specular = { 0.0 , 0.0 , 0.0 , 1.0 };
	GLfloat expF = 0; // Exponente para la reflexi�n especular
	GLuint face = GL_FRONT_AND_BACK;
	GLuint sh = GL_SMOOTH; // Tipo de matizado
public:
	Material() {};
	virtual ~Material() {};
	virtual void upload();
	void setCopper();
	void setGold();
};
#endif