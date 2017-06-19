//说明：
//时间复杂度：
//ParitySequence函数在将list线性链表分解成两个循环链表时，只用了一个循环遍历一次线性表。
//其时间复杂度约为O(n)(链表的长度)，此时，时间复杂度应为最小。
//空间复杂度：
//在创建两个循环链表(list1,list2)时，只分别重新动态分配了一个头结点。
//创建两个循环链表的过程，属分解list的过程，list1,list2初头结点外其他结点，没有重新分配空间，而是直接将next指针指向list对应结点。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;


//输出单链表；
Status output(LinkList L){
	LinkList p = L;
	if (!p->next){
		return ERROR;
	}
	while (p->next)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
	return OK;
}

//输出循环单链表的一个周期；
Status output1(LinkList L)
{
	LinkList p = L, m = L;
	if (!p->next)
	{
		return ERROR;
	}
	while (p->next!=m)
	{
		p = p->next;
		printf("%d\n", p->data);
	}
	return OK;
}

//建立一个测试用例（第一个链结点为指针list的链表）
void CreateList_L(LinkList L, int n)
{
	L->data = (int)rand() % 1024;
	L->next = NULL;
	LinkList p;
	int i;
	for (i = 0; i < n - 1; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = (int)rand() % 1024;
		p->next = L->next;
		L->next = p;
		L = L->next;
	}
}

//将线性单链表安奇偶性分解为两个循环链表；
void ParitySequence(LinkList list, LinkList list1, LinkList list2)
{

	LNode*p1 = list1;
	LNode*p2 = list2;
	LNode*p = list;
	list1->data = 0;
	list2->data = 0;
	while (p != NULL)
	{
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if (p != NULL)
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