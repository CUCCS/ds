//2.12

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
	LNode* p;
	int data = 20;
	int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	srand((unsigned int)time(NULL));
	printf("�����������\n");
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
	    p->data=data-=rand()%5+1;   //ʹǰһ�����ݱض��Ⱥ�һ�����ݴ�������֮����1��5��
		printf("%d ",p->data);
		p->next = (*L)->next;
		(*L)->next=p;
	}
	printf("\n");
}

void MergeList ( LinkList *La,LinkList *Lb,LinkList *Lc)
{
	LNode *pa,*pb,*pc;
	pa = (*La)->next;
	pb = (*Lb)->next;
	*Lc = pc = *La;
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
	if(*Lb != NULL)
		free(*Lb);
}

void PrintList (LinkList Lc ) // �˲��ֲ�����C���Կμ������޸�
{
    LNode *p;
    p = Lc->next;
    printf("����ϲ�����Lc�и�������ݣ�\n");
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
	int a,b;
	srand((unsigned int)time(NULL));
	a=10+rand()%5;
	printf("��������La�ĳ���Ϊ%d\n",a);
	b=10+rand()%5;
	printf("��������Lb�ĳ���Ϊ%d\n",b);
	printf("��ʼ����La\n");
	CreateList( &La ,a);
	printf("��ʼ����Lb\n");
	CreateList( &Lb ,b);
	MergeList( &La, &Lb ,&Lc);
	PrintList( Lc);
	return 0;
}