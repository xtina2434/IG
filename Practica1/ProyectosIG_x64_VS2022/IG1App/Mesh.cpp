#include "Mesh.h"
#include "CheckML.h"
#include <fstream>
#include <array>
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
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(
		  3, GL_DOUBLE, 0, vVertices.data()); // number of coordinates per vertex, type of
		                                      // each coordinate, stride, pointer
		if (vColors.size() > 0) {             // transfer colors
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(
			  4, GL_DOUBLE, 0, vColors.data()); // components number (rgba=4), type of
			                                    // each component, stride, pointer
		}

		draw();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
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

	mesh->mPrimitive = GL_LINE_LOOP;
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
	mesh->vVertices.emplace_back(w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2,- h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);

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
	mesh->vVertices.emplace_back(w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, h / 2, 0.0);
	mesh->vVertices.emplace_back(w / 2, -h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);

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
	mesh->mNumVertices = 36;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const GLdouble m = length / 2;

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

