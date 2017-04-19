#include <stdio.h>
#include <stdlib.h>
#include "13.h"

Status CreateList(LinkList L,int n)
{//����һ������
	printf("��������\n");
	L->next = NULL;//ͷ�����Ϊ��
	int i;
	i = 0;
	LinkList a;//�贴���������a
	for(i = n;i > 0; i--)
	{
		a = (LinkList)malloc(sizeof(LNode));//��̬�����µĽ����ڴ�
		a->data = i;//��ʼ������
		a->next = L->next;//��������
		L->next = a;//ʹL��βָ��ָ��a
	}
	printf("�����������\n");
	return OK;//��������ɹ�	
}
Status Traverse(LinkList L)
{//��������
	LinkList b;
	b = (LinkList)malloc(sizeof(LNode));//��̬�����µĽ��
	if(b->next == NULL)//��ֹ����Ϊ��
	{
		return ERROR;//��Ϊ�շ��ش���
	}
	b = L->next;//Lβָ��ָ��b
	while(b->next != NULL)//�ж��Ƿ����
	{
		printf("%d\t",b->data);//�������Ԫ��
		b = b->next;//ָ����һ��Ԫ��
	}
	printf("%d\t",b->next);
	printf("\n");
	printf("��������\n");
	return OK;
}
Status Distribute(LinkList L1,LinkList L2,LinkList L3)
{//������������
	LinkList a = L1; //p1,list1
	LinkList b = L2; //p2,list2
	LinkList c = L3; //p,list
	L1->data = 0;//��ʼL1
	L2->data = 0;//��ʼL2
	c = c->next;//��ʼc��ָ��ָ��
	while(c != NULL)//��c��Ϊ��ʱ
	{
		a->next = c;//a��βָ��ָ��c
		a = a->next;//aָ����һ��Ԫ��
		L1->data++;//L1Ϊdata�Լӵ�ֵ
		c = c->next;//cָ����һ��
		if(c != NULL)//��c��Ϊ��ʱ
		{
			b->next = c;
			b = a->next;
			L2->data++;
			c = c->next;
		}
	}
	a->next = L1;
	b->next = L2;
	return OK;
}
Status Traverse_separate(LinkList L)
{//�����ֿ�������
	LinkList m = L;
	LinkList n = L;
	if(m->next == NULL)//�ж�Ϊ�յ����
	{
		return ERROR;
	}
	printf("������Ϊ%d\n",n->data);
	n = n->next;//ָ����һ��Ԫ��
	while(n->next != m)
	{
		printf("%d\t",n->data);
		if(n->next != NULL)
		{
			n = n->next;
		}
	}
	printf("%d",n->data);
	printf("\n");
	printf("�������\n");
	return OK;
}