#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 5;
#define y 5;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *Linklist;
void CreatList(Linklist *L, int n);
void MergeList_L(Linklist La, Linklist Lb, Linklist *Lc);
void output(Linklist s);
void A(int a[], int n);
void destroyList(Linklist);
