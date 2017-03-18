#pragma once
#include<stdio.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;


void scan(ElemType *);
void CreateList_L(LinkList , int , void(*)(ElemType*));
//算法2.11	新建单链表

void print(const ElemType);
void TraverseList_L(const LinkList,void(*)(ElemType));

void MergeList_L(LinkList, LinkList, LinkList);
//算法2.12	归并两个单链表