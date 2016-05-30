#include "Figure.h"
#include <stdlib.h>
#include <string.h>

static double *GetRatio(double params[])
{
	double ratio = 4 * params[0];

	return &ratio;
}

static double *GetArea(double params[]) {
	double area = params[0] * params[0];

	return &area;
}

const struct figure_vtable_ SQUARE[] = { { GetRatio, GetArea } };