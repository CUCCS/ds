#include "LinkList.h"

/* ����ı��� */
void TraverseList(LinkList p) {
	LinkList l = p;
	l = l->next;
	while ( l != p) {
		printf("%d ",l->data);
		l = l->next;
	}
	printf("\n");
}

/* �������� */
LinkList CreatList( int n) {
	LNode *L,* p;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = L;
	L->data = n;
	if (!L)
		exit(1);
	for (i = 0; i < n ; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)
			exit(1);
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
	return L;
}

/*��ʼ������*/
void InitList(LinkList a) {
	LinkList p = a;
	for (; p->next != a; p = p->next) {
		p->data = 0;

	}
}

/* ������� */
void SeparateList(LinkList A, LinkList b, LinkList c) {
//�㷨�������㷨�ĵ�ʱ�临�Ӷ�Ϊ O��n�����ռ临�Ӷ�ΪO��1����
//�ڱ�֤�㷨����ȷ�Ե�ǰ���£�ʹ�������ٵ�ʱ�临�ӶȺ����ٵĿռ临�Ӷ�
	LinkList p = A,p1 = b,p2 = c;
	InitList(b);
	InitList(c);
	p = p->next;
	p1 = p1->next;
	p2 = p2->next;
	while ( p != A) {
		p1->data = p->data;
		b->data++;
		p1 = p1->next;
		p = p->next;
		if (p != A) {
			p2->data = p->data;
			c->data++;
			p2 = p2->next;
			p = p->next;
		}
	}
	return;
}



