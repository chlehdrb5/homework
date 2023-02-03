#include<stdio.h>
#include <stdlib.h>

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
int clac1(char *s, int *b)
{
	int num2 = 0;
	int ret;
	char c;
	char op;
	c = *s++;
	op = c;
	c = *s++;
	while (isdigit(c)) {
		num2 = 10 * num2 + (c - '0');
		c = *s++;
	}
	switch (op) {
	case '+':
		ret = *b + num2;
		break;
	case '-':
		ret = *b - num2;
		break;
	case '*':
		ret = *b * num2;
		break;
	case '/':
		ret = *b / num2;
		break;
	default:
		printf("error ");
		exit(1);
	}
	return ret;
}

int main() {
	char line[100];
	char a,c;
	int b; // b는 결과값 저장
ONE:;
	printf("INPUT : ");
	read(line);
	b = clac(line);
	printf("\nRESULT = %d\n\n", clac(line));
	printf("Do you want to use this value to calculate? (Y/N) : ");
TWO:;
	a = getchar();
	switch (a) {
	case 'Y':
		while (1) {
			printf("INPUT (EX: *4) : ");
			read(line);
			b = clac1(line,b);
			printf("\nRESULT = %d\n\n", b);
			printf("Do you want to use this value to calculate? (Y/N) : ");
			goto TWO;
		}
		break;
	case 'N':
		printf("IF you want to OFF -> Enter || IF you want to RESET -> R ");
		scanf_s("%c", &c);
		if (c == '\n')
			break;
		else if (c == 'R')
			
			goto ONE;
		else {
			printf("Error -> EXIT PROGRAM");
			break;
		}
		
		
	default:
		printf("This is not 'Y' or 'N' -> EXIT PROGRAM");
		break;
	}

	return 0;
}