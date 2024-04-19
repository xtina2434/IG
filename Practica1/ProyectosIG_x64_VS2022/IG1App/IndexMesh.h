#include "Mesh.h"

class IndexMesh : public Mesh {
protected:
	static GLuint* vIndices = nullptr; // tabla de índices
	static GLuint nNumIndices = 0;
	
public:
	IndexMesh() { mPrimitive = GL_TRIANGLES; }
	~IndexMesh() { delete[] vIndices; }
	virtual void render() const override;
	virtual void draw() const;

	static IndexMesh* generateIndexedBox(GLdouble l);
	static glm::dvec3 calculoVectorNormalPorNewell(glm::dvec3 a, glm::dvec3 b, glm::dvec3 c);
};