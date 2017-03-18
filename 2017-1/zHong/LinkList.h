#pragma once
#include<stdio.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;


void scan(ElemType *);
void print(const ElemType);

void CreateList_L(LinkList , int , void(*)(ElemType*));
void MergeList_L(LinkList, LinkList, LinkList);
void TraverseList_L(const LinkList, void(*)(ElemType));