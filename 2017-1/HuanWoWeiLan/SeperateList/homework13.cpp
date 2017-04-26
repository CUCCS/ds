#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node 
{
	int data;
	struct Node *next;

}LNode,*LinkList;
//链表输出
void OutPutList(LinkList head)
{

	LNode *temp;
	int count=head->data;
	temp=head->next;

	while(count)
	{
		printf("%d——>",temp->data);
		temp=temp->next;
		count--;
	}    
	printf("NULL");
	printf("\n\n");


}
//建立链表
LinkList CreateList(int n)
{
	int i=0,number;
	LinkList head,current,previous;
	head=NULL;
	current=NULL;
	previous=NULL;
	srand(time(NULL));
	while( i<n) // 循环输入数据，建立链表
	{
		number=rand()%100+1;
		current=(LinkList)malloc(sizeof(LNode));
		if(head==0 ) // ①建立首结点
		{
			head = current;
		}
		if (previous != NULL) //②中间结点的加入
		{
			previous->next=current;
		}
		current->data = number;
		current->next = NULL;
		previous = current;
		i++;
	}

	return(head); //返回创建链表的首指针

}
void PrintList(LinkList x)//输出分解前的链表
{
	printf("链表分解前为:\n");
	while(x!=NULL)
	{
		printf("%d ——>",x->data);
		x=x->next;
	}
	printf("NULL \n\n");
}
//分解链表
void SeperateList(LinkList list,LinkList list1,LinkList list2)
{

	LNode*p1 = list1; 
	LNode*p2 = list2; 
	LNode*p = list; 

	list1->data = 0; 
	list2->data = 0; 
	while (p!=NULL) 
	{ 

		p1->next = p; 
		p1 = p1->next; 
		list1->data++; 
		p = p->next; 
		if (p!= NULL) 	{ 

			p2->next = p; 
			p2 = p2->next; 
			list2->data++; 	p = p->next;} 



	}
	p1->next = list1; 
	p2->next = list2;
}
int main()

{

	LinkList list,list1,list2;
	int n;//链表生成的长度
	srand(time(NULL));
	n=rand()%10+1;
	list=CreateList(n);
	PrintList(list);


	list1=(LNode *)malloc(sizeof(LNode));
	list2=(LNode *)malloc(sizeof(LNode));

	SeperateList(list,list1,list2);

	printf("链表1——序号为奇数: 元素个数为%d\n",list1->data);

	OutPutList(list1);

	printf("链表2——序号为偶数: 元素个数为%d\n",list2->data);

	OutPutList(list2);

	return 0;

}