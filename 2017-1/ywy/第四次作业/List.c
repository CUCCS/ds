#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"List.h"
Status CreatList(Linklist L,int n)
{
	printf("创建长度为%d的链表：\n",n);
	L->next = NULL;
    Linklist p;
	Elemtype i;
	for (i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(Node));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
	return ok;
}
Status TravelList(Linklist L)
{
	printf("遍历链表：\n");
	Linklist p ;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return ok;
}
Status chaifen(Linklist List, Linklist L1, Linklist L2)
{
	int count = 0;
	printf("拆分链表： \n");
	L1->data = 0;
	L2->data = 0;
	L1->next = L2->next = NULL;
	Linklist p = List->next;
	while (p)
	{
		Linklist temp = (Linklist)malloc(sizeof(Node));
		count++;
		if (count % 2 == 1)//序号为奇数
		{
			L1->data++;
			temp->data = p->data;
			temp->next = L1->next;
			L1->next = temp;
		}
		if (count % 2 == 0)//序号为偶数
		{
			L2->data++;
			temp->data = p->data;
			temp->next = L2->next;
			L2->next = temp;
		}
		p = p->next;
	}

	return ok;
}
int main()
{
	int n = 10;
	Linklist L=(Linklist)malloc(sizeof(Node));
	Linklist L1 = (Linklist)malloc(sizeof(Node));
	Linklist L2 = (Linklist)malloc(sizeof(Node));
	CreatList (L,n);
	TravelList(L);
	chaifen(L, L1, L2);
	printf("奇数序号元素有: %d位", L1->data);
	TravelList(L1);
	printf("偶数序号元素有: %d位", L2->data);
	TravelList(L2);
}