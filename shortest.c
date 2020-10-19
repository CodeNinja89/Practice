#include <stdio.h>
#include <stdlib.h>

struct node {
	int visited;
	int label;
	int cost; // cost from parent node to this node
	struct node *next;
};

struct node vertices[10];

void graphify(int from, int to, int cost) {
	struct node *vertex = (struct node *)malloc(sizeof(struct node));
	struct node *temp = vertices[from].next;
	
	if(vertices[from].label == -1) { // this is a new vertex
		vertices[from].label = from;
		vertices[from].visited = 0;
		vertices[from].cost = 0;
	}
	vertex->visited = 0; // this node is not yet visited
	vertex->label = to;
	vertex->cost = cost;

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
				printf("->(%d, %d)", temp->label, temp->cost);
				temp = temp->next;
			}
		}
		printf("\n");
	}
}

void shortest(int start) {
	struct node *temp;
	int currCost, currVertex;

	printf("%d ", start);

	if(vertices[start].label != -1) {
		temp = vertices[start].next;
		if(temp != NULL) {
			currCost = temp->cost;
			currVertex = temp->label;
		}
		if(vertices[currVertex].next == NULL) { // this is a peek operation :?
			temp = temp->next;
			if(temp != NULL) {
				currCost = temp->cost;
				currVertex = temp->label;
			}
		}
		while(temp != NULL) {
			if(temp->next != NULL) {
				if(currCost > temp->next->cost) {
					currCost = temp->next->cost;
					currVertex = temp->next->label;
				}
			}
			temp = temp->next;
		}
		shortest(currVertex);
	}
}

int main() {
	int i = 0;
	for(i = 0; i < 10; i++) {
		vertices[i].visited = 0;
		vertices[i].label = -1;
		vertices[i].next = NULL;
	}

	graphify(0, 1, 3);
    graphify(0, 2, 10);
    graphify(2, 4, 1);
    graphify(1, 3, 10);
    graphify(1, 4, 6);
    graphify(3, 4, 10);
    graphify(3, 5, 5);
    graphify(4, 5, 2);

    shortest(0);
    printf("\n");
    printf("Adjacency list with cost\n");
	printAdjencyList();
}