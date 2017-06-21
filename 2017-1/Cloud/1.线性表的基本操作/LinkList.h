#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#define length 10

typedef  struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum {
	true,
	false
}bool;

/* ����ı��� */
void TraverseList(LNode * p);

/* �������� */
LinkList CreatList(int n);

/* ������� */
void SeparateList(LinkList A, LinkList b, LinkList c);

/*��ʼ������*/
void InitList(LinkList);

#endif