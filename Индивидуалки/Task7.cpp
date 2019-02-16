#include "pch.h"
#include <stdio.h>
#include <locale.h>
#include <cstdlib>

#include <string.h>
//Глаза бы мои не видели этот код

struct Student {
	char* firstName;
	char* secondName;
	int value;
};

typedef struct List {
	Student student;
	struct List *next;
} List;

void add(List **list, Student &student) {
	List *newItem = (List*)malloc(sizeof(List));
	newItem->student.firstName = student.firstName;
	newItem->student.secondName = student.secondName;
	newItem->student.value = student.value;
	newItem->next = *list;
	*list = newItem;
}

Student* read_student(char* str) {
	char items[3][30];
	int current_item = 0, current_letter = 0;

	Student *student = (Student*)malloc(sizeof(Student));

	for (int i = 0; ; i++) {
		if (str[i] == ' ' || str[i] == '\n') {
			items[current_item++][current_letter] = '\0';
			current_letter = 0;
			if (str[i] == '\n') break;
		}
		else items[current_item][current_letter++] = str[i];
	}

	student->firstName = (char*)malloc(30 * sizeof(char));
	student->secondName = (char*)malloc(30 * sizeof(char));
	strcpy(student->firstName, items[1]);
	strcpy(student->secondName, items[0]);
	student->value = atoi(items[2]);

	return student;
}

int main() {
	setlocale(LC_ALL, "Russian");

	FILE *data;
	char input_name[20];
	List *list = NULL;

	printf("Введите название файла: ");
	gets_s(input_name);

	fopen_s(&data, input_name, "r");
		
	if (!data) {
		printf("GG\n");
		system("pause");
		return 0;
	}

	int amount_students = 0;
	while (!feof(data)) {
		char line[100];
		Student *student;
		if (fgets(line, 100, data) != NULL) {
			student = read_student(line);
			
			add(&list, *student);
			amount_students++;

		}
	}

	FILE *output;
	char output_name[20], min[3];


	printf("Введите название файла: ");
	gets_s(output_name);

	fopen_s(&output, output_name, "w");

	printf("Введите порог: ");
	gets_s(min);

	int limit = atoi(min);
	List *node = list;
	do {
		if (node->student.value > limit) {
			printf("%s %s %i\n", node->student.secondName, node->student.firstName, node->student.value);
			fprintf_s(output, "%s %s %i\n", node->student.secondName, node->student.firstName, node->student.value);
		}
		node = node->next;
	} while (node != NULL);

	system("pause");
	return 0;
}