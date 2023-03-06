#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>

typedef struct {
	int** matrix;
	int Stroka;
	int Stolbec;
}matrixs;

typedef struct {
	float** matrixF;
	unsigned StrokaF;
	unsigned StolbecF;
}matrixsF;

int** alloc2DIntArrayInt(int Stroka, int Stolbec);
float** alloc2DIntArrayFloat(unsigned StrokaF, unsigned StolbecF);
int additionMatrixInt(matrixs* matrix1, matrixs* matrix2);
float additionMatrixFloat(matrixsF* matrix3, matrixsF* matrix4);