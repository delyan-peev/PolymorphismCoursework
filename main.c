#include "Figure.h"
#include <stdio.h>
#define AREA 0
#define RATIO 1

int menu();
void inputData(struct figure* circle, struct figure* square, struct figure* triangle);
void writeData(double circleRatio, double circleArea, double squareRatio, double squareArea, double triangleRatio, double triangleArea);


int main() {
	struct figure circle = { CIRCLE };
	struct figure square = { SQUARE };
	struct figure triangle = { TRIANGLE };
	int choice = 0;
	int chosen = 0;
	double circleRatio, circleArea, squareRatio, squareArea, triangleRatio, triangleArea;

	do {
		choice = menu();

		switch (choice) {
			case 0: return 0; break;
			case 1: 
				inputData(&circle, &square, &triangle); chosen = 1;

				circleRatio = *figure_wrapper(&circle, circle.params, RATIO);
				circleArea = *figure_wrapper(&circle, circle.params, AREA);
				squareRatio = *figure_wrapper(&square, square.params, RATIO);
				squareArea = *figure_wrapper(&square, square.params, AREA);
				triangleRatio = *figure_wrapper(&triangle, triangle.params, RATIO);
				triangleArea = *figure_wrapper(&triangle, triangle.params, AREA);
				break;
			case 2: 
				if (chosen) {
					writeData(circleRatio, circleArea, squareRatio, squareArea, triangleRatio, triangleArea);
				}
				else {
					printf("\nPlease, input data first\n");
				} break;
		}
		printf("\n");
	} while (choice != 0);

	return 0;
}

int menu() {
	int validator = 0;
	int choice;

	printf("Please choose one of the following:\n\n1.Start the data input\n2.Write the data to file\n\n0. Exit\n");
	
	while (validator == 0) {
		validator = scanf("%d", &choice);
	}
	
	return choice;
}

void inputData(struct figure* circle, struct figure* square, struct figure* triangle) {
	int validator = 0;

	printf("Please enter radius of circle: ");
	while (validator == 0) {
		validator = scanf("%lf", &(circle->params[0]));
	}

	validator = 0;
	printf("Please enter side of square: ");
	while (validator == 0) {
		validator = scanf("%lf", &(square->params[0]));
	}

	validator = 0;
	printf("Please enter side of triangle: ");
	while (validator == 0) {
		validator = scanf("%lf", &(triangle->params[0]));
	}

	validator = 0;
	printf("Please enter height of triangle: ");
	while (validator == 0) {
		validator = scanf("%lf", &(triangle->params[1]));
	}
}

void writeData(double circleRatio, double circleArea, double squareRatio, double squareArea, double triangleRatio, double triangleArea) {
	FILE *fp;
	char strCircleRatio[] = "Circle Ratio is -> ";
	char strCircleArea[] = "Circle Area is -> ";
	char strSquareRatio[] = "Square Ratio is -> ";
	char strSquareArea[] = "Square Area is -> ";
	char strTriangleRatio[] = "Triangle Ratio is -> ";
	char strTriangleArea[] = "Triangle Area is -> ";
	
	do {
		fp = fopen("C:/FiguresData/data.txt", "w+");
		if (fp == NULL)
			printf("Error opening file. Please try again\n");
	} while (fp == NULL);
	
	fprintf(fp, "%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n%s%.2f\n", strCircleRatio, circleRatio, strCircleArea, circleArea, strSquareRatio, squareRatio, strSquareArea, squareArea, strTriangleRatio, triangleRatio, strTriangleArea, triangleArea);
	fclose(fp);

	printf("The data has been written successfully to the file C:/FiguresData/data.txt\n");
}