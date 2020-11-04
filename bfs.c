/*
994.
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROTTEN 2
#define FRESH  1
#define EMPTY  0

struct queue {
	int row;
	int col;
	struct queue *next;
};

void createQueue(int row, int col, struct queue **node) {
 	if(*node == NULL) {
		(*node) = (struct queue *)malloc(sizeof(node));
		(*node)->next = NULL;
		(*node)->row = row;
		(*node)->col = col;
		return;
	} else {
		createQueue(row, col, &(*node)->next);
	}
}

int queueSize(struct queue *node) {
	int size = 0;
	while(node != NULL) {
		++size;
		node = node->next;
	}
	return size;
}

void printQueue(struct queue *node) {
	while(node != NULL) {
		printf("%d %d\n", node->row, node->col);
		node = node->next;
	}
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
	struct queue *head = NULL;
	struct queue *node = NULL;
	struct queue *temp = NULL;
	
	int i = 0, j = 0, size = 0, ticks = 0, fresh = 0;

	for(i = 0; i < gridSize; i++) {
		for(j = 0; j < *gridColSize; j++) {
			if(grid[i][j] == FRESH) fresh++; // total number of fresh apples
			if(grid[i][j] == ROTTEN) {
				createQueue(i, j, &head); // add the rotten apples in the queue
			}
		}				
	}
	
	node = head;

	while(node != NULL && fresh > 0) {
		// mark the adjacent directions as rotten if there are apples
		printf("queue: %d %d, ticks: %d, queue size: %d\n", node->row, node->col, ticks, queueSize(head));

		for(i = 0; i < gridSize; i++) {
			for(j = 0; j < *gridColSize; j++) {
				printf("%d ", grid[i][j]);
			}
			printf("\n");
		}

		size = queueSize(node);
		temp = node;

		while(temp != NULL && size > 0) {
			if((temp->row + 1) < gridSize && grid[temp->row + 1][temp->col] == FRESH) { 
				grid[temp->row + 1][temp->col] = ROTTEN;
				createQueue(temp->row + 1, temp->col, &head);
				fresh--;
			}
			if((temp->row - 1) >= 0 && grid[temp->row - 1][temp->col] == FRESH) {
				grid[temp->row - 1][temp->col] = ROTTEN;
				createQueue(temp->row - 1, temp->col, &head);
				fresh--;
			}
			if((temp->col + 1) < *gridColSize && grid[temp->row][temp->col + 1] == FRESH) {
				grid[temp->row][temp->col + 1] = ROTTEN;
				createQueue(temp->row, temp->col + 1, &head);
				fresh--;
			}
			if((temp->col - 1) >= 0 && grid[temp->row][temp->col - 1] == FRESH) {
				grid[temp->row][temp->col - 1] = ROTTEN;
				createQueue(temp->row, temp->col - 1, &head);
				fresh--;
			}
			temp = temp->next;
			size--;
		}
		/*printQueue(node);*/
		node = node->next;
		ticks++;
	}
	return fresh == 0 ? ticks : -1;
}

int main() {
	int numRows = 5;
	int numCols = 1;
	int row, cols, ret = 0;

	int **grid;

	printf("Enter grid\n");

	grid = (int **)malloc(numRows * sizeof(int *));
	
	for(row = 0 ; row < numRows; row++) {
		grid[row] = (int *)malloc(numCols * sizeof(int)) ;
	}

	for(row = 0; row < numRows; row++) {
		for(cols = 0; cols < numCols; cols++) {
			scanf("%d", &grid[row][cols]);
		}
	}

	ret = orangesRotting(grid, numRows, &numCols);
	printf("%d\n", ret);
	return 0;
}
