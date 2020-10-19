#include <stdio.h>
#include <stdlib.h>

struct node {
	int visited;
	int label;
	struct node *next;
};

struct node vertices[10];

void graphify(int from, int to) {
	struct node *vertex = (struct node *)malloc(sizeof(struct node));
	struct node *temp = vertices[from].next;
	
	if(vertices[from].label == -1) { // this is a new vertex
		vertices[from].label = from;
		vertices[from].visited = 0;
	}
	vertex->visited = 0; // this node is not yet visited
	vertex->label = to;

	// enqueue the 'to' node
	while(temp != NULL) {
		if(temp->next == NULL)
			break;
		else temp = temp->next;
	}
	if(temp == NULL)
		vertices[from].next = vertex;
	else temp->next = vertex;

	vertex->next = NULL;
}

void printAdjencyList() {
	int i = 0;
	struct node *temp;

	for(i = 0; i < 10; i++) {
		printf("%d", vertices[i].label);
		if(vertices[i].next != NULL) {
			temp = vertices[i].next;
			while(temp != NULL) {
				printf("->%d", temp->label);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}

void depthFirst(int vertex) {
	struct node *temp;

	if(vertices[vertex].visited == 0) {
		// this vertex is not yet visited, print it and go to the next vertex
		printf("%d ", vertices[vertex].label);
		vertices[vertex].visited = 1;
		if(vertices[vertex].next != NULL) {
			temp = vertices[vertex].next;
			while(temp != NULL) {
				depthFirst(temp->label);
				temp = temp->next;
			}
		}
	}
}

int main() {
	int i = 0;
	for(i = 0; i < 10; i++) {
		vertices[i].visited = 0;
		vertices[i].label = -1;
		vertices[i].next = NULL;
	}

	graphify(0, 1);
    graphify(0, 2);
    graphify(2, 4);
    graphify(1, 3);
    graphify(1, 4);
    graphify(3, 4);
    graphify(3, 5);
    graphify(4, 5);


    depthFirst(0);
    printf("\n");

	printAdjencyList();
}