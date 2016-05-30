#ifndef FIGURE_H_
#define FIGURE_H_
#define MAX_PARAMS 2
#include <stdio.h>

struct figure
{
	const struct figure_vtable_ *vtable_;
	double params[MAX_PARAMS];
};

struct figure_vtable_
{
	double *(*GetRatio)(double*);
	double *(*GetArea)(double*);
};

// wrapper function
static double *figure_wrapper(struct figure *figure, double params[], int choice)
{
	if (choice) {
		figure->vtable_->GetRatio(params);
	} else figure->vtable_->GetArea(params);
};



// make the vtables arrays so they can be used as pointers
extern const struct figure_vtable_ CIRCLE[], SQUARE[], TRIANGLE[];

#endif