#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main() {
	setlocale(LC_ALL, "Russian");

	float a, b, c, x1, x2, dx;

	printf("Введите значение параметра a: ");
	scanf_s("%f", &a);
	printf("Введите значение параметра b: ");
	scanf_s("%f", &b);
	printf("Введите значение параметра c: ");
	scanf_s("%f", &c);
	
	printf("Введите значение параметра x1: ");
	scanf_s("%f", &x1);
	printf("Введите значение параметра x2: ");
	scanf_s("%f", &x2);

	while (x1 >= x2) {
		printf("Неверное значение границ интервала\n");

		printf("Введите значение параметра x1: ");
		scanf_s("%f", &x1);
		printf("Введите значение параметра x2: ");
		scanf_s("%f", &x2);
	}

	printf("Введите значение шага табуляции dx: ");
	scanf_s("%f", &dx);
	while (dx >= x2 - x1 || dx <= 0) {
		printf("Неверное значение шага табуляции\n");
		printf("Введите значение шага табуляции dx: ");
		scanf_s("%f", &dx);
	}

	printf("_________________________________\n");
	printf("|\tx\t|\tF(x)\t|\n");
	printf("_________________________________\n");

	float F, x = x1;
	int n = 1;
	while (x < x2) {
		if (x + c > 0 && b != 0) {
			F = a * x * x + b * x * (x - 5);
			printf("|\t%f\t|\t%f\t|\n", x, F);
		}
		else if (x + c > 0 && b == 0)
			if (x != c) {
				F = (x - 3 * a) / (x - c);
				printf("|\t%f\t|\t%f\t|\n", x, F);
			} else printf("|\t%f\t|\terror\t|\n", x);
		else {
			if (c != 0) {
				F = a + x / c;
				printf("|\t%f\t|\t%f\t|\n", x, F);
			} else printf("|\t%f\t|\terror\t|\n", x);
		}

		x += dx; n++;
		if (n % 10 == 0 && x < x2) {
			system("pause");
			system("cls");

			printf("_________________________________\n");
			printf("|\tx\t|\tF(x)\t|\n");
			printf("_________________________________\n");
		}
	}

	system("pause");
	return 0;
}
