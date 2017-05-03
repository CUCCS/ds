#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef char TElemType;
#define MAXQSIZE 100 //���д�С����
typedef struct BiTNode
{
	TElemType      data;
	struct BiTNode  *lchild, *rchild;
} BiTNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef enum {
	false,
	true
}bool;//��������״̬
typedef struct QNode { //���нṹ����
	TElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q);
Status EnQueue(LinkQueue *Q, TElemType e);
Status DeQueue(LinkQueue *Q, TElemType *e);
Status CreateBiTree(BiTree *T, TElemType *p);
void PostOrderTraverse(BiTree T);
int Depth(BiTree T); 
int Count(BiTree top);
int Width(BiTree T);
int NoLeafCount(BiTree  T);