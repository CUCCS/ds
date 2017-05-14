
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList_L(LinkList, int);
void MergeList_L(LinkList, LinkList, LinkList*);
void Order_L(LinkList L);

void output(LinkList);

