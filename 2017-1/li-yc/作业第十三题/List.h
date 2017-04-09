#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
typedef enum {
	OK,
	ERROR,
	OVERFLOW
} Status;

Status CreateList(LinkList L, int n);
Status Traverse(LinkList L);
Status Traverse_loop(LinkList L);
Status List_Distribute(LinkList list,LinkList list1,LinkList list2);
/*创建了三个链表，然后在List_Distribute中创立了三个指向结构体的指针，然后一个个分配，达到了时间利用的最少性，指针用完也释放
也最少利用空间了*/