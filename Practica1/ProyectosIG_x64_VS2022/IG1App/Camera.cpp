#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <iostream>

using namespace glm;

Camera::Camera(Viewport* vp)
  : mViewMat(1.0)
  , mProjMat(1.0)
  , xRight(vp->width() / 2.0)
  , xLeft(-xRight)
  , yTop(vp->height() / 2.0)
  , yBot(-yTop)
  , mViewPort(vp)
{
	setPM();
}

void Camera::setAxes() {
	mRight = row(mViewMat, 0);
	mUpward = row(mViewMat, 1);
	mFront = - row(mViewMat, 2);
}


void
Camera::uploadVM() const
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(mViewMat)); // transfers view matrix to the GPU
}

void
Camera::setVM()
{
	mViewMat = lookAt(mEye, mLook, mUp); // glm::lookAt defines the view matrix
	setAxes();
}

void
Camera::set2D()
{
	mEye = dvec3(0, 0, 500);
	mLook = dvec3(0, 0, 0);
	mUp = dvec3(0, 1, 0);
	setVM();
}

void
Camera::set3D()
{
	
	mEye = dvec3(500, 500, 500);
	mLook = dvec3(0, 10, 0);
	mUp = dvec3(0, 1, 0);
	setVM();
	
	//APARTADO 49
	/*mEye = dvec3(mLook.x + cos(radians(mAng)) * mRadio, 500, mLook.z - sin(radians(mAng)) * mRadio);
	mLook = dvec3(0, 10, 0);
	mUp = dvec3(0, 1, 0);
	setVM();*/
}

void
Camera::setCenital()
{
	mEye = dvec3(0, 500, 0);
	mLook = dvec3(0, 0, 0);
	mUp = dvec3(1, 0, 0);
	setVM();
}

void
Camera::pitch(GLdouble a)
{
	mViewMat = rotate(mViewMat, glm::radians(a), glm::dvec3(1.0, 0, 0));
	// glm::rotate returns mViewMat * rotationMatrix
	setAxes();
}

void
Camera::yaw(GLdouble a)
{
	mViewMat = rotate(mViewMat, glm::radians(a), glm::dvec3(0, 1.0, 0));
	// glm::rotate returns mViewMat * rotationMatrix
	setAxes();
}

void
Camera::roll(GLdouble a)
{
	mViewMat = rotate(mViewMat, glm::radians(a), glm::dvec3(0, 0, 1.0));
	// glm::rotate returns mViewMat * rotationMatrix
	setAxes();
}

void
Camera::setSize(GLdouble xw, GLdouble yh)
{
	xRight = xw / 2.0;
	xLeft = -xRight;
	yTop = yh / 2.0;
	yBot = -yTop;
	setPM();
}

void
Camera::setScale(GLdouble s)
{
	mScaleFact -= s;
	if (mScaleFact < 0)
		mScaleFact = 0.01;
	setPM();
}

void
Camera::setPM()
{
	if (bOrto) { //  if orthogonal projection
		mProjMat = ortho(xLeft * mScaleFact,
		                 xRight * mScaleFact,
		                 yBot * mScaleFact,
		                 yTop * mScaleFact,
		                 mNearVal,
		                 mFarVal);
		// glm::ortho defines the orthogonal projection matrix
	}
	else {
		mProjMat = frustum(xLeft * mScaleFact,
			xRight * mScaleFact,
			yBot * mScaleFact,
			yTop * mScaleFact,
			mNearVal,
			mFarVal);
	}
}

void
Camera::uploadPM() const
{
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(value_ptr(mProjMat)); // transfers projection matrix to the GPU
	glMatrixMode(GL_MODELVIEW);
}

void Camera::moveUD(GLdouble cs) { // Up / Down
	mEye += mUpward * cs;
	mLook += mUpward * cs;
	setVM();
}
void Camera::moveLR(GLdouble cs) { // Left / Right ...
	mEye += mRight * cs;
	mLook += mRight * cs;
	setVM();
}
void Camera::moveFB(GLdouble cs) { // Forward / Backward ...
	mEye += mFront * cs;
	mLook += mFront * cs;
	setVM();
}

void Camera::changePrj() {
	bOrto = !bOrto;
	setPM();
	uploadPM();
}

void Camera::orbit(GLdouble incAng, GLdouble incY)
{
	mAng += incAng;
	mEye.x = mLook.x + cos(radians(mAng)) * mRadio;
	mEye.z = mLook.z - sin(radians(mAng)) * mRadio;
	mEye.y += incY;
	setVM();
}

void Camera::pitchReal(GLdouble cs) {
	mLook[1] += cs;
	setVM();
}
void Camera::yawReal(GLdouble cs) {
	mLook[0] += cs;
	mLook[2] -= cs;
	setVM();
}
void Camera::rollReal(GLdouble cs) {
	
	glm::dvec3 v = mUp;
	double radianAngle = 0.1 * cs;
	glm::dvec3 axis = normalize(mEye - mLook);

	// Main algorithm
	double cosAngle = cos(radianAngle), sinAngle = sin(radianAngle);
	glm::dvec3 aCROSSv = cross(axis, v);
	glm::dvec3 ret = v;
	ret = ret * cosAngle;
	ret = (sinAngle * aCROSSv) + ret;
	ret = ((dot(axis, v) * (1 - cosAngle)) * axis) + ret;

	mUp = ret;
	setVM();
}