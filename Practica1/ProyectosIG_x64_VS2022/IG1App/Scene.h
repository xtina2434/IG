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

protected:
	void free();
	void setGL();
	void resetGL();
	int mId;

	std::vector<Abs_Entity*> gObjects; // Entities (graphic objects) of the scene
};

#endif //_H_Scene_H_
