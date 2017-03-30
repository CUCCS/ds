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
	printf("随机产生数据\n");
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = data-=rand()% 10;   //使前一个数据必定比后一个数据大，且两者之差再1到5；
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
	printf("输出合并链表Lc：\n");
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
	printf("La的长度为%d\n",a);
	b=10+rand()%5;
	printf("Lb的长度为%d\n",b);
	CreateList( &La ,a);
	CreateList( &Lb ,b);
	MergeList( La, Lb ,&Lc);
	output( Lc);
	return 0;
}