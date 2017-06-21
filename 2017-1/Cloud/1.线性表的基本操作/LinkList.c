#include "LinkList.h"

/* 链表的遍历 */
void TraverseList(LinkList p) {
	LinkList l = p;
	l = l->next;
	while ( l != p) {
		printf("%d ",l->data);
		l = l->next;
	}
	printf("\n");
}

/* 创建链表 */
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

/*初始化链表*/
void InitList(LinkList a) {
	LinkList p = a;
	for (; p->next != a; p = p->next) {
		p->data = 0;

	}
}

/* 拆分链表 */
void SeparateList(LinkList A, LinkList b, LinkList c) {
//算法分析：算法的的时间复杂度为 O（n），空间复杂度为O（1），
//在保证算法的正确性的前提下，使用了最少的时间复杂度和最少的空间复杂度
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



