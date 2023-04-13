#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


int* findPodstring(char* str, char* podstr) {
	int kolvo = 0;
	int check = 0;
	for (int i = 0; i < strlen(str); i++) {
		kolvo = 0;
		for (int j = 0; j < strlen(podstr); j++) {
			if (str[i + j] == podstr[j]) {
				kolvo += 1;
			}
		}
		if (kolvo == strlen(podstr)) {
			int* b = &str[i];
			check = i;
			return b;
		}
	}
	return NULL;
}

int countPodstring(char* cstr, char* cpodstr) {
	int countAll = 0;
	int countTmp = 0;
	for (int i = 0; i < strlen(cstr); i++) {
		countTmp = 0;
		for (int j = 0; j < strlen(cpodstr); j++) {
			if (cstr[i + j] == cpodstr[j]) {
				countTmp += 1;
			}
		}
		if (countTmp == strlen(cpodstr)) {
			countAll += 1;
		}
	}
	return countAll;
}