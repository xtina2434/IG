#include "Mesh.h"
#include "CheckML.h"
#include <fstream>
#include <array>
#include <iostream>
using namespace std;
using namespace glm;

void
Mesh::draw() const
{
	glDrawArrays(
	  mPrimitive,
	  0,
	  size()); // primitive graphic, first index and number of elements to be rendered
}

void
Mesh::render() const
{
	if (vVertices.size() > 0) { // transfer data
		// transfer the coordinates of the vertices
		if (vNormals.size() > 0) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_DOUBLE, 0, vNormals.data());
		}
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(
		  3, GL_DOUBLE, 0, vVertices.data()); // number of coordinates per vertex, type of
		                                      // each coordinate, stride, pointer
		if (vColors.size() > 0) {             // transfer colors
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(
			  4, GL_DOUBLE, 0, vColors.data()); // components number (rgba=4), type of
			                                    // each component, stride, pointer
		}

		glTexCoordPointer(2, GL_DOUBLE, 0, vTexCoords.data());
		draw();

		if (vNormals.size() > 0) {
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

Mesh*
Mesh::createRGBAxes(GLdouble l)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_LINES;

	mesh->mNumVertices = 6;
	mesh->vVertices.reserve(mesh->mNumVertices);

	// X axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(l, 0.0, 0.0);
	// Y axis vertices
	mesh->vVertices.emplace_back(0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, l, 0.0);
	// Z axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, 0.0, l);

	mesh->vColors.reserve(mesh->mNumVertices);
	// X axis color: red  (Alpha = 1 : fully opaque)
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}
Mesh*
Mesh::generateRegularPolygon(GLuint num, GLdouble r) {

	Mesh* mesh = new Mesh();
	/* //PRUEBAS PARA EL APARTADO 71 ........IGNORAR
	GLuint p = 10; 
	GLuint m = 10;
	glm::dvec3* perfil = new glm::dvec3[p];

	mesh->mPrimitive = /*GL_TRIANGLES*//*GL_LINES;
	mesh->mNumVertices = p/* * m*//*;
	mesh->vVertices.reserve(mesh->mNumVertices);
	glm::dvec3* vs = new glm::dvec3[mesh->mNumVertices];
	for (int i = 0; i < p; i++) {
		//GLdouble theta = i * 180 / p;
		GLdouble theta = (3.14 / (p - 1)) * i;
		perfil[i] = { r * sin(theta), r * cos(theta), 0 };
		cout << "x: " << perfil[i].x << " y: " << perfil[i].y << endl;
		mesh->vVertices.emplace_back(perfil[i].x, perfil[i].y, 0.0);
	}
	*/

	/*
	for (int i = 0; i < p; i++) {
		// Generar la muestra i- ésima de vértices
		GLdouble theta = i * 360 / p;
		GLdouble c = cos(glm::radians(theta));
		GLdouble s = sin(glm::radians(theta));
		for (int j = 0; j < m; j++) {
			GLdouble z = -s * perfil[j].x + c * perfil[j].z;
			GLdouble x = c * perfil[j].x + s * perfil[j].z;
			//GLdouble x = c * perfil[j].x + s * perfil[j].z;
			vs[(i * m) + j] = glm::dvec3(x, perfil[j].y, z);
			//indice++;
		}
	}
	*/

	//for (int i = 0; i < perfil->length(); i++) {
	//	mesh->vVertices.emplace_back(perfil[i]);
	//}

	/*
	if (num == 3) {
		mesh->mPrimitive = GL_TRIANGLES;
	}
	else mesh->mPrimitive = GL_LINE_LOOP;
	mesh->mNumVertices = num;
	mesh->vVertices.reserve(mesh->mNumVertices);

	//incremento del angulo
	GLdouble angleIncrement = glm::radians(360.0) / num;

	for (GLuint i = 0; i < num; i++){
		//empieza por el vertice que se encuentra en el eje Y
		GLdouble alpha = glm::radians(90.0) + i * angleIncrement;
		//calcular coordenadas x e y de cada vertice dentro del circulo
		GLdouble x = r * cos(alpha);
		GLdouble y = r * sin(alpha);
		//plano Z = 0
		mesh->vVertices.emplace_back(x, y, 0.0 ); //agregar las coordenadas	al vector de vertices
	}
	*/


	return mesh;	
}
Mesh*
Mesh::generateRectangle(GLdouble w, GLdouble h) {

	Mesh* mesh = new Mesh();

	mesh->mPrimitive =	GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 4;
	mesh->vVertices.reserve(mesh->mNumVertices);

	//generar los cuatro vertices del rectangulo sobre el plano Z = 0
	//se divide entre dos para asegurarse que los vertices estan centrados en el origen
	mesh->vVertices.emplace_back(-w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2,- h / 2, 0.0);


	return mesh;
}
Mesh*
Mesh::generateRGBRectangle(GLdouble w, GLdouble h) {

	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 4;
	mesh->vVertices.reserve(mesh->mNumVertices);

	//generar los cuatro vertices del rectangulo sobre el plano Z = 0
	//se divide entre dos para asegurarse que los vertices estan centrados en el origen
	mesh->vVertices.emplace_back(-w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, -h / 2, 0.0);

	//colores RGB
	
	std::vector<glm::dvec4> myRGBcolors;
	// X axis color: red  (Alpha = 1 : fully opaque)
	myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	//el color verde se repite en dos vertices
	myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
	myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->setColor(myRGBcolors);
	
	return mesh;
}
Mesh* 
Mesh::generateCube(GLdouble length) {
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 14;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const GLdouble m = length / 2;

	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(m, -m, m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(m, m, -m);
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(-m, -m, -m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(m, m, -m);

	return mesh;
}

Mesh*
Mesh::generateRGBCubeTriangles(GLdouble length) {
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLES;
	//6 caras, 2 triangulos por cara = 12 triangulos * 3 vertices = 36
	mesh->mNumVertices = 36;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const GLdouble m = length / 2;

	//Se define un array de vectores bidimensionales PIVOTS, que representan las posiciones relativas de los vértices dentro de cada cara del cubo.
	constexpr array<dvec2, 3> PIVOTS = { dvec2{-1, 1}, {1, -1}, {1, 1} };
	//vertices
	for (int edge = 0; edge < 3; ++edge) {
		for (int value : {-m,m}) {
			dvec3 center = { 0,0,0 };
			center[edge] = value;

			dvec3 u = { 0,0,0 };
			u[(edge + 1) % 3] = 1; 
			dvec3 v = glm::cross(u, glm::normalize(-center));

			for (double triangle : {m, -m})
				for (const dvec2& m : PIVOTS)
					mesh->vVertices.push_back(center + triangle *  (m.x * u + m.y * v));
		}
	}

	//colores
	for (int edge = 0; edge < 3; ++edge) {
		dvec4 color = { 0.0,0.0,0.0, 1.0 };
		color[edge] = 1.0;
		for (int i = 0; i < 12;i++) {
			mesh->vColors.push_back(color);
		}
	}

	return mesh;
} 
Mesh*
Mesh::generateRectangleTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh) {
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 4;
	mesh->vVertices.reserve(mesh->mNumVertices);
	mesh->vTexCoords.reserve(mesh->mNumVertices);

	//definir vertices
	//se divide entre dos para asegurarse que los vertices estan centrados en el origen
	mesh->vVertices.emplace_back(-w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, -h / 2, 0.0);

	//definir coordenadas de textura
	mesh->vTexCoords.emplace_back(0.0, 1.0 * rh);
	mesh->vTexCoords.emplace_back(0.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0 * rw, 1.0 * rh);
	mesh->vTexCoords.emplace_back(1.0 * rw, 0.0);

	return mesh;
}

Mesh* Mesh::generateBoxOutline(GLdouble length)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 10;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const GLdouble m = length / 2;
	//cubo sin tapas
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(m, -m, m);
	mesh->vVertices.emplace_back(m, m, -m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(-m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);

	return mesh;
}

Mesh* Mesh::generateBoxOutlineTexCor(GLdouble length)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 10;
	mesh->vVertices.reserve(mesh->mNumVertices);
	mesh->vTexCoords.reserve(mesh->mNumVertices);

	const GLdouble m = length / 2;
	//cubo sin tapas
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(m, -m, m);
	mesh->vVertices.emplace_back(m, m, -m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(-m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);

	//definir coordenadas de textura
	mesh->vTexCoords.emplace_back(0.0, 1.0);
	mesh->vTexCoords.emplace_back(0.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0, 1.0);
	mesh->vTexCoords.emplace_back(1.0, 0.0);
	mesh->vTexCoords.emplace_back(0.0, 1.0);
	mesh->vTexCoords.emplace_back(0.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0, 1.0);
	mesh->vTexCoords.emplace_back(1.0, 0.0);
	mesh->vTexCoords.emplace_back(0.0, 1.0);
	mesh->vTexCoords.emplace_back(0.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0, 1.0);
	mesh->vTexCoords.emplace_back(1.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0, 1.0);
	mesh->vTexCoords.emplace_back(1.0, 0.0);

	return mesh;
}

Mesh* Mesh::generateStar3D(GLdouble re, GLuint np, GLdouble h)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_FAN;
	mesh->mNumVertices = (np * 2) + 2; //+2 para contar con el vertice de origen de origen y cerrar la estrella al final 
	mesh->vVertices.reserve(mesh->mNumVertices);

	//incremento del angulo
	GLdouble angleIncrement = glm::radians(360.0) / (mesh->mNumVertices - 2); //-2 para no contar con el vertice de origen ni con el ultimo

	//vertice de origen
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);

	//radio puntos internos
	GLdouble ri = re / 2;

	for (GLuint i = 0; i < mesh->mNumVertices - 1; ++i) { //hay 14 en total, mesh->mNumVertices - 1 es 13, para no contar con el de origen ni con el ultimo
		GLdouble alpha = i * angleIncrement;
		//calcular coordenadas x e y de cada vertice dentro del circulo
		GLdouble x=0, y=0;
		//circulo interno
		if (i % 2 == 0) {
			x = ri * cos(alpha);
			y = ri * sin(alpha);
		}
		//circulo externo
		else {
			x = re * cos(alpha);
			y = re * sin(alpha);
		}
		//plano Z = h
		mesh->vVertices.emplace_back(x, y, h); //agregar las coordenadas al vector de vertices
	}
	//concectar el ultimo vertice con el primero
	mesh->vVertices.emplace_back(mesh->vVertices[1]);
	return mesh;

}

