#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QElemType int
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	true,
	false
}bool;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue*Q);
Status EnQueue(LinkQueue*Q, QElemType e);
Status DeQueue(LinkQueue*Q, QElemType*e);
bool QueueEmpty(LinkQueue*Q);
Status ClearQueue(LinkQueue*Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType *e);
Status QueueTraverse(LinkQueue Q);
