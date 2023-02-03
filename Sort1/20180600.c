/*
개인 명세서 처리 ( 입력 정렬 출력 )
구조체 배열(10개)
입력 5~10개
출력을 3가지로
- 그냥 그대로
- 이름 정렬(이름 내림차순)
- 생년월일 나이 많은 순으로 정렬(출생연도 오름차순)
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
	printf("입력할 데이터의 개수 (10개이하) : ");
	scanf_s("%d", &data_num);
	for (int i = 0; i < data_num; i++) {
		printf("%d번째\n", i + 1);
		printf("이름                   : ");
		scanf_s("%s", people[i].name, 20);
		printf("생년월일(ex 1999 12 30): ");
		scanf_s("%d %d %d", &people[i].birth.year, &people[i].birth.month, &people[i].birth.day);
		printf("성별(남:B ,여:G )      : ");
		scanf_s("%s", people[i].gender, 3);
		printf("주소(서울시 동작구)    : ");
		scanf_s(" %[^\n]", people[i].place, 70);
		printf("전화번호(010-1234-1234): "); // 02-000-0000 같은 번호도 있어서 '-'를 직접입력하게 했습니다!
		scanf_s("%s", people[i].phonenum, 15);
	}
	printf("--------------------------------------------------------------------------------------\n");
	printf(" 이름\t\t생년월일\t성별\t\t주소\t\t\t  전화번호\n");
	printf("--------------------------------------------------------------------------------------\n");
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t     %s\t\t %s\n",
			people[i].name, people[i].birth.year, people[i].birth.month, people[i].birth.day, people[i].gender, people[i].place, people[i].phonenum);
	}
	printf("\n\n-------------------------------------<이름 순서 정렬>----------------------------------\n\n");
	nameswap(people, data_num);
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t     %s\t\t %s\n",
			people[i].name, people[i].birth.year, people[i].birth.month, people[i].birth.day, people[i].gender, people[i].place, people[i].phonenum);
	}
	printf("\n\n-------------------------------------<생일 순서 정렬>----------------------------------\n\n");
	birthswap(people, data_num);
	for (int i = 0; i < data_num; i++) {
		printf(" %s\t  %d년 %d월 %d일\t %s\t     %s\t\t %s\n",
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