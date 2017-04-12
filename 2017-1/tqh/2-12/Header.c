#include<stdio.h>
#include"Header.h"
#include<time.h>
//随机创建链表
void CreateList(LinkList *L,int n)
{
	LinkList p = NULL;
	int i ;
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	srand((unsigned)time( NULL ) );
	for(i=0;i<n;i++){
		p = (LinkList)malloc(sizeof(LNode));
		/*scanf("%d",&p->data);*/
		p->data = rand()%1024;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}//createlist

//链表从小到大排序
void SortList(LinkList L,int n)
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

//遍历链表
void Traverse(LinkList L)
{
	LNode *p = L->next;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
}

//链表合并成一个新链表
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

//将主函数中的一些操作综合，简化主函数
void ShowList(LinkList *L1,LinkList *L2)
{
	int i,j;
	LinkList Lc;
	*L1 =(LinkList) malloc(sizeof(LNode));
	*L2 =(LinkList) malloc(sizeof(LNode));

	printf("L1中值得个数:");
	scanf("%d",&i);

	CreateList(L1,i);
	printf("\n排序前遍历L1:\n");
	Traverse(*L1);
	printf("\n");

	SortList(*L1,i);
	printf("\n排序后遍历L1:\n");
	Traverse(*L1);
	printf("\n");

	printf("\nL2中值得个数:");
	scanf("%d",&j);

	CreateList(L2,j);
	printf("\n排序前遍历L2:\n");
	Traverse(*L2);
	printf("\n");

	SortList(*L2,j);
	printf("\n排序后遍历L2:\n");
	Traverse(*L2);
	printf("\n");

	printf("\n合并后遍历:\n");
	MergeList_L(*L1,*L2,&Lc);
	Traverse(Lc);
}

