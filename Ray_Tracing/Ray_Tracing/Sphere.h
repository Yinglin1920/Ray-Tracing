#pragma once

#ifndef CSPHERE_H  
#define CSPHERE_H  

#include "gvector3.h"
#include "Ray.h"
#include "intersectresult.h"

class CSphere
{
private:
	gvector3 center;
	double radius;

public:
	CSphere();
	virtual ~CSphere();

	CSphere(gvector3 center, double radius);
	CSphere(CSphere& s);
	void setCenter(gvector3& c);
	void setRadius(double r);
	gvector3 getCenter();
	double getRadius();
	//获取物体表面一点的法线  
	virtual gvector3 getNormal(gvector3 point);
	//用于判断射线和该物体的交点  
	virtual IntersectResult isIntersected(CRay RAY);

};

#endif // CSPHERE_H  

