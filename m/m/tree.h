#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define rootcreat 0

typedef struct tree {
	int key;
	struct tree* right;
	struct tree* left;
	struct tree* parent;
} Node;

Node* creat(Node* root, int key) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->key = key;
	tmp->parent = NULL;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

Node* addYzel(Node* root, int key) {
	Node* root2 = root;
	Node* root3 = NULL;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->key = key;
	while (root2 != NULL) {
		root3 = root2;
		if (key < root2->key) {
			root2 = root2->left;
		}
		else {
			root2 = root2->right;
		}
	}
	tmp->parent = root3;
	tmp->left = NULL;
	tmp->right = NULL;
	if (key < root3->key) {
		root3->left = tmp;
	}
	else {
		root3->right = tmp;
	}
	return root;
}

Node* search(Node* root, int key) {
	if ((root == NULL) || (root->key == key)) {
		return root;
	}
	if (key < root->key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}

void printTree(Node* root) {
	if (root == NULL) {
		return;
	}
	printTree(root->left);
	printf_s("%d ", root->key);
	printTree(root->right);
}

