#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

Status CreateList(LinkList L, const int len) {
	L->next = NULL;
	Node *p, *pL = L;
	int i = 0;
	int randBase = RANDBASE;

	DEBUG && printf("开始创建长度为 %d 的链表 \n", len);
	while (++i <= len) {
		/*Step 1 新建节点*/
		p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 为新节点赋值*/
		p->data = randBase +=
			rand() % (RANDMAXINCREMENT - RANDMININCREMENT + 1) + RANDMININCREMENT;
		DEBUG && printf("第%02d个节点的数据被随机赋值为 %d \n", i, p->data);

		p->next = NULL;

		/*Step 3 将新节点合并到链表中*/
		pL->next = p;
		pL = pL->next;

	}/*end while*/
	DEBUG && printf("长度为 %d 的链表创建完毕 \n\n", len);

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
	DEBUG && printf("开始归并链表La与Lb到Lc中\n");
	while (pa&&pb) {
		/*Step 1 新建节点*/
		Node * p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 为新节点赋值*/
		p->next = NULL;
		DEBUG && printf("由于pa->data( %d ) %s pb->data( %d ) , ", pa->data, pa->data <= pb->data ? "<=" : "> ", pb->data);
		if (pa->data <= pb->data) {
			p->data = pa->data; pa = pa->next;
		}
		else {
			p->data = pb->data; pb = pb->next;
		}
		DEBUG && printf("新节点的数据被赋值为 %d \n", p->data);
		/*Step 3 将新节点合并到链表中*/
		pc->next = p;
		pc = pc->next;
	}//end while
	 /*如果pa与pb均为空，则所有节点已加入新链表，归并操作完成*/
	if (!pa && !pb) {
		DEBUG && printf("pa与pb均为空，归并操作完成\n");
		return OK;
	}
	DEBUG && printf("%s不为空，将剩余部分复制到Lc中\n", pa ? "pa" : "pb");
	Node * pr = pa ? pa : pb;
	while (pr) {
		/*Step 1 新建节点*/
		Node * p = NEWNODE;
		if (!p)
			return OVERFLOW;
		/*Step 2 为新节点赋值*/
		p->next = NULL;
		p->data = pr->data;
		DEBUG && printf("新节点的数据被赋值为 %d \n", p->data);
		pr = pr->next;
		/*Step 3 将新节点合并到链表中*/
		pc->next = p;
		pc = pc->next;
	}//end while
	DEBUG && printf("归并操作完成\n\n");
	return OK;
}