#include "array.h"

int main() {
	srand((unsigned)time(0));
	stringMass* mass = new_Mass();
	while (1) {
		printf_s("print: \n");
		string str = recordString();
		insertElem(mass, str);
		printf_s("Element \'%s\' has inserted\n", str);
		printf_s("Array:\t ");
		printArray(mass);
		printf_s("Length: %u\n", stringLength(mass));
		unsigned index = rand() % mass->size;
		printf_s("Element \'%s\' has index %u\n", getElem(mass, index), index);
	}
	return 0;
}







