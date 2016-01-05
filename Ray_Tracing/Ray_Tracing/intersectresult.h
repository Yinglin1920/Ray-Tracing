#include "gvector3.h"  

#ifndef INTERSECTRESULT_H_INCLUDED  
#define INTERSECTRESULT_H_INCLUDED 

struct IntersectResult{
	float distance;
	bool isHit;
	gvector3 position;
	gvector3 normal;
	static inline IntersectResult noHit() { return IntersectResult(); }
};

#endif // INTERSECTRESULT_H_INCLUDED 