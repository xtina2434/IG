#pragma once
#ifndef _H_Light_H_
#define _H_Light_H_
#include <GL/freeglut.h> // OpenGL Utility Toolkit
#include <glm/glm.hpp>   // OpenGL Mathematics
#include <glm/gtc/type_ptr.hpp>
class Light { // Abstract class
protected:
	static GLuint cont; // Atributo para poder generar un nuevo id cada vez
	GLuint id = GL_LIGHT0 + GL_MAX_LIGHTS; // Primer id no válido
	// Atributos lumínicos y geométrico de la fuente de luz
	glm::fvec4 ambient = { 0.1 , 0.1 , 0.1 , 1 };
	glm::fvec4 diffuse = { 0.5 , 0.5 , 0.5 , 1 };
	glm::fvec4 specular = { 0.5 , 0.5 , 0.5 , 1 };
	glm::fvec4 posDir = { 0 , 0 , 1 , 0 };
	// Añade setters para cambiar el valor de los atributos lumínicos
	
	
public:
	Light();
	virtual ~Light() { disable(); } 
	void uploadL() const; //??
	// Método abstracto
	virtual void upload(glm::dmat4 const& modelViewMat) const = 0;
	void setAmb(glm::fvec4 amb) { ambient = amb; uploadL(); }
	void setDiff(glm::fvec4 diff) { diffuse = diff; uploadL(); }
	void setSpec(glm::fvec4 spec) { specular = spec; uploadL(); }
	void disable();
	void enable();
};

#endif