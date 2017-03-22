#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode,*LinkList;


void CreateList_L(LinkList &L,int n)
{


	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	LNode *p;
	int i;
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
	    L->next=p;
	}
};//CraeteList_L

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{

	LNode *pa = La->next, *pb = Lb->next, *pc;
	Lc= pc = La;
	

	while (pa&&pb){
		
		if (pa->data <= pb->data){
		
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else{
		
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;

	free(Lb);

};
void TraverseList_L(LinkList &L)
{
	LNode *p = L->next;
	while (p){
		printf("%2d ",p->data);
		p = p->next;
	}
};
int main(){
	int n,m;
	LinkList La, Lb, Lc;
	srand((unsigned)time(NULL));

	La = (LinkList)malloc(sizeof(LNode));
	printf("输入La的长度");
	scanf("%d",&n);
	CreateList_L(La,n);

	Lb = (LinkList)malloc(sizeof(LNode));
	printf("输入Lb的长度");
	scanf("%d",&m);
	CreateList_L(Lb,m);

	printf("\nLa:");
	TraverseList_L(La);
	printf("\n");
	printf("Lb:");
	TraverseList_L(Lb);
	printf("\n\n");

	MergeList_L(La, Lb,Lc);
	printf("Lc:");
	TraverseList_L(Lc);
	printf("\n");
	return 0;
}