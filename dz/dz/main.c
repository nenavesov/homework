#include "array.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	stringMass* mass = newMass();
	while (1) {
		printf_s("������� ������: ");
	}
}

int LstringLength(stringMass* mass) {
	printf_s("����� ���������: %d", mass->size);
}

stringMass* newMass(){
	stringMass* mass = (stringMass*)malloc(sizeof(stringMass));
	mass->size = 0;
	mass->quantity = InitialMemory;
	mass->row = (string*)malloc(InitialMemory * sizeof(string));
	return mass;
}









