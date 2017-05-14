#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct LNode{
	int    data;
	struct LNode  *next;
}LNode,*LinkList;
LinkList Insert(LinkList head,  LinkList p);//将p指向的结点插入链表, 结果链表保持有序，返回值是新链表的首指针。
LinkList CreateList1();//创建一条新的有序链表 一共包含十个数据
LinkList CreateList2();
void PrintList(LinkList head);//打印链表
LinkList Merge(LinkList pHead1, LinkList pHead2);//合并链表

LinkList CreateList1()
{
	LinkList p1,head=0;
	int a,i=0;
	printf("产生第一条排序链表，共包含10个数: \n");
	srand(time(NULL));
	while(i<10)
	{
		a=rand()%100+1;
		p1=(LinkList)malloc(sizeof(LNode));
		p1->data = a;
		head=Insert(head,p1);
		i++;
	}
	return(head);
}
LinkList CreateList2()
{
	LinkList p1, head=0;
	int a,i=0;
	printf("产生第二条排序链表，共包含10个数: \n");
	srand(time(NULL));
	while(i<10)
	{
		a=rand()%80;
		p1=(LinkList)malloc(sizeof(LNode));
		p1->data = a;
		head=Insert(head,p1);
		i++;
	}
	return(head);
}
LinkList Insert(LinkList head,  LinkList p) //
{
	LinkList p1, p2;
	if(head == NULL) // 原链表为空链表，对应情况①
	{	head = p;
	p->next = NULL;
	return(head);
	}
	p1 = head;
	while( (p->data) > (p1->data) && p1->next != NULL )
	{	                                             // 寻找待插入位置
		p2 = p1; p1 = p1->next;
		// p2指向的结点在p1指向的结点之前
	}
	if( (p->data) <= (p1->data) ) // 插在p1之前
	{
		p->next = p1;
		if(head == p1)
			head = p;	           // 插在链表首部，对应情况②
		else
			p2->next = p;	// 插在链表中间，对应情况③
	}
	else 	          // 插在链表尾结点之后，对应情况④
	{
		p1->next = p;
		p->next = NULL;
	}
	return(head);
}
void PrintList(LinkList x)
{
	while(x!=NULL)
	{
		printf("%d ——>",x->data);
		x=x->next;
	}
	printf("NULL \n");
}
LinkList Merge(LinkList pHead1, LinkList pHead2)
{
	if(pHead1 == NULL)//判断二者中是否有空表的情况
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	LinkList pMergedHead=NULL;//合并后链表的首节点


	if(pHead1->data < pHead2->data)
	{
		pMergedHead = pHead1;
		pMergedHead->next = Merge(pHead1->next, pHead2);
	}
	else
	{
		pMergedHead = pHead2;
		pMergedHead->next = Merge(pHead1, pHead2->next);
	}

	return pMergedHead;
}

int main()
{
	LinkList x,y,z;
	x=CreateList1();
	PrintList(x);

	y=CreateList2();
	PrintList(y);

	printf("\n合并后的链表: \n");
	z=Merge(x,y);
	PrintList(z);

	return 0;

}
