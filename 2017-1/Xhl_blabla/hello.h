#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  LIST_NUM_A 4;
#define LIST_NUM_B 4;
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;
void CreatList(LinkList  *L, int n);
void MergeList(LinkList la, LinkList lb, LinkList *c);
void output(LinkList l);
void assign_value(int a[], int n);
void destoryList(LinkList);





