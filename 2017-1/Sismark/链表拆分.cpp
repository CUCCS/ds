#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define OK 0
#define ERROR 1
#define NEWNODE (LinkList)malloc(sizeof(LNode))
typedef int ElemType;
typedef int Status;

typedef struct LNode {//结点
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

Status CreateList_L(LinkList *pL, int n) {
	int i;
	*pL = NEWNODE;
	(*pL)->next = NULL;
	(*pL)->data = 0;
	LinkList temp;
	LinkList p;
	p = *pL;
	for (i = 0; i < n; i++) {
		temp = NEWNODE;
		temp->data = 0;
		temp->next = NULL;
		
		temp->data = rand()%101;

		p->next = temp;
		p = p->next;

	}
	return OK;
}
Status SplitLink(LinkList *pL, LinkList *pL1, LinkList *pL2) {
	int num = 0;
	LinkList p;
	LinkList p1;
	LinkList p2;
	*pL1= NEWNODE;
	*pL2 = NEWNODE;
	printf("建造两个链表\n");
	(*pL1)->next = (*pL2)->next = NULL;
	(*pL1)->data = (*pL2)->data = 0;
	printf("pL1=0x%p\n", pL1);
	printf("pL2=0x%p\n", pL2);
	p = (*pL)->next;
	p1 = *pL1;
	p2 = *pL2;
	printf("开始拆分\n");
	while (p) {
		printf("p=0x%p\n",p);
		//创建新节点
		LinkList temp = NEWNODE;
		temp->next = NULL;
		temp->data = 0;
		//给节点赋值
		temp->data = p->data;
		//把节点归并到新链表
		p1->next = temp;
		p1 = p1->next;
		p = p->next;
		printf("p1->data=%d\n", p1->data);
		if (!p) break;

		temp = NEWNODE;
		temp->next = NULL;
		temp->data = 0;
		//给节点赋值
		temp->data = p->data;
		//把节点归并到新链表
		p2->next = temp;
		p2 = p2->next;
		p = p->next;
		printf("p2->data=%d\n",p2->data);
	}
	return OK;
}
Status Traverse(LinkList *pL) {
	*pL = (*pL)->next;
	while (*pL) {
		printf("%d ", (*pL)->data);
		*pL = (*pL)->next;
	}
	printf("\n");
	return 0;
}
int main() {
	srand(time(NULL));
	int n = rand()%10;
	printf("n=%d\n",n);
	LinkList L;
	LinkList L1;
	LinkList L2;
	CreateList_L(&L, n);
	SplitLink(&L, &L1, &L2);
	printf("L=");
	Traverse(&L);
	printf("L1=");
	Traverse(&L1);
	printf("L2=");
	Traverse(&L2);
	return 0;
}