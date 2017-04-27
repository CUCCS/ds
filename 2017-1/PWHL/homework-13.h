#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK    1
#define ERROR 0
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;
//初始化链表
LNode *InitList(LNode *L);
//拆分链表
int SplitList(LNode *L, LNode **L1, LNode **L2);
//输出单链表
int PrintList(LNode *L);
//输出循环链表
int PrinttCircle_List(LNode *L);
//销毁链表
int Destroy(LNode **L);

//空间复杂度为O(1)
//时间复杂度为O(n),将链表拆分为2时只需要对链表循环一次