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


	int APARTADO = 17;
	switch (APARTADO)
	{
	case 3: {  //APARTADO 3
		GLuint numSides = 7;
		RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
		gObjects.push_back(myPolygon); }
		break;

	case 4: {  //APARTADO 4
		GLuint numSides = 7;
		RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
		myPolygon->setColor(glm::dvec4(0.0, 0.0, 0.0, 1.0));
		gObjects.push_back(myPolygon); }
		break;

	case 5: { //APARTADO 5
		GLuint numSidesT = 3;
		RegularPolygon* myTriangle = new RegularPolygon(numSidesT, 100.0);
		myTriangle->setColor(glm::dvec4(0.0, 1.0, 0.8, 1.0));
		gObjects.push_back(myTriangle);
		GLuint numSidesC = 30;
		RegularPolygon* myCircle = new RegularPolygon(numSidesC, 100.0);
		myCircle->setColor(glm::dvec4(1.0, 0.0, 1.0, 1.0));
		gObjects.push_back(myCircle); }
		break;

	case 6: {  //APARTADO 6
		RGBTriangle* myRGBTriangle = new RGBTriangle(3, 100);
		gObjects.push_back(myRGBTriangle); }
		break;

	case 8: {  //APARTADO 8
		RegularPolygon* myRectangle = new RegularPolygon(100.0, 70.0);
		gObjects.push_back(myRectangle);
		RGBRectangle* myRGBRectangle = new RGBRectangle(100.0, 80.0);
		gObjects.push_back(myRGBRectangle); }
		break;

	case 9: {  //APARTADO 9
		Cube* myCube = new Cube(300);
		gObjects.push_back(myCube); }
		break;

	case 10: {  //APARTADO 10
		RGBCube* myCube = new RGBCube(200);
		gObjects.push_back(myCube); }
		break;

	case 11:
	case 12:
	case 13:
	case 14:
	case 15: 
	case 16: 
	case 17: {  //APARTADOS DEL 11 EN ADELANTE
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
			static double angle = 3.1416/2;
			glm::dmat4 mT = glm::translate(glm::dmat4(1.0f), glm::dvec3(100, -100, 100));
			glm::dmat4 mR = glm::rotate(glm::dmat4(1.0), angle, glm::dvec3(0.0, 0.0, 1.0));
			mR = glm::rotate(mR, angle, glm::dvec3(0.0, 1.0, 0.0));
			myCube->setModelMat(mR * mT);
			gObjects.push_back(myCube);
		}
	}
	break;

	default:
	break;
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

