#include<stdio.h>
#include<stdlib.h>

#define OK 0
#define ERROR 1
#define OVERFLOW 2

typedef int Elemtype;

typedef struct LNode{
	int data;
	struct LNode  *next;
}LNode,*LinkList;
//创建结构体及结构体指针

void CreateList(LinkList* ,int );
void SortList(LinkList,int);
void Traverse(LinkList );
void MergeList_L(LinkList ,LinkList ,LinkList *);
void ShowList(LinkList *,LinkList *);
