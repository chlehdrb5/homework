#include<stdio.h>
#include<ctype.h>

long rfibo(long num);
long sfibo(long num);

int main() {

	printf("3부터 45까지의 홀수 값에 대한 피보나치 수\n");
	sfibo(1);
	for (long num = 3; num <= 45; num = num + 2) {
		printf("rfibo(%d) : %d\n", num, rfibo(num));
		sfibo(num);
		printf("sfibo(%d) : %d\n", num, sfibo(num));
		printf("\n");
	}

	system("pause");
	return 0;
}

long rfibo(long num) {
	if (num == 1)
		return 1;
	if (num == 0)
		return 0;
	return rfibo(num - 1) + rfibo(num - 2);
}

long sfibo(long num) {
	static long num1 = 0;
	static long num2 = 1;
	static long save;
	save = num1;
	num1 = num2;
	num2 = num2 + save;
	return num1;
}