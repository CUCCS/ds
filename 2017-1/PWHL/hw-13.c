#include "hw-13.h"
int main()
{
	LNode *L;
	LNode *p = InitList(&L);//����Ҫ��ʼ������������
	PrintList(p);
	LNode *p1;
	LNode *p2;
	SplitList(p, &p1, &p2);
	printf("��ֺ�ĵ�һ������\n");
	PrinttCircle_List(p1);
	printf("��ֺ�ĵڶ�������\n");
	PrinttCircle_List(p2);
	Destroy(&p1);
	Destroy(&p2);
	return 0;
}


//��ʼ������
LNode *InitList(LNode *L)
{
	int i, j;
	printf("������Ϊ:\n");
	scanf_s("%d", &i);
	L = (LNode*)malloc(sizeof(LNode));
	L->data = 1;
	L->next = NULL;//����������
	LNode *p;
	p = L;
	for (j = 2; j <= i; j++)
	{
		LNode *l;
		l = (LNode *)malloc(sizeof(LNode));
		l->data = j;//�����������ֵ
		p->next = l;
		p = l;
	}
	p->next = NULL;
	return L;
}
//�������
int SplitList(LNode *L, LNode **L1, LNode **L2)
{
	LNode *p, *p1, *p2, *q1, *q2, *temp;
	p = L;//��Pָ��Ҫ��ֵ�����L
	p1 = (LNode *)malloc(sizeof(LNode));
	p1->next = NULL;
	p2 = (LNode *)malloc(sizeof(LNode));
	p2->next = NULL;
	q1 = p1;
	q2 = p2;
	int i = 0;
	while (NULL != p)
	{
		i++;
		temp = p;
		p = p->next;
		if (i% 2 == 0)//��ż����������q1
		{
			temp->next = q1->next;
			q1->next = temp;
			q1 = temp;
		}
		//��������������q2
		else
		{
			temp->next = q2->next;
			q2->next = temp;
			q2 = temp;
		}
	}
	p1->data = (q1->data) / 2;
	p2->data = (q2->data + 1) / 2;
	q1->next = p1;
	q2->next = p2;
	*L1 = p1;
	*L2 = p2;
	return 0;
}
//�������
int PrintList(LNode *L)
{
	do
	{
		printf("%d ", L->data);
		L = L->next;
	} while (L != NULL);
	printf("\n");
	return OK;
}
//���ѭ������
int PrinttCircle_List(LNode *L)
{
	LNode *p;
	printf("������ %d \n", L->data);
	p = L;
	L = L->next;
	printf("����Ԫ��Ϊ:\n");
	do
	{
		printf("%d ", L->data);
		L = L->next;
	} while (L != p);
	printf("\n");
	return OK;
}
//��������
int Destroy(LNode **L)
{
	LNode *p;
	int i, j;
	j = (*L)->data + 1;
	for (i = 0; i < j; i++)
	{
		p = (*L);
		(*L) = (*L)->next;
		free(p);
	}
	return OK;
}



