#include "RGBCube.h"

RGBCube::~RGBCube() {
	delete mMesh;
	mMesh = nullptr;
}
void RGBCube::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);

		//glPolygonMode(GL_BACK, GL_FILL);
		//std::vector<glm::dvec4> myRGBcolors;
		//// X axis color: red  (Alpha = 1 : fully opaque)
		//myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
		//// Y axis color: green
		//myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		//// Z axis color: blue
		//myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
		//mMesh->setColor(myRGBcolors);
		//mMesh->setPrimitive(GL_TRIANGLES);

		//glPolygonMode(GL_FRONT, GL_POINT);
		//glPointSize(10);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glColor4d(0.0, 0.0, 0.0, 0.0);
		mMesh->render();
	}
}