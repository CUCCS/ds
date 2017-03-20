#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIST_A_NUM 4;
#define LIST_B_NUM 4;
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l, int n);
void assign_value(int a[],int n);//随机给数组赋值