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
		printf("\nExit Program\n\n");
		exit(1);
	}
	return ret;
}

int main() {
	printf("               ---------------Calculator-------------\n");
	printf("Don't use spacebar. only two natural number is calculated. When divided, only the quotient are printed.\n\n");
	printf("If you want to stop this program, Input any alphabet.\n\n");
	while (1) {
		char line[100];
		printf("INPUT (Ex : 5*4) :  ");
		read(line);
		printf("\nRESULT = %d\n\n", clac(line));
	}
	
	return 0;
}
