#include "2.12.h"
int main() {
	int n1, n2;
	printf("���������������б��ȣ�\n");
	scanf_s("%d %d", &n1, &n2);
	LinkList l1,l2,l3;
	l1 = (LinkList)malloc(sizeof(LNode));
	l2 = (LinkList)malloc(sizeof(LNode));
	l3 = (LinkList)malloc(sizeof(LNode));
	//l1->next = NULL; l2->next = NULL;
	CreateList_L(l1, n1);
	CreateList_L(l2, n2);
	printf("����1��\n");
	PRINT(l1);
	printf("����2��\n");
	PRINT(l2);
	MergeList_L(l1,l2,l3);
    printf("\n�ϲ�����:\n");
	PRINT(l3);
}