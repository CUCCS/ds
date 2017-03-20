#include "hello.h"
int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a = LIST_A_NUM;
	int b = LIST_B_NUM;//la的长度和lb的长度均为宏常量
	CreatList(la, a);

	output(la,a);
	CreatList(lb, b);
	
	output(lb,b);
	MergeList(la, lb, lc);
	if (lb != NULL)
	{
      free(lb);
	}
	
	output(lc, a + b);
	return 0;

}
//逆序输入n个元素的值，建立单链表
void CreatList(LinkList &L, int n)
{
	
	int i;
	int *a=(int*)malloc(sizeof(int)*n);
	assign_value(a,n);
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));//头节点
	L->next = NULL;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		p->data = a[n - i];           //输入元素值   
		p->next = L->next; L->next = p; //插入到表头 
	}

}
//已知单链表线性表la和lb的元素按值非递减排列
	//合并后的链lc 仍然按值非递减排列
void MergeList(LinkList&la, LinkList&lb, LinkList&lc)
{
	int  j, i=1,k1,k2;//打印时用于输出计数
	LinkList  pa, pb, pc, l = NULL,lc_copy;
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
		lc_copy = lc->next ;
		for (j = 0; j < i; j++)
		{
		
			printf("%d ", lc_copy->data);
			lc_copy=lc_copy->next;
		}
		printf("\n");
		i++;
		//厉害了  我的算法；
	}
	pc->next = pa ? pa : pb;
	lc_copy = lc->next;
	k1 = LIST_A_NUM;
	k2 = LIST_B_NUM;
	k1 = k1 + k2;
	for (i = 0; i <k1; i++)
	{
		printf("%d ", lc_copy->data);
		lc_copy = lc_copy->next;
	}
	printf("\n");
}
//产生随机数，并进行排序
void assign_value(int a[],int n)
{
	int i, j, temp;
	//产生随机数
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 20 + 1;
	}
	// 冒泡法对随机数排序
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1 - i; j++)
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
void output(LinkList  l, int n)
{
	int i;
	printf("\nthe List is:\n");
    l = l->next;
	for (i = n; i > 0; i--)
	{
		printf("%d  ", l->data);
		l = l->next;

	}
	printf("\n\n");
}
