#include "RGBRectangle.h"
#include "RGBTriangle.h"

RGBRectangle::~RGBRectangle() {
	delete mMesh;
	mMesh = nullptr;
}
void RGBRectangle::render(glm::dmat4 const& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::dmat4 aMat = modelViewMat * mModelMat;
		upload(aMat);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//std::vector<glm::dvec4> myRGBcolors;
		//// X axis color: red  (Alpha = 1 : fully opaque)
		//myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
		//// Y axis color: green
		//myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		//// Z axis color: blue
		//myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
		//mMesh->setColor(myRGBcolors);
		//mMesh->setPrimitive(GL_TRIANGLES);
		//mMesh->render();

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		std::vector<glm::dvec4> myRGBcolors;
		// X axis color: red  (Alpha = 1 : fully opaque)
		myRGBcolors.emplace_back(1.0, 0.0, 0.0, 1.0);
		// Y axis color: green
		myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		myRGBcolors.emplace_back(0.0, 1.0, 0.0, 1.0);
		// Z axis color: blue
		myRGBcolors.emplace_back(0.0, 0.0, 1.0, 1.0);
		mMesh->setColor(myRGBcolors);
		//mMesh->setPrimitive(GL_TRIANGLES);

		//glPolygonMode(GL_BACK, GL_LINE);
		//glPointSize(10);
		mMesh->render();
	}
}