#include <stdio.h>
#include <stdlib.h>

typedef int ElenType;
typedef struct LNode{
	ElenType data;
	struct LNode *next;
}LNode , *LinkList;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
}Status;

//函数
Status CreateList(LinkList L,int n);//创建一个链表
Status Traverse(LinkList L);//遍历链表
Status Distribute(LinkList L1,LinkList L2,LinkList L3);//创建三个链表
Status Traverse_separate(LinkList L);//遍历分开的链表