#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//20180600
typedef struct {
	int year;
	int month;
	int day;
} birth;

typedef struct {
	char name[20];
	birth birth;
	char gender[10];
	char phonenum[15];
}statement;

void swapfun(statement *pi[], int i, int j);
void namesort(statement *pi[], int num);
void birthsort(statement *pi[], int num);
void make_hyphen(char phonenum[15]);

int main() {
	int num;
	int i = 0;
	printf("입력할 명세서의 개수를 입력하시오 : ");
	scanf_s("%d", &num);
	statement **pi = (statement**)malloc(sizeof(statement*)*num);
	for (i = 0; i < num; i++) {
		pi[i] = (statement*)malloc(sizeof(statement)); //동적 메모리 할당
		printf("%d번째\n", i + 1);
		printf("이름                   : ");
		scanf_s("%s", pi[i]->name, 20);
		printf("생년월일(ex 1999/12/30): ");
		scanf_s("%d/%d/%d", &pi[i]->birth.year, &pi[i]->birth.month, &pi[i]->birth.day);
		printf("성별(남자/여자)        : ");
		scanf_s("%s", pi[i]->gender, 6);
		printf("전화번호(01012341234)  : ");
		scanf_s("%s", pi[i]->phonenum, 15);
		make_hyphen(pi[i]->phonenum);
	}
	printf("---------------------------------------------------------------------------\n");
	printf(" 이름\t\t생년월일\t성별\t\t  전화번호\n");
	printf("---------------------------------------------------------------------------\n");
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t    %s\n",
			pi[i]->name, pi[i]->birth.year, pi[i]->birth.month, pi[i]->birth.day, pi[i]->gender, pi[i]->phonenum);
	}
	printf("\n\n---------------------------------<이름 순서 정렬>---------------------------\n\n");
	namesort(pi, num);
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t    %s\n",
			pi[i]->name, pi[i]->birth.year, pi[i]->birth.month, pi[i]->birth.day, pi[i]->gender, pi[i]->phonenum);
	}
	printf("\n\n--------------------------------<생일 순서 정렬>---------------------------\n\n");
	birthsort(pi, num);
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t    %s\n",
			pi[i]->name, pi[i]->birth.year, pi[i]->birth.month, pi[i]->birth.day, pi[i]->gender, pi[i]->phonenum);
	}
	printf("\n\n-------------------------------------------------------------------------\n");
	for (i = 0; i < num; i++) {
		free(pi[i]);
	}
	free(pi);
	system("pause");
	return 0;
}

void swapfun(statement *pi[], int i, int j) {
	statement *memory;
	memory = pi[i];
	for (int k = i; k > j; k--) {
		pi[k] = pi[k - 1];
	}
	pi[j] = memory;
}

void namesort(statement *pi[], int num) {
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (strcmp(pi[i]->name, pi[j]->name)>0) {
				swapfun(pi, i, j);
			}
		}
	}
}

void birthsort(statement *pi[], int num) {
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (pi[i]->birth.year < pi[j]->birth.year) {
				swapfun(pi, i, j);
			}
			else if (pi[i]->birth.year == pi[j]->birth.year) {
				if (pi[i]->birth.month < pi[j]->birth.month) {
					swapfun(pi, i, j);
				}
				else if (pi[i]->birth.month == pi[j]->birth.month) {
					if (pi[i]->birth.day < pi[j]->birth.day) {
						swapfun(pi, i, j);
					}
				}
			}
		}
	}
}

void make_hyphen(char phonenum[15]) {
	for (int i = 10; i >= 3; i--) 
		phonenum[i + 1] = phonenum[i];
	for (int i = 11; i >= 8; i--) 
		phonenum[i + 1] = phonenum[i];
	phonenum[3] = '-';
	phonenum[8] = '-';
	phonenum[13] = '\0';
}