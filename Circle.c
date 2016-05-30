#include "Figure.h"

#ifndef MATH_PI
#define MATH_PI 3.14
#endif

static double *GetRatio(double *radius)
{
	double ratio = 2 * MATH_PI * (*radius);
	
	return &ratio;
}

static double *GetArea(double *radius) {
	double area = MATH_PI * (*radius) * (*radius);	
	
	return &area;
}

const struct figure_vtable_ CIRCLE[] = { { GetRatio, GetArea } };