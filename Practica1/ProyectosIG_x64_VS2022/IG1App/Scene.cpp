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
	//debe ir en setscene
	int APARTADO = 63;
	switch (APARTADO)
	{
	case 3: {  //APARTADO 3
		GLuint numSides = 7;
		RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
		myPolygon->setColor(glm::dvec4(0.0, 0.0, 0.0, 1.0));
		gObjects.push_back(myPolygon); }
		  break;

	case 4: {  //APARTADO 4
		GLuint numSides = 7;
		RegularPolygon* myPolygon = new RegularPolygon(numSides, 100.0);
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

	case 6: {  //APARTADO 6 y 7
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
		myCube->setColor(glm::dvec4(0.0, 0.0, 0.0, 1.0));
		gObjects.push_back(myCube); }
		  break;

	case 10: {  //APARTADO 10
		RGBCube* myCube = new RGBCube(200);
		gObjects.push_back(myCube); }
		   break;

	case 17: {  //APARTADOS DEL 11 EN ADELANTE
		if (mId == 0) {

			GLuint numSides = 128;
			int r = 260;

			RGBRectangle* myRGBRectangle = new RGBRectangle(2.0 * r, r);
			gObjects.push_back(myRGBRectangle);

			RegularPolygon* myCircle = new RegularPolygon(numSides, r);
			gObjects.push_back(myCircle);

			RGBTriangle* myRGBTriangle = new RGBTriangle(3, 50);
			glm::dmat4 mT = glm::translate(glm::dmat4(1.0f), glm::dvec3(r, 0, 0));
			myRGBTriangle->setModelMat(mT);
			gObjects.push_back(myRGBTriangle);
		}

		else if (mId == 1) {
			RGBCube* myCube = new RGBCube(200);
			static double angle = 3.1416 / 2;

			glm::dmat4 mR = glm::rotate(glm::dmat4(1.0), angle, glm::dvec3(0.0, 0.0, 1.0));
			glm::dmat4 mT = glm::translate(glm::dmat4(1.0f), glm::dvec3(100, -100, -100));

			myCube->setModelMat(mR * mT);
			gObjects.push_back(myCube);
		}
	}
		   break;
	case 20: {	//APARTADO 18 19 y 20
		Ground* myGround = new Ground(225, 225, gTextures[0], 4, 4);
		gObjects.push_back(myGround);
	}
		   break;
	case 24: { //APARTADO 21,22,23,24
		BoxOutline* myBox = new BoxOutline(200, gTextures[1], gTextures[2]);
		gObjects.push_back(myBox);
	}
		   break;
	case 28: {//APARTADO 25,26,27,28
		Star3D* myStar = new Star3D(100, 6, 100, gTextures[3]);
		gObjects.push_back(myStar);
	}
		   break;
	case 31: {
		GlassParapet* myGP = new GlassParapet(200, gTextures[4]);
		gObjects.push_back(myGP);
	}
		   break;
	case 36: { // APARTADO 35,36
		Ground* myGround = new Ground(600, 600, gTextures[0], 4, 4);
		gObjects.push_back(myGround);
		Photo* myPhoto = new Photo(200, 200);
		gObjects.push_back(myPhoto);
	}
		   break;
	case 38: {
		Ground* myGround = new Ground(225, 225, gTextures[0], 4, 4);
		gObjects.push_back(myGround);
		BoxOutline* myBox = new BoxOutline(30, gTextures[1], gTextures[2]);
		glm::dmat4 translBox = glm::translate(glm::dmat4(1.0f), glm::dvec3(112, 10, 112));
		myBox->setModelMat(translBox);
		gObjects.push_back(myBox);
		Star3D* myStar = new Star3D(30, 6, 30, gTextures[3]);
		glm::dmat4 translStar = glm::translate(glm::dmat4(1.0f), glm::dvec3(112, 50, 112));
		myStar->setModelMat(translStar);
		gObjects.push_back(myStar);
		Photo* myPhoto = new Photo(100, 100);
		gObjects.push_back(myPhoto);
		GlassParapet* myGP = new GlassParapet(300, gTextures[4]);
		gObjects.push_back(myGP);
	}
		   break;
	case 58: {
		Sphere* mySphere = new Sphere(200);
		mySphere->setColor(glm::dvec4(1.0, 0.5, 0.0, 1.0));
		gObjects.push_back(mySphere);

		Disk* myDisk = new Disk(100, 200);
		myDisk->setColor(glm::dvec4(1.0, 0.0, 0.0, 1.0));
		glm::dmat4 rotateDisk = glm::rotate(glm::dmat4(1.0), 3.14 / 2, glm::dvec3(1.0, 0.0, 0.0));
		glm::dmat4 translDisk = glm::translate(glm::dmat4(1.0f), glm::dvec3(0, 0, -150));
		myDisk->setModelMat(rotateDisk * translDisk);
		gObjects.push_back(myDisk);

		PartialDisk* myPartialDisk = new PartialDisk(100, 150, 90, 180);
		myPartialDisk->setColor(glm::dvec4(0.0, 1.0, 0.0, 1.0));
		glm::dmat4 translPartialDisk = glm::translate(glm::dmat4(1.0f), glm::dvec3(0, 0, 150));
		myPartialDisk->setModelMat(translPartialDisk);
		gObjects.push_back(myPartialDisk);

		Cylinder* myCylinderA = new Cylinder(20, 0, 20);
		myCylinderA->setColor(glm::dvec4(0.0, 0.0, 1.0, 1.0));
		glm::dmat4 translCylinderA = glm::translate(glm::dmat4(1.0f), glm::dvec3(50, 80, 200));
		myCylinderA->setModelMat(translCylinderA);
		gObjects.push_back(myCylinderA);
		Cylinder* myCylinderB = new Cylinder(20, 0, 20);
		myCylinderB->setColor(glm::dvec4(0.1, 0.3, 0.5, 1.0));
		glm::dmat4 translCylinderB = glm::translate(glm::dmat4(1.0f), glm::dvec3(-50, 80, 200));
		myCylinderB->setModelMat(translCylinderB);
		gObjects.push_back(myCylinderB);
	}
		   break;
	case 60: {
		AdvancedTIE * myTIE = new AdvancedTIE();
		
		Cylinder* myCylinder = new Cylinder(30, 30, 400);
		glm::dmat4 mT1 = glm::translate(glm::dmat4(1.0f), glm::dvec3(0, 0, -200));
		myCylinder->setModelMat(mT1);
		myTIE->addEntity(myCylinder);

		Sphere* mySphere = new Sphere(100);
		myTIE->addEntity(mySphere);

		WingAdvancedTIE* myWing1 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		myTIE->addEntity(myWing1);

		WingAdvancedTIE* myWing2 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		glm::dmat4 mR1 = glm::rotate(glm::dmat4(1.0), 3.1416, glm::dvec3(0.0, 1.0, 0.0));
		myWing2->setModelMat(mR1);
		myTIE->addEntity(myWing2);

		CompoundEntity* myMorro = new CompoundEntity();

		Cylinder* myMorroCylinder = new Cylinder(70, 70, 20);
		glm::dmat4 mR2 = glm::rotate(glm::dmat4(1.0), 3.1416/2, glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 mT2 = glm::translate(glm::dmat4(1.0f), glm::dvec3(80, 0, 0));
		myMorroCylinder->setModelMat(mT2 * mR2);
		myMorro->addEntity(myMorroCylinder);

		Disk* myMorroDisk = new Disk(0,70);
		glm::dmat4 mT3 = glm::translate(glm::dmat4(1.0f), glm::dvec3(100, 0, 0));
		myMorroDisk->setModelMat(mT3* mR2);
		myMorro->addEntity(myMorroDisk);

		myTIE->addEntity(myMorro);

		myTIE->setColor(glm::dvec4(0.0, 0.25, 0.6, 1.0));
		gObjects.push_back(myTIE);
	}
		break;
	case 63: {
		IndexedBox* myIndexedBox = new IndexedBox(200);
		myIndexedBox->setColor(glm::dvec4(0.0, 1.0, 0.0, 1.0));
		gObjects.push_back(myIndexedBox);
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
	glEnable(GL_COLOR_MATERIAL);
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
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

	Texture* starText = new Texture();
	starText->load("../BmpsP1-20240223/baldosaP.bmp",255);
	gTextures.push_back(starText);

	Texture* glassText = new Texture();
	glassText->load("../BmpsP1-20240223/windowV.bmp",128);
	gTextures.push_back(glassText);

	Texture* nightText = new Texture();
	nightText->load("../BmpsP1-20240223/noche.bmp", 128);
	gTextures.push_back(nightText);
}

void
Scene::render(Camera const& cam) const
{
	sceneDirLight(cam);
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

void 
Scene::sceneDirLight(Camera const& cam) const {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glm::fvec4 posDir = { 1, 1, 1, 0 };
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(cam.viewMat()));
	glLightfv(GL_LIGHT0, GL_POSITION, value_ptr(posDir));
	glm::fvec4 ambient = { 0, 0, 0, 1 };
	glm::fvec4 diffuse = { 1, 1, 1, 1 };
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, value_ptr(ambient));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, value_ptr(diffuse));
	glLightfv(GL_LIGHT0, GL_SPECULAR, value_ptr(specular));
}

