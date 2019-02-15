#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

#include <string.h>
#include <ctype.h>

#define SIZE_INPUT 20

int lenght_str(char* str) {
	int len;
	for (len = 0; str[len]; len++);
	return len;
}
//Ищет последнее вхождение символа в строке
int last_chr(char* str, char symbol) {
	for (int i = lenght_str(str) - 1; i >= 0; i--)
		if (str[i] == symbol) return i;

	return -1;
}
char* slice(char* str, int start, int end) {
	char* newStr = (char*)malloc((end - start + 1) * sizeof(char));
	for (int i = start; i < end; i++) {
		newStr[i - start] = str[i];
	}
	newStr[end - start] = '\0';
	return newStr;
}

int main() {
	setlocale(LC_ALL, "Russian");

	FILE *file_input = NULL;
	char input_name[SIZE_INPUT];
	
	do {
		printf("Введите имя файла: ");
		gets_s(input_name);
		
		int last_index = last_chr(input_name, '.');
		if (last_index != -1) {
			char* extension = slice(input_name, last_index + 1, lenght_str(input_name));
			if (strcmp("txt", extension)) {
				printf("Неверное (%s) расширение файла (необходимо .txt)! Попробуйте еще раз...\n", extension);
				continue;
			}
		}
		else {
			printf("Отсутствует расширение файла (необходимо .txt)! Попробуйте еще раз...\n");
			continue;
		}

		fopen_s(&file_input, input_name, "r");

		if (!file_input) {
			printf("Файла не существует! Попробуйте еще раз...\n");
		}
	} while (!file_input);

	FILE *file_output;
	char *output_name = strcat(slice(input_name, 0, last_chr(input_name, '.')), ".dat");
	fopen_s(&file_output, output_name, "w");

	while (!feof(file_input)) {
		char ch = (char)fgetc(file_input);
		fprintf_s(file_output, "%c", islower(ch) ? toupper(ch) : tolower(ch));
		printf("%c", ch);
	}

	fclose(file_input);
	fclose(file_output);

	printf("Готово...\n");

	system("pause");
	return 0;
}