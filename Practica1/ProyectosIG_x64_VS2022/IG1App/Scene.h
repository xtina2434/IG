#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Entity.h"
#include "RegularPolygon.h"
#include <vector>
#include "RGBTriangle.h"
#include "RGBRectangle.h"
#include "Cube.h"
#include "RGBCube.h"
#include "Texture.h"
#include "Ground.h"
#include "BoxOutline.h"
#include "Star3D.h"
#include "GlassParapet.h"
#include "Photo.h"
#include "Sphere.h"
#include "Disk.h"
#include "Cylinder.h"
#include "PartialDisk.h"
#include "AdvancedTIE.h"
#include "WingAdvancedTIE.h"
#include "IndexedBox.h"
#include "SphereR.h"

class Scene
{
public:
	Scene() = default;
	~Scene()
	{
		free();
		resetGL();
	};

	Scene(const Scene& s) = delete;            // no copy constructor
	Scene& operator=(const Scene& s) = delete; // no copy assignment

	void init();

	void render(Camera const& cam) const;
	void update();

	void setScene(int id);
	void sceneDirLight(Camera const& cam) const;

	void cazaRotate();
	void cazaOrbit();

protected:
	void free();
	void setGL();
	void resetGL();
	void load(); //para crear y cargar las texturas de los objetos de la	escena
	int mId;

	std::vector<Abs_Entity*> gObjects; // Entities (graphic objects) of the scene
	std::vector<Texture*> gTextures; //texturas

	AdvancedTIE* myAdvancedTie68;
	CompoundEntity* nodo68;
};

#endif //_H_Scene_H_
