#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode
{
	int  data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList (LinkList *L,int n)
{
	LinkList p;
	int data = 20;
	int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	srand(( int)time(NULL));
	printf("�����������\n");
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = data-=rand()% 10;   //ʹǰһ�����ݱض��Ⱥ�һ�����ݴ�������֮����1��5��
		printf("%d ",p->data);
		p->next = (*L)->next;
		(*L)->next=p;
	}
	printf("\n");
}

void MergeList ( LinkList La,LinkList Lb,LinkList *Lc)
{
	LNode *pa,*pb,*pc;
	pa = La->next;
	pb = Lb->next;
	*Lc = pc = La;
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc ->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa :pb;
	if(Lb != NULL)
		free(Lb);
}

void output (LinkList Lc )
{
	LNode *p;
	p = Lc->next;
	printf("����ϲ�����Lc��\n");
	while( p!=NULL )
	{
		printf("%d ",p->data) ;
		p=p->next;
	}
	printf("\n");
}

int main()
{
	LinkList La,Lb,Lc;
	int a = 0,b = 0;
	srand(( int)time(NULL));
	a=10+rand()%5;
	printf("La�ĳ���Ϊ%d\n",a);
	b=10+rand()%5;
	printf("Lb�ĳ���Ϊ%d\n",b);
	CreateList( &La ,a);
	CreateList( &Lb ,b);
	MergeList( La, Lb ,&Lc);
	output( Lc);
	return 0;
}