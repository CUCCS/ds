#include "2.12.h"
int main() {
	int n1, n2;
	printf("列表长度：\n");
	srand(time(0));
	n1 = rand() % 10 + 1;
	n2 = rand() % 10 + 1;
	printf("%d %d\n", n1, n2);
	LinkList l1,l2,l3;
	l1 = (LinkList)malloc(sizeof(LNode));
	l2 = (LinkList)malloc(sizeof(LNode));
	l3 = (LinkList)malloc(sizeof(LNode));
	//l1->next = NULL; l2->next = NULL;
	CreateList_L(l1, n1);
	CreateList_L(l2, n2);
	order(l1, n1);
	order(l2, n2);
	printf("链表1：\n");
	PRINT(l1);
	printf("链表2：\n");
	PRINT(l2);

	MergeList_L(l1,l2,l3);
    printf("\n合并链表:\n");
	PRINT(l3);
}