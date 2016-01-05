#pragma once

#include "Ray.h"

class perspectiveCamera
{
public:
	perspectiveCamera();
	~perspectiveCamera();

	perspectiveCamera(const gvector3& _eye, const gvector3& _front, const gvector3& _refUp, float _fov);
	CRay generateRay(float x, float y);

private:
	gvector3 eye;
	gvector3 front;
	gvector3 refUp;
	float   fov;
	gvector3 right;
	gvector3 up;
	float   fovScale;
};

