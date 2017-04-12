#include <stdio.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

void creatList(LinkList L,int n);
void Traverse(LinkList L);
void MergeList(LinkList La,LinkList Lb,LinkList Lc);