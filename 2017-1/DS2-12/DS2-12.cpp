#include<stdio.h>
#include<stdlib.h>
#define ListLength 2
typedef int ElemType; //元素类型
typedef struct LNode{ 
	ElemType data;
    struct LNode *next;
}LNode;
LNode *createList()//链表创建函数
{
	LNode *p1, *p2;
	LNode *head = NULL;//头结点
	int n = 0;
	int l = ListLength;//l等于链表长度，便于控制输入的数据个数
	p2 = p1 = (LNode *)malloc(sizeof(LNode));//为p1p2分配内存
	scanf("%d", &p1->data);//输入p1链表的数据元素
	while(l){
	    n = n + 1;
		if( n == 1)
			head = p1;//头结点指向p1
		else
			p2->next = p1;//p2尾结点指向p1
		p2 = p1;//?
		p1 = (LNode *) malloc(sizeof(LNode));//再次分配内存
		if( l != 1)
			scanf("%d", &p1->data);//若输入数据个数小于链表长度，则继续输入
		l--;
	}//end of while
	p2->next = NULL;
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
LNode *mergeList(LNode *l1, LNode *l2)
{
	LNode *head, *p1, *p2, *pos;
	head = p1 = l1;
	p2 = l2;
	pos = head;
	while(p2 != NULL){
		p1 = p1->next;//依次进行插入
		pos->next = p2;
		pos = p2;
		p2 = p2->next;
		pos->next = p1;
		pos = p1;
	}
	return head;
}//end of mergeList

int main()
{
	LNode *A = NULL;
	LNode *B = NULL;
	A = createList();
	B = createList();
	A = mergeList(A, B);
	printList(A);
	return 0;
}