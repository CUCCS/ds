#include <stdio.h>
#include <stdlib.h>
#include "13.h"

Status CreateList(LinkList L,int n)
{//创建一个链表
	printf("创建链表\n");
	L->next = NULL;//头结点设为空
	int i;
	i = 0;
	LinkList a;//设创建的链表叫a
	for(i = n;i > 0; i--)
	{
		a = (LinkList)malloc(sizeof(LNode));//动态生成新的结点的内存
		a->data = i;//初始化链表
		a->next = L->next;//更新链表
		L->next = a;//使L的尾指针指向a
	}
	printf("创建链表完成\n");
	return OK;//创建链表成功	
}
Status Traverse(LinkList L)
{//遍历链表
	LinkList b;
	b = (LinkList)malloc(sizeof(LNode));//动态生成新的结点
	if(b->next == NULL)//防止链表为空
	{
		return ERROR;//若为空返回错误
	}
	b = L->next;//L尾指针指向b
	while(b->next != NULL)//判断是否结束
	{
		printf("%d\t",b->data);//输出链表元素
		b = b->next;//指向下一个元素
	}
	printf("%d\t",b->next);
	printf("\n");
	printf("遍历链表\n");
	return OK;
}
Status Distribute(LinkList L1,LinkList L2,LinkList L3)
{//创建三个链表
	LinkList a = L1; //p1,list1
	LinkList b = L2; //p2,list2
	LinkList c = L3; //p,list
	L1->data = 0;//初始L1
	L2->data = 0;//初始L2
	c = c->next;//初始c的指针指向
	while(c != NULL)//当c不为空时
	{
		a->next = c;//a的尾指针指向c
		a = a->next;//a指向下一个元素
		L1->data++;//L1为data自加的值
		c = c->next;//c指向下一个
		if(c != NULL)//当c不为空时
		{
			b->next = c;
			b = a->next;
			L2->data++;
			c = c->next;
		}
	}
	a->next = L1;
	b->next = L2;
	return OK;
}
Status Traverse_separate(LinkList L)
{//遍历分开的链表
	LinkList m = L;
	LinkList n = L;
	if(m->next == NULL)//判断为空的情况
	{
		return ERROR;
	}
	printf("链表长度为%d\n",n->data);
	n = n->next;//指向下一个元素
	while(n->next != m)
	{
		printf("%d\t",n->data);
		if(n->next != NULL)
		{
			n = n->next;
		}
	}
	printf("%d",n->data);
	printf("\n");
	printf("分配结束\n");
	return OK;
}