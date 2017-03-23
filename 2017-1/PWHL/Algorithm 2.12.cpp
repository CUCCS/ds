 #include "Algorithm 2.12.h"
void CreatList(SLinkList &L, int n)//逆位序输入n个元素的值,建立带表头结点的单链线性表L
{
	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	A(a, n);
	SLinkList p;
	L = (SLinkList)malloc(sizeof(component));
	L->next = NULL;//先建立一个带头结点的单链表
	for (i = n; i > 0; --i)
	{
		p = (SLinkList)malloc(sizeof(component));//生成新的结点
		p->data = a[n - i];//输入元素值
		p->next = L->next;
		L->next = p;//插入到表头
	}

}
void output(SLinkList b)
{

	b = b->next;
	printf("\nthe List is:\n");
	while (b != NULL)
	{
		printf("%d ", b->data);
		b = b->next;
	}
	printf("\n\n");
}
void MergeList_L(SLinkList &La, SLinkList &Lb, SLinkList &Lc) {
	//已知单链线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
	SLinkList l;
	SLinkList pa = La->next;
	SLinkList pb = Lb->next;
	SLinkList pc = Lc = La;
	while (pa&&pb) {//判断pa和pb是否为空

		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa;
			pa = pa->next;//将Pa赋给Pc，将Pa的地址给Pc,Pa指向下一个相邻结点
		}
		else
		{
			pc->next = pb; pc = pb; pb = pb->next;//将Pb赋给Pc，将Pa的地址给Pc,Pb指向下一个相邻结点
		}
		l = Lc->next;
		while (l != NULL)
		{
			printf("%d ", l->data);
			l = l->next;
		}
		printf("\n");
	}
	pc->next = pa ? pa : pb;//插入剩余段
	l = Lc->next;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}//MergeList
void A(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 + 1;//产生随机数
	for (i = 0; i < n - 1; i++)//冒泡排序
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
int main()
{
	srand(time(0));
	SLinkList La, Lb, Lc;
	int a = x;
	int b = y;
	CreatList(La, a);
	output(La);
	printf("\n");
	CreatList(Lb, a);
	output(Lb);
	printf("\n");
	MergeList_L(La, Lb, Lc);
	if (Lb != NULL)
	{
		free(Lb);
	}
	output(Lc);
	return 0;
}