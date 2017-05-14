#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node 
{
	int data;
	struct Node *next;

}LNode,*LinkList;
//�������
void OutPutList(LinkList head)
{

	LNode *temp;
	int count=head->data;
	temp=head->next;

	while(count)
	{
		printf("%d����>",temp->data);
		temp=temp->next;
		count--;
	}    
	printf("NULL");
	printf("\n\n");


}
//��������
LinkList CreateList(int n)
{
	int i=0,number;
	LinkList head,current,previous;
	head=NULL;
	current=NULL;
	previous=NULL;
	srand(time(NULL));
	while( i<n) // ѭ���������ݣ���������
	{
		number=rand()%100+1;
		current=(LinkList)malloc(sizeof(LNode));
		if(head==0 ) // �ٽ����׽��
		{
			head = current;
		}
		if (previous != NULL) //���м���ļ���
		{
			previous->next=current;
		}
		current->data = number;
		current->next = NULL;
		previous = current;
		i++;
	}

	return(head); //���ش����������ָ��

}
void PrintList(LinkList x)//����ֽ�ǰ������
{
	printf("����ֽ�ǰΪ:\n");
	while(x!=NULL)
	{
		printf("%d ����>",x->data);
		x=x->next;
	}
	printf("NULL \n\n");
}
//�ֽ�����
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
	int n;//�������ɵĳ���
	srand(time(NULL));
	n=rand()%10+1;
	list=CreateList(n);
	PrintList(list);


	list1=(LNode *)malloc(sizeof(LNode));
	list2=(LNode *)malloc(sizeof(LNode));

	SeperateList(list,list1,list2);

	printf("����1�������Ϊ����: Ԫ�ظ���Ϊ%d\n",list1->data);

	OutPutList(list1);

	printf("����2�������Ϊż��: Ԫ�ظ���Ϊ%d\n",list2->data);

	OutPutList(list2);

	return 0;

}