#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct Human {
	char* name;
	int data1;
	int height;
}people;

typedef int(*sortP)(int, int);

int sortName(people* a, people* b) {
	return strlen(a->name) - strlen(b->name);
}

int sortOld(people* a, people* b) {
	return a->data1 - b->data1;
}


int sortHeight(people* a, people* b) {
	return a->height - b->height;
}

void printAr(people** peoples) {
	for (int i = 0; i < N; i++) {
		printf_s("Name: %s\n", peoples[i]->name);
		printf_s("Old: %d\n", peoples[i]->data1);
		printf_s("Height: %d\n\n", peoples[i]->height);
	}
}

people** SortAll(people** a, sortP g) {
	people** tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (g(a[j], a[j - 1]) > 0) {
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main() {
	sortP pole = NULL;
	people** peoples = malloc(sizeof(people*) * N);
	for (int i = 0; i < N; i++) {
		peoples[i] = malloc(sizeof(people));
	}
	peoples[0]->name = "sofi";
	peoples[0]->data1 = 2004;
	peoples[0]->height = 167;

	peoples[1]->name = "artem";
	peoples[1]->data1 = 2004;
	peoples[1]->height = 189;

	peoples[2]->name = "raze";
	peoples[2]->data1 = 1999;
	peoples[2]->height = 172;

	peoples[3]->name = "chyngyk";
	peoples[3]->data1 = 1997;
	peoples[3]->height = 194;

	peoples[4]->name = "Fresh";
	peoples[4]->data1 = 1875;
	peoples[4]->height = 151;

	printAr(peoples);

	printf_s("1) Sort by name\n 2) Sort by data\n 3) Sort by Height\n");
	int a;
	scanf_s("%d", &a);
	switch (a){
	case 1:
		pole = sortName;
		break;
	case 2:
		pole = sortOld;
		break;
	case 3:
		pole = sortHeight;
		break;
	default:
		printf_s("ERROR");
		break;
	}
	SortAll(peoples, pole);
	printAr(peoples);
}