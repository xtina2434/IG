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
	//RegularPolygon* mySquare = new RegularPolygon(4, 50);
	//
	////APARTADO 4
	//glm::dvec4 blueColor(0.0, 0.0, 1.0, 1.0);
	//mySquare->setColor(blueColor);
	//gObjects.push_back(mySquare);

	//RegularPolygon* myHepyagono = new RegularPolygon(7, 100);
	//gObjects.push_back(myHepyagono);

	////APARTADO 5
	//RegularPolygon* myTriangle = new RegularPolygon(3, 100);
	//glm::dvec4 cyanColor(0.0, 1.0, 0.8, 1.0);
	//myTriangle->setColor(cyanColor);
	//gObjects.push_back(myTriangle);

	//RegularPolygon* myCircle = new RegularPolygon(128, 100);
	//glm::dvec4 magentaColor(1.0, 0.0, 1.0, 1.0);
	//myCircle->setColor(magentaColor);
	//gObjects.push_back(myCircle);
	////APARTADO 6,7
	//RGBTriangle* myRGBTriangle = new RGBTriangle(3, 100);
	//gObjects.push_back(myRGBTriangle);

	/*RegularPolygon* myRectangle = new RegularPolygon(100.0, 70.0);
	gObjects.push_back(myRectangle);*/

	//APARTADO 8
	/*RGBRectangle* myRGBRectangle= new RGBRectangle(100, 80);
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

