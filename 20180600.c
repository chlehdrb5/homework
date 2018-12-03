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
	printf("����� �������� �Է��Ͻÿ� (�������� -1�� �Է� �� ����) : ");
	while (1) {
		scanf_s("%d", &num);
		if (num == -1) //
			break;
		head=append(head, createnode(num));
	}
	printf("�Է� ������ ��� : ");
	count = printlist(head);
	printf("\n�Էµ� �ڷ��� ���� : %d\n", count);
	printf("��� �Է� �� : ");
	midprint(head, count);
	printf("���� : ");
	reverse_print(head);
	printf("\nȦ����° ��� ����:\n");
	head = evennode(head);
	printf("���� ��� : ");
	printlist(head);
	allnodefree(head); // ���� �޸� ����
	printf("Finish..\n");
	system("pause");
	return 0;
}

link createnode(int num) { // ��� ����
	link cur;
	cur = (link)malloc(sizeof(node));
	cur->value = num;
	cur->next = NULL;
	return cur;
}

link append(link head, link cur) { // ��� �߰�
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

int printlist(link head) { //��� ��� (ó������ ������) ���ÿ� ����� ���� ī��Ʈ
	int count = 0;
	link nextnode = head;
	while (nextnode != NULL) {
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
		count++;
	}
	return count;
}

void midprint(link head,int count) { // ��� �Է� �� ��� -> count�� ¦���� ��� �ΰ��� ���� ���
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

void reverse_print(link head) { //���� ���
	if (head->next == NULL) {
		printf("%d ", head->value);
		return;
	}
	reverse_print(head->next);
	printf("%d ", head->value);
}

link remove_node(link node) { //node1, node2, node3 �� ������ node2�� ���ְ� node1 -> node3
	if (node->next == NULL)
		return node;
	link xnode = node->next;
	node->next = xnode->next;
	free(xnode);
	return node;
}

link evennode(link head) { //Ȧ����° ��带 ����
	link firstnode = head;
	head = firstnode->next;
	free(firstnode);
	link node = head;
	while (1) {
		node = remove_node(node);
		if (node->next == NULL)
			break;
		node = node->next;
	}
	return head;
}

void allnodefree(link head) { // ��� ���� �޸� �Ҵ� ����
	printf("\n���� �޸� ���� ��...\n");
	link save;
	while (1) {
		save = head->next;
		free(head);
		if (save == NULL)
			break;
		head = save;
	}
}