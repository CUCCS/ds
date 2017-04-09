#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;
Status CreateList(LinkList , int );
Status SperateList(LinkList, LinkList, LinkList, int);
void PRINT(LinkList L);

