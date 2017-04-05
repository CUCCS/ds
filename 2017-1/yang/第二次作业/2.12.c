#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//����������
#define N 4
#define M 5
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//��������
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
//����ϲ�
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
//��������
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
	//��������ĳ�����ȷ��
	printf("��һ��������Ϊ4���ڶ���������Ϊ5\n");
	CreateList_L(La, N);
	CreateList_L(Lb, M);
	printf("����LaΪ��");
	print(La);
	printf("\n����LbΪ��");
	print(Lb);
	MergeList_L(La, Lb, Lc);
	printf("\n�ϲ�����Ϊ��");
	print(La);
}