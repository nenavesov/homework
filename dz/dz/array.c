#include "array.h"


unsigned stringLength(stringMass* mass) {

	return mass->quantity;
}

stringMass* new_Mass() {

	stringMass* mass = (stringMass*)malloc(sizeof(stringMass));
	if (mass == NULL) {

		return NULL;
	}
	mass->size = 0;
	mass->quantity = Initial_Memory;
	mass->row = (string*)malloc(Initial_Memory * sizeof(string));
	return mass;
}

int insertElem(stringMass* mass, string str) {

	if (mass->size == mass->quantity) {

		string* newArr = copyData(mass);
		copyNewString(mass, str);
		mass->row = newArr;
		mass->quantity++;
	}
	mass->row[mass->size] = str;
	mass->size++;
	return 1;
}

string getElem(stringMass* mass, unsigned index) {

	if (index >= mass->size) {

		return NULL;
	}
	else {

		return mass->row[index];
	}
}

string recordString() {

	string str = (string)malloc(sizeof(char));
	unsigned len = 1;
	char c;
	int flag = 0;
	while ((c = getchar()) != '\n') {

		str[len - 1] = c;
		len++;
		str = (string)realloc(str, len);
	}
	str[len - 1] = '\0';
	return str;
}

void printArray(stringMass* mass) {

	for (int i = 0; i < (mass->size); i++) {
		printf_s("%s ", mass->row[i]);
	}
	printf_s("\n");
}
string* copyData(stringMass* mass) {

	string* newArr = (string*)malloc(sizeof(string) * (mass->size + 1));
	for (int i = 0; i < mass->size; i++){

		newArr[i] = (string)malloc(sizeof(char) * (strlen(mass->row[i]) + 1));
		for (int j = 0; j < strlen(mass->row[i]); j++){

			newArr[i][j] = mass->row[i][j];
		}
		newArr[i][strlen(mass->row[i])] = '\0';
	}
	freePrevDataArr(mass);
	return newArr;
}

void copyNewString(stringMass* mass, string str) {

	unsigned len = strlen(str);
	mass->row[mass->size] = (string)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++){

		mass->row[mass->size][i] = str[i];
	}
	mass->row[mass->size][len] = '\0';
}

void freePrevDataArr(stringMass* mass) {

	for (int i = 0; i < mass->size; i++){

		free(mass->row[i]);
	}
	free(mass->row);
}