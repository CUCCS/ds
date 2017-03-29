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
	printf("��������Ϊ:");
	while(p->data){
		printf("%d ",p->data );
		p = p->next ;
	}
	printf("\n");

}
void CreatList(LinkList L,int n){

	srand( time(NULL) );
	LNode *p;//�����ɵĽڵ�
	int lastData;//�����ϸ��ڵ������
	int i;
	lastData = rand()%dataIncreasBase;
	L = (LinkList)malloc( sizeof(LNode) );
	L->next = NULL;//�����������ͷ���
	/*if(L){
		printf("ͷ�ڵ㴴���ɹ���\n");
	}*/
	for( i = 0; i < n ;i++){
		p = (LinkList)malloc(sizeof(LNode));
		while( !p ){
			p = (LinkList)malloc(sizeof(LNode));
		}
		p->data = lastData;
		lastData += rand()%dataIncreasBase;//�������>=lastdata������
		p->next  = L->next ;//��һ������ʱL->next����һ�β���Ľڵ���������������
		L->next  = p;//������һ�������ɵĽ������ȥ��
	}
	Traverse(L);
}
void MergeList( LinkList La, LinkList Lb, LinkList Lc ){
	
	LinkList pa,pb,pc;
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc = La;
	//pa pb��δnext�����һ���ڵ�
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
	printf("��������Ϊ:");
	while(p->data){
		printf("%d ",p->data );
		p = p->next ;
	}
	printf("\n");

}
void CreatList(LinkList L,int n){
	LNode *p;//�����ɵĽڵ�
	int lastData;//�����ϸ��ڵ������
	int i;
	lastData = rand()%dataIncreasBase;
	L = (LinkList)malloc( sizeof(LNode) );
	L->next = NULL;//�����������ͷ���
	/*if(L){
		printf("ͷ�ڵ㴴���ɹ���\n");
	}*/
	for( i = 0; i < n ;i++){
		p = (LinkList)malloc(sizeof(LNode));
		while( !p ){
			p = (LinkList)malloc(sizeof(LNode));
		}
		p->data = lastData;
		lastData += rand()%dataIncreasBase;//�������>=lastdata������
		p->next  = L->next ;//��һ������ʱL->next����һ�β���Ľڵ���������������
		L->next  = p;//������һ�������ɵĽ������ȥ��
	}
	Traverse(L);
}
void MergeList( LinkList La, LinkList Lb, LinkList Lc ){
	
	LinkList pa,pb,pc;
	pa = La->next ;
	pb = Lb->next ;
	Lc = pc = La;
	//pa pb��δnext�����һ���ڵ�
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

