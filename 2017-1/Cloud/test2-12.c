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
	printf("��������:");
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
	L->next = NULL;//�����������ͷ���
	if(L)
		printf("ͷ�ڵ㴴���ɹ���\n");
	for(i = n; i > 0;--i){
		p = (LinkList)malloc(sizeof(LNode));
		if(p)
			printf("�ɹ�����һ���ڵ�ռ䣬������һ��������");
		scanf("%d",& p->data );
		p->next  = L->next ;//��һ������ʱL->next����һ�β���Ľڵ��������������󡣣�
		L->next  = p;//������һ�������ɵĽ������ȥ��
	}
	travle(L);
	//printf("����һ����������");
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


