#include "matrix.h"


int main() {
	setlocale(LC_ALL, "Rus");
	matrixs matrix1;
	matrixs matrix2;
	matrixsF matrix3;
	matrixsF matrix4;
	FILE* matrixA, * matrixB, *matrixC, *matrixD;
	if (fopen_s(&matrixA, "matrix_A.txt", "r") == EOF) {
		printf_s("ERROR");
		_fcloseall();
		exit(1);
	}
	printf_s("ФАЙЛЫ ОТКРЫТЫ:\n");
	//
	printf_s("_____________________________\n");
	char file;
	matrix1.matrix;
	matrix1.Stroka = 1;
	matrix1.Stolbec = 1;
	while (fscanf_s(matrixA, "%c", &file, 1) != EOF) {
		if (file == '\n') {
			matrix1.Stroka++;
		}
		else if (file == ' ' && matrix1.Stroka == 1) {
			matrix1.Stolbec++;
		}
	}

	int** mass1 = alloc2DIntArrayInt(matrix1.Stroka, matrix1.Stolbec);
	fseek(matrixA, 0, SEEK_SET);
	printf_s("первая матрица %dX%d\n", matrix1.Stroka, matrix1.Stolbec);
	for (int i = 0; i < matrix1.Stroka; i++) {
		for (int j = 0; j < matrix1.Stolbec; j++) {
			fscanf_s(matrixA, "%d\t", &mass1[i][j], 1);
		}
	}
	for (int i = 0; i < matrix1.Stroka; i++) {
		for (int j = 0; j < matrix1.Stolbec; j++) {
			printf("%d\t", mass1[i][j]);
		}
		printf_s("    |");
		printf_s("\n");
	}
	matrix1.matrix = mass1;
	printf_s("_____________________________\n");
	//
	if (fopen_s(&matrixB, "matrix_B.txt", "r") == EOF) {
		printf_s("ERROR");
		_fcloseall();
		exit(1);
	}

	char file2;
	matrix2.matrix;
	matrix2.Stroka = 1;
	matrix2.Stolbec = 1;
	while (fscanf_s(matrixB, "%c", &file2, 1) != EOF) {
		if (file2 == '\n') {
			matrix2.Stroka++;
		}
		else if (file2 == ' ' && matrix2.Stroka == 1) {
			matrix2.Stolbec++;
		}
	}

	printf_s("вторая матрица %dX%d\n", matrix2.Stroka, matrix2.Stolbec);
	fseek(matrixB, 0, SEEK_SET);
	int** mass2 = alloc2DIntArrayInt(matrix2.Stroka, matrix2.Stolbec);
	for (int i = 0; i < matrix2.Stroka; i++) {
		for (int j = 0; j < matrix2.Stolbec; j++) {
			fscanf_s(matrixB, "%d\t", &mass2[i][j], 1);
		}
	}
	for (int i = 0; i < matrix2.Stroka; i++) {
		for (int j = 0; j < matrix2.Stolbec; j++) {
			printf("%d\t", mass2[i][j]);
		}
		printf_s("    |");
		printf_s("\n");
	}
	matrix2.matrix = mass2;
	printf_s("_____________________________\n");
	//
	if (fopen_s(&matrixC, "matrix_3.txt", "r") == EOF) {
		printf_s("ERROR");
		_fcloseall();
		exit(1);
	}

	char file3;
	matrix3.matrixF;
	matrix3.StrokaF = 1;
	matrix3.StolbecF = 1;
	while (fscanf_s(matrixC, "%c", &file3) != EOF) {
		if (file3 == '\n') {
			matrix3.StrokaF++;
		}
		else if (file3 == ' ' && matrix3.StrokaF == 1) {
			matrix3.StolbecF++;
		}
	}

	printf_s("\nпервая матрица float %dX%d\n\n", matrix3.StrokaF, matrix3.StolbecF);
	fseek(matrixC, 0, SEEK_SET);
	float** mass3 = alloc2DIntArrayFloat(matrix3.StrokaF, matrix3.StolbecF);
	for (int i = 0; i < matrix3.StrokaF; i++) {
		for (int j = 0; j < matrix3.StolbecF; j++) {
			fscanf_s(matrixC, "%f\t", &mass3[i][j], 1);
		}
	}
	for (int i = 0; i < matrix3.StrokaF; i++) {
		for (int j = 0; j < matrix3.StolbecF; j++) {
			printf("%.1f\t", mass3[i][j]);
		}
		printf_s("    |");
		printf_s("\n");
	}
	matrix3.matrixF = mass3;
	printf_s("_____________________________\n");
	//
	if (fopen_s(&matrixD, "matrix_4.txt", "r") == EOF) {
		printf_s("ERROR");
		_fcloseall();
		exit(1);
	}

	char file4;
	matrix4.matrixF;
	matrix4.StrokaF = 1;
	matrix4.StolbecF = 1;
	while (fscanf_s(matrixD, "%c", &file4, 1) != EOF) {
		if (file4 == '\n') {
			matrix4.StrokaF++;
		}
		else if (file4 == ' ' && matrix4.StrokaF == 1) {
			matrix4.StolbecF++;
		}
	}

	printf_s("вторая матрица float %dX%d\n\n", matrix4.StrokaF, matrix4.StolbecF);
	fseek(matrixD, 0, SEEK_SET);
	float** mass4 = alloc2DIntArrayFloat(matrix4.StrokaF, matrix4.StolbecF);
	for (int i = 0; i < matrix4.StrokaF; i++) {
		for (int j = 0; j < matrix4.StolbecF; j++) {
			fscanf_s(matrixD, "%f\t", &mass4[i][j], 1);
		}
	}
	for (int i = 0; i < matrix4.StrokaF; i++) {
		for (int j = 0; j < matrix4.StolbecF; j++) {
			printf("%.1f\t", mass4[i][j]);
		}
		printf_s("    |");
		printf_s("\n");
	}
	matrix4.matrixF = mass4;
	printf_s("_____________________________________________________\n");
	_fcloseall();

	system("pause");
	system("cls");
	printf_s("МАТРИЦЫ:\n"
		"1) int МАТРИЦЫ\n"
		"2) float МАТРИЦА\n"
		"0) EXIT");
	while (!_kbhit());
	char action = _getch();
	system("cls");
	switch (action) {
	case '1':
		additionMatrixInt(&matrix1, &matrix2);
		system("pause");
		break;
	case '2':
		additionMatrixFloat(&matrix3, &matrix4);
		system("pause");
	case '0':
		printf_s("ДО СВИДАНИЯ");
		return 0;
	default:
		printf_s("ВВЕДИТЕ ЧИСЛО ИЗ СПИСКА");
		break;
	}
	free(mass1);
	free(mass2);
	return 0;
}