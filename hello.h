#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  x 5;
#define y 4;
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l);
void assign_value(int a[], int n);



