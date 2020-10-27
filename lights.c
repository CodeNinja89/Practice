#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*You are given a grid of size N x N, and each cell of this grid has a lamp that is initially turned off.

You are also given an array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

Finally, you are given a query array queries, where queries[i] = [rowi, coli]. For the ith query, determine whether grid[rowi][coli] is illuminated or not. After answering the ith query, turn off the lamp at grid[rowi][coli] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowi][coli].

Return an array of integers ans, where ans[i] should be 1 if the lamp in the ith query was illuminated, or 0 if the lamp was not.

*/

int* gridIllumination(int N, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
	int *hashmap = (int *)malloc(N * N * sizeof(int));
	int i = 0, j = 0, k = 0;
	int *ans = (int *)malloc(queriesSize * sizeof(int));
	
	memset(hashmap, 0, N * N);
	memset(ans, 0, queriesSize);
	*returnSize = queriesSize;

	// light up the lamps
	for(i = 0; i < lampsSize; i++) {
		for(k = 0; k < N; k++){
			hashmap[N * lamps[i][0] + k]++; // light up the row
			hashmap[N * k + lamps[i][1]]++; // light up the column
			// check diagonals
			if((lamps[i][0] < N / 2) && (lamps[i][0] == lamps[0][i])) {
				hashmap[N * k + k]++;
			} else if((lamps[i][0] > N / 2) && (lamps[i][0] == lamps[0][i])) {
				hashmap[(N - 1) * (k + 1)]++;
			}
		}
	}

	for(i = 0; i < queriesSize; i++) {
		if(hashmap[(N * queries[i][0] + queries[i][1])] > 0) {
			hashmap[(N * queries[i][0] + queries[i][1])]--;
			ans[i] = 1;
		}

		if((queries[i][1] - 1 >= 0) && (hashmap[(N * queries[i][0] + queries[i][1]) - 1] > 0))
			hashmap[(N * queries[i][0] + queries[i][1]) - 1]--;
		if((queries[i][1] + 1 <= N) && (hashmap[(N * queries[i][0] + queries[i][1]) + 1] > 0))
			hashmap[(N * queries[i][0] + queries[i][i]) + 1]--;
		if(((queries[i][0] - 1) >= 0) && hashmap[N * (queries[i][0] - 1) + queries[i][1]] > 0)
			hashmap[N * (queries[i][0] - 1) + queries[i][1]]--;
		if(((queries[i][0] + 1) <= N) && hashmap[N * (queries[i][0] + 1) + queries[i][1]] > 0)
			hashmap[N * (queries[i][0] + 1) + queries[i][1]]--;
		if(((queries[i][0] - 1) >= 0) && ((queries[i][1] - 1) >= 0) && hashmap[N * (queries[i][0] - 1) + (queries[i][1] - 1)] > 0)
			hashmap[N * (queries[i][0] - 1) + (queries[i][1] - 1)]--;
		if(((queries[i][0] - 1) >= 0) && ((queries[i][1] + 1) <= N) && hashmap[N * (queries[i][0] - 1) + (queries[i][1] + 1)] > 0)
			hashmap[N * (queries[i][0] - 1) + (queries[i][1] + 1)]--;
		if(((queries[i][0] + 1) <= N) && ((queries[i][1] - 1) >= 0) && hashmap[N * (queries[i][0] + 1) + (queries[i][1] - 1)] > 0)
			hashmap[N * (queries[i][0] + 1) + (queries[i][1] - 1)]--;
		if(((queries[i][0] + 1) <= N) && ((queries[i][1] + 1) <= N) && hashmap[N * (queries[i][0] + 1) + (queries[i][1] + 1)] > 0)
			hashmap[N * (queries[i][0] + 1) + (queries[i][1] + 1)]--;

	}

	for(i = 0; i < N * N; i++)
		printf("i: %d : %d\n", i, hashmap[i]);
	return ans;
}

int main() {
	int numRowsLamp = 2;
	int numColsLamp = 2;
	int numRowsQuery = 2;
	int numColsQuery = 2;
	int **grid, row, cols;
	int **lamps, **query, *ans;
	int returnSize;

	printf("Enter lamps\n");

	lamps = (int **)malloc(numRowsLamp * sizeof(int *));
	
	for(row = 0 ; row < numRowsLamp ; row++ ) {
		lamps[row] = (int *)malloc(numColsLamp * sizeof(int)) ;
	}

	for(row = 0; row < numRowsLamp; row++) {
		for(cols = 0; cols < numColsLamp; cols++) {
			scanf("%d", &lamps[row][cols]);
		}
	}

	printf("Enter queries\n");

	query = (int **)malloc(numRowsQuery * sizeof(int *));
	
	for(row = 0 ; row < numRowsQuery ; row++ ) {
		query[row] = (int *)malloc(numColsQuery * sizeof(int)) ;
	}

	for(row = 0; row < numRowsQuery; row++) {
		for(cols = 0; cols < numColsQuery; cols++) {
			scanf("%d", &query[row][cols]);
		}
	}

	ans = gridIllumination(5, lamps, numRowsLamp, &numColsLamp, query, numRowsQuery, &numColsQuery, &returnSize);
	for(row = 0; row < returnSize; row++) {
		printf("%d ", ans[row]);
	}
	printf("\n");
	return 0;
}