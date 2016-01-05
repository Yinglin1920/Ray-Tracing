#include "Ray.h"


CRay::CRay()
{
}


CRay::~CRay()
{
}

CRay::CRay(gvector3 o, gvector3 d)
{
	origin = o;
	direction = d;
}

void CRay::setDirection(gvector3 d)
{
	direction = d;
}

void CRay::setOrigin(gvector3 o)
{
	origin = o;
}

gvector3 CRay::getDirection()
{
	return direction;
}

gvector3 CRay::getOrigin()
{
	return origin;
}

gvector3 CRay::getPoint(double t)
{
	return origin + direction*t;
}