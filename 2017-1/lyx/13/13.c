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

	printf("链表长度为%d\n",10);
	printf("Traverse\n");
	Traverse(L);
	printf("遍历完成\n");

	Distribute(L,L1,L2);
	printf("\n");

	printf("遍历奇数链表\n");
	Traverse_separate(L1);
	printf("\n");

	printf("遍历偶数链表\n");
	Traverse_separate(L2);
	printf("\n");

	return 0;
}