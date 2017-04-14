#include <stdio.h>
#include <stdlib.h>

#include "List.h"

Status CreateList(LinkList L, int n){
	printf("��ʼ������ʼ����\n");
	L->next = NULL;//ͷ��㣻
	int i = 0;
	LinkList p;
	for (i = n; i > 0; i--){
		p = (LinkList)malloc(sizeof(LNode));//�����½�㣻
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
	printf("���������\n");
	return OK;
}
Status Traverse(LinkList L){
	LinkList Line;
	Line = (LinkList)malloc(sizeof(LNode));
	if(Line->next == NULL){
		return ERROR;
	}
	Line = L->next;
	while (Line->next != NULL){
		printf("%d ", Line->data);
		Line = Line->next;
	}
	printf("%d", Line->data);
	printf("\n��������\n");
	return OK;
}
Status Traverse_loop(LinkList L){
	LinkList p = L;
	LinkList q = L;
	if(p->next == NULL){
		return ERROR;
	}
	printf("������Ϊ%d\n", q->data);
	q = q->next;
	while(q->next != p){
		printf("%d\n", q->data);
		if(q->next != NULL){
			q = q->next;
		}
	}
	printf("%d", q->data);
	printf("\n��������\n");
	return OK;
}
Status List_Distribute(LinkList list,LinkList list1,LinkList list2){
	LinkList p = list;
	LinkList p1 = list1;
	LinkList p2 = list2;
	list1->data = 0;
	list2->data = 0;
	p = p->next;
	printf("��ʼ�����������\n");
	while(p != NULL){
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if(p != NULL){
			p2->next = p;
			p2 = p1->next;
			list2->data++;
			p = p->next;
		}
	}
	p1->next = list1;
	p2->next = list2;
	printf("����������\n");
	return OK;
}