#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//限制链表长度
#define N 4
#define M 5
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//创建链表
void CreateList_L(LinkList L, ElemType n)
{
	LinkList p;
	ElemType a;
	//a = EnterData(n);
	L->next = NULL;
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a);
		p = (LinkList)malloc(sizeof(LNode));
		p->data = a;
		p->next = L->next;
		L->next = p;
	}
}
//链表合并
void MergeList_L(LinkList La, LinkList Lb, LinkList Lc)
{
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	Lc = La;
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
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}
//遍历链表
void print(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList La, Lb, Lc;
	La = (LinkList)malloc(sizeof(LNode));
	Lb = (LinkList)malloc(sizeof(LNode));
	Lc = (LinkList)malloc(sizeof(LNode));
	//两个链表的长度已确定
	printf("第一个链表长度为4，第二个链表长度为5\n");
	CreateList_L(La, N);
	CreateList_L(Lb, M);
	printf("链表La为：");
	print(La);
	printf("\n链表Lb为：");
	print(Lb);
	MergeList_L(La, Lb, Lc);
	printf("\n合并后结果为：");
	print(La);
}