#include<stdio.h>
#include<stdlib.h>
#define length 10

typedef  struct LNode{
	int data;
	struct LNode *next ;
}LNode;
typedef  struct LNode *LinkList;

typedef enum {
	true,
	false
}bool;

void travle(LinkList p);
void CreatList(LinkList L,int n);
void MergeList(LinkList La,LinkList Lb,LinkList Lc);

void travle(LinkList p){

	int i;
	printf("有序单链表:");
	//p = L_->next
	for( i = 0 ;i <length;i++){
		//printf("%d ",(L_+i)->data);
		printf("%d ",p->data );
		p = p->next ;
	}
	printf("\n");
}

void CreatList(LinkList L,int n){
	LNode *p;
	int i;
	L = (LinkList)malloc( sizeof(LNode) );
	L->next = NULL;//建立单链表的头结点
	if(L)
		printf("头节点创建成功！\n");
	for(i = n; i > 0;--i){
		p = (LinkList)malloc(sizeof(LNode));
		if(p)
			printf("成功分配一个节点空间，请输入一个整数：");
		scanf("%d",& p->data );
		p->next  = L->next ;//第一次连入时L->next，第一次插入的节点在整个链表的最后。？
		L->next  = p;//两步把一个新生成的结点连上去了
	}
	travle(L);
	//printf("生成一个有序单链表");
	//for(int i ;i <length;i++){
	//	printf("%d",L+i);
	//}

}

void MergeList(LinkList La,LinkList Lb,LinkList Lc){
	LinkList pa,pb,pc;
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc = La;
	while(pa && pb){
		if( pa->data <= pb->data ){
			pc->next = pa;
			pc = pa;
			pa = pa->next ;
		}
		else{
			pc->next  = pb;
			pc = pb;
			pb = pc->next;
		}
	}
	pc->next = pa ? pa : pb;  
	free(Lb);
}

int main(){
	LNode list_a,list_b,list_c;

	CreatList(&list_a,length);
	CreatList(&list_b,length);
	MergeList(&list_a,&list_b,&list_c);
	travle(&list_c);
	return 0;
}


