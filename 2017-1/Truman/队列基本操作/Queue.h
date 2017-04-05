#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int QElemType;
typedef enum {
	FALSE,
	OK,
	OVERFLOW,
	TRUE,
	ERROR,
}Status;
typedef struct QNode {
	QElemType data;
	struct QNode *Next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType *e);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
Status QueueTraverse(LinkQueue Q);