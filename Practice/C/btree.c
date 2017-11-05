#include <stdio.h>
#include <stdlib.h>


typedef struct node_t { 

	int val;
	struct node_t * left;
	struct node_t * right;

} node_t;

node_t * root;
	 
struct node_t * createNode(int data) {

	node_t * newNode;

	newNode = malloc(sizeof(node_t));

	newNode->val = data;

	newNode->left = NULL;

	newNode->right = NULL;

	return newNode;

}

void insertNode(int data) {

	node_t * newNode = createNode(data);

	node_t * current = root;

	node_t * parent = NULL;

	while(1) {

		parent = current;

		if(data > parent->val) {

			current = current->right;

			printf("%p\n", current);

			if(current == NULL) {

				parent->right = newNode;

				return;
			}
		}

		else {

			current = current->left;

			printf("%p\n", current);

			if(current == NULL) {

				parent->left = newNode;

				return;
			}

		}

	}

}

void printTree(node_t * root) {

	if(root == NULL) 
		return;

	printTree(root->left);

	printf("%d\n" , root->val);

	printTree(root->right);
}


int main() {

	root = createNode(24);

	root->right = createNode(33);

	root->left = createNode(11);

	// root->left->left = createNode(0);

	// root->left->right = createNode(5);

	insertNode(4);

	insertNode(27);

	insertNode(11);

	printTree(root);

	return 0;

}

