#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LNode{
	int data;
	struct LNode  *next;
}LNode,*LinkList;

void CreateList (LinkList *L,int n)
{
	LinkList p = (LinkList) malloc(sizeof(LNode));
	LinkList temp = p;
	srand((unsigned)time( NULL ) );
	for(;n!=0;--n){
		p->next = (LinkList)malloc(sizeof(LNode));
		p->next->data = rand()%1024;
		p=p->next;
	}
	p->next = NULL;
	*L = temp->next;
	free(temp);
}//createlist

void Traverse1 (LinkList L)
{
	LNode *p = L;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
void Traverse2 (LinkList L)
{
	LNode *p = L->next;
	do{
		printf("%d ",p->data);
		p = p->next;
	}while(p != L->next);
	printf("\n");
}
void SplitList(LinkList L,LinkList*pL1,LinkList*pL2)
{
	*pL1=(LNode*)malloc(sizeof(LNode));
	(*pL1)->data = 0;
	(*pL1)->next = NULL;
	*pL2=(LNode*)malloc(sizeof(LNode));
	(*pL2)->data = 0;
	(*pL2)->next = NULL;
	LinkList p,rear1 = *pL1,rear2=*pL2;
	int count=0;
	for(p = L;p != NULL;p = p->next)
	{
		++count;
		if(count%2)
		{
			(*pL1)->data++;
			rear1->next = p;
			rear1 = p;
		}
		else
		{
			(*pL2)->data++;
			rear2->next = p;
			rear2 = p;
		}
	}
	rear1->next = (*pL1)->next;
	rear2->next = (*pL2)->next;
}
int main()
{
	LinkList L,L1 = NULL,L2 = NULL;
	int n;

	srand((unsigned)time( NULL ) );
	n = rand()%9+2;
	printf("数据的总个数为: %d\n",n);
	/*scanf("%d",&n);*/
	CreateList(&L,n);
	printf("待拆分的链表:\n");
	Traverse1(L);

	SplitList(L,&L1,&L2);
	printf("\n遍历链表L1:\n");
	Traverse2(L1);
	printf("\n遍历链表L2:\n");
	Traverse2(L2);
	return 0;
}
//程序又算法2-12修改得到，新增核心函数SplitList
//整个程序中，时间复杂度应在SplitList函数中体现，再拆分链表时有一个一重for循环的遍历，
//故时间复杂度应为o（n）
//空间复杂度在核心函数中用p1,p2，rear1,rear2辅助创建链表。