#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int  data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList (LinkList &L,int n)
{
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		printf("����������\n");
		scanf("%d",&p->data);
		p->next = L->next;
		L->next=p;
	}
}

void MergeList ( LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LNode *pa,*pb,*pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
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

void PrintList (LinkList Lc ) // �˲��ֲ�����C���Կμ������޸�
{
    LNode *p;
    p = Lc->next;
    printf("����ϲ�����Lc�и�������ݣ�");
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
	printf("��ֱ�����La��Lb�ĳ��Ȳ��Կո�ֿ�\n");
	scanf("%d %d",&a,&b);
	printf("����La\n");
	CreateList( La ,a);
	printf("����Lb\n");
	CreateList( Lb ,b);
	MergeList( La, Lb ,Lc);
	PrintList( Lc);
	return 0;
}