Mesh* Mesh::generateStar3DTexCor(GLdouble re, GLuint np, GLdouble h)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_FAN;
	mesh->mNumVertices = (np * 2) + 2; //+2 para contar con el vertice de origen de origen y cerrar la estrella al final 
	mesh->vVertices.reserve(mesh->mNumVertices);
	mesh->vTexCoords.reserve(mesh->mNumVertices);

	//incremento del angulo
	GLdouble angleIncrement = glm::radians(360.0) / (mesh->mNumVertices - 2); //-2 para no contar con el vertice de origen ni con el ultimo

	//vertice de origen
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	//definir coordenadas de textura
	mesh->vTexCoords.emplace_back(0.5, 0.5); //v0
	//radio puntos internos
	GLdouble ri = re / 2;
	//coordenadas de textura
	GLdouble u = 0.5, v = 0.5;

	for (GLuint i = 0; i < mesh->mNumVertices - 1; ++i) { //hay 14 en total, mesh->mNumVertices - 1 es 13, para no contar con el de origen ni con el ultimo
		GLdouble alpha = i * angleIncrement;
		//calcular coordenadas x e y de cada vertice dentro del circulo
		GLdouble x = 0, y = 0;
		//circulo externo
		if (i % 2 != 0) {
			x = re * cos(alpha);
			y = re * sin(alpha);
		}
		//circulo interno
		else {
			x = ri * cos(alpha);
			y = ri * sin(alpha);
		}
		//plano Z = h
		mesh->vVertices.emplace_back(x, y, h); //agregar las coordenadas al vector de vertices

		//textura
		u = 0.5 + 0.5 * cos(alpha);
		v = 0.5 + 0.5 * sin(alpha);
		//añadir las coordenadas de la textura a la mesh
		mesh->vTexCoords.emplace_back(u, v);
	}
	//concectar el ultimo vertice con el primero
	mesh->vVertices.emplace_back(mesh->vVertices[1]);
	mesh->vTexCoords.emplace_back(mesh->vTexCoords[1]);

	
	//GLdouble u = 0, v = 0;
	//for (GLuint i = 0; i < mesh->mNumVertices - 1; ++i) { //hay 14 en total, mesh->mNumVertices - 1 es 13, para no contar con el de origen ni con el ultimo
	//	//empieza 8 en positivo
	//	if ((i/8) % 2 == 0) {
	//		if ((i / 4) % 2 == 0) {
	//			u += 0.25;
	//		}
	//		else {
	//			v += 0.25;
	//		}
	//	}
	//	//luego 8 restando
	//	else {
	//		if ((i / 4) % 2 == 0) {
	//			u -= 0.25;
	//		}
	//		else {
	//			v -= 0.25;
	//		}
	//	}
	//	mesh->vTexCoords.emplace_back(u, v); //agregar las coordenadas al vector de vertices
	//}
	//mesh->vTexCoords.emplace_back(0.5, 0.5); //v0

	return mesh;
}



