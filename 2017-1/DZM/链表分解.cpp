/* 
	时间复杂度：
	本方法的时间复杂度为O(n)
	若每遍历一遍链表提出一个数则复杂度为O(n^2)
	所以为最低时间复杂度
	空间复杂度：
	该方法和每遍历一遍链表提出一个数的空间复杂度差不多
*/
#include<stdio.h>
#define MAX 100

typedef struct LNode
{	//定义链表
	int data;                //数据域
	struct LNode *next;		 //指针域
}LNode,*LinkList;

int InitList(LinkList &L)
{	//初始化链表
	L=new LNode;
	L->next=NULL;
	return 1;
} 

int ListLength(LinkList L)
{	//返回链表长度
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
{	//打印链表
	struct LNode *p;
	p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void CreateList(LinkList &L,int n)
{	//输入链表的值
	L=new LNode;
	L->next=NULL;
	struct LNode *p;
	p=L;
	for(int i=0;i<n;i++){
		struct LNode *s;
		s=new LNode;
		printf("请输入%d个结点的值:",i+1);
		scanf("%d",&s->data);
		s->next=NULL;
		p->next=s;
		p=s;
	}
}

void Resolve(LinkList &LA,LinkList &LB,LinkList &LC)
{	//分解链表函数
	struct LNode *pa,*pb,*pc;
	pa=LA->next;	
	LB=new LNode;
	LC=new LNode;	//生成两个新节点
	pb=LB;
	pc=LC;

	while(pa){
		if( (pa->data) % 2 == 0 )	//若数据为偶数
		{
			pb->next=pa;
			pa=pa->next;			//指向下一节点
			pb=pb->next;
			pb->next=NULL;			//该节点为尾节点
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
		printf("LA初始化成功!\n");
	}else{
		printf("LA初始化失败!\n");
	}
	
	if(LinkList(LB)){
		printf("LB初始化成功!\n");
	}else{
		printf("LB初始化失败!\n");
	}
	
	if(LinkList(LC)){
		printf("LC初始化成功!\n");
	}else{
		printf("LC初始化失败!\n");
	}
	
	printf("\n请输入LA的长度:");
	int n1;
	scanf("%d",&n1);
	CreateList(LA,n1);
	printf("\n链表A：\n");
	TraveList(LA);
	
	Resolve(LA,LB,LC);
	printf("链表B：\n");
	TraveList(LB);
	printf("链表C：\n");
	TraveList(LC);
	
	return 0;
}