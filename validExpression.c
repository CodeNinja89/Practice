#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char *stack, char c, int *top, int len) {
	if(*top >= len - 1) {
		return;
	} else {
		++*top;
		stack[*top] = c;
	}

}

void pop(char *stack, int *top) {
	if(*top <= -1) {
		return;
	} else {
		--*top;
	}
}

void isValid(char *s) {
	int i = 0;
	int top = -1;
	char *stack = (char *)malloc(strlen(s));

	for(i = 0; i < strlen(s); i++) {
		if(top == -1) {
			push(stack, s[i], &top, strlen(s));
		} else {
			if((s[i] == ')') && (stack[top] == '(')) {
				pop(stack, &top);
			} else if((s[i] == ']') && (stack[top] == '[')) {
				pop(stack, &top);
			} else if((s[i] == '}') && (stack[top] == '{')) {
				pop(stack, &top);
			} else {
				push(stack, s[i], &top, strlen(s));
			}
		}
	}
	if(top == -1) {
		printf("valid expression\n");
	} else {
		printf("invalid expression\n");
	}
}

int main() {
	char *exp = "()()()((()))({[]})";
	isValid(exp);
}