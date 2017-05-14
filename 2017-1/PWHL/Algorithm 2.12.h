#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 5;
#define y 5;
typedef struct component
{
	int data;
	struct component *next;
}component, *SLinkList;
void CreatList(SLinkList &L, int n);
void MergeList_L(SLinkList&La, SLinkList&Lb, SLinkList&Lc);
void output(SLinkList l);
void A(int a[], int n);