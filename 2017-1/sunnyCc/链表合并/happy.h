#include <stdio.h>

typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;


void CreateList_L(LinkList *L,int n);
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc);
void TraverseList_L(const LinkList L );
