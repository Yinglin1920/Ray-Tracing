#pragma once

#ifndef GVECTOR3_H  
#define GVECTOR3_H  

#include <iostream>  
#include <cmath>  
#define MIN(x,y) (x)>(y)?(y):(x);  
#define MAX(x,y) (x)>(y)?(x):(y);  

using namespace std;

class gvector3
{
public:
	gvector3();
	~gvector3();

	float x;
	float y;
	float z;

	gvector3(float posX, float posY, float posZ);
	//输出向量信息  
	void getInfo();
	//矢量加法  
	gvector3 operator+(gvector3 v);
	//矢量减法  
	gvector3 operator-(gvector3 v);
	//数乘  
	gvector3 operator*(float n);
	//数除  
	gvector3 operator/(float n);
	//向量点积  
	float dotMul(gvector3 v2);
	//向量叉乘  
	gvector3 crossMul(gvector3 v2);
	//绝对值化  
	gvector3 abs();
	//获取分量中的最大值  
	float max();
	//获取分量的最小值  
	float min();
	//获取矢量长度  
	float getLength();
	//向量单位化  
	gvector3 normalize();
	//求两点之间的距离  
	float getDist(gvector3 v);
	//返回零向量  
	static inline gvector3 zero(){ return gvector3(0, 0, 0); }
	//打印向量的分量值  
	void show();
};

#endif // GVECTOR3_H 

