#include <stdio.h>
#include <stdlib.h>

#include "2.12.h"

void CreateList_L(LinkList L) {                  //逆序输入，否则输出为逆序
	int i, n;
	LinkList p;
	scanf("%d", &n);
	printf("输入链表元素： ");
	L->next = NULL;
	for (i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
	printf("当前链表构造完成\n\n");
}

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc) {    //归并两个链表为新链表LC
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

void PrintList(const LinkList L) {     //遍历并输出元素
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

	printf("输入链表1的大小： ");
	CreateList_L(La);

	printf("输入链表2的大小： ");
	CreateList_L(Lb);

	printf("链表一： ");
	PrintList(La);

	printf("链表二： ");
	PrintList(Lb);

	printf("归并两个链表：");
	MergeList_L(La, Lb, &Lc);
	PrintList(Lc);

}