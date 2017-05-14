/* 
	ʱ�临�Ӷȣ�
	��������ʱ�临�Ӷ�ΪO(n)
	��ÿ����һ���������һ�������Ӷ�ΪO(n^2)
	����Ϊ���ʱ�临�Ӷ�
	�ռ临�Ӷȣ�
	�÷�����ÿ����һ���������һ�����Ŀռ临�ӶȲ��
*/
#include<stdio.h>
#define MAX 100

typedef struct LNode
{	//��������
	int data;                //������
	struct LNode *next;		 //ָ����
}LNode,*LinkList;

int InitList(LinkList &L)
{	//��ʼ������
	L=new LNode;
	L->next=NULL;
	return 1;
} 

int ListLength(LinkList L)
{	//����������
	int length=0;
	struct LNode *p;
	p=L->next;
	while(p){
		++length;
		p=p->next;
	}
	return length;
}

void TraveList(LinkList L)
{	//��ӡ����
	struct LNode *p;
	p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void CreateList(LinkList &L,int n)
{	//���������ֵ
	L=new LNode;
	L->next=NULL;
	struct LNode *p;
	p=L;
	for(int i=0;i<n;i++){
		struct LNode *s;
		s=new LNode;
		printf("������%d������ֵ:",i+1);
		scanf("%d",&s->data);
		s->next=NULL;
		p->next=s;
		p=s;
	}
}

void Resolve(LinkList &LA,LinkList &LB,LinkList &LC)
{	//�ֽ�������
	struct LNode *pa,*pb,*pc;
	pa=LA->next;	
	LB=new LNode;
	LC=new LNode;	//���������½ڵ�
	pb=LB;
	pc=LC;

	while(pa){
		if( (pa->data) % 2 == 0 )	//������Ϊż��
		{
			pb->next=pa;
			pa=pa->next;			//ָ����һ�ڵ�
			pb=pb->next;
			pb->next=NULL;			//�ýڵ�Ϊβ�ڵ�
		}
		else
		{
			pc->next=pa;
			pa=pa->next;
			pc=pc->next;
			pc->next=NULL;
		}
	}
}

int main(){
	LinkList LA;
	LinkList LB;
	LinkList LC;

	InitList(LA);
	InitList(LB);
	InitList(LC);
	
	if(LinkList(LA)){
		printf("LA��ʼ���ɹ�!\n");
	}else{
		printf("LA��ʼ��ʧ��!\n");
	}
	
	if(LinkList(LB)){
		printf("LB��ʼ���ɹ�!\n");
	}else{
		printf("LB��ʼ��ʧ��!\n");
	}
	
	if(LinkList(LC)){
		printf("LC��ʼ���ɹ�!\n");
	}else{
		printf("LC��ʼ��ʧ��!\n");
	}
	
	printf("\n������LA�ĳ���:");
	int n1;
	scanf("%d",&n1);
	CreateList(LA,n1);
	printf("\n����A��\n");
	TraveList(LA);
	
	Resolve(LA,LB,LC);
	printf("����B��\n");
	TraveList(LB);
	printf("����C��\n");
	TraveList(LC);
	
	return 0;
}