Mesh* Mesh::generateWingText(GLdouble w, GLdouble h, GLdouble r) {
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;
	mesh->mNumVertices = 8; 
	mesh->vVertices.reserve(mesh->mNumVertices);
	mesh->vTexCoords.reserve(mesh->mNumVertices);

	mesh->vVertices.emplace_back(-w / 2, h * 1.5, r/2);
	mesh->vVertices.emplace_back(w / 2, h * 1.5, r / 2);
	mesh->vVertices.emplace_back(-w / 2, h / 2, r);
	mesh->vVertices.emplace_back(w / 2, h / 2, r);
	mesh->vVertices.emplace_back(-w / 2,- h / 2, r);
	mesh->vVertices.emplace_back(w / 2,- h / 2, r);
	mesh->vVertices.emplace_back(-w / 2, -h *1.5, r/2);
	mesh->vVertices.emplace_back(w / 2, -h * 1.5, r / 2);


	mesh->vTexCoords.emplace_back(0.0, 0.0);
	mesh->vTexCoords.emplace_back(1.0, 0.0);
	mesh->vTexCoords.emplace_back(0.0 , 0.33);
	mesh->vTexCoords.emplace_back(1.0, 0.33);
	mesh->vTexCoords.emplace_back(0.0, 0.66);
	mesh->vTexCoords.emplace_back(1.0, 0.66);
	mesh->vTexCoords.emplace_back(0.0, 1.0);
	mesh->vTexCoords.emplace_back(1.0, 1.0);
	return mesh;
}