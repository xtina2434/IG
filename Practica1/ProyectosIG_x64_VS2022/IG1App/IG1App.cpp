#include "IG1App.h"
#include "CheckML.h"
#include <iostream>

using namespace std;

// static single instance (singleton pattern)

IG1App IG1App::s_ig1app; // default constructor (constructor with no parameters)

void
IG1App::close()
{
	if (!mStop) { // if main loop has not stopped
		cout << "Closing glut...\n";
		glutLeaveMainLoop(); // stops main loop and destroy the OpenGL context
		mStop = true;        // main loop stopped
	}
	free();
}

void
IG1App::run() // enters the main event processing loop
{
	if (mWinId == 0) {      // if not initialized
		init();         // initialize the application
		glutMainLoop(); // enters the main event processing loop
		mStop = true;   // main loop has stopped
	}
}

void
IG1App::init()
{
	// create an OpenGL Context
	iniWinOpenGL();

	// create the scene after creating the context
	// allocate memory and resources
	mViewPort =
	  new Viewport(mWinW, mWinH); // glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)
	mCamera = new Camera(mViewPort);

	for (int i = 0; i < numScenes; i++) {
		mScenes[i] = new Scene();
		mScenes[i]->setScene(i);
		mScenes[i]->init();
	
	}
	//por defecto empezamos en la bidimensional
	mCamera->set2D();
}

void
IG1App::iniWinOpenGL()
{ // Initialization
	cout << "Starting glut...\n";
	int argc = 0;
	glutInit(&argc, nullptr);

	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); // GLUT_CORE_PROFILE
	glutInitContextFlags(GLUT_DEBUG);                   // GLUT_FORWARD_COMPATIBLE

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitWindowSize(mWinW, mWinH); // window size
	// glutInitWindowPosition (140, 140);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE |
	                    GLUT_DEPTH /*| GLUT_STENCIL*/); // RGBA colors, double buffer, depth
	                                                    // buffer and stencil buffer

	mWinId = glutCreateWindow(
	  "IG1App"); // with its associated OpenGL context, return window's identifier

	// Callback registration
	glutReshapeFunc(s_resize);
	glutKeyboardFunc(s_key);
	glutSpecialFunc(s_specialKey);
	glutDisplayFunc(s_display);

	cout << glGetString(GL_VERSION) << '\n';
	cout << glGetString(GL_VENDOR) << '\n';
}

void
IG1App::free()
{ // release memory and resources
	for (int i = 0; i < 2; ++i) {
		delete mScenes[i];
	}
	//mScene = nullptr;
	delete mCamera;
	mCamera = nullptr;
	delete mViewPort;
	mViewPort = nullptr;
}

void
IG1App::display() const
{ // double buffering

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the back buffer

	mScenes[sceneId]->render(*mCamera); // uploads the viewport and camera to the GPU

	glutSwapBuffers(); // swaps the front and back buffer
}

void IG1App::display2V() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the back buffer

	cout << "Display2V" << endl;
	// para renderizar las vistas utilizamos una c�mara auxiliar :
	Camera auxCam = *mCamera; // copiando mCamera
	// el puerto de vista queda compartido (se copia el puntero )
	Viewport auxVP = *mViewPort; // lo copiamos en una var. aux . para *
	// el tama�o de los 4 puertos de vista es el mismo , lo configuramos
	mViewPort->setSize(mWinW / 2, mWinH);
	// igual que en resize , para que no cambie la escala ,
	// tenemos que cambiar el tama�o de la ventana de vista de la c�mara
	auxCam.setSize(mViewPort->width(), mViewPort-> height());

	mViewPort->setPos(0, 0);
	auxCam.set3D();
	mScenes[sceneId]->render(auxCam); // uploads the viewport and camera to the GPU

	mViewPort->setPos(mWinW / 2, mWinH);
	auxCam.set2D();
	mScenes[sceneId]->render(auxCam); // uploads the viewport and camera to the GPU

	//*mViewPort = auxVP; // * restaurar el puerto de vista ( NOTA )
	glutSwapBuffers(); // swaps the front and back buffer
}

void
IG1App::resize(int newWidth, int newHeight)
{
	mWinW = newWidth;
	mWinH = newHeight;

	// Resize Viewport to the new window size
	mViewPort->setSize(newWidth, newHeight);

	// Resize Scene Visible Area such that the scale is not modified
	mCamera->setSize(mViewPort->width(), mViewPort->height());
}
void 
IG1App::update() {
	mScenes[sceneId]->update();
	glutPostRedisplay();
}
void
IG1App::key(unsigned char key, int x, int y)
{
	bool need_redisplay = true;

	switch (key) {
		case 27:                     // Escape key
			glutLeaveMainLoop(); // stops main loop and destroy the OpenGL context
			break;
		case '+':
			mCamera->setScale(+0.01); // zoom in  (increases the scale)
			break;
		case '-':
			mCamera->setScale(-0.01); // zoom out (decreases the scale)
			break;
		case 'l':
			mCamera->set3D();
			break;
		case 'o':
			mCamera->set2D();
			break;
		case 'c':
			mCamera->setCenital();
			break;
		case 'i':
			mCamera->orbit(1, 1);
			break;
		case 'k':
			display2V();
			break;
		case '0':
			sceneId = 0;
			mCamera->set2D();
			break;
		case '1':
			sceneId = 1;
			mCamera->set3D();
			break;
		case 'u':
			mScenes[sceneId]->update();
			break;
		case 'U':
			glutIdleFunc(mUpdateFlag ? nullptr : s_update);
			mUpdateFlag = !mUpdateFlag; //se activa la bandera para llamar al update
			break;
		case 'p':
			mCamera->changePrj();
			break;
		default:
			need_redisplay = false;
			break;
	} // switch

	if (need_redisplay)
		glutPostRedisplay(); // marks the window as needing to be redisplayed -> calls to
		                     // display()
}

void
IG1App::specialKey(int key, int x, int y)
{
	bool need_redisplay = true;
	int mdf = glutGetModifiers(); // returns the modifiers (Shift, Ctrl, Alt)

	switch (key) {
		case GLUT_KEY_RIGHT:
			if (mdf == GLUT_ACTIVE_CTRL)
				//mCamera->pitch(-1); // rotates -1 on the X axis
				//mCamera->moveLR(-1);
				mCamera->pitchReal(-1);
			else
				//mCamera->pitch(1); // rotates 1 on the X axis
				//mCamera->moveLR(1);
				mCamera->pitchReal(1);
			break;
		case GLUT_KEY_LEFT:
			if (mdf == GLUT_ACTIVE_CTRL)
				//mCamera->yaw(1); // rotates 1 on the Y axis
				//mCamera->moveUD(1);
				mCamera->yawReal(1);
			else
				//mCamera->yaw(-1); // rotate -1 on the Y axis
				//mCamera->moveUD(-1);
				mCamera->yawReal(-1);
			break;
		case GLUT_KEY_UP:
			//mCamera->roll(1); // rotates 1 on the Z axis
			//mCamera->moveFB(1);
			mCamera->rollReal(1);
			break;
		case GLUT_KEY_DOWN:
			//mCamera->roll(-1); // rotates -1 on the Z axis
			//mCamera->moveFB(-1);
			mCamera->rollReal(-1);
			break;
		default:
			need_redisplay = false;
			break;
	} // switch

	if (need_redisplay)
		glutPostRedisplay(); // marks the window as needing to be redisplayed -> calls to
		                     // display()
}
