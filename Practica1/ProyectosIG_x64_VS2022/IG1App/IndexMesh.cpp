#include "IndexMesh.h"
#include <vector>
#include <iostream>

void IndexMesh::render() const {
	 // Comandos OpenGL para enviar datos de arrays a GPU
	if (vVertices.size() > 0) {
		if (vNormals.size() > 0) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_DOUBLE, 0, vNormals.data());
		}
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(
			3, GL_DOUBLE, 0, vVertices.data());

		if (vColors.size() > 0) {
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(
				4, GL_DOUBLE, 0, vColors.data());
		}
		glTexCoordPointer(2, GL_DOUBLE, 0, vTexCoords.data());

		// Nuevos comandos para la tabla de índices
		if (vIndices != nullptr) {
			glEnableClientState(GL_INDEX_ARRAY);
			glIndexPointer(GL_UNSIGNED_INT, 0, vIndices);
		}
		draw();

		glDisableClientState(GL_INDEX_ARRAY);

		if (vNormals.size() > 0) {
			glDisableClientState(GL_NORMAL_ARRAY);
		}
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	
	// Comandos OpenGL para deshabilitar datos enviados
	// Nuevo comando para la tabla de índices :
	if (vIndices != nullptr) {
		glDisableClientState(GL_INDEX_ARRAY);
	}
}
// Comando para renderizar la malla indexada enviada
void IndexMesh::draw() const {
	glDrawElements(mPrimitive, nNumIndices,
		GL_UNSIGNED_INT, vIndices);
}

IndexMesh* IndexMesh::generateIndexedBox(GLdouble l)
{
	IndexMesh* mesh = new IndexMesh();

	mesh->mPrimitive = GL_TRIANGLES;
	//6 caras, 2 triangulos por cara = 12 triangulos * 3 vertices = 36
	mesh->mNumVertices = 8;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const GLdouble m = l / 2;
	mesh->vVertices.emplace_back(-m, m, m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(m, -m, m);
	mesh->vVertices.emplace_back(m, m, -m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(-m, -m, -m);
	
	mesh->nNumIndices = 36;
	mesh->vIndices = new GLuint[mesh->nNumIndices];
	GLuint arr[36] = {
		0, 1, 2, 1, 3, 2,
		2, 3, 4, 3, 5, 4,
		4, 5, 6, 5, 7, 6,
		0, 6, 1, 6, 7, 1,
		0, 2, 4, 4, 6, 0,
		1, 5, 3, 1, 7, 5 };

	for (int i = 0; i < mesh->nNumIndices; i++) {
		mesh->vIndices[i] = arr[i];
	}
	//normales a mano
	mesh->vNormals.reserve(mesh->mNumVertices);
	/*mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, 2, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, -1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(1, 1, 2)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(2, -1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(7, 7, -3)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(3, -7, -7)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-7, 3, -7)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, -1, -1)));*/
	mesh->buildNormalVectors();
	return mesh;
}

void
IndexMesh::buildNormalVectors() {
	
	for (int i = 0; i < mNumVertices; i++) {
		vNormals.emplace_back(0,0,0);
	}
	for (int i = 0; i < nNumIndices; i += 3) {
		glm::dvec3 n(0.0, 0.0, 0.0); //vector normal donde nos dara el resultado de las operaciones entre los vertices
		//obtener los 3 indices que corresponden al triangulo actual
		GLuint ind_a = vIndices[i];
		GLuint ind_b = vIndices[i + 1];
		GLuint ind_c = vIndices[i + 2];
		//vectores entre vertices
		glm::dvec3 v1 = vVertices[ind_b] - vVertices[ind_a];
		glm::dvec3 v2 = vVertices[ind_c] - vVertices[ind_b];
		////producto cruz entre los vectores para asi obtener la normal
		n.x += (v1.y - v2.y) * (v1.z + v2.z);
		n.y += (v1.z - v2.z) * (v1.x + v2.x);
		n.z += (v1.x - v2.x) * (v1.y + v2.y);
		//sumar la normal obtenida a los vertices de la cara actual
		vNormals[ind_a] += n;
		vNormals[ind_b] += n;
		vNormals[ind_c] += n;
	}
	//normalizar todas las normales resultantes
	for (auto& normal : vNormals) {
		normal = glm::normalize(normal);
	}
}
