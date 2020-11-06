#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 9
#define COLS 9

int minDistance(int *distance, int *spt) {
	int i = 0;
	int min = INT_MAX, min_index = 0;

	for(i = 0; i < ROWS; i++) {
		if(distance[i] <= min && spt[i] == 0) {
			min_index = i;
			min = distance[i];
		}
	}
	return min_index;
}

int *spt(int **grid, int rows, int cols, int start) {
	int i = 0, j = 0, min = INT_MAX, *distance;
	int *spt, vertex = 0;

#if 0
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
#endif

	// to start with, define an array of length ROWS, with all the values set to some very large number.
	// this array will be updated every time we add a node to the vertex set.

	distance = malloc(ROWS * sizeof(int));
	distance[start] = 0; // distance from the source vertex is always 0
	for(i = 1; i < rows; i++) distance[i] = INT_MAX;
	i = 0;

#if 0
	for(i = 0; i < rows; i++) {
		printf("%d ", distance[i]);
	}
	printf("\n");
#endif

	// this is the shortest path tree

	spt = malloc(ROWS * sizeof(int));
	for(i = 0; i < rows; i++) 
		spt[i] = 0;

	i = 0;

	while(i < ROWS - 1) { // calculate the distances of 
		vertex = minDistance(distance, spt); // pick the shortest path to the vertex not yet included in the shortest path tree
		spt[vertex] = 1; // mark this vertex as visited
		// update the values of the adjacent vertices
		for(j = 0; j < ROWS; j++) {
			if(!spt[j] && grid[vertex][j] && distance[vertex] != INT_MAX
				&& (distance[vertex] + grid[vertex][j]) < distance[j])
				distance[j] = distance[vertex] + grid[vertex][j];
		}
		i++;
	}
	return distance;
}

int main() {
	int row, cols, start = 0;

	int **grid, *shortestPathTree;

	printf("Enter adjacency matrix\n");

	grid = (int **)malloc(ROWS * sizeof(int *));
	
	for(row = 0 ; row < ROWS; row++) {
		grid[row] = (int *)malloc(COLS * sizeof(int)) ;
	}

	for(row = 0; row < COLS; row++) {
		for(cols = 0; cols < COLS; cols++) {
			scanf("%d", &grid[row][cols]);
		}
	}

	printf("starting node: ");
	scanf("%d", &start);

	shortestPathTree = spt(grid, ROWS, COLS, start);
	for(row = 0; row < ROWS; row++) {
		printf("distance from source to %d : %d\n", row, shortestPathTree[row]);
	}

	return 0;
}