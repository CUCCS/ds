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

//����
Status CreateList(LinkList L,int n);//����һ������
Status Traverse(LinkList L);//��������
Status Distribute(LinkList L1,LinkList L2,LinkList L3);//������������
Status Traverse_separate(LinkList L);//�����ֿ�������