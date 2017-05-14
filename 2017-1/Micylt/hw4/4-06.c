//�����ֳ���
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef int ElemType;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum 
{
	OK,
	ERROR,
	OVERFLOW
} Status;


Status CreateList(LinkList L, int n) 
{
	printf("��ʼ������ʼ����\n");
	L->next = NULL;//ͷ��㣻
	int i = 0;
	int num;
	LinkList p;
	for (i = n; i > 0; i--) 
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½�㣻
		num = rand() % 101;  //ʹ�����������Ϊ��������
		p->data = num;
		p->next = L->next;
		L->next = p;
	}
	printf("���������\n");
	return OK;
}
Status Traverse(LinkList L) //���������
{
	LinkList Line;
	Line = (LinkList)malloc(sizeof(LNode));
	if (Line->next == NULL) 
	{
		return ERROR;
	}
	Line = L->next;
	while (Line->next != NULL) 
	{
		printf("%d ", Line->data);
		Line = Line->next;
	}
	printf("%d", Line->data);
	printf("\n��������\n");
	return OK;
}
Status Traverse_loop(LinkList L) //ѭ������ı���
{
	LinkList p = L;
	LinkList q = L;
	if (p->next == NULL) 
	{
		return ERROR;
	}
	printf("������Ϊ%d\n", q->data);
	q = q->next;
	while (q->next != p) 
	{
		printf("%d\n", q->data);
		if (q->next != NULL) 
		{
			q = q->next;
		}
	}
	printf("%d", q->data);
	printf("\n��������\n");
	return OK;
}
Status List_Distribute(LinkList list, LinkList list1, LinkList list2) // ������
{
	LinkList p = list;
	LinkList p1 = list1;
	LinkList p2 = list2;
	list1->data = 0;
	list2->data = 0;
	p = p->next;
	printf("��ʼ����������\n");
	while (p != NULL) 
	{
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if (p != NULL) 
		{
			p2->next = p;
			p2 = p1->next;
			list2->data++;
			p = p->next;
		}
	}
	p1->next = list1;
	p2->next = list2;
	printf("�����ֽ���\n");
	return OK;
}

int main() 
{
	LinkList La;
	LinkList L1;
	LinkList L2;
	int n;
	La = (LinkList)malloc(sizeof(LNode));
	L1 = (LinkList)malloc(sizeof(LNode));
	L2 = (LinkList)malloc(sizeof(LNode));

	printf("���������������ȣ�");
	scanf("%d", &n);
	CreateList(La, n);

	printf_s("��ʼ����ԭ����La:\n");
	Traverse(La);
	printf("\n");

	List_Distribute(La, L1, L2);
	printf("\n");

	printf("��ʼ������������\n");
	Traverse_loop(L1);
	printf("\n");

	printf("��ʼ����ż������\n");
	Traverse_loop(L2);
	printf_s("\n");
}