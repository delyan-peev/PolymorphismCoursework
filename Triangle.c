#include "Figure.h"

static double *GetRatio(double params[])
{
	//assume its an equal sided triangle
	double ratio = 3 * params[0];

	return &ratio;
}

static double *GetArea(double params[]) {
	//side and height
	double area = params[0] * params[1] / 2;

	return &area;
}

const struct figure_vtable_ TRIANGLE[] = { { GetRatio, GetArea } };