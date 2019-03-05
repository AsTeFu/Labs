#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

#define SIZE_INPUT 20

int lenght_str(char* str) {
	int len;
	for (len = 0; str[len]; len++);
	return len;
}
int Is_txt(char* name) {
	int len_name = lenght_str(name);

	if (len_name < 4)
		return 0;

	if (name[len_name - 1] == 't' &&
		name[len_name - 2] == 'x' &&
		name[len_name - 3] == 't' &&
		name[len_name - 4] == '.') return 0;
	else return 1;
}
int isAllowed(char ch) {
	char allowed[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

	for (int i = 0; i < 10; i++)
		if (ch == allowed[i]) return 1;
	return 0;
}

void  SaveNewFile(char* name, FILE *file_input) {
	FILE *file_output;

	fopen_s(&file_output, name, "w");

	char num1, num2;
	while (!feof(file_input)) {
		num1 = (char)fgetc(file_input);

		if (num1 == -1)
			break;

		if (!isAllowed(num1)) {
			printf("%c", num1);
			fprintf_s(file_output, "%c", num1);
			continue;
		}


		if (!feof(file_input)) {
			num2 = (char)fgetc(file_input);

			if (isAllowed(num2)) {
				printf("%c+%c", num1, num2);
				fprintf_s(file_output, "%c+%c", num1, num2);
			}
			else {
				printf("%c%c", num1, num2);
				fprintf_s(file_output, "%c%c", num1, num2);
			}
		}
	}

	fclose(file_output);
}

int main() {
	setlocale(LC_ALL, "Russian");

	FILE *file_input = NULL;
	char input_name[SIZE_INPUT];

	do {
		printf("Введите имя файла: ");
		gets_s(input_name);

		if (Is_txt(input_name)) {
			printf("Неверное расширение файла (необходимо .txt)! Попробуйте еще раз...\n");
			continue;
		}

		fopen_s(&file_input, input_name, "r");

		if (!file_input) {
			printf("Файла не существует! Попробуйте еще раз...\n");
		}
	} while (!file_input);

	int len = lenght_str(input_name);
	input_name[len - 1] = 't';
	input_name[len - 2] = 'a';
	input_name[len - 3] = 'd';

	SaveNewFile(input_name, file_input);

	fclose(file_input);

	printf("\nГотово...\n");

	system("pause");
	return 0;
}

