#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dataIncreasBase 6; 

struct _LNode{
	int data;
	struct _LNode *next ;
}LNode,*LinkList;

typedef  struct _LNode LNode;
typedef  struct _LNode* LinkList;

void Traverse(LinkList p);
void CreatList(LinkList L,int n);
void MergeList( LinkList La, LinkList Lb, LinkList Lc );

void Traverse(LinkList p){
	p = p->next ;
	printf("有序单链表为:");
	while(p->data){
		printf("%d ",p->data );
		p = p->next ;
	}
	printf("\n");

}
void CreatList(LinkList L,int n){

	srand( time(NULL) );
	LNode *p;//新生成的节点
	int lastData;//储存上个节点的数据
	int i;
	lastData = rand()%dataIncreasBase;
	L = (LinkList)malloc( sizeof(LNode) );
	L->next = NULL;//建立单链表的头结点
	/*if(L){
		printf("头节点创建成功！\n");
	}*/
	for( i = 0; i < n ;i++){
		p = (LinkList)malloc(sizeof(LNode));
		while( !p ){
			p = (LinkList)malloc(sizeof(LNode));
		}
		p->data = lastData;
		lastData += rand()%dataIncreasBase;//随机生成>=lastdata的数据
		p->next  = L->next ;//第一次连入时L->next，第一次插入的节点在整个链表的最后。
		L->next  = p;//两步把一个新生成的结点连上去了
	}
	Traverse(L);
}
void MergeList( LinkList La, LinkList Lb, LinkList Lc ){
	
	LinkList pa,pb,pc;
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc = La;
	//pa pb都未next到最后一个节点
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
	//	free( pa ? pb : pa);
}
int main(){

	//srand( time(NULL) );
	LinkList list_a, list_b, list_c;
    int length = 10;
	CreatList(list_a,length);
	Traverse(list_a );
	CreatList(list_b,length);
	Traverse(list_b );
	MergeList(list_a,list_b,list_c);
	Traverse(list_c );
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define dataIncreasBase 6; 

typedef  struct LNode{
	int data;
	struct LNode *next ;
}LNode;
typedef  struct LNode *LinkList;

typedef enum {
	true,
	false
}bool;

void Traverse(LinkList p);
void CreatList(LinkList L,int n);
void MergeList( LinkList La, LinkList Lb, LinkList Lc );

void Traverse(LinkList p){
	p = p->next ;
	printf("有序单链表为:");
	while(p->data){
		printf("%d ",p->data );
		p = p->next ;
	}
	printf("\n");

}
void CreatList(LinkList L,int n){
	LNode *p;//新生成的节点
	int lastData;//储存上个节点的数据
	int i;
	lastData = rand()%dataIncreasBase;
	L = (LinkList)malloc( sizeof(LNode) );
	L->next = NULL;//建立单链表的头结点
	/*if(L){
		printf("头节点创建成功！\n");
	}*/
	for( i = 0; i < n ;i++){
		p = (LinkList)malloc(sizeof(LNode));
		while( !p ){
			p = (LinkList)malloc(sizeof(LNode));
		}
		p->data = lastData;
		lastData += rand()%dataIncreasBase;//随机生成>=lastdata的数据
		p->next  = L->next ;//第一次连入时L->next，第一次插入的节点在整个链表的最后。
		L->next  = p;//两步把一个新生成的结点连上去了
	}
	Traverse(L);
}
void MergeList( LinkList La, LinkList Lb, LinkList Lc ){
	
	LinkList pa,pb,pc;
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc = La;
	//pa pb都未next到最后一个节点
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
	//	free( pa ? pb : pa);
}
int main(){

	srand( time(0) );
	LNode list_a, list_b, list_c;
    int length = 10;
	CreatList(&list_a,length);
	Traverse(&list_a );
	CreatList(&list_b,length);
	Traverse(&list_b );
	MergeList(&list_a,&list_b,&list_c);
	Traverse(&list_c );
	return 0;
}

