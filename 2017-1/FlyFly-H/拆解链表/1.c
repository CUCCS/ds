#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList (LinkList *L,int n)
{
    LNode* p = *L;
    int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	srand((unsigned int)time(NULL));
	printf("�����������\n");
	for(i=0;i<n;i++)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data=rand()%25+1;   
		p->next = (*L)->next;
		(*L)->next=p;
	}
}

void PrintList (LinkList Lc ) // �˲��ֲ�����C���Կμ������޸�
{
	LNode *p;
	p = Lc->next;
	while( p!=NULL )
	{
		printf("%d ",p->data) ;
		p=p->next;
		if(p == Lc->next)
		{
			printf("\n");
			break;
		}
	}
	printf("\n");
}

void split(LinkList list,LinkList *list1,LinkList *list2)
{
	LNode *p,*la,*lb;
	int count = 1;
	*list1 = (LNode *)malloc (sizeof(LNode));
	*list2 = (LNode *)malloc (sizeof(LNode));

	p = list;
	la = *list1;
	lb = *list2;
	(*list1)->data = 0;
	(*list2)->data = 0;
	(*list1)->next = NULL;
	//(*list2)->next = NULL;
	p=p->next;
	
	while(p)
	{
		int a = count%2;
		if(a)    
		{
			(*list1)->data = p->data;
		   la->next = p;
		   la = p;
		    p = p->next;
		   count++;
		}
		else
		{
			(*list2)->data = p->data;
			lb->next = p;
			lb = p;
			p = p->next;
			count++;
		}
	}

	la->next = (*list1)->next;
	lb->next = (*list2)->next;

}


int main()
{
	LinkList list,list1,list2;
	int a;
	srand((unsigned int)time(NULL));
	a=15+rand()%5;
	printf("��������List�ĳ���Ϊ%d\n",a);
	printf("��ʼ����List\n");
	CreateList( &list ,a);
	PrintList(list);
	split( list, &list1 ,&list2);
	printf("���list1������\n");
	PrintList( list1);
	printf("���list2������\n");
	PrintList( list2);
	return 0;
}
