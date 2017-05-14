#include "算法2.12.h"
void CreatList(Linklist *L, int n)//逆位序输入n个元素的值,建立带表头结点的单链线性表L
{
	int i;
	Linklist p;
	int *a = (int *)malloc(sizeof(int)*n);
	A(a, n);
	(*L) = (Linklist)malloc(sizeof(LNode));
	(*L)->next = NULL;//先建立一个带头结点的单链表
	for (i = n; i > 0; i--)
	{
		p = (Linklist )malloc(sizeof(LNode));//生成新的结点
		p->data = a[n - i];
		p->next = (*L)->next;
		(*L)->next = p;//插入到表头
	}
	free(a);
}
void output(Linklist s)
{
	s = s->next;
	printf("\nthe List is:\n");
	while (s != NULL)
	{
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n\n");
}
void MergeList_L(Linklist La, Linklist Lb, Linklist *Lc)
{
	//已知单链线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
	Linklist l,pa,pb,pc;
	 pa = La->next;
	 pb = Lb->next;
	 (*Lc) = pc = La;
	while (pa&&pb) //判断pa和pb是否为空
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;//将Pa赋给Pc，将Pa的地址给Pc,Pa指向下一个相邻结点
			pc->next = NULL;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;//将Pb赋给Pc，将Pa的地址给Pc,Pb指向下一个相邻结点
			pc->next = NULL;

		}
		l = (*Lc)->next;
		while (l != NULL)
		{
			printf("%d ", l->data);
			l = l->next;
		}
		printf("\n");
	}
	pc->next = pa ? pa : pb;
	l = (*Lc)->next;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
}//MergeList


void A(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 + 1;//产生随机数
	for (i = 0; i < n - 1; i++)//冒泡排序,将随机数排序
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
	}
}

void destroyList(Linklist s)
{
	Linklist l;
	while (s != NULL)
	{
		l = s->next;
		free(s);
		s = l;
	}
}
int main()
{
	srand(time(0));
	Linklist La, Lb, Lc;
	int a = x;
	int b = y;
	CreatList(&La, a);
	output(La);
	printf("\n");
	CreatList(&Lb, a);
	output(Lb);
	printf("\n");
	MergeList_L(La, Lb, &Lc);
	output(Lc);
	destroyList(Lb);
	return 0;
}