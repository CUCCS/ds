#include<stdio.h>
#include"Header.h"
#include<stdlib.h>

int main()
{
	int i,j;
	LinkList L1,L2,Lc;

	L1 =(LinkList) malloc(sizeof(LNode));
	L2 =(LinkList) malloc(sizeof(LNode));

	printf("L1中值得个数：");
	scanf("%d",&i);
	CreateList(&L1,i);
	sortList(L1,i);
	Traverse(L1);
	printf("\n");

	printf("L2中值得个数：");
	scanf("%d",&j);
	CreateList(&L2,j);
	sortList(L2,j);
	Traverse(L2);
	printf("\n");

	MergeList_L(L1,L2,&Lc);
	Traverse(Lc);
	return OK;
}

