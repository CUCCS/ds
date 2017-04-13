#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "S.h"

ElemType GetElem(LinkList *L, int i) { //返回第i个元素的值
	LinkList *p;
	int j;
	p = L;
	for (j = 0; j != i; j++) {
		p = p->next;
	}
	return p->data;
}
LinkList* CreateList(LinkList *L, int n) { //构建大小为n的随机数单链表,返回头指针
	LinkList *list, *p, *q ;
	int i;
	list= (LinkList *)malloc(sizeof(LinkList));
	list->data = n;
	list->next = NULL;
	for (i = 0; i < n; i++) {
		p = (LinkList *)malloc(sizeof(LinkList));
		if (!p) {
			exit(0);
		}
		p->data = (int)rand() % 100;
		if (list->next == NULL) {
			list ->next= p;
			q = p;
		}
		else {
			q->next = p;
			q = p;
		}
	}
	if (list != NULL) {
		q->next = NULL;
	}
	L = list;
	return list;
}
LinkList* ListInsert(LinkList *L, ElemType e) { //在链表末尾添加元素e
	LinkList *p, *q;
	q = (LinkList *)malloc(sizeof(LinkList));
	p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	q->data = e;
	q->next = NULL;
	p->next = q;
	return L;
}
LinkList* Connect(LinkList *L) { //首尾相连，构成循环链表
	LinkList *p;
	p = L;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = L;
	return L;
}
Status Traverse(LinkList *L) {
	LinkList *p;
	if (ListEmpty(L)) {
		return ERROR;
	}
	p = L->next;
	while (p && p != L) {
		printf("%4d", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status DestroyList(LinkList *L) {
	LinkList *p;
	if (ListEmpty(L)) {
		return ERROR;
	}
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
	printf("\nThe Original List has been destoryed.\n");
	return OK;
}
bool ListEmpty(LinkList *L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
}
int InputSize() { //输入原始链表的大小
	int n = 0;
	do {
		if (n == 0) {
			printf("Please input a positive integer: ");
		}
		scanf("%d", &n);
		if (n <= 0) {
			printf("Error! The size of the list can't be less than zero\n");
			printf("Please input a positive integer again:");
		}
	} while (n <= 0);
	return n;
}


int main() {
	LinkList *L, *La, *Lb;
	int i, n, temp;
	srand(time(NULL));
	n = InputSize();
	L = CreateList(&L, n);
	if (!ListEmpty(L)) {
		printf("\nThe numbers of List are:");
		Traverse(L);
	}
	else{
		exit(0);
	}
	La = (LinkList *)malloc(sizeof(LinkList));
	Lb = (LinkList *)malloc(sizeof(LinkList));
	if (n % 2 == 0) {
		La->data = Lb->data= n / 2;
		La->next = Lb->next = NULL;
		for (i = 1; i <= n; i++) {
			temp = GetElem(L, i);
			if (i % 2 != 0) {
				La = ListInsert(La, temp);
			}
			else {
				Lb = ListInsert(Lb, temp);
			}
		}
	}
	else {
		La->data = (n + 1) / 2;
		Lb->data = (n - 1) / 2;
		La->next = Lb->next = NULL;
		for (i = 1; i <= n; i++) {
			temp = GetElem(L, i);
			if (i % 2 != 0) {
				La = ListInsert(La, temp);
			}
			else {
				Lb = ListInsert(Lb, temp);
			}
		}
	}
	printf("\nThe size of List 1 is: %d", Lb->data);
	printf("\nThe List 1 is:");
	Lb = Connect(Lb);
	Traverse(Lb);
	printf("\nThe size of List 2 is: %d", La->data);
	printf("\nThe List 2 is:");
	La = Connect(La);
	Traverse(La);
	DestroyList(L);
	return 0;
}