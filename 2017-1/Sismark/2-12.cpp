#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;// �������
  struct Node *pNext;//�ṹ��ָ�룬ָ����һ���뵱ǰ�ڵ���ͬ�Ľڵ�
}NODE,*LinkList;


LinkList CreateList_L(int len){
	int base = 10;
int i;//ѭ����������һ��ѭ����ÿ�δ���һ���ڵ㣬����ÿ���ڵ�����һ��
LinkList pHead=(LinkList)malloc(sizeof(NODE));//����һ��ͷ�ڵ�
printf("LinkList pHead=%X\n",pHead);
LinkList pTail=pHead;//����һ��βָ��pTail,��ָ��ͷ�ڵ�
printf("LinkList pTail=%X\n",pTail);
pHead->pNext=NULL;
printf("pHead->pNext=NULL\n");
for(i=0;i<len;i++){
	//����len���ڵ�
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
	pTail=p;//ʹpTailָ���������һ��Ԫ��
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
	printf( "��ʼ����La\n" );
	La = CreateList_L(rand()%5+3);
	TravelList_L(La);
	printf( "\n��ʼ����Lb\n" );
	Lb = CreateList_L(rand()%5+3);
	TravelList_L(Lb);
	LinkList Lc;	
	printf( "\n��ʼ����Lc\n" );
	Lc = MergeList_L(La,Lb);
	TravelList_L(Lc);

	printf("\nLa=");
	TravelList_L(La);
	printf("\nLb=");
	TravelList_L(Lb);
	printf("\nLc=");
	TravelList_L(Lc);
}
