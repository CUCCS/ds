#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ListLength 12
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
	        p1->data = rand()%101 + 5*n;
			printf( "%d  ", p1->data );
		}
		l--;
	}
	p2->next = NULL;
	printf("\n");
	return head;
}//end of createList

//链表遍历函数
Status TraverseList(LNode *head)
{
	LNode *p;
	p = head;
	if( head != NULL ){
		do{
			printf("%d  ", p->data);
			p = p->next;
		}while( p != NULL );
	}
	printf("\n");
	return OK;
}//end of printList