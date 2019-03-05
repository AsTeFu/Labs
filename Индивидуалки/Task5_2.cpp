//Вариант-11
#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

float** read_matrix(char* input_name, int &size) {
	FILE *file;
	fopen_s(&file, input_name, "r");

	if (!file) {
		printf("Ошибка открытия файла!\n");
		return NULL;
	}

	float** matrix;
	fscanf_s(file, "%i", &size);
	matrix = (float**)malloc(size * sizeof(float*));
	for (int i = 0; i < size; i++) {
		*(matrix + i) = (float*)malloc(size * sizeof(float));

		for (int j = 0; j < size; j++) {
			fscanf_s(file, "%f ", &*(*(matrix + i) + j));
		}
	}

	fclose(file);

	return matrix;
}
void print(float** matrix, int size) {
	printf("Матрица %ix%i:\n", size, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("\t%f", *(*(matrix+i)+j));
		}
		printf("\n");
	}
}
float** calc_B(int size) {
	float** matrix = (float**)malloc(size * sizeof(float*));
	
	for (int i = 0; i < size; i++) {
		*(matrix + i) = (float*)malloc(size * sizeof(float));

		for (int j = 0; j < size; j++) {
			*(*(matrix + i) + j) = (i - j) / (i + j + 1.0);
		}
	}

	return matrix;
}
float** calc_C(float **A, float **B, int size) {
	float** matrix = (float**)malloc(size * sizeof(float*));

	for (int i = 0; i < size; i++) {
		*(matrix + i) = (float*)malloc(size * sizeof(float));

		for (int j = 0; j < size; j++) {
			*(*(matrix + i) + j) = 3 * *(*(A + i) + j) - 4 * *(*(B + i) + j) - 4 * (i == j ? 1.0 : 0.0);
		}
	}

	return matrix;
}
void save_matrix(char* name, float** C, int size) {
	FILE *file;
	fopen_s(&file, name, "w");

	fprintf_s(file, "%i\n", size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fprintf_s(file, "%f ", *(*(C + i) + j));
		}
		fprintf_s(file, "\n");
	}

	fclose(file);
}

int main() {
	setlocale(LC_ALL, "Russian");

	char input_name[20], output_name[20];
	int size;
	float **A, **B, **C;
	printf("Введите имя файла, в котором хранится матрица А: ");
	gets_s(input_name);

	A = read_matrix(input_name, size);
	if (!A) {
		printf("Файл не найден!\n");
		system("pause");
		return 0;
	}
	print(A, size);

	B = calc_B(size);
	print(B, size);

	C = calc_C(A, B, size);
	print(C, size);

	printf("Введите имя файла для записи матрицы С: ");
	gets_s(output_name);
	save_matrix(output_name, C, size);

	for (int i = 0; i < size; i++) {
		free(*(A + i));
		free(*(B + i));
		free(*(C + i));
	}
	free(A);
	free(B);
	free(C);

	system("pause");
	return 0;
}

