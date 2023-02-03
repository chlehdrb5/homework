#include<stdio.h>

void indexAddMat(int a[][3], int b[][3], int c[][3]);
void ptrProdMat(int a[][3], int b[][3], int c[][3]);

int main() {
	while (1) {
		int repeat;
		int a[3][3], b[3][3], c[3][3];
		printf("3x3 정방행렬 입력(A)\n");
		for (int i = 0; i < 3; i++) {
			printf("%d행 3개 입력 ( X X X ) :", i + 1);
			scanf_s("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		}
		printf("3x3 정방행렬 입력(B)\n");
		for (int i = 0; i < 3; i++) {
			printf("%d행 3개 입력 ( X X X ) :", i + 1);
			scanf_s("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
		}

		indexAddMat(a, b, c);
		printf("합\n");
		for (int i = 0; i < 3; i++) {
			printf("%3d %3d %3d\n", c[i][0], c[i][1], c[i][2]);
		}

		ptrProdMat(a, b, c);
		printf("곱\n");
		for (int i = 0; i < 3; i++) {
			printf("%3d %3d %3d\n", c[i][0], c[i][1], c[i][2]);
		}

		printf("Repeat? (Yes : 1, No :0) : ");
		scanf_s("%d", &repeat);
		if (repeat == 0)
			break;
	}
	return 0;
}

void indexAddMat(int a[][3], int b[][3], int c[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void ptrProdMat(int a[][3], int b[][3], int c[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(c + i) + j) = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				*(*(c + i) + j) += (*(*(a + i) + k))*(*(*(b + k) + j));
			}
		}
	}
}
