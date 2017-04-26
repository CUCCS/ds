//链表拆分程序
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef int ElemType;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum 
{
	OK,
	ERROR,
	OVERFLOW
} Status;


Status CreateList(LinkList L, int n) 
{
	printf("开始创建初始链表\n");
	L->next = NULL;//头结点；
	int i = 0;
	int num;
	LinkList p;
	for (i = n; i > 0; i--) 
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新结点；
		num = rand() % 101;  //使用随机整数作为链表数据
		p->data = num;
		p->next = L->next;
		L->next = p;
	}
	printf("链表创建完毕\n");
	return OK;
}
Status Traverse(LinkList L) //单链表遍历
{
	LinkList Line;
	Line = (LinkList)malloc(sizeof(LNode));
	if (Line->next == NULL) 
	{
		return ERROR;
	}
	Line = L->next;
	while (Line->next != NULL) 
	{
		printf("%d ", Line->data);
		Line = Line->next;
	}
	printf("%d", Line->data);
	printf("\n遍历结束\n");
	return OK;
}
Status Traverse_loop(LinkList L) //循环链表的遍历
{
	LinkList p = L;
	LinkList q = L;
	if (p->next == NULL) 
	{
		return ERROR;
	}
	printf("链表长度为%d\n", q->data);
	q = q->next;
	while (q->next != p) 
	{
		printf("%d\n", q->data);
		if (q->next != NULL) 
		{
			q = q->next;
		}
	}
	printf("%d", q->data);
	printf("\n遍历结束\n");
	return OK;
}
Status List_Distribute(LinkList list, LinkList list1, LinkList list2) // 链表拆分
{
	LinkList p = list;
	LinkList p1 = list1;
	LinkList p2 = list2;
	list1->data = 0;
	list2->data = 0;
	p = p->next;
	printf("开始进行链表拆分\n");
	while (p != NULL) 
	{
		p1->next = p;
		p1 = p1->next;
		list1->data++;
		p = p->next;
		if (p != NULL) 
		{
			p2->next = p;
			p2 = p1->next;
			list2->data++;
			p = p->next;
		}
	}
	p1->next = list1;
	p2->next = list2;
	printf("链表拆分结束\n");
	return OK;
}

int main() 
{
	LinkList La;
	LinkList L1;
	LinkList L2;
	int n;
	La = (LinkList)malloc(sizeof(LNode));
	L1 = (LinkList)malloc(sizeof(LNode));
	L2 = (LinkList)malloc(sizeof(LNode));

	printf("请输入生成链表长度：");
	scanf("%d", &n);
	CreateList(La, n);

	printf_s("开始遍历原链表La:\n");
	Traverse(La);
	printf("\n");

	List_Distribute(La, L1, L2);
	printf("\n");

	printf("开始遍历奇数链表\n");
	Traverse_loop(L1);
	printf("\n");

	printf("开始遍历偶数链表\n");
	Traverse_loop(L2);
	printf_s("\n");
}