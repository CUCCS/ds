#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include"2.12.h"

void InitSpace_SL(SLinkList *space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; ++i)
		(*space)[i].cur = i + 1;
	(*space)[MAXSIZE - 1].cur = 0;
}

int Malloc_SL(SLinkList *space) {
	int i;
	i = (*space)[0].cur;
	if ((*space)[0].cur)
		(*space)[0].cur = (*space)[i].cur;
	return i;
}

int LocateElem_SL(SLinkList S, ElemType e) {
	int i;
	i = S[0].cur;
	while (i&&S[i].data != e)
		i = S[i].cur;
	return i;
}

void Free_SL(SLinkList *space, int k) {
	(*space)[k].cur = (*space)[0].cur;
	(*space)[0].cur = k;
}

int difference(SLinkList *space, int &S) {
	int i, j, m, n;
	int b, p, k, r;
	InitSpace_SL(space);
	S = Malloc_SL(space);
	r = S;
	printf("输入A和B的元素个数: ");
	scanf("%d%d",&m, &n);
	printf("输入A的元素值: ");
	for (j = 1; j <= m; ++j)
	{
		i = Malloc_SL(space);
		scanf("%d", &(*space)[i].data);
		(*space)[r].cur = i;
		r = i;
	}
	(*space)[r].cur = 0;
	printf("输入B的元素值: ");
	for (j = 1; j <= n; ++j) {          //实际操作是将B中元素插入A
		scanf("%d", &b);
		p = S;
		k = (*space)[S].cur;
		while (k != (*space)[r].cur&&(*space)[k].data != b)   //查找该元素
		{
			p = k;
			k = (*space)[k].cur;
		}
		if (k == (*space)[r].cur) {                 //插入元素
			i = Malloc_SL(space);
			(*space)[i].data = b;
			(*space)[i].cur = (*space)[r].cur;
			(*space)[r].cur = i;
		} 
		else
		{
			(*space)[p].cur = (*space)[k].cur;      //删除元素
			Free_SL(space, k);
			if (r == k)               //删除的是r所指节点，修改尾指针
				r = p;
		}
	}
	return S;//返回头结点
}

void PrintList(SLinkList *space,int n) {
	int p = (*space)[n].cur;
	while (p)
	{
		printf("%d ", (*space)[p].data);
		p = (*space)[p].cur;
	}
	printf("\n");
}

int Create_L(SLinkList *space,int n,int &S) {     //创建元素个数为n的随机链表
	int i, r;
	InitSpace_SL(space);
	S = Malloc_SL(space);
	r = S;
	for (i = 1; i <= n+1; i++) {
		i = Malloc_SL(space);
		(*space)[i].data = (int)rand() % 1024;
		(*space)[r].cur = i;
		r = i;
	}
	(*space)[r].cur = 0;
	return S;
}

int main()
{
	SLinkList La, Lb;
	SLinkList L;
	int n;
	int Sa, Sb, S;     //头结点

	srand(time(NULL));

	InitSpace_SL(&La);
	InitSpace_SL(&Lb);

	printf("建立随机链表，输入所需要的元素个数： ");
	scanf("%d", &n);

	Sa = Create_L(&La, n, Sa);
	Sb = Create_L(&Lb, n, Sb);

	printf("链表一： ");
	PrintList(&La,Sa);
	printf("链表二： ");
	PrintList(&Lb,Sb);

	printf("\n获得链表(A-B)∪(B-A)\n");
	S = difference(&L, S);
	printf("(A-B)∪(B-A)的结果为：");
	PrintList(&L, S);

}