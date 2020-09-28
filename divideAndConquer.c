#include <stdio.h>

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

char *divideAndConquer(char **strings, int left, int right) {
	if(left == right) {
		return strings[left];
	} else {
		int mid = (left + right) / 2;
		char *lcpLeft = divideAndConquer(strings, left, mid);
		char *lcpRight = divideAndConquer(strings, mid + 1, right);
		return commonPrefix(lcpLeft, lcpRight);
	}
}


