/*
���� ���� ó�� ( �Է� ���� ��� )
����ü �迭(10��)
�Է� 5~10��
����� 3������
- �׳� �״��
- �̸� ����(�̸� ��������)
- ������� ���� ���� ������ ����(������� ��������)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//Choi Dong Kyu
void sortfun(struct single p[], int i, int j);
void nameswap(struct single p[], int num);
void birthswap(struct single p[], int num);

struct birth {
	int year;
	int month;
	int day;
};

struct single {
	char name[20];
	struct birth birth;
	char gender[3];
	char place[70];
	char phonenum[15];
};

int main() {
	struct single people[10];
	int data_num;
	printf("�Է��� �������� ���� (10������) : ");
	scanf_s("%d", &data_num);
	for (int i = 0; i < data_num; i++) {
		printf("%d��°\n", i + 1);
		printf("�̸�                   : ");
		scanf_s("%s", people[i].name, 20);
		printf("�������(ex 1999 12 30): ");
		scanf_s("%d %d %d", &people[i].birth.year, &people[i].birth.month, &people[i].birth.day);
		printf("����(��:B ,��:G )      : ");
		scanf_s("%s", people[i].gender, 3);
		printf("�ּ�(����� ���۱�)    : ");
		scanf_s(" %[^\n]", people[i].place, 70);
		printf("��ȭ��ȣ(010-1234-1234): "); // 02-000-0000 ���� ��ȣ�� �־ '-'�� �����Է��ϰ� �߽��ϴ�!
		scanf_s("%s", people[i].phonenum, 15);
	}
	printf("--------------------------------------------------------------------------------------\n");
	printf(" �̸�\t\t�������\t����\t\t�ּ�\t\t\t  ��ȭ��ȣ\n");
	printf("--------------------------------------------------------------------------------------\n");
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t     %s\t\t %s\n",
			people[i].name, people[i].birth.year, people[i].birth.month, people[i].birth.day, people[i].gender, people[i].place, people[i].phonenum);
	}
	printf("\n\n-------------------------------------<�̸� ���� ����>----------------------------------\n\n");
	nameswap(people, data_num);
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t     %s\t\t %s\n",
			people[i].name, people[i].birth.year, people[i].birth.month, people[i].birth.day, people[i].gender, people[i].place, people[i].phonenum);
	}
	printf("\n\n-------------------------------------<���� ���� ����>----------------------------------\n\n");
	birthswap(people, data_num);
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d�� %d�� %d��\t %s\t     %s\t\t %s\n",
			people[i].name, people[i].birth.year, people[i].birth.month, people[i].birth.day, people[i].gender, people[i].place, people[i].phonenum);
	}
	printf("\n\n---------------------------------------------------------------------------------------\n");
	system("pause");
	return 0;
}

void sortfun(struct single p[], int i, int j) {
	struct single memory;
	memory = p[i];
	for (int k = i; k > j; k--) {
		p[k] = p[k - 1];
	}
	p[j] = memory;
}

void nameswap(struct single p[], int num) {
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (strcmp(p[i].name, p[j].name)>0) {
				sortfun(p, i, j);
			}
		}
	}
}

void birthswap(struct single p[], int num) {
	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (p[i].birth.year < p[j].birth.year) {
				sortfun(p, i, j);
			}
			else if (p[i].birth.year == p[j].birth.year) {
				if (p[i].birth.month < p[j].birth.month) {
					sortfun(p, i, j);
				}
				else if (p[i].birth.month == p[j].birth.month) {
					if (p[i].birth.day < p[j].birth.day) {
						sortfun(p, i, j);
					}
				}
			}
		}
	}
}