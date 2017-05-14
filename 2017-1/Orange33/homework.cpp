#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode* next;
	}LNode,*LinkList;

void CreateList(LinkList *L,int n)/*算法2.11*/{
	/* 逆位序(插在表头)输入n个元素的值，建立带表头结构的单链线性表L */
	int i;
	LinkList p;
	printf("请输入Lb中的值个数\n");
	scanf_s("%d",&n);
	printf("请输入Lb中所有值\n");
	*L=(LinkList)malloc(sizeof(struct LNode));
	(*L)->next=NULL;/*建立一个带头结点的单链表*/
	for(i=n;i>0;--i){
		p=(LinkList)malloc(sizeof(struct LNode));/*生成新结点*/
		scanf_s("%d",&p->data);
		p->next=(*L)->next;/* 插入到表头*/
		(*L)->next=p;
	}
}
void CreateList2(LinkList *L,int n){
/*正位序(插在表尾)输入n个元素的值，建立带表头结构的单链线性表 */
	int i;
	LinkList p,q;
	*L=(LinkList)malloc(sizeof(struct LNode));/*生成头结点*/
	(*L)->next=NULL;
	q=*L;
	printf("请输入La中的值个数\n");
	scanf_s("%d",&n);
	printf("请输入La中所有值\n");
	for(i=1;i<=n;i++){
		p=(LinkList)malloc(sizeof(struct LNode));
		scanf_s("%d",&p->data);
		q->next=p;
		q=q->next;
	}
	p->next=NULL;
}
void MergeList(LinkList La,LinkList *Lb,LinkList *Lc)/* 算法2.12 */{
	LinkList pa=La->next,pb=(*Lb)->next,pc;
	*Lc=pc=La;/*用La的头结点作为Lc的头结点*/
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
void main()
{
	int n=0;
	LinkList La,Lb,Lc;
	CreateList2(&La,n);
	printf("La=");/* 输出链表La的内容*/
	ListTraverse(La,visit);
	CreateList(&Lb,n);
	printf("Lb=");/* 输出链表Lb的内容 */
	ListTraverse(Lb,visit);
	MergeList(La,&Lb,&Lc);/*归并La和Lb,得到新表Lc */	
	printf("Lc=");/* 输出链表Lc的内容*/
	ListTraverse(Lc,visit);
}