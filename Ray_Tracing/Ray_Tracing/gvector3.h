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
	//���������Ϣ  
	void getInfo();
	//ʸ���ӷ�  
	gvector3 operator+(gvector3 v);
	//ʸ������  
	gvector3 operator-(gvector3 v);
	//����  
	gvector3 operator*(float n);
	//����  
	gvector3 operator/(float n);
	//�������  
	float dotMul(gvector3 v2);
	//�������  
	gvector3 crossMul(gvector3 v2);
	//����ֵ��  
	gvector3 abs();
	//��ȡ�����е����ֵ  
	float max();
	//��ȡ��������Сֵ  
	float min();
	//��ȡʸ������  
	float getLength();
	//������λ��  
	gvector3 normalize();
	//������֮��ľ���  
	float getDist(gvector3 v);
	//����������  
	static inline gvector3 zero(){ return gvector3(0, 0, 0); }
	//��ӡ�����ķ���ֵ  
	void show();
};

#endif // GVECTOR3_H 

