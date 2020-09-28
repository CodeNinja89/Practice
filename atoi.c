#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *multiply(char *a, char *b) {
	int len_a = strlen(a);
	int len_b = strlen(b);
	int lenRes = (len_a + len_b) - 1;
	int i = 0, j = 0;
	long int x = 0, y = 0, res = 0;
	char *resultTemp = (char *)malloc(lenRes);
	char *result = (char *)malloc(lenRes);
	char temp;

	while(len_a) {
		x += (a[len_a - 1] - 0x30) * pow(10, i);
		i++;
		len_a--;
	}
	i = 0;
	while(len_b) {
		y += (b[len_b - 1] - 0x30) * pow(10, i);
		i++;
		len_b--;
	}

	res = x * y;
	i = 0;

	while(res != 0) {
		resultTemp[i] = 0x30 + (res % 10);
		/*printf("%c", result[i]);*/
		res /= 10;
		i++;
	}
	resultTemp[i] = '\0';

	for(j = i - 1, i = 0; j >= 0; j--, i++) {
		temp = resultTemp[i];
		resultTemp[i] = resultTemp[j];
		resultTemp[j] = temp;
		/*printf("%c", result[j]);*/
	}

	return resultTemp;
}

int main() {
	printf("%s\n", multiply("123", "456"));
}