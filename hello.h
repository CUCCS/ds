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
void output(LinkList l, int n);// ����ϲ����������֤�Ƿ���ȷ�ϲ�
void output(LinkList l);//����ϲ�ǰ������
void assign_value(int a[]);//��������鸳ֵ
