#include <stdio.h>
#include <limits.h>

int isPalindrome(int x) {
	int copy_x = x;
	if(x < 0) {
		return 0;
	}
	int temp = 0;
	int rev = 0;
	while(x != 0) {
		temp = x % 10;
		if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && temp > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && temp < -8)) return 0;
        rev = rev * 10 + temp;
		x = x / 10;
	}
	if(rev == copy_x) {
		return 1;
	}
}

int main() {
	int test = -1331;
	int result;
	result = isPalindrome(test);
	printf("%d\n", result);
	return 0;
}