#include "2.12.h"

//�㷨2-11 �����½�������
void CreateList_L(LinkList L, int n)//��λ������n��ֵ��������ͷָ��ĵ������Ա�L��
{

	L->next = NULL;//ͷ��㣻
	int i = 0;
	LinkList p;
	
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½�㣻
		p->data = (int)rand()%1024;
		//scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;//��λ��
	}
}

//�㷨2-12 �鲢����������
void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList pc;
	LinkList pa, pb, p;
	pa = La->next;
	pb = Lb->next;
	(*Lc) = pc = La;
	printf("�鲢����\n");
	while (pa&&pb)//pa,pb����=NULL,��La->next,Lb->next!=null,La,Lb����û�н�����
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
	pc->next = pa ? pa : pb;//�������while;
}

//���������������
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

//���������
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



