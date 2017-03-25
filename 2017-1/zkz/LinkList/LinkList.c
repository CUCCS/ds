#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

Status CreateList(LinkList L, const int len) {
	L->next = NULL;
	Node *p, *pL = L;
	int i = 0;
	int randBase = RANDBASE;

	DEBUG && printf("��ʼ��������Ϊ %d ������ \n", len);
	while (++i <= len) {
		/*Step 1 �½��ڵ�*/
		p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 Ϊ�½ڵ㸳ֵ*/
		p->data = randBase +=
			rand() % (RANDMAXINCREMENT - RANDMININCREMENT + 1) + RANDMININCREMENT;
		DEBUG && printf("��%02d���ڵ�����ݱ������ֵΪ %d \n", i, p->data);

		p->next = NULL;

		/*Step 3 ���½ڵ�ϲ���������*/
		pL->next = p;
		pL = pL->next;

	}/*end while*/
	DEBUG && printf("����Ϊ %d ����������� \n\n", len);

	return OK;
}/*end CreateList*/
Status TravelList(const LinkList L) {
	if (!L)
		return ERROR;
	Node * pL = L->next;
	while (pL) {
		printf("%d ", pL->data);
		pL = pL->next;
	}
	return OK;
}
Status MergeList(LinkList La, LinkList Lb, LinkList Lc) {
	Node * pa = La->next, *pb = Lb->next, *pc = Lc;
	DEBUG && printf("��ʼ�鲢����La��Lb��Lc��\n");
	while (pa&&pb) {
		/*Step 1 �½��ڵ�*/
		Node * p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 Ϊ�½ڵ㸳ֵ*/
		p->next = NULL;
		DEBUG && printf("����pa->data( %d ) %s pb->data( %d ) , ", pa->data, pa->data <= pb->data ? "<=" : "> ", pb->data);
		if (pa->data <= pb->data) {
			p->data = pa->data; pa = pa->next;
		}
		else {
			p->data = pb->data; pb = pb->next;
		}
		DEBUG && printf("�½ڵ�����ݱ���ֵΪ %d \n", p->data);
		/*Step 3 ���½ڵ�ϲ���������*/
		pc->next = p;
		pc = pc->next;
	}//end while
	 /*���pa��pb��Ϊ�գ������нڵ��Ѽ����������鲢�������*/
	if (!pa && !pb) {
		DEBUG && printf("pa��pb��Ϊ�գ��鲢�������\n");
		return OK;
	}
	DEBUG && printf("%s��Ϊ�գ���ʣ�ಿ�ָ��Ƶ�Lc��\n", pa ? "pa" : "pb");
	Node * pr = pa ? pa : pb;
	while (pr) {
		/*Step 1 �½��ڵ�*/
		Node * p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 Ϊ�½ڵ㸳ֵ*/
		p->next = NULL;
		p->data = pr->data;
		DEBUG && printf("�½ڵ�����ݱ���ֵΪ %d \n", p->data);
		pr = pr->next;
		/*Step 3 ���½ڵ�ϲ���������*/
		pc->next = p;
		pc = pc->next;
	}//end while
	DEBUG && printf("�鲢�������\n\n");
	return OK;
}