//算法2.12   静态单链表   游标（指示器cur）

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define OK 0
#define ERROR 1
#define OVERFLOW 2

typedef int ElemType;

typedef struct {
	ElemType data;
	int cur;
}component, SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList &spcae);            //初始化

int Malloc_SL(SLinkList &spcae);                //返回分配的节点坐标

int LocateElem_SL(SLinkList S, ElemType e);     //查找第一个为e的元素

void Free_SL(SLinkList &space, int k);          //将下标为k的空闲节点回收

int difference(SLinkList &space, int &S);       //获得链表(A-B)∪(B-A),返回S（新链表的头结点）

void Print_L(SLinkList &space, int i);          //输出链表

int Create_L(SLinkList *space, int n, int &S);  //创建元素个数为n的随机链表