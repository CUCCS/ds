#include "hw-13.h"
int main()
{
	LNode *L;
	LNode *p = InitList(&L);//制造要初始化的线性链表
	PrintList(p);
	LNode *p1;
	LNode *p2;
	SplitList(p, &p1, &p2);
	printf("拆分后的第一个链表\n");
	PrinttCircle_List(p1);
	printf("拆分后的第二个链表\n");
	PrinttCircle_List(p2);
	Destroy(&p1);
	Destroy(&p2);
	return 0;
}


//初始化链表
LNode *InitList(LNode *L)
{
	int i, j;
	printf("链表长度为:\n");
	scanf_s("%d", &i);
	L = (LNode*)malloc(sizeof(LNode));
	L->data = 1;
	L->next = NULL;//创建空链表
	LNode *p;
	p = L;
	for (j = 2; j <= i; j++)
	{
		LNode *l;
		l = (LNode *)malloc(sizeof(LNode));
		l->data = j;//给结点数据域赋值
		p->next = l;
		p = l;
	}
	p->next = NULL;
	return L;
}
//拆分链表
int SplitList(LNode *L, LNode **L1, LNode **L2)
{
	LNode *p, *p1, *p2, *q1, *q2, *temp;
	p = L;//将P指向要拆分的链表L
	p1 = (LNode *)malloc(sizeof(LNode));
	p1->next = NULL;
	p2 = (LNode *)malloc(sizeof(LNode));
	p2->next = NULL;
	q1 = p1;
	q2 = p2;
	int i = 0;
	while (NULL != p)
	{
		i++;
		temp = p;
		p = p->next;
		if (i% 2 == 0)//将偶数存入链表q1
		{
			temp->next = q1->next;
			q1->next = temp;
			q1 = temp;
		}
		//将奇数存入链表q2
		else
		{
			temp->next = q2->next;
			q2->next = temp;
			q2 = temp;
		}
	}
	p1->data = (q1->data) / 2;
	p2->data = (q2->data + 1) / 2;
	q1->next = p1;
	q2->next = p2;
	*L1 = p1;
	*L2 = p2;
	return 0;
}
//输出链表
int PrintList(LNode *L)
{
	do
	{
		printf("%d ", L->data);
		L = L->next;
	} while (L != NULL);
	printf("\n");
	return OK;
}
//输出循环链表
int PrinttCircle_List(LNode *L)
{
	LNode *p;
	printf("链表长度 %d \n", L->data);
	p = L;
	L = L->next;
	printf("表中元素为:\n");
	do
	{
		printf("%d ", L->data);
		L = L->next;
	} while (L != p);
	printf("\n");
	return OK;
}
//销毁链表
int Destroy(LNode **L)
{
	LNode *p;
	int i, j;
	j = (*L)->data + 1;
	for (i = 0; i < j; i++)
	{
		p = (*L);
		(*L) = (*L)->next;
		free(p);
	}
	return OK;
}



