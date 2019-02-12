#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	printf("Введите целое число в интервале от 3 до 50: ");
	scanf_s("%i", &n);

	if ((n < 3) || (n > 50)) {
		printf("Введено	неверное число\n");
		system("pause");
		return 0;
	}

	float a1, a2, ai;
	printf("Введите первый и второй элементы последовательности a1 a2: ");
	scanf_s("%f %f", &a1, &a2);

	float sum = a1 + a2;
	for (int i = 3; i <= n; i++) {
		ai = 2 + a2 + i + a1;
		ai = ai * ai + i * 0.5;

		sum += ai;

		a1 = a2;
		a2 = ai;
	}

	printf("Сумма первых %i членов последовательности равна %f \n", n, sum);

	system("pause");
	return 0;
}
