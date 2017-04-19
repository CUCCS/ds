#include <stdio.h>
#include <stdlib.h>

#include "2.12.h"

void CreateList_L(LinkList L) {                  //�������룬�������Ϊ����
	int i, n;
	LinkList p;
	scanf("%d", &n);
	printf("��������Ԫ�أ� ");
	L->next = NULL;
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	printf("��ǰ���������\n\n");
}

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {    //�鲢��������Ϊ������LC
	LinkList pa, pb, pc;
	pa = La->next;
	pb = Lb->next;
	(*Lc) = pc = La;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}

void PrintList(const LinkList L) {     //���������Ԫ��
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%2d ", p->data);
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

	printf("��������1�Ĵ�С�� ");
	CreateList_L(La);

	printf("��������2�Ĵ�С�� ");
	CreateList_L(Lb);

	printf("����һ�� ");
	PrintList(La);

	printf("������� ");
	PrintList(Lb);

	printf("�鲢��������");
	MergeList_L(La, Lb, &Lc);
	PrintList(Lc);

}