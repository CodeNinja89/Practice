#include <stdio.h>

int compare(char *str1, char *str2) {
	while(*str1 && *str2) {
		if(*str1 != *str2) {
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 == '\0');
}

char *strStr(char *haystack, char *needle) {
	int i = 0;
	while(*haystack != '\0') {
		if((*haystack == *needle) && compare(haystack, needle)) {
			return haystack;
		}
		haystack++;
		i++;
	}
	return NULL;
}

int main() {
	char *haystack = "hello";
	char *needle = "ll";
	char *pos = strStr(haystack, needle);
	printf("%s\n", pos);
}