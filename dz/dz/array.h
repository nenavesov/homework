#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#pragma once

#define Initial_Memory 5

typedef char* string;

typedef struct stringMass{

	string* row;
	unsigned size;
	unsigned quantity;
}stringMass;

stringMass* new_Mass();
string* copyData(stringMass* mass);
string getElem(stringMass* mass, unsigned index);
string recordString();

unsigned stringLength(stringMass* mass);
int insertElem(stringMass* mass, string str);

void printArray(stringMass* mass);
void copyNewString(stringMass* mass, string str);
void freePrevDataArr(stringMass* mass);





