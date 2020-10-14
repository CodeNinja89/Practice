#include <stdio.h>
#include <stdlib.h>

/*There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

In each step, you will choose any 3 piles of coins (not necessarily consecutive).
Of your choice, Alice will pick the pile with the maximum number of coins.
You will pick the next pile with maximum number of coins.
Your friend Bob will pick the last pile.
Repeat until there are no more piles of coins.
Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins which you can have.*/

int compare_function(const void *a,const void *b) {
	int *x = (int *) a;
	int *y = (int *) b;
	return *x - *y;
}

int maxCoins(int *piles, int pileSize) {
	int i = 0, j = pileSize;
	int coins = 0;
	// sort the array
	qsort(piles, pileSize, sizeof(*piles), compare_function);
	
	while(i + 1 < j) {
		coins += piles[j - 2];
		i++;
		j -= 2;
	}
	return coins;
}

int main() {
	int piles[] = {9, 8, 7, 6, 5, 1, 2, 3, 4};
	int coins = maxCoins(piles, 9);
	printf("%d\n", coins);
}