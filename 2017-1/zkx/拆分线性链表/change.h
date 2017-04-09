#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;    //声明变量类型

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;   

}LNode, *LinkList;     //结构体的建立

void CreateList(LinkList L, int n);

void TraverseList_L1(LinkList L);

void TraverseList_L2(LinkList L);

void change(LinkList list, LinkList *list1, LinkList *list2);
