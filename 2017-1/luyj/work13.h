//说明：
//时间复杂度：
//ParitySequence函数在将list线性链表分解成两个循环链表时，只用了一个循环遍历一次线性表。其时间复杂度约为O(n)(n为list链表的长度)，此时，时间复杂度应为最小。
//空间复杂度：
//在创建两个循环链表(list1,list2)时，只分别重新动态分配了一个头结点。创建两个循环链表的过程，属分解list的过程，list1,list2初头结点外其他结点，没有重新分配空间，而是直接将next指针指向list对应结点。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

//输出单链表；
Status output(LinkList L);

//输出循环单链表的一个周期；
Status output1(LinkList L);

//建立一个测试线性链表（第一个链结点为指针list的链表）
void CreateList_L(LinkList L, int n);

//将线性单链表分解到奇偶序列循环链表；
void ParitySequence(LinkList list, LinkList list1, LinkList list2);
