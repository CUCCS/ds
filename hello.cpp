#include"hello.h"

int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a=4, b=4;//la的长度和lb的长度均为4
	CreatList(la, a);
	output(la);
	CreatList(lb, b);
	output(lb);
	MergeList(la, lb, lc);
	free(lb);
	lc = lc->next;
	output(lc, a + b);
	return 0;

}
void CreatList(LinkList &L, int n)
{
	//逆序输入n个元素的值，建立单链表
	int i;
	int a[4];
	assign_value(a);
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
	
}
void assign_value(int a[])
{
	int i ,j,temp ;
	//产生随机数
	for (i = 0; i < 4; i++)
	{
		a[i]=rand() % 20 + 1;
	}
   // 冒泡法对随机数排序
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3- i; j++)
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
void output(LinkList  l, int n)
{
	int i;
	printf("\nthe List is:\n");
	for (i = n; i > 0; i--)
	{
		printf("%d  ", l->data);
		l = l->next;

	}
}
void output(LinkList l)
{
	int i;
	l = l->next;
	printf("\nthe List:\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d  ", l->data);
		l = l->next;
	}
}
