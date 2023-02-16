#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define InitialMemory 5;

typedef char* string;

typedef struct stringMass{
	string* row;
	unsigned size;
	unsigned quantity;

}stringMass;

stringMass* nemWass();
int stringLength(stringMass* mass);





