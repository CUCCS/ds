#include <stdio.h>
#include <stdlib.h>

# include "List.h"

int main(){
	LinkList La;
	LinkList L1;
	LinkList L2;

	La = (LinkList)malloc(sizeof(LNode));
	L1 = (LinkList)malloc(sizeof(LNode));
	L2 = (LinkList)malloc(sizeof(LNode));

	printf("����������\n%d\n",20);

	CreateList(La, 20);

	printf_s("��ʼ��������La:\n");
	Traverse(La);
	printf("\n");

	List_Distribute(La, L1, L2);
	printf("\n");

	printf("��ʼ������������\n");
	Traverse_loop(L1);
	printf("\n");

	printf("��ʼ����ż������\n");
	Traverse_loop(L2);
	printf_s("\n");
}