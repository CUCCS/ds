 #include<stdio.h>
#include<stdlib.h>

typedef int ElemType;  

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;   //结构体建立；

void CreateList_L(LinkList &L, int n){
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L ->next = NULL;
	for( int i = n; i > 0; --i){
		p = (LinkList) malloc (sizeof(LNode));
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	}
};
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	//已知单链线性表La和Lb的元素按值非递减排列。
	//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	LinkList pa = La->next,pb = Lb->next,pc;
	pc = La;
	Lc = La;
	while(pa && pb){
		if(pa->data<= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc ->next = pa ? pa : pb;
	free(Lb);
}
int main()
{
	LinkList La,Lb,Lc,p;
	int n,m;
	scanf("%d",&m);
	scanf("%d",&n);
	CreateList_L(La,m);
	CreateList_L(Lb,n);
	p = La;
	MergeList_L(La, Lb, Lc); 
	for(p=p->next;p->next!=NULL;p=p->next)
	{
	
		printf("%d ",p->data);
	}
	return 0;
}
 
