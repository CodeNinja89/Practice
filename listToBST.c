#include <stdio.h>
#include <stdlib.h>

/* Given a sorted linked list, arrange the elements in a binary search tree */

struct ListNode {
    int val;
    struct ListNode *next;
 };

 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };

 void createList(int val, struct ListNode **node) {
 	if(*node == NULL) {
		(*node) = (struct ListNode *)malloc(sizeof(node));
		(*node)->next = NULL;
		(*node)->val = val;
		return;
	} else {
		createList(val, &(*node)->next);
	}
 }

 void insert(unsigned int n, struct TreeNode **node) {
	if(*node == NULL) {
		(*node) = (struct TreeNode *)malloc(sizeof(struct TreeNode *));
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->val = n;
		return;
	} else {
		if((*node)->val > n) {
			insert(n, &(*node)->left);
		} else {
			insert(n, &(*node)->right);
		}
	}
}

struct TreeNode* sortedListToBST(struct ListNode* head){
	// traverse the list node to get the length
	struct ListNode *temp = head;
	struct TreeNode *root = NULL;

	int listLen = 0, i = 0;
	while(temp != NULL) {
		listLen++;
		temp = temp->next;
	}

	// traverse to the middle of the list. This element is the root of the tree
	temp = head;
	while(i != listLen / 2) {
		temp = temp->next;
		i++;
	}

	insert(temp->val, &root);
	temp = head;
	i = 0;

	// traverse the list and keep inserting the elements.
	while(i != listLen && temp != NULL) {
		if(i == listLen / 2) {
			temp = temp->next;
		} else {
			insert(temp->val, &root);
			temp = temp->next;
		}
		i++;
	}

	return root;
}

int height(struct TreeNode *node){
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

void printLevel(struct TreeNode *node, int level) {
	if(node == NULL)
		return;
	if(level == 1)
		printf("%d\n", node->val);
	else if(level > 1) {
		printLevel(node->left, level - 1);
		printLevel(node->right, level - 1);
	}
}

void bfs(struct TreeNode *node) {
	if(node == NULL) {
		return; // empty tree
	}
	int h = height(node);
	int i;
	for(i = 1; i <= h; i++) {
		printLevel(node, i);
	}
}

void parseList(struct ListNode *head) {
	while(head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct ListNode *head = NULL;
	struct TreeNode *root = NULL;
	int arr[5] = {-10, -3, 0, 5, 9};
	int i = 0;
	
	for(i = 0; i < 5; i++)
		createList(arr[i], &head);
	
	printf("sorted list\n");
	parseList(head);

	root = sortedListToBST(head);
	printf("BST\n");
	bfs(root);
}