#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;    //������������

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;   

}LNode, *LinkList;     //�ṹ��Ľ���

void CreateList(LinkList L, int n);

void TraverseList_L1(LinkList L);

void TraverseList_L2(LinkList L);

void change(LinkList list, LinkList *list1, LinkList *list2);
