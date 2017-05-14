#include "happy.h"
#include <stdlib.h>

void CreateList_L(LinkList *L,int n)
{
	int i;
	LinkList p;
	int b = 20;

	//头节点L
	(*L)=(LinkList)malloc(sizeof(LNode));
	(*L)->next=NULL;


	for(i=n;i>0;--i)
	{
		//生成新节点p
		p = (LinkList)malloc(sizeof(LNode));
		//随机产生测试数据
		b -= rand() % 5+1;
		//进行一系列指针操作
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
	//释放LB
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
