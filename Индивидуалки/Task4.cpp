#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <malloc.h>

void Output(int* arr, int len) {
	printf("Массив: ");
	for (int i = 0; i < len; i++)
		printf("%i ", arr[i]);
	printf("\n");
}

int AmountZeroElements(int* arr, int len) {
	int amount = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] == 0) amount++;
	return amount;
}
int max(int* arr, int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > max) max = arr[i];
	return max;
}
//Определить количество элементов массива, превышающих половину от максимального элемента массива
int Task4_1_2(int* arr, int len) {
	int halfMax = max(arr, len) / 2, amount = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] > halfMax) amount++;
	return amount;
}
//Найти сумму элементов, расположенных на четных местах.
int Task4_21_1(int* arr, int len) {
	int sum = 0;
	for (int i = 0; i < len; i += 2)
		sum += arr[i];
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int length;
	printf("Введите длину массива не более 50: ");
	scanf_s("%i", &length);

	if (length > 50 || length < 1) {
		printf("Неверная длина массива\n");
		system("pause");
		return 0;
	}

	int *arr = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		printf("Введите %i элемент массива: ", i + 1);
		scanf_s("%i", &arr[i]);
	}

	Output(arr, length);

	printf("Число нулевых элементов %i \n", AmountZeroElements(arr, length));
	printf("Максимальный элемент %i \n", max(arr, length));
	
	free(arr);
	system("pause");
	return 0;
}
