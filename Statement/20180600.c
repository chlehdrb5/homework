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
	printf("�Է��� ������ ������ �Է��Ͻÿ� : ");
	scanf_s("%d", &num);
	statement **pi = (statement**)malloc(sizeof(statement*)*num);
	for (i = 0; i < num; i++) {
		pi[i] = (statement*)malloc(sizeof(statement)); //���� �޸� �Ҵ�
		printf("%d��°\n", i + 1);
		printf("�̸�                   : ");
		scanf_s("%s", pi[i]->name, 20);
		printf("�������(ex 1999/12/30): ");
		scanf_s("%d/%d/%d", &pi[i]->birth.year, &pi[i]->birth.month, &pi[i]->birth.day);
		printf("����(����/����)        : ");
		scanf_s("%s", pi[i]->gender, 6);
		printf("��ȭ��ȣ(01012341234)  : ");
		scanf_s("%s", pi[i]->phonenum, 15);
		make_hyphen(pi[i]->phonenum);
	}
	printf("---------------------------------------------------------------------------\n");
	printf(" �̸�\t\t�������\t����\t\t  ��ȭ��ȣ\n");
	printf("---------------------------------------------------------------------------\n");
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t    %s\n",
			pi[i]->name, pi[i]->birth.year, pi[i]->birth.month, pi[i]->birth.day, pi[i]->gender, pi[i]->phonenum);
	}
	printf("\n\n---------------------------------<�̸� ���� ����>---------------------------\n\n");
	namesort(pi, num);
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t    %s\n",
			pi[i]->name, pi[i]->birth.year, pi[i]->birth.month, pi[i]->birth.day, pi[i]->gender, pi[i]->phonenum);
	}
	printf("\n\n--------------------------------<���� ���� ����>---------------------------\n\n");
	birthsort(pi, num);
	for (int i = 0; i < num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t    %s\n",
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