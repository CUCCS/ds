#include"List.h"
Status CreateList(LinkList L,int n) {
	//L = (LinkList)malloc(sizeof(LNode));
	LinkList p;
	L->next = NULL;
	L->data = n;
	int i,temp;
	for (i = n; i > 0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		temp = rand() % 100 + 1;
		p->data = temp;
		p->next = L->next; L->next = p;
	}
	return OK;
}
Status SperateList(LinkList L, LinkList L1, LinkList L2, int n) {
	LinkList p = L->next;
	LinkList p1 = L1->next = (LinkList)malloc(sizeof(LNode));
	LinkList p2 = L2->next = (LinkList)malloc(sizeof(LNode));
	int n1=0, n2=0;
	for (int i = 0; i < n; i++) {
		switch ((i+1) % 2) {
		case 1:
			p1->next = (LinkList)malloc(sizeof(LNode));
			p1->data = p->data;
			p1 = p1->next;
			n1++;
			break;
		case 0:
			p2->next = (LinkList)malloc(sizeof(LNode));
			p2->data = p->data;
			p2 = p2->next;
			n2++;
			break;
		}
		p = p->next;
	}
	L1->data = n1;
	L2->data = n2;
	p1 = L1;
	p2 = L2;
	return OK;
}
void PRINT(LinkList L)

{
	LinkList p = L->next;
	int n = L->data;
	for (int i = 0; i < n;i++){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}