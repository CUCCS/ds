#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
	}LNode,*LinkList;

void CreateList (LinkList *L,int n)
{
	LNode* p;
	int data = 20;
	int i;
	(*L) = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	srand((unsigned int)time(NULL));
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
	    p->data=data-=rand()%5+1;  
		printf("%d ",p->data);
		p->next = (*L)->next;
		(*L)->next=p;
	}
	printf("\n");
}

void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc)/* 算法2.12 */{
	LinkList pa=(*La)->next,pb=(*Lb)->next,pc;
	*Lc=pc=*La;/*用La的头结点作为Lc的头结点*/
	while(pa&&pb)
		if(pa->data<=pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		pc->next=pa?pa:pb;/*插入剩余段*/
		free(*Lb);/* 释放Lb的头结点*/
		Lb=NULL;
}
void ListTraverse(const LinkList L, void(*func)(ElemType)){ 
	LNode *p = L->next; 
	while (p){ 
		func(p->data); 
		p = p->next; 
	}
}
void visit(ElemType c)/*ListTraverse()调用的函数*/{
	printf("%d ",c);
}

void PrintList (LinkList Lc )
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
	a=rand()%10+5;
	printf("La的长度为%d\n",a);
	b=rand()%10+5;
	printf("Lb的长度为%d\n",b);
	printf("La中所有值为\n");
	CreateList( &La ,a);
	printf("Lb中所有值为\n");
	CreateList( &Lb ,b);
	MergeList( &La, &Lb ,&Lc);
	PrintList( Lc);
	return 0;
}