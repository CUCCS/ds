 #include<stdio.h>
#include<stdlib.h>

typedef int ElemType;  

typedef struct  LNode
{
	ElemType data;
	struct LNode *next;
}LNode , *LinkList;   //�ṹ�彨����

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
	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
	//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
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
 
