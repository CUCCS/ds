#include "Linklist.h"

Status InitList(Linklist* pL, const int length) {
	int i;/*ѭ������*/
	Node* p;/*ָ��ڵ��ָ�� , ���빹������*/

			/*�������*/
	checkNull(pL, "pL");

	if (length == 0) { (*pL) = NULL; return OK; }
	(*pL) = NEWNODE;
	checkOverflow(*pL, "*pL");
	(*pL)->data = rd(MINNUM, MAXNUM);
	(*pL)->next = (*pL)->prev = *pL;
	if (length == 1) { return OK; }

	/*ѭ������ڵ�*/
	times(i, length - 1) {
		p = NEWNODE;
		checkOverflow(p, "p");
		p->data = rd(MINNUM, MAXNUM);
		p->next = (*pL);
		p->prev = (*pL)->prev;
		(*pL)->prev->next = p;
		(*pL)->prev = p;
	}
	return OK;
}
Status TraverseList(const Linklist L) {
	Node* p;/*ָ��ڵ��ָ�� , ���ڱ�������L*/

	if (!L) {
		printf("(empty)\n");
		return OK;
	}

	p = L;
	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != L);
	printf("\n");
	return OK;
}
Status Insert(Linklist* pL, Elemtype data) {
	Node *p;/*ָ���½ڵ��ָ��*/

			/*�������*/
	checkNull(pL, "pL");

	p = NEWNODE;
	checkOverflow(p, "p");
	p->data = data;
	if (!(*pL)->next) {
		p->prev = p->next = p;
		(*pL)->next = p;
	}
	else {
		p->next = (*pL)->next;
		p->prev = (*pL)->next->prev;
		(*pL)->next->prev->next = p;
		(*pL)->next->prev = p;
	}
	return OK;
}
Status DivideList(Linklist list, Linklist* pL1, Linklist* pL2) {
	Node *p;/* ָ��ڵ��ָ�� , ���ڱ���list */
	Node *p1;/* ָ��ڵ��ָ�� , ���ڱ���*pL1 */
	Node *p2;/* ָ��ڵ��ָ�� , ���ڱ���*pL2 */

	/*�������*/
	checkNull(pL1, "pL1");
	checkNull(pL2, "pL2");

	debug_print("====�������====\n");
	debug_print("���������� : ");
	DEBUG && TraverseList(list);
	debug_print("��ʼ��� \n");

	*pL1 = NEWNODE;
	(*pL1)->data = 0;
	(*pL1)->prev = (*pL1)->next = NULL;
	p1 = *pL1;
	*pL2 = NEWNODE;
	(*pL2)->data = 0;
	(*pL2)->prev = (*pL2)->next = NULL;
	p2 = *pL2;

	p = list;
	if (!p) { return OK; }
	do {
		p1->next = p;
		p1->next->prev = p1;
		p1 = p1->next;
		++(*pL1)->data;
		debug_print("������ , ���������1 , �ڵ�����Ϊ %d \n", p->data);
		p = p->next;
		if (p == list) { break; }

		p2->next = p;
		p2->next->prev = p2;
		p2 = p2->next;
		++(*pL2)->data;
		debug_print("ż���� , ���������2 , �ڵ�����Ϊ %d \n", p->data);
		p = p->next;
	} while (p != list);

	p1->next = (*pL1)->next;
	p2->next = (*pL2)->next;
	if (p1->next) {
		p1->next->prev = p1;
	}
	if (p2->next) {
		p2->next->prev = p2;
	}
	return OK;
}