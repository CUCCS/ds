#pragma once
#include<stdio.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;


void scan(ElemType *);
void CreateList_L(LinkList , int , void(*)(ElemType*));
//�㷨2.11	�½�������

void print(const ElemType);
void TraverseList_L(const LinkList,void(*)(ElemType));

void MergeList_L(LinkList, LinkList, LinkList);
//�㷨2.12	�鲢����������