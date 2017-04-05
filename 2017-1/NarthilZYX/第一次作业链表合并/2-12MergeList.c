#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ListLength 2
typedef int ElemType; //元素类型
typedef enum {
    ERROR,
	OK,
	OVERFLOW
}Status;
typedef struct LNode{
	ElemType data;
    struct LNode *next;
}LNode, *LinkList;
LNode *createList()//链表创建函数
{
	LNode *p1, *p2;
	LNode *head = NULL;//头结点
	int n = 0;
	int l = ListLength;//l等于链表长度，便于控制输入的数据个数
	p2 = p1 = (LNode *)malloc(sizeof(LNode));//为p1p2分配内存
	srand((int)time(NULL));
	p1->data = rand()%101;//create random number
	printf( "%d  ", p1->data );
	while(l){
	    n = n + 1;
		if( n == 1)
			head = p1;//头结点指向p1
		else
			p2->next = p1;//p2尾结点指向p1
		p2 = p1;//?
		p1 = (LNode *) malloc(sizeof(LNode));//再次分配内存
		if( l != 1){
			srand((int)time(NULL));
	        p1->data = rand()%101 + 3;//create random number
			printf( "%d  ", p1->data );
		}
		l--;
	}//end of while
	p2->next = NULL;
	printf("\n");
	return head;
}//end of createList

void printList(LNode *head)
{
	LNode *p;
	p = head;//指针指向链表头结点
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