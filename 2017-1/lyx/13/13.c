#include <stdio.h>
#include <stdlib.h>
#include "13.h"
int main ()
{
	LinkList L;
	LinkList L1;
	LinkList L2;
	L = (LinkList)malloc(sizeof(LNode)); 
    L1 = (LinkList)malloc(sizeof(LNode)); 
	L2 = (LinkList)malloc(sizeof(LNode)); 

	printf("������Ϊ%d\n",10);
	printf("Traverse\n");
	Traverse(L);
	printf("�������\n");

	Distribute(L,L1,L2);
	printf("\n");

	printf("������������\n");
	Traverse_separate(L1);
	printf("\n");

	printf("����ż������\n");
	Traverse_separate(L2);
	printf("\n");

	return 0;
}