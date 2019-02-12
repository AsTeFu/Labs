#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	printf("Введите целое число в интервале от 1 до 20: ");
	scanf_s("%i", &n);

	if ((n < 1) || (n > 20)) {
		printf("Введено	неверное число\n");
		system("pause");
		return 0;
	}

	int c = 0;
	for (int i = 0; i <= n; i++)
		if (i * i % 5 < i % 4)	c++;

	printf("Количество чисел в интервале от 0 до %i, квадрат которых при делении на 5 дает остаток больше, чем остаток от деления самого числа на 4 равно %i \n", n, c);
	
	system("pause");
	return 0;
}
