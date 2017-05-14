#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  LIST_numa  4;
#define  LIST_numb  4;//对其存储空间进行限定为4
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;//线性表的单链表储存结构。
//对下面函数进行声明
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l);
void assign_value(int a[], int n);



//输入主函数，
int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a =LIST_numa;
	int b =    LIST_numb ;//la的长度和lb的长度均为宏常量，在前面已经被限定为四
	CreatList(la, a);
	output(la);
	CreatList(lb, b);
	output(lb);
	MergeList(la, lb, lc);
	if (lb != NULL)
	{
		free(lb);
	}

	output(lc);
	return 0;

}
//逆序输入n个元素的值，建立代表头节点的单链表
void CreatList(LinkList &L, int n)
{

	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	assign_value(a, n);
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//先建立一个带头结点的单链表
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		p->data = a[n - i];           //输入元素值   
		p->next = L->next; L->next = p; //插入到表头 
	}

}
//已知单链表线性表la和lb的元素按值非递减排列
//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
void MergeList(LinkList&la, LinkList&lb, LinkList&lc)
{	
	LinkList  pa, pb, pc, l = NULL, lc_copy;
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
			pc->next = NULL;

		}//对其La的进行归并当第一次循环中其中一个为空的时候说明归并一个完毕
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			pc->next = NULL;
		}

		lc_copy = lc->next;

		while (lc_copy != NULL)
		{
			printf("%d ", lc_copy->data);
			lc_copy = lc_copy->next;
		}
		printf("\n");//第二个归并完
	
		
	}
	pc->next = pa ? pa : pb;
	lc_copy = lc->next;
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
	// 冒泡排序法对随机数排序
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
		l= l->next;
	}
	printf("\n\n");
}