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
	printf("随机产生数据\n");
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
	    p->data=data-=rand()%5+1;   //使前一个数据必定比后一个数据大，且两者之差再1到5；
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

void PrintList (LinkList Lc ) // 此部分参照了C语言课件进行修改
{
    LNode *p;
    p = Lc->next;
    printf("输出合并链表Lc中各结点数据：\n");
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
	printf("创建链表La的长度为%d\n",a);
	b=10+rand()%5;
	printf("创建链表Lb的长度为%d\n",b);
	printf("开始创建La\n");
	CreateList( &La ,a);
	printf("开始创建Lb\n");
	CreateList( &Lb ,b);
	MergeList( &La, &Lb ,&Lc);
	PrintList( Lc);
	return 0;
}