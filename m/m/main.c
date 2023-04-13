#include "tree.h"


int main(void) {
	Node* root = NULL;
	root = creat(root, 5);
	root = addYzel(root, 7);
	root = addYzel(root, 8);
	root = addYzel(root, 2);
	root = addYzel(root, 9);
	root = search(root, 5);
	printTree(root);

	return 0;
}