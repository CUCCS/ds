#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;// 存放数据
  struct Node *pNext;//结构体指针，指向下一个与当前节点相同的节点
}NODE,*LinkList;


LinkList CreateList_L(int len){
	int base = 10;
int i;//循环变量，用一个循环来每次创建一个节点，并把每个节点连在一起；
LinkList pHead=(LinkList)malloc(sizeof(NODE));//分配一个头节点
printf("LinkList pHead=%X\n",pHead);
LinkList pTail=pHead;//定义一个尾指针pTail,并指向头节点
printf("LinkList pTail=%X\n",pTail);
pHead->pNext=NULL;
printf("pHead->pNext=NULL\n");
for(i=0;i<len;i++){
	//创建len个节点
   LinkList p=(LinkList)malloc(sizeof(NODE));
   printf("LinkList p=%X\n",p);
	//scanf("%d",&p->data);
   base += rand()%3+2;
   p->data = base;
	printf("p->data=%d\n",p->data);
	pTail->pNext=p;
	printf("pTail->pNext=%X\n",pTail->pNext);
	p->pNext=NULL;
	printf("LinkList p->pNext=%X\n",p->pNext);
	pTail=p;//使pTail指向链表最后一个元素
	printf("LinkList pTail=%X\n",pTail);
  }
return pHead;
}

LinkList MergeList_L(const LinkList La,const LinkList Lb){
	LinkList pa=La->pNext,pb=Lb->pNext,L,pl;
	L=(LinkList)malloc(sizeof(Node));
	printf("LinkList L=%X\n",L);
	pl=L;
	printf("LinkList pl=%X\n",pl);
	while(pa&&pb){
		NODE*p=(LinkList)malloc(sizeof(Node));
		printf("LinkList p=%X\n",p);
		if(pa->data<=pb->data) {
		      p->data=pa->data; printf("p->data=%d\n",p->data); pa=pa->pNext;
		      printf("LinkList pa=%X\n",pa);
		}
	
		else { 
			p->data=pb->data; printf("p->data=%d\n",p->data); pb=pb->pNext; 
		    printf("LinkList pb=%X\n",pb);
		}
		p->pNext=NULL;
		printf("LinkList p->pNext=%X\n",p->pNext);
		pl->pNext=p;
		printf("LinkList pl->pNext=%X\n",pl->pNext);
		pl=pl->pNext;
		printf("LinkList pl=%X\n",pl);
	}
	NODE*P=pa?pa:pb;
	for(;P;P=P->pNext){
		NODE*p=(LinkList)malloc(sizeof(Node));
		printf("LinkList p=%X\n",p);
		p->data=P->data;
		printf("p->data=%d\n",p->data);
		p->pNext=NULL;
		printf("LinkList p->pNext=%X\n",p->pNext);
		pl->pNext=p;
		printf("LinkList pl->pNext=%X\n",pl->pNext);
		pl=pl->pNext;
		printf("LinkList pl=%X\n",pl);
	}
	return L;
}

void TravelList_L(const LinkList L){
	Node * p = L->pNext;
	for(;p;p=p->pNext)
		printf("%d ",p->data);
}
int main(){
	LinkList La,Lb;
	printf( "开始创建La\n" );
	La = CreateList_L(rand()%5+3);
	TravelList_L(La);
	printf( "\n开始创建Lb\n" );
	Lb = CreateList_L(rand()%5+3);
	TravelList_L(Lb);
	LinkList Lc;	
	printf( "\n开始创建Lc\n" );
	Lc = MergeList_L(La,Lb);
	TravelList_L(Lc);

	printf("\nLa=");
	TravelList_L(La);
	printf("\nLb=");
	TravelList_L(Lb);
	printf("\nLc=");
	TravelList_L(Lc);
}
