#include "tree.h"


int main(void) {
	Node* root = NULL;
	root = creat(root, 5);
	root = addYzel(root, 3);
	root = addYzel(root, 8);
	root = addYzel(root, 2);
	root = addYzel(root, 19);
	root = addYzel(root, 9);
	root = search(root, 1);
	printTree(root);

	return 0;
}