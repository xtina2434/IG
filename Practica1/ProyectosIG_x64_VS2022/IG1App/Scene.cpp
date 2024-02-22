#include "Scene.h"
#include "CheckML.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new EjesRGB(400.0));

	////APARTADO 3
	/*GLuint numSides = 7;
	RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
	gObjects.push_back(myPolygon);*/

	////APARTADO 4
	/*GLuint numSides = 7;
	RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
	myPolygon->setColor(glm::dvec4(0.0, 0.0, 0.0, 1.0));
	gObjects.push_back(myPolygon);*/

	////APARTADO 5
	/*GLuint numSidesT = 3;
	RegularPolygon* myTriangle = new RegularPolygon(numSidesT, 100.0);
	myTriangle->setColor(glm::dvec4(0.0, 1.0, 0.8, 1.0));
	gObjects.push_back(myTriangle);
	GLuint numSidesC = 30;
	RegularPolygon* myCircle = new RegularPolygon(numSidesC, 100.0);
	myCircle->setColor(glm::dvec4(1.0, 0.0, 1.0, 1.0));
	gObjects.push_back(myCircle);*/

	////APARTADO 6
	/*RGBTriangle* myRGBTriangle = new RGBTriangle(3, 100);
	gObjects.push_back(myRGBTriangle);*/

	//APARTADO 8
	/*RegularPolygon* myRectangle = new RegularPolygon(100.0, 70.0);
	gObjects.push_back(myRectangle);*/
	/*RGBRectangle* myRGBRectangle= new RGBRectangle(100.0, 80.0);
	gObjects.push_back(myRGBRectangle);*/

	//APARTADO 9
	//Cube* myCube = new Cube(500);
	//gObjects.push_back(myCube);

	//APARTADO 10
	//	RGBCube* myCube = new RGBCube(200);
	//gObjects.push_back(myCube);

	if (mId == 0) {
		RGBRectangle* myRGBRectangle = new RGBRectangle(500, 300);
		gObjects.push_back(myRGBRectangle);

		GLuint numSides = 128;
		int r = 260;
		RegularPolygon* myCircle = new RegularPolygon(numSides, r);
		gObjects.push_back(myCircle);

		RGBTriangle* myRGBTriangle = new RGBTriangle(3, 50);
		glm::dmat4 mT = glm::translate(glm::dmat4(1.0f), glm::dvec3(r, 0, 0));
		myRGBTriangle->setModelMat(mT);
		gObjects.push_back(myRGBTriangle);
	}

	if (mId == 1) {
		RGBCube* myCube = new RGBCube(200);
		gObjects.push_back(myCube);

	}
}

void
Scene::setScene(int id) {
	mId = id;
}

void
Scene::free()
{ // release memory and resources

	for (Abs_Entity* el : gObjects) {
		delete el;
		el = nullptr;
	}
}
void
Scene::setGL()
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)  //APARTADO 1
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
}

void
Scene::render(Camera const& cam) const
{
	cam.upload();
	for (Abs_Entity* el : gObjects) {
		el->render(cam.viewMat());
	}
}
void
Scene::update() {
	for (Abs_Entity* entity : gObjects) {
		entity->update();
	}
}

