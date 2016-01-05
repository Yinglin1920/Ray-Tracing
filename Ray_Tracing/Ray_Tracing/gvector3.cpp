#include "gvector3.h"


gvector3::gvector3()
{
}


gvector3::~gvector3()
{
}

gvector3::gvector3(float posX, float posY, float posZ)
{
	x = posX;
	y = posY;
	z = posZ;
}

gvector3 gvector3::operator+(gvector3 v)
{
	return gvector3(x + v.x, v.y + y, v.z + z);
}

gvector3 gvector3::operator-(gvector3 v)
{
	return gvector3(x - v.x, y - v.y, z - v.z);
}

gvector3 gvector3::operator*(float n)
{
	return gvector3(x*n, y*n, z*n);
}

gvector3 gvector3::operator/(float n)
{
	return gvector3(x / n, y / n, z / n);
}

void gvector3::getInfo()
{
	cout << "x:" << x << " y:" << y << " z:" << z << endl;
}

gvector3 gvector3::abs()
{
	if (x<0) x *= -1;
	if (y<0) y *= -1;
	if (z<0) z *= -1;
	return gvector3(x, y, z);
}

float gvector3::dotMul(gvector3 v2)
{
	return (x*v2.x + y*v2.y + z*v2.z);
}

gvector3 gvector3::crossMul(gvector3 v2)
{
	gvector3 vNormal;
	// ¼ÆËã´¹Ö±Ê¸Á¿  
	vNormal.x = ((y * v2.z) - (z * v2.y));
	vNormal.y = ((z * v2.x) - (x * v2.z));
	vNormal.z = ((x * v2.y) - (y * v2.x));
	return vNormal;
}

float gvector3::getLength()
{
	return  (float)sqrt(x*x + y*y + z*z);
}

gvector3 gvector3::normalize()
{
	float length = getLength();
	x = x / length;
	y = y / length;
	z = z / length;
	return gvector3(x, y, z);
}

void gvector3::show()
{
	cout << "x:" << x << "  y:" << y << "  z" << z << endl;
}

float gvector3::max()
{
	float tmp = MAX(y, z);
	return MAX(x, tmp);
}
float gvector3::min()
{
	float tmp = MIN(y, z);
	return MIN(x, tmp);
}

float gvector3::getDist(gvector3 v)
{
	float tmp = (x - v.x)*(x - v.x) + (y - v.y)*(y - v.y) + (z - v.z)*(z - v.z);
	return sqrt(tmp);
}