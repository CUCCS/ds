#include "hello.h"
int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a = LIST_NUM_A;
	int b = LIST_NUM_B;//la的长度和lb的长度均为宏常量
	CreatList(&la, a);
	output(la);
	CreatList(&lb, b);
	output(lb);
	MergeList(la, lb, &lc);
	output(lc);
	destoryList(lb);
	return 0;
}

//逆序输入n个元素的值，建立单链表
void CreatList(LinkList *L, int n)
{

	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	assign_value(a, n);
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));//头节点
	(*L)->next = NULL;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		p->data = a[n - i];           //输入元素值   
		p->next = (*L)->next;
		(*L)->next = p; //插入到表头 
	}
	free(a);
}

//已知单链表线性表la和lb的元素按值非递减排列
//合并后的链lc 仍然按值非递减排列
void MergeList(LinkList la, LinkList lb, LinkList *lc)
{
	LinkList  pa, pb, pc, l = NULL, lc_copy;
	pa = la->next;
	pb = lb->next;
	(*lc) = pc = la;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pc->next = NULL;

		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			pc->next = NULL;
		}

		lc_copy = (*lc)->next;

		while (lc_copy != NULL)
		{
			printf("%d ", lc_copy->data);
			lc_copy = lc_copy->next;
		}
		printf("\n");

		//厉害了  我的算法；
	}
	pc->next = pa ? pa : pb;
	lc_copy = (*lc)->next;
	while (lc_copy != NULL)
	{
		printf("%d ", lc_copy->data);
		lc_copy = lc_copy->next;
	}
	printf("\n");
}
//产生随机数，并进行排序
void assign_value(int a[], int n)
{
	int i, j, temp;
	//产生随机数
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 20 + 1;
	}
	// 冒泡法对随机数排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
		}
	}
}
//输出链表
void output(LinkList  l)
{
	l = l->next;
	printf("\nthe List is:\n");

	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n\n");
}
//对链表执行销毁
void destoryList(LinkList  l)
{
	LinkList  p;

	while (NULL != l)
	{
		p = l->next;
		free(l);
		l = p;
	}

}