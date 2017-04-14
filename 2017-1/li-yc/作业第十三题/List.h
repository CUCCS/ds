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
/*��������������Ȼ����List_Distribute�д���������ָ��ṹ���ָ�룬Ȼ��һ�������䣬�ﵽ��ʱ�����õ������ԣ�ָ������Ҳ�ͷ�
Ҳ�������ÿռ���*/