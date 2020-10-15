/*create a BST and perform in-order, post order, preorder and breadth first traversal */
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for generating random numbers
#include <limits.h>
#include <string.h>

struct node {
	struct node *left;
	struct node *right;
	unsigned int data;
};

void insert(unsigned int n, struct node **node) {
	if(*node == NULL) {
		(*node) = (struct node *)malloc(sizeof(node));
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->data = n;
		return;
	} else {
		if((*node)->data > n) {
			insert(n, &(*node)->left);
		} else {
			insert(n, &(*node)->right);
		}
		
	}
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

int height(struct node *node){
	if(node == NULL) {
		return 0;
	} else {
		int heightLeft = height(node->left);
		int heightRight = height(node->right);
		if(heightLeft > heightRight)
			return (heightLeft + 1);
		else return (heightRight + 1);
	}
}

void printLevel(struct node *node, int level) {
	if(node == NULL)
		return;
	if(level == 1)
		printf("%d\n", node->data);
	else if(level > 1) {
		printLevel(node->left, level - 1);
		printLevel(node->right, level - 1);
	}
}

void bfs(struct node *node) {
	if(node == NULL) {
		return; // empty tree
	}
	int h = height(node);
	int i;
	for(i = 1; i <= h; i++) {
		printLevel(node, i);
	}
}

int main(int argc, const char **argv) {
	struct node *tree = NULL;
	unsigned int num;

	time_t t;
	unsigned int stop = 0;

	srand(time(&t));

	do {
		num = rand() % INT_MAX;
		insert(num, &tree);
		stop++;
	}while(stop != 100);

	if(!(strcmp("inorder", argv[1]))) {
		printf("IN ORDER TRAVERSAL\n");
		inOrder(tree);
	} else if(!(strcmp("preorder", argv[1]))) {
		printf("PRE ORDER TRAVERSAL\n");
		preOrder(tree);
	} else if(!(strcmp("postorder", argv[1]))) {
		printf("POST ORDER TRAVERSAL\n");
		postOrder(tree);
	} else if(!(strcmp("bfs", argv[1]))) {
		printf("\n\nBFS traversal\n");
		bfs(tree);
	}
	
}
