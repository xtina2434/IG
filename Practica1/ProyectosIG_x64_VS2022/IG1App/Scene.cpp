#include "Scene.h"
#include "CheckML.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings
	setLights();
	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new EjesRGB(400.0));
	load();
	//debe ir en setscene
	int APARTADO = 67;
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
		glm::dmat4 rotateDisk = glm::rotate(myDisk->modelMat(), 3.14 * 1.5, glm::dvec3(1.0, 0.0, 0.0));
		glm::dmat4 translDisk = glm::translate(myDisk->modelMat(), glm::dvec3(0, 0, 150));
		myDisk->setModelMat(rotateDisk * translDisk);
		gObjects.push_back(myDisk);

		PartialDisk* myPartialDisk = new PartialDisk(100, 150, 90, 180);
		myPartialDisk->setColor(glm::dvec4(0.0, 1.0, 0.0, 1.0));
		myPartialDisk->setModelMat(glm::translate(myPartialDisk->modelMat(), glm::dvec3(0, 0, 150)));
		gObjects.push_back(myPartialDisk);

		Cylinder* myCylinderA = new Cylinder(20, 0, 20);
		myCylinderA->setColor(glm::dvec4(0.0, 0.0, 1.0, 1.0));
		myCylinderA->setModelMat(glm::translate(myCylinderA->modelMat(), glm::dvec3(50, 80, 180)));
		gObjects.push_back(myCylinderA);
		Cylinder* myCylinderB = new Cylinder(20, 0, 20);
		myCylinderB->setColor(glm::dvec4(0.1, 0.3, 0.5, 1.0));
		myCylinderB->setModelMat(glm::translate(myCylinderB->modelMat(), glm::dvec3(-50, 80, 180)));
		gObjects.push_back(myCylinderB);
	}
		   break;
	case 60: {
		glClearColor(0.0, 0.0, 0.0, 1.0);

		AdvancedTIE * myTIE = new AdvancedTIE();
		
		Cylinder* myCylinder = new Cylinder(30, 30, 400);
		myCylinder->setModelMat(glm::translate(myCylinder->modelMat(), glm::dvec3(0, 0, -200)));
		myTIE->addEntity(myCylinder);

		Sphere* mySphere = new Sphere(100);
		myTIE->addEntity(mySphere);

		WingAdvancedTIE* myWing1 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		myTIE->addEntity(myWing1);

		WingAdvancedTIE* myWing2 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		myWing2->setModelMat(glm::rotate(myWing1->modelMat(), 3.1416, glm::dvec3(0.0, 1.0, 0.0)));
		myTIE->addEntity(myWing2);

		CompoundEntity* myMorro = new CompoundEntity();

		Cylinder* myMorroCylinder = new Cylinder(70, 70, 20);
		glm::dmat4 mRot = glm::rotate(myMorro->modelMat(), 3.1416 / 2, glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 mTrans1 = glm::translate(myMorro->modelMat(), glm::dvec3(80, 0, 0));
		myMorroCylinder->setModelMat(mTrans1* mRot);
		myMorro->addEntity(myMorroCylinder);

		Disk* myMorroDisk = new Disk(0,70);
		glm::dmat4 mTrans2 = glm::translate(myMorro->modelMat(), glm::dvec3(100, 0, 0));
		myMorroDisk->setModelMat(mTrans2* mRot);
		myMorro->addEntity(myMorroDisk);

		myTIE->addEntity(myMorro);

		myTIE->setColor(glm::dvec4(0.0, 0.25, 0.42, 1.0));
		gObjects.push_back(myTIE);
	}
		break;
	case 63: {
		IndexedBox* myIndexedBox = new IndexedBox(200);
		myIndexedBox->setColor(glm::dvec4(0.0, 1.0, 0.0, 1.0));
		gObjects.push_back(myIndexedBox);
	}
		   break;
	case 66: {
		GLuint numSides = 128;
		int r = 300;
		RegularPolygon* myCircle = new RegularPolygon(numSides, r);
		gObjects.push_back(myCircle);

		CompoundEntity* nodoFicticio = new CompoundEntity();

		RGBTriangle* myRGBTriangle = new RGBTriangle(3, 50);
		nodoFicticio->addEntity(myRGBTriangle);
		
		//trasladar el triangulo a traves del nodo ficticio a la circunferencia
		myRGBTriangle->setModelMat(translate(nodoFicticio->modelMat(), dvec3(r, 0, 0)));
		gObjects.push_back(nodoFicticio);
	}
		   break;
	case 67: {

		glClearColor(0.0, 0.0, 0.0, 1.0);

		Sphere* myPlanet = new Sphere(800);
		myPlanet->setColor(glm::dvec4(1.0, 0.8, 0.0, 1.0));
		gObjects.push_back(myPlanet);

		nodo68 = new CompoundEntity();

		myAdvancedTie68 = new AdvancedTIE();

		Cylinder* myCylinder = new Cylinder(30, 30, 400);
		myCylinder->setModelMat(glm::translate(myCylinder->modelMat(), glm::dvec3(0, 0, -200)));
		myAdvancedTie68->addEntity(myCylinder);

		Sphere* mySphere = new Sphere(100);
		myAdvancedTie68->addEntity(mySphere);

		WingAdvancedTIE* myWing1 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		myAdvancedTie68->addEntity(myWing1);

		WingAdvancedTIE* myWing2 = new WingAdvancedTIE(200, 100, 200, gTextures[5]);
		myWing2->setModelMat(glm::rotate(myWing2->modelMat(), 3.1416, glm::dvec3(0.0, 1.0, 0.0)));
		myAdvancedTie68->addEntity(myWing2);

		CompoundEntity* myMorro = new CompoundEntity();

		Cylinder* myMorroCylinder = new Cylinder(70, 70, 20);
		glm::dmat4 mRot1 = glm::rotate(myMorroCylinder->modelMat(), 3.1416 / 2, glm::dvec3(0.0, 1.0, 0.0));
		glm::dmat4 mTrans1 = glm::translate(myMorroCylinder->modelMat(), glm::dvec3(80, 0, 0));
		myMorroCylinder->setModelMat(mTrans1* mRot1);
		myMorro->addEntity(myMorroCylinder);

		Disk* myMorroDisk = new Disk(0, 70);
		glm::dmat4 mTrans2 = glm::translate(myMorroDisk->modelMat(), glm::dvec3(100, 0, 0));
		myMorroDisk->setModelMat(mTrans2* mRot1);
		myMorro->addEntity(myMorroDisk);

		myAdvancedTie68->addEntity(myMorro);

		myAdvancedTie68->setColor(glm::dvec4(0.0, 0.25, 0.42, 1.0));

		nodo68->addEntity(myAdvancedTie68);
		//trasladar el caza a una distancia del radio y un poco mas del centro de la esfera
		myAdvancedTie68->setModelMat(translate(nodo68->modelMat(), dvec3(0, 950, 0)));
		gObjects.push_back(nodo68);
	}
		   break;
	case 71: {
		SphereR* mySphere = new SphereR(50, 10, 20);
		mySphere->setColor(glm::dvec4(0.0, 0.0, 0.0, 1.0));
		gObjects.push_back(mySphere);
	}
		   break;
	case 74: {
		
		Sphere* yellowSphere = new Sphere(100);
		yellowSphere->setColor(glm::dvec4(1.0, 1.0, 0.0, 1.0));
		yellowSphere->setModelMat(glm::translate(yellowSphere->modelMat(), glm::dvec3(300, 0, 0)));
		gObjects.push_back(yellowSphere);

		
		Sphere* goldSphere = new Sphere(100);
		goldMaterial = new Material();

		goldMaterial->setGold();
		goldSphere->setMaterial(goldMaterial);
		goldSphere->setModelMat(glm::translate(goldSphere->modelMat(), glm::dvec3(-200, 0, 0)));
		gObjects.push_back(goldSphere);
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
	delete goldMaterial;
	goldMaterial = nullptr;

	delete dirLight;
	dirLight = nullptr;

	delete posLight;
	posLight = nullptr;

	delete spotLight;
	spotLight = nullptr;

	delete tieSpotLight;
	tieSpotLight = nullptr;
}
void
Scene::setGL()
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)  //APARTADO 1
	glEnable(GL_DEPTH_TEST);          // enable Depth test
	glEnable(GL_TEXTURE_2D);		  // activar texturas
	glEnable(GL_LIGHTING);			  // activar la iluminacion
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);			  // activar normalizacion de los vectores normales
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_NORMALIZE);
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
	cam.upload();
	//upload luces de la escena
	dirLight->upload(cam.viewMat());
	posLight->upload(cam.viewMat());
	spotLight->upload(cam.viewMat());
	tieSpotLight->upload(cam.viewMat());
	
	//sceneDirLight(cam);
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
//void 
//Scene::sceneDirLight(Camera const& cam) const {
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glm::fvec4 posDir = { 1, 1, 1, 0 };
//	glMatrixMode(GL_MODELVIEW);
//	glLoadMatrixd(value_ptr(cam.viewMat()));
//	glLightfv(GL_LIGHT0, GL_POSITION, value_ptr(posDir));
//	glm::fvec4 ambient = { 0.0, 0.0, 0.0, 1 };
//	glm::fvec4 diffuse = { 1, 1, 1, 1 };
//	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, value_ptr(ambient));
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, value_ptr(diffuse));
//	glLightfv(GL_LIGHT0, GL_SPECULAR, value_ptr(specular));
//}

