#include "perspectiveCamera.h"


perspectiveCamera::perspectiveCamera()
{
}


perspectiveCamera::~perspectiveCamera()
{
}

perspectiveCamera::perspectiveCamera(const gvector3& _eye, const gvector3& _front, const gvector3& _refUp, float _fov)
{
	eye = _eye;
	front = _front;
	refUp = _refUp;
	fov = _fov;
	right = front.crossMul(refUp);
	up = right.crossMul(front);
	fovScale = tan(fov* (PI  * 0.5f / 180)) * 2;
}

CRay perspectiveCamera::generateRay(float x, float y)
{
	gvector3 r = right*((x - 0.5f) * fovScale);
	gvector3 u = up*((y - 0.5f) * fovScale);
	gvector3 tmp = front + r + u;
	tmp.normalize();
	return CRay(eye, tmp);
}