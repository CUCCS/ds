#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l, int n);// 输出合并后的链表，验证是否正确合并
void output(LinkList l);//输出合并前的链表
void assign_value(int a[]);//随机给数组赋值
