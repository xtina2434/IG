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
	/*mesh->vVertices.emplace_back(-m, -m, -m);
	mesh->vVertices.emplace_back(m, -m, -m);
	mesh->vVertices.emplace_back(m, m, -m);
	mesh->vVertices.emplace_back(-m, m, -m);
	mesh->vVertices.emplace_back(-m, -m, m);
	mesh->vVertices.emplace_back(m, -m, m);
	mesh->vVertices.emplace_back(m, m, m);
	mesh->vVertices.emplace_back(-m, m, m);*/
	
	mesh->vNormals.reserve(mesh->mNumVertices);
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(1, 1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(1, 1, -1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(1, -1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(1, -1, -1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, 1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, 1, -1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, -1, 1)));
	mesh->vNormals.emplace_back(glm::normalize(glm::dvec3(-1, -1, -1)));

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


	
	//mesh->vNormals.reserve(mesh->mNumVertices);
	//for (int i = 0; i < mesh->nNumIndices; i + 3) {
	//	std::cout << "i: " << i << std::endl;
	//	glm::dvec3 n(0, 0, 0);
	//	//n = glm::normalize(glm::cross((mesh->vVertices[mesh->vIndices[i + 2]] - mesh->vVertices[mesh->vIndices[i + 1]]), (mesh->vVertices[mesh->vIndices[i]] - mesh->vVertices[mesh->vIndices[i + 1]])));
	//	n = calculoVectorNormalPorNewell(mesh->vVertices[mesh->vIndices[i]], mesh->vVertices[mesh->vIndices[i + 1]], mesh->vVertices[mesh->vIndices[i + 2]]);
	//	mesh->vNormals[mesh->vIndices[i]] += n;
	//	mesh->vNormals[mesh->vIndices[i+1]] += n;
	//	mesh->vNormals[mesh->vIndices[i+2]] += n;
	//}
	
	return mesh;
}


//glm::dvec3 IndexMesh::calculoVectorNormalPorNewell(glm::dvec3 a, glm::dvec3 b, glm::dvec3 c) {
//	//glm::dvec3 n(0, 0, 0);
//
//	//std::vector< glm::dvec3> cara = { a, b, c };
//	//
//	//for (int i = 0; i < 3; ++i) {
//	//	glm::dvec3 vertActual = cara[i];
//	//	glm::dvec3 vertSiguiente = cara[(i + 1) % 3];
//	//	n.x += (vertActual.y - vertSiguiente.y) * (vertActual.z + vertSiguiente.z);
//	//	n.y += (vertActual.z - vertSiguiente.z) * (vertActual.x + vertSiguiente.x);
//	//	n.z += (vertActual.x - vertSiguiente.x) * (vertActual.y + vertSiguiente.y);
//	//}
//	//return glm::normalize(n);
//}
