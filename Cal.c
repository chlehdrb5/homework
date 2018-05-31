#include <stdio.h> 
#include <stdlib.h>

// 20180600 최동규 20181366 이석민 
void read(char s[])
{
	int c, i = 0;
	while ((c = getchar()) != '\n')
		s[i++] = c;
	s[i] = '\0';
}

int clac(char *s)
{
	int num1 = 0;
	int num2 = 0;
	int ret;
	char c;
	char op;
	c = *s++;
	while (isdigit(c)) {
		num1 = 10 * num1 + (c - '0');
		c = *s++;
	}
	op = c;
	c = *s++;
	while (isdigit(c)) {
		num2 = 10 * num2 + (c - '0');
		c = *s++;
	}
	switch (op) {
	case '+':
		ret = num1 + num2;
		break;
	case '-':
		ret = num1 - num2;
		break;
	case '*':
		ret = num1 * num2;
		break;
	case '/':
		ret = num1 / num2;
		break;
	default:
		printf("error ");
		exit(1);
	}
	return ret;
}
int main() {
	char line[100];
	printf("INPUT (When divided, only the quotient are printed.) : ");
	read(line);
	printf("\nRESULT = %d\n\n", clac(line));
	return 0;
}