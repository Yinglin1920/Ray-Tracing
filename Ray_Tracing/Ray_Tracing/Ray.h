#pragma once

#ifndef CRAY_H  
#define CRAY_H  

#include <iostream>  
#include "gvector3.h"  
#define PI 3.14159  
using namespace std;

class CRay
{
private:
	gvector3 origin;
	gvector3 direction;

public:
	CRay();
	~CRay();

	CRay(gvector3 o, gvector3 d);
	void setOrigin(gvector3 o);
	void setDirection(gvector3 d);

	gvector3 getOrigin();
	gvector3 getDirection();
	//ͨ�������ߵĲ������̴������t������������ϵĵ�  
	gvector3 getPoint(double t);
};
#endif  
