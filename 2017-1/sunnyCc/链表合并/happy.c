#include "happy.h"
#include <stdlib.h>

void CreateList_L(LinkList *L,int n)
{
	int i;
	LinkList p;
	int b = 20;

	//ͷ�ڵ�L
	(*L)=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;


	for(i=n;i>0;--i)
	{
		//�����½ڵ�p
		p = (LinkList)malloc(sizeof(LNode));
		//���������������
		b -= rand() % 5+1;
		//����һϵ��ָ�����
		p->data=b;
		p->next = (*L)->next;
		(*L)->next = p;
	}
};//end CraeteList_L

void MergeList_L(LinkList La, LinkList Lb, LinkList *Lc)
{

	LNode *pa = La->next, *pb = Lb->next, *pc;
	(*Lc)= pc = La;


	while (pa&&pb){

		if (pa->data <= pb->data){
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else{
			pc->next = pb; pc = pb; pb = pb->next;
		}

	}
	pc->next = pa ? pa : pb;
	//�ͷ�LB
	if ( NULL != Lb )
	{
		free(Lb);
		Lb=NULL;
	}

}
void TraverseList_L(const LinkList L ){
	LNode *p = L->next;
	while (p){
		printf("%d ",p->data);
		p = p->next;
	}
}
