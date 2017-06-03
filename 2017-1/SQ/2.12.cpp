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
	printf("����A��B��Ԫ�ظ���: ");
	scanf("%d%d",&m, &n);
	printf("����A��Ԫ��ֵ: ");
	for (j = 1; j <= m; ++j)
	{
		i = Malloc_SL(space);
		scanf("%d", &(*space)[i].data);
		(*space)[r].cur = i;
		r = i;
	}
	(*space)[r].cur = 0;
	printf("����B��Ԫ��ֵ: ");
	for (j = 1; j <= n; ++j) {          //ʵ�ʲ����ǽ�B��Ԫ�ز���A
		scanf("%d", &b);
		p = S;
		k = (*space)[S].cur;
		while (k != (*space)[r].cur&&(*space)[k].data != b)   //���Ҹ�Ԫ��
		{
			p = k;
			k = (*space)[k].cur;
		}
		if (k == (*space)[r].cur) {                 //����Ԫ��
			i = Malloc_SL(space);
			(*space)[i].data = b;
			(*space)[i].cur = (*space)[r].cur;
			(*space)[r].cur = i;
		} 
		else
		{
			(*space)[p].cur = (*space)[k].cur;      //ɾ��Ԫ��
			Free_SL(space, k);
			if (r == k)               //ɾ������r��ָ�ڵ㣬�޸�βָ��
				r = p;
		}
	}
	return S;//����ͷ���
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

int Create_L(SLinkList *space,int n,int &S) {     //����Ԫ�ظ���Ϊn���������
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
	int Sa, Sb, S;     //ͷ���

	srand(time(NULL));

	InitSpace_SL(&La);
	InitSpace_SL(&Lb);

	printf("�������������������Ҫ��Ԫ�ظ����� ");
	scanf("%d", &n);

	Sa = Create_L(&La, n, Sa);
	Sb = Create_L(&Lb, n, Sb);

	printf("����һ�� ");
	PrintList(&La,Sa);
	printf("������� ");
	PrintList(&Lb,Sb);

	printf("\n�������(A-B)��(B-A)\n");
	S = difference(&L, S);
	printf("(A-B)��(B-A)�Ľ��Ϊ��");
	PrintList(&L, S);

}