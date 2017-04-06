#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ListLength 2
typedef int ElemType; 
typedef enum {
    ERROR,
	OK,
	OVERFLOW
}Status;
typedef struct LNode{
	ElemType data;
    struct LNode *next;
}LNode, *LinkList;
//链表创建函数
LNode *createList()
{
	LNode *p1, *p2;
	LNode *head = NULL;
	int n = 0;
	int l = ListLength;
	p2 = p1 = (LNode *)malloc(sizeof(LNode));
	srand((int)time(NULL));
	p1->data = rand()%101;
	printf( "%d  ", p1->data );
	while(l){
	    n = n + 1;
		if( n == 1){
			head = p1;
		}
		else{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (LNode *) malloc(sizeof(LNode));
		if( l != 1){
			srand((int)time(NULL));
	        p1->data = rand()%101 + 3;
			printf( "%d  ", p1->data );
		}
		l--;
	}
	p2->next = NULL;
	printf("\n");
	return head;
}//end of createList

void printList(LNode *head)
{
	LNode *p;
	p = head;
	if( head != NULL ){
		do{
			printf("%d\n", p->data);
			p = p->next;
		}while( p != NULL );
	}
}//end of printList

LinkList sort(LinkList l)
{
    LinkList p,q,small;
    int temp;
    for(p=l;p->next!=NULL;p=p->next)
    {
        small=p;
        for(q=p->next;q!=NULL;q=q->next){
             if(q->data<small->data)
			 {
                small=q;
			 }
                if(small!=p)
                {
                   temp=p->data;
                   p->data=small->data;
                   small->data=temp;
                }
		}
    }
    return l;
}//end of sort

Status MergeList_L(LinkList La, LinkList Lb)
{
//已知单链线性表La和Lb的元素按值非递减排列。
//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列。
	LinkList Lc;
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
	Lc = pc = La;
//用La的头结点作为Lc的头结点
    while (pa && pb) { 
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa; 
            pa = pa->next; 
        } 
		else {
			pc->next = pb; 
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; 
//插入剩余段
   free(Lb); 
//释放Lb的头结点
   Lc = sort(Lc);
   printList(Lc);
   return OK;
}//end of MergeList_L

int main()
{
	LNode *A = NULL;
	LNode *B = NULL;
	A = createList();
	B = createList();
	A = sort(A);
	B = sort(B);
	MergeList_L(A, B);
	return 0;
}