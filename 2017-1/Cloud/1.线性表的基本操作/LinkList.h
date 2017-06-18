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

/* 链表的遍历 */
void TraverseList(LNode * p);

/* 创建链表 */
LinkList CreatList(int n);

/* 拆分链表 */
void SeparateList(LinkList A, LinkList b, LinkList c);

/*初始化链表*/
void InitList(LinkList);

#endif