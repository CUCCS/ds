#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct LNode{
	int    data;
	struct LNode  *next;
}LNode,*LinkList;
LinkList Insert(LinkList head,  LinkList p);//��pָ��Ľ���������, ������������򣬷���ֵ�����������ָ�롣
LinkList CreateList1();//����һ���µ��������� һ������ʮ������
LinkList CreateList2();
void PrintList(LinkList head);//��ӡ����
LinkList Merge(LinkList pHead1, LinkList pHead2);//�ϲ�����

LinkList CreateList1()
{
	LinkList p1,head=0;
	int a,i=0;
	printf("������һ����������������10����: \n");
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
	printf("�����ڶ�����������������10����: \n");
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
	if(head == NULL) // ԭ����Ϊ��������Ӧ�����
	{	head = p;
	p->next = NULL;
	return(head);
	}
	p1 = head;
	while( (p->data) > (p1->data) && p1->next != NULL )
	{	                                             // Ѱ�Ҵ�����λ��
		p2 = p1; p1 = p1->next;
		// p2ָ��Ľ����p1ָ��Ľ��֮ǰ
	}
	if( (p->data) <= (p1->data) ) // ����p1֮ǰ
	{
		p->next = p1;
		if(head == p1)
			head = p;	           // ���������ײ�����Ӧ�����
		else
			p2->next = p;	// ���������м䣬��Ӧ�����
	}
	else 	          // ��������β���֮�󣬶�Ӧ�����
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
		printf("%d ����>",x->data);
		x=x->next;
	}
	printf("NULL \n");
}
LinkList Merge(LinkList pHead1, LinkList pHead2)
{
	if(pHead1 == NULL)//�ж϶������Ƿ��пձ�����
		return pHead2;
	else if(pHead2 == NULL)
		return pHead1;

	LinkList pMergedHead=NULL;//�ϲ���������׽ڵ�


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

	printf("\n�ϲ��������: \n");
	z=Merge(x,y);
	PrintList(z);

	return 0;

}