void Scene::cazaRotate()
{
	//rotar el caza para que varie la direccion a la que apunta el morro
	myAdvancedTie68->setModelMat(glm::rotate(myAdvancedTie68->modelMat(), radians(3.0), glm::dvec3(0.0, 1.0,0.0)));
	//actualizar foco
	glm::dvec3 tiePos = glm::dvec3(glm::dvec3(myAdvancedTie68->modelMat() * glm::dvec4(0.0, 0.0, 0.0, 1.0)));
	tieSpotLight->setPosDir(glm::fvec3(tiePos));

	//tieSpotLight->setSpot(glm::fvec3(0.0, -1.0, 0.0), 45.0, 0.0);
}

void Scene::cazaOrbit()
{
	//obtener y normalizar la direccion a la que apunta el morro
	glm::dvec3 direction = glm::normalize(glm::dvec3(myAdvancedTie68->modelMat() * glm::dvec4(0.0, 0.0, 1.0, 0.0)));
	//orbita alrededor de la esfera en la direccion del morro
	nodo68->setModelMat(glm::rotate(nodo68->modelMat(), glm::radians(-3.0), direction) );
	//actualizar foco
	glm::dvec3 tiePos = glm::dvec3(myAdvancedTie68->modelMat() * glm::dvec4(0.0, 0.0, 0.0, 1.0));
	tieSpotLight->setPosDir(glm::fvec3(tiePos));

	//tieSpotLight->setSpot(glm::fvec3(0.0, -1.0, 0.0), 45.0, 0.0);
}
void Scene::setLights() {
	dirLight = new DirLight();
	dirLight->setAmb(glm::fvec4(0.0, 0.0, 0.0, 1.0));
	dirLight->setDiff(glm::fvec4(1.0, 1.0, 1.0, 1.0));
	dirLight->setSpec(glm::fvec4(0.5, 0.5, 0.5, 1.0));
	dirLight->setPosDir(glm::fvec3(1.0,1.0,1.0));

	posLight = new PosLight();
	posLight->setAmb(glm::fvec4(0.0, 0.0, 0.0, 1.0));
	posLight->setDiff(glm::fvec4(1.0, 1.0, 0.0, 1.0));
	posLight->setSpec(glm::fvec4(0.5, 0.5, 0.5, 1.0));
	posLight->setPosDir(glm::fvec3(100.0,1500.0, 0.0));

	spotLight = new SpotLight();
	spotLight->setAmb(glm::fvec4(0.0, 0.0, 0.0, 1.0));
	spotLight->setDiff(glm::fvec4(1.0, 1.0, 1.0, 1.0));
	spotLight->setSpec(glm::fvec4(0.5, 0.5, 0.5, 1.0));
	spotLight->setPosDir(glm::fvec3(100.0, 300.0, 3000.0));

	tieSpotLight = new SpotLight();
	tieSpotLight->setAmb(glm::fvec4(0.0, 0.0, 0.0, 1.0));
	tieSpotLight->setDiff(glm::fvec4(1.0, 1.0, 1.0, 1.0));
	tieSpotLight->setSpec(glm::fvec4(0.5, 0.5, 0.5, 1.0));
	tieSpotLight->setPosDir(glm::fvec3(0.0, 900.0, 0.0)); //posicion inicial foco
}