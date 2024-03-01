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
	load();


	int APARTADO = 26;
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

	case 18:
	case 19:
	case 20: {	//APARTADO 18 19 y 20
		Ground* myGround = new Ground(225, 225, gTextures[0]);
		gObjects.push_back(myGround); 
		}
		break;

	case 21:
	case 22: {
		BoxOutline* myBox = new BoxOutline(200, gTextures[1], gTextures[2]);
		gObjects.push_back(myBox);
	}
		break;
	case 25:
	case 26: {
		Star3D* myStar = new Star3D(100, 4, 100);
		gObjects.push_back(myStar);
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
	for (Texture* tex : gTextures) {
		delete tex;
		tex = nullptr;
	}
}
void
Scene::setGL()
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)  //APARTADO 1
	glEnable(GL_DEPTH_TEST);          // enable Depth test
	glEnable(GL_TEXTURE_2D);
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
	glDisable(GL_TEXTURE_2D);
}

void Scene::load()
{
	Texture* groundText = new Texture();
	groundText->load("../BmpsP1-20240223/baldosaC.bmp",255);
	gTextures.push_back(groundText);
	
	Texture* boxExtText = new Texture();
	boxExtText->load("../BmpsP1-20240223/container.bmp",255);
	gTextures.push_back(boxExtText);

	Texture* boxIntText = new Texture();
	boxIntText->load("../BmpsP1-20240223/papelE.bmp",255);
	gTextures.push_back(boxIntText);
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

