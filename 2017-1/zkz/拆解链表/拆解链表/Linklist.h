#pragma once

#include <stdlib.h>
#include "Status.h"

#define NEWNODE (Node*)malloc(sizeof(Node))
#define MAXNUM 99
#define MINNUM 10
/*rd : 返回一个不小于Min且不大于Max的随机数*/
#define rd(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
#define DEBUG 1
#define debug_print(...) if(DEBUG){printf(__VA_ARGS__);}

typedef int Elemtype;
typedef struct _Node {
	Elemtype data;
	struct _Node* prev;
	struct _Node* next;
}Node,*Linklist;

/*初始化链表*/
/*pL : 待初始化链表的地址*/
/*length : 链表长度*/
Status InitList(Linklist* pL, const int length);
/*遍历打印链表*/
/*L : 待遍历链表*/
Status TraverseList(const Linklist L);
/*在表尾插入元素*/
/*pL : 待插入链表的地址*/
/*data : 待插入数据*/
Status Insert(Linklist* pL, Elemtype data);

/*拆解链表*/
/*将一个链表中的奇偶项分别拆分到两个新的链表中*/
/*list : 待分解链表*/
/*pL1 : 存放奇数项的链表的头节点地址*/
/*pL2 : 存放偶数项的链表的头节点地址*/
Status DivideList(Linklist list, Linklist* pL1, Linklist* pL2);