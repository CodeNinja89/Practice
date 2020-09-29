#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	int data;
	int height;
};

int max(int a, int b) {
	return a > b ? a : b;
}

int height(struct node *n) {
	if(n == NULL) {
		return 0;
	}
	return n->height;
}

int getBalance(struct node *n) {
	if(n == NULL) {
		return 0;
	}
	return (height(n->left) - height(n->right));
}

struct node *rotateRight(struct node *n) {
	printf("RIGHT ROTATE\n");
	struct node *a = n->left;
	struct node *b = a->right;

	// perform rotation
	a->right = n;
	n->left = b;

	// update heights
	n->height = 1 + max(height(n->left), height(n->right));
	a->height = 1 + max(height(a->left), height(a->right));

	return a;
}

struct node *rotateLeft(struct node *n) {
	printf("LEFT ROTATE\n");
	struct node *a = n->right;
	struct node *b = a->left;

	a->left = n;
	n->right = b;

	n->height = 1 + max(height(n->left), height(n->right));
	a->height = 1 + max(height(a->left), height(a->right));

	return a;
}

struct node *insert(int n, struct node *node) {
	if(node == NULL) {
		printf("INSERTING NODE: %d\n", n);
		node = (struct node *)malloc(sizeof(node));
		node->left = NULL;
		node->right = NULL;
		node->data = n;
		node->height = 1;
		return node;
	} else {
		if(node->data > n) {
			node->left = insert(n, node->left);
		} else {
			node->right = insert(n, node->right);
		}
	}

	// update the height of the ancestor node
	node->height = 1 + max(height(node->left), height(node->right));

	// get the balance of this node
	int balance = getBalance(node);

	// balance the node

	// left of left balancing
	if((balance > 1) && (n < node->left->data)) {
		return rotateRight(node);
	}

	// right of right balancing
	if((balance < -1) && (n > node->right->data)) {
		return rotateLeft(node);
	}

	// left of right balancing
	if((balance > 1) && (n > node->left->data)) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	// right of left balancing
	if((balance < -1) && (n < node->right->data)) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

void inOrder(struct node *node) {
	if(node != NULL) {
		inOrder(node->left);
		printf("%d\n", node->data);
		inOrder(node->right);
	} else return;
}

void preOrder(struct node *node) {
	if(node != NULL) {
		printf("%d\n", node->data);
		preOrder(node->left);
		preOrder(node->right);
	} else return;	
}

void postOrder(struct node *node) {
	if(node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("%d\n", node->data);
	} else return;	
}

int main() {
	struct node *root = NULL;
	int num;

	root = insert(10, root); 
	root = insert(20, root); 
	root = insert(30, root); 
	root = insert(40, root); 
	root = insert(50, root); 
	root = insert(25, root); 

	printf("IN ORDER TRAVERSAL\n");
	inOrder(root);

	printf("PRE ORDER TRAVERSAL\n");
	preOrder(root);

	printf("POST ORDER TRAVERSAL\n");
	postOrder(root);
}