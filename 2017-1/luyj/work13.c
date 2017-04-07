#include "work13.h"

Status output(LinkList L)
{
	LinkList p = L;
	if (L->next == NULL)
	{
		return ERROR;
	}
	LinkList Line;
	Line = L;
	while (Line->next != NULL)
	{
		printf("%d", Line->data);
		printf("\n");
		if (Line->next != NULL)
		{
			Line = Line->next;
		}
	}
	printf("%d", Line->data);
	return OK;
}

Status output1(LinkList L)
{
	LinkList p = L;
	if (L->next == NULL)
	{
		return ERROR;
	}
	LinkList Line;
	Line = L;
	while (Line->next !=p)
	{
		printf("%d", Line->data);
		printf("\n");
		if (Line->next != NULL)
		{
			Line = Line->next;
		}
	}
	printf("%d", Line->data);
	return OK;
}
//建立一个测试线性链表（第一个链结点为指针list的链表）
void CreateList_L(LinkList L, int n)
{
	LinkList L1 = L;
	L1->data = (int)rand() % 1024;
	LinkList p;
	int i;
	for (i = 0; i < n-1; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));  //生成新结点；
		p->data = (int)rand() % 1024;
		L1->next= p;
		L1 = L1->next;
		p->next=NULL;
	}
}


void ParitySequence(LinkList list,LinkList list1,LinkList list2)
{
	
	
	LNode*p1 = list1;
	LNode*p2 = list2;
	LNode*p = list;
	list1->data = 0;
	list2->data = 0;
	while (p!=NULL)
	{
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if (p!= NULL)
		{
			p2->next = p;
			p2 = p2->next;
			list2->data++;
			p = p->next;
		}
	}
	p1->next = list1;
	p2->next = list2;
}

