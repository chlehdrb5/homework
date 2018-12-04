#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
	int value;
	struct node *next;
};
typedef struct node node;
typedef node *link;

link createnode(int num);
link append(link head, link cur);
int printlist(link head);
void midprint(link head, int count);
void reverse_print(link head);
link remove_node(link node);
link evennode(link head);
void allnodefree(link head);

int main() {
	int num = 0, count;
	link head = NULL;
	printf("띄어쓰기로 정수값을 입력하시오 (마지막에 -1을 입력 후 엔터) : ");
	while (1) {
		scanf_s("%d", &num);
		if (num == -1) //
			break;
		head=append(head, createnode(num));
	}
	printf("입력 순으로 출력 : ");
	count = printlist(head);
	printf("\n입력된 자료의 개수 : %d\n", count);
	printf("가운데 입력 값 : ");
	midprint(head, count);
	printf("역순 : ");
	reverse_print(head);
	printf("\n홀수번째 노드 삭제:\n");
	head = evennode(head);
	printf("삭제 결과 : ");
	printlist(head);
	allnodefree(head); // 동적 메모리 해제
	printf("Finish..\n");
	system("pause");
	return 0;
}

link createnode(int num) { // 노드 생성
	link cur;
	cur = (link)malloc(sizeof(node));
	cur->value = num;
	cur->next = NULL;
	return cur;
}

link append(link head, link cur) { // 노드 추가
	link nextnode = head;
	if (head == NULL) {
		head = cur;
		return head;
	}
	while (nextnode->next != NULL) {
		nextnode = nextnode->next;
	}
	nextnode->next = cur;
	return head;
}

int printlist(link head) { //노드 출력 (처음부터 끝까지) 동시에 노드의 개수 카운트
	int count = 0;
	link nextnode = head;
	while (nextnode != NULL) {
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
		count++;
	}
	return count;
}

void midprint(link head,int count) { // 가운데 입력 값 출력 -> count가 짝수면 가운데 두개의 값을 출력
	int half = count / 2;
	link nextnode = head;
	if (count % 2 == 0) {
		for (int i = 1; i < half; i++)
			nextnode = nextnode->next;
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
		printf("%d\n", nextnode->value);
	}
	else {
		for (int i = 1; i <= half; i++)
			nextnode = nextnode->next;
		printf("%d\n", nextnode->value);
	}
}

void reverse_print(link head) { //역순 출력
	if (head->next == NULL) {
		printf("%d ", head->value);
		return;
	}
	reverse_print(head->next);
	printf("%d ", head->value);
}

link remove_node(link node) { //node1, node2, node3 가 있으면 node2를 없애고 node1 -> node3
	if (node->next == NULL){
		return node;
	}
	link xnode = node->next;
	node->next = xnode->next;
	free(xnode);
	return node;
}

link evennode(link head) { //홀수번째 노드를 삭제
	link firstnode = head;
	head = firstnode->next;
	free(firstnode);
	link node = head;
	while (1) {
		node = remove_node(node);
		if (node->next == NULL){
			break;
		}
		node = node->next;
	}
	return head;
}

void allnodefree(link head) { // 모든 동적 메모리 할당 해제
	printf("\n동적 메모리 해제 중...\n");
	link save;
	while (1) {
		save = head->next;
		free(head);
		if (save == NULL){
			break;
		}
		head = save;
	}
}
