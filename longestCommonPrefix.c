#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *commonPrefix(char *left, char *right) {
	int minLen;
	if(left == NULL || right == NULL) {
		printf("SOMETHING IS NULL\n");
        return NULL;
    }
	minLen = strlen(left) > strlen(right) ? strlen(right) : strlen(left);
	int i = 0;
	char *subStr = (char *)malloc(minLen);
	for(i = 0; i < minLen; i++) {
		if(left[i] != right[i]) {
			break;
		} else {
			subStr[i] = left[i];
		}
	}
	return subStr;
}

char *divideAndConquer(char **strings, int left, int right) {
	int mid;
	if(left == right) {
		return strings[left];
	} else {
		mid = (left + right) / 2;
		char *lcpLeft = divideAndConquer(strings, left, mid);
		char *lcpRight = divideAndConquer(strings, mid + 1, right);
		return commonPrefix(lcpLeft, lcpRight);
	}
}

char *longestCommonPrefix(char **strings, int len) {	
	return divideAndConquer(strings, 0, len - 1);
}

int main() {
	char *str[3] = {"flower","flow","flight"};
	char *substr;
	substr = longestCommonPrefix(str, 3);
	printf("%s\n", substr);
}