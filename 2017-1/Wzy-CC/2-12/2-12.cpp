//#include <stdio.h>            //头文件
//typedef struct LNode          //结构体LNode表示头节点
//{
//	int data;
//	struct LNode *next;
//}LNode, *ListList;            //并且加了指针表示
//void CreateList_L(LinkList&L, int n)//创建一个线性表（函数）
//{
//	L = (LinkList)malloc(sizeof(LNode));
//	L—— > next = NULL;
//	for (i = n; i > 0; ——i)
//	{
//		p = (Listlist)malloc(sizeof(LNode));
//		scanf(&p—— > data);
//		p->next = L->next;
//		L->next = p;
//	}
//}
//void MergeList_L(LinkList&La, LinkList&Lb, LinkList&Lc)//合并线性表函数
//{
//	pa = La->next;
//	pb = Lb->next;
//	Lc = pc = La;
//	while (pa&&pb)
//	{
//		if (pa->data <= pb->data)
//		{
//			pc->next = pa;
//			pc = pa;
//			pa = pa->next;
//		}
//		else
//		{
//			pc->next = pb; pc = pb; pb = pb->next;
//		}
//	}
//	pc->next = pa ? pa : pb;
//	free(Lb);
//}
//int main
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "List.h"
typedef int ElemType;
//将ElemType设为int？
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
void creatList(LinkList &L, int n);
//创建函数中有两个参数：某线性表，长度
void Traverse(LinkList &L);
void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc);
void creatList(LinkList &L, int n) {
	printf("\nCreatList:\n");
	printf("开始创建长度为%d的单链表\n", n);
	int i;
	int number = 20;
	LinkList p = NULL;
	L->next = NULL;
	for (i = n; i>0; i--) {
		p = (LinkList)malloc(sizeof(LNode));
		number = number - (rand() % n + 1);
		p->data = number;
		p->next = L->next;
		L->next = p;
	}
	printf("链表创建完毕\n");
}

void Traverse(LinkList &L) {
	LinkList a = L;
	a = a->next;
	while (a) {
		printf("%d", a->data);
		printf(" ");
		a = a->next;
	}
	printf("\n");
	printf("遍历完成");
}

void MergeList(LinkList &La, LinkList &Lb, LinkList &Lc) {
	printf("MergeList\n");
	printf("开始归并链表La和Lb\n");
	LinkList pa, pb, pc;

	pa = pb = pc = NULL;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;

	while (pa&&pb) {
		printf("pa与pb都不为空链表,循环继续执行\n");
		printf("pa->data(%d)%spb->data(%d),所以\n", pa->data, pa->data <= pb->data ? "<=" : ">", pb->data);
		if (pa->data <= pb->data) {
			printf("pc->next=pa(%x),pc=pa(%x),pa=pa->next(%x)\n", pa, pa, pa->next);
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			printf("pc->next=pa(%x),pc=pa(%x),pb=pb->next(%x)\n", pb, pb, pa->next);
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	printf("pa与pb中至少有一个为空，循环终止\n");
	pc->next = pa ? pa : pb;
	free(Lb);
	printf("释放链表Lb\n");
	printf("归并链表结束\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define length 5

int main() {
	LinkList La;
	LinkList Lb;
	LinkList Lc;
	//三个LinkList类型的线性表la,lb,lc
	printf("函数开始执行\n\n");
	srand(time(0));
	//种子
	La = (LinkList)malloc(sizeof(LNode));
	printf("开始创建链表La\n");
	creatList(La, length + rand() % 5);
	//创建la
	printf("对链表La进行遍历");
	printf("\nLa:");
	Traverse(La);
	//遍历La
	printf("\n\n");

	Lb = (LinkList)malloc(sizeof(LNode));
	printf("开始创建链表Lb\n");
	creatList(Lb, length + rand() % 5);
	printf("对链表Lb进行遍历");
	printf("\nLb:");
	Traverse(Lb);
	printf("\n\n");

	printf("\n");
	MergeList(La, Lb, Lc);
	printf("合并后的数组Lc为:");
	Traverse(Lc);
	printf("\n");
	return 0;
}//主函数