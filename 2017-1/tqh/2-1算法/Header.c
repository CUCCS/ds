#include<stdio.h>
#include"Header.h"

void CreateList(LinkList *L,int n)
{
	LinkList p = NULL;
	int i ;
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	for(i=0;i<n;i++){
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
	//createlist

void sortList(LinkList L,int n)
{
	int i=0;
	int j=0;
	LinkList head;
	LinkList p1;
	LinkList p2;

	for(i=0;i<n;i++)
	{
		head = L->next;
		for( j=0;j<n-1;j++)
		{
			p1=head;
			p2=head->next;
			if( p1->data > p2->data){
				Elemtype temp = p1->data;
				 p1->data = p2 -> data;
				 p2->data = temp;
			}
			head = head->next;
		}
	}
}
void Traverse(LinkList L)
{
	LNode *p = L->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
}

void MergeList_L(LinkList La,LinkList Lb,LinkList  *Lc)
{
	LinkList pa,pb,pc;
	pa = La->next;
	pb = Lb->next;
	*Lc = pc = La;
	while(pa&&pb){
		if(pa->data <= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb =pb ->next;
		}
	}
	pc->next = pa? pa:pb;
	free(Lb);
}


