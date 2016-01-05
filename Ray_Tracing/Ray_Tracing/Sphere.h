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
	//��ȡ�������һ��ķ���  
	virtual gvector3 getNormal(gvector3 point);
	//�����ж����ߺ͸�����Ľ���  
	virtual IntersectResult isIntersected(CRay RAY);

};

#endif // CSPHERE_H  

