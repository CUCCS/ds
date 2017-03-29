#include "2.12.h"

//算法2-11 逆序新建单链表
void CreateList_L(LinkList L, int n)//逆位序输入n个值，建立带头指针的单链线性表L；
{

	L->next = NULL;//头结点；
	int i = 0;
	LinkList p;
	
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新结点；
		p->data = (int)rand()%1024;
		//scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;//逆位序；
	}
}

//算法2-12 归并两个单链表
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList pc;
	LinkList pa, pb, p;
	pa = La->next;
	pb = Lb->next;
	(*Lc) = pc = La;
	printf("归并过程\n");
	while (pa&&pb)//pa,pb链表！=NULL,即La->next,Lb->next!=null,La,Lb链表没有结束；
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

		output(*Lc);
		printf("\n");

	}
	pc->next = pa ? pa : pb;//结合上述while;
}

//将单链表进行排序
void Order_L(LinkList L)
{
	L = L->next;
	int i, j;
	LinkList La = L;
	LinkList Lb = La;
	while (La)
	{
		while (Lb->next)
		{
			Lb = Lb->next;
			if (La->data>Lb->data)
			{
				ElemType p;
				p = La->data;
				La->data = Lb->data;
				Lb->data = p;
			}
		}
		La = La->next;
		Lb = La;
	}
}

//输出单链表
void output(LinkList L)
{
	LinkList Line;
	Line = L->next;
	while (Line->next != NULL)
	{
		printf("%d ", Line->data);
		Line = Line->next;
	}
	printf("%d", Line->data);
	/*int i;
	for(i=n;i>0;i--)*/
}



