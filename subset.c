#include <stdio.h>
#include <string.h>

/*Given the array favoriteCompanies where favoriteCompanies[i] is the list of favorites companies for the ith person (indexed from 0).
Return the indices of people whose list of favorite companies is not a subset of any other list of favorites companies. You must return the indices in increasing order.
 */

/* the problem is to find if a given set is a subset of another set. */

int main() {
	char *favoriteCompanies[5][3] = {
		{"leetcode","google","facebook"},
		{"google","microsoft"},
		{"google","facebook"},
		{"google"},
		{"amazon"}
	};
	int peopleIndexes[5] = {0};
	int flag = 0;
	//peopleIndexes(&favoriteCompanies, 5, 3, NULL);
	int i = 0, j = 0, k = 0, c = 1, interSize = 0, size_0 = sizeof(favoriteCompanies[0]) / sizeof(char *);
	peopleIndexes[0] = 0;
	for(i = 1; i < 5; i++) {
		interSize = sizeof(favoriteCompanies[i]) / sizeof(char *);
		for(j = 0; j < size_0; j++) {
			for(k = 0; k < interSize; k++) {
				if(favoriteCompanies[i][k] != NULL) {
					if(!strcmp(favoriteCompanies[0][j], favoriteCompanies[i][k])) {
						flag = 0;
					} else {flag = 1;}
				}
			}
			if(flag == 0) {
				break;
			}
		}
		if(flag != 0) {
			peopleIndexes[c++] = i;
		}
	}
	for(i = 0; i < 5; i++) {
		printf("%d ", peopleIndexes[i]);
	}
	printf("\n");
}