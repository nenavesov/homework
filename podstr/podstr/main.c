#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main(int argc, char* argv[]) {
	char* podstring = argv[1];
	char** string = (char**)malloc(sizeof(char*) * (argc - 2));
	for (int i = 0; i < argc - 2; i++) {
		string[i] = argv[i + 2];
	}
	int nomer = 1;
	for (int i = 0; i < argc - 2; i++) {
		int* tmp = findPodstring(string[i], podstring);
		if (tmp == NULL) {
		}
		else {
			int b = countPodstring(string[i], podstring);
			printf("address %d:%p  string:%s      kolvo:%d\n",nomer, tmp, string[i], b);
			nomer = nomer + 1;
		}
	}
	return 0;
}