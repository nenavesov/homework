#include "matrix.h"

int** alloc2DIntArrayInt(int Stroka, int Stolbec) {
	int** matrix = (int**)malloc(Stroka * sizeof(int*));
	if (!matrix) {
		exit(1);
	}
	for (int i = 0; i < Stroka; i++) {
		matrix[i] = (int*)malloc(Stolbec * sizeof(int));
	}
	return matrix;

}

float** alloc2DIntArrayFloat(unsigned StrokaF, unsigned StolbecF) {
	float** matrix = (float**)malloc(StrokaF * sizeof(float*));
	if (!matrix) {
		exit(1);
	}
	for (int i = 0; i < StrokaF; i++) {
		matrix[i] = (float*)malloc(StolbecF * sizeof(float));
	}
	return matrix;

}

int additionMatrixInt(matrixs* matrix1, matrixs* matrix2) {
	printf_s("СУММА МАТРИЦ<3\n");
	if ((matrix1->Stroka == matrix2->Stroka) && (matrix1->Stolbec == matrix2->Stolbec)) {
		int** sum = alloc2DIntArrayInt(matrix1->Stroka, matrix2->Stolbec);
		for (int i = 0; i < matrix1->Stroka; i++) {
			for (int j = 0; j < matrix2->Stolbec; j++) {
				sum[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
				printf_s("%d\t", sum[i][j]);
			}
			printf_s("\n");
		}
	}
	else if ((matrix1->Stroka == '\0') && (matrix1->Stolbec == '\0') || (matrix2->Stroka == '\0') && (matrix2->Stolbec == '\0')) {
		printf_s("ПУСТОЙ ФАЙЛ\n");
		return 0;
	}
	else {
		printf_s("матрица разного размера\n");
		exit(1);
	}
	return 0;
}

float additionMatrixFloat(matrixsF* matrix3, matrixsF* matrix4) {
	printf_s("СУММА МАТРИЦ<3\n");
	if ((matrix3->StrokaF == matrix4->StrokaF) && (matrix3->StolbecF == matrix4->StolbecF)) {
		float** sum = alloc2DIntArrayFloat(matrix3->StrokaF, matrix4->StolbecF);
		for (int i = 0; i < matrix3->StrokaF; i++) {
			for (int j = 0; j < matrix4->StolbecF; j++) {
				sum[i][j] = matrix3->matrixF[i][j] + matrix4->matrixF[i][j];
				printf_s("%.1f\t", sum[i][j]);
			}
			printf_s("\n");
		}
	}
	else if ((matrix3->StrokaF == '\0') && (matrix3->StolbecF == '\0') || (matrix4->StrokaF == '\0') && (matrix4->StolbecF == '\0')) {
		printf_s("ПУСТОЙ ФАЙЛ\n");
		return 0;
	}
	else {
		printf_s("матрица разного размера\n");
		exit(1);
	}
	return 0;
}