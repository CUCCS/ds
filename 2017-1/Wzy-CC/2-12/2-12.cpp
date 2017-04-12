//#include <stdio.h>            //ͷ�ļ�
//typedef struct LNode          //�ṹ��LNode��ʾͷ�ڵ�
//{
//	int data;
//	struct LNode *next;
//}LNode, *ListList;            //���Ҽ���ָ���ʾ
//void CreateList_L(LinkList&L, int n)//����һ�����Ա�������
//{
//	L = (LinkList)malloc(sizeof(LNode));
//	L���� > next = NULL;
//	for (i = n; i > 0; ����i)
//	{
//		p = (Listlist)malloc(sizeof(LNode));
//		scanf(&p���� > data);
//		p->next = L->next;
//		L->next = p;
//	}
//}
//void MergeList_L(LinkList&La, LinkList&Lb, LinkList&Lc)//�ϲ����Ա���
//{
//	pa = La->next;
//	pb = Lb->next;
//	Lc = pc = La;
//	while (pa&&pb)
//	{
//		if (pa->data <= pb->data)
//		{
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//		}
//		else
//		{
//			pc->next = pb; pc = pb; pb = pb->next;
//		}
//	}
//	pc->next = pa ? pa : pb;
//	free(Lb);
//}
//int main
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "List.h"
typedef int ElemType;
//��ElemType��Ϊint��
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
void creatList(LinkList &L, int n);
//����������������������ĳ���Ա�����
void Traverse(LinkList &L);
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc);
void creatList(LinkList &L, int n) {
	printf("\nCreatList:\n");
	printf("��ʼ��������Ϊ%d�ĵ�����\n", n);
	int i;
	int number = 20;
	LinkList p = NULL;
	L->next = NULL;
	for (i = n; i>0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		number = number - (rand() % n + 1);
		p->data = number;
		p->next = L->next;
		L->next = p;
	}
	printf("���������\n");
}

void Traverse(LinkList &L) {
	LinkList a = L;
	a = a->next;
	while (a) {
		printf("%d", a->data);
		printf(" ");
		a = a->next;
	}
	printf("\n");
	printf("�������");
}

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
	printf("MergeList\n");
	printf("��ʼ�鲢����La��Lb\n");
	LinkList pa, pb, pc;

	pa = pb = pc = NULL;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;

	while (pa&&pb) {
		printf("pa��pb����Ϊ������,ѭ������ִ��\n");
		printf("pa->data(%d)%spb->data(%d),����\n", pa->data, pa->data <= pb->data ? "<=" : ">", pb->data);
		if (pa->data <= pb->data) {
			printf("pc->next=pa(%x),pc=pa(%x),pa=pa->next(%x)\n", pa, pa, pa->next);
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			printf("pc->next=pa(%x),pc=pa(%x),pb=pb->next(%x)\n", pb, pb, pa->next);
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	printf("pa��pb��������һ��Ϊ�գ�ѭ����ֹ\n");
	pc->next = pa ? pa : pb;
	free(Lb);
	printf("�ͷ�����Lb\n");
	printf("�鲢�������\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define length 5

int main() {
	LinkList La;
	LinkList Lb;
	LinkList Lc;
	//����LinkList���͵����Ա�la,lb,lc
	printf("������ʼִ��\n\n");
	srand(time(0));
	//����
	La = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ��������La\n");
	creatList(La, length + rand() % 5);
	//����la
	printf("������La���б���");
	printf("\nLa:");
	Traverse(La);
	//����La
	printf("\n\n");

	Lb = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ��������Lb\n");
	creatList(Lb, length + rand() % 5);
	printf("������Lb���б���");
	printf("\nLb:");
	Traverse(Lb);
	printf("\n\n");

	printf("\n");
	MergeList(La, Lb, Lc);
	printf("�ϲ��������LcΪ:");
	Traverse(Lc);
	printf("\n");
	return 0;
}//������