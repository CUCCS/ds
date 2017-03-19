#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l, int n);// 输出合并后的表格，验证是否正确合并


int main()
{
	LinkList la, lb, lc;
	int a, b;
	scanf("%d", &a);
	CreatList(la, a);
	scanf("%d", &b);
	CreatList(lb, a);
	MergeList(la, lb, lc);
	lc = lc->next;
	output(lc, a + b);
	return 0;

}
void CreatList(LinkList &L, int n)
{
	//逆序输入n个元素的值，建立单链表
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));//头节点
	L->next = NULL;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		scanf("%d", &p->data);//输入元素值   
		p->next = L->next; L->next = p; //插入到表头 
	}

}
void MergeList(LinkList&la, LinkList&lb, LinkList&lc)
{
	//已知单链表线性表la和lb的元素按值非递减排列
	//合并后的链lc 仍然按值非递减排列
	LinkList  pa, pb, pc, l = NULL;
	pa = la->next;
	pb = lb->next;
	lc = pc = la;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		//厉害了  我的算法；
	}
	pc->next = pa ? pa : pb;
	free(lb);
}
void output(LinkList  l, int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		printf("%d  ", l->data);
		l = l->next;

	}
}
