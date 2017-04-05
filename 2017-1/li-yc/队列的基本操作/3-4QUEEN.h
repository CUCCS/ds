#include <stdio.h>
#include <string.h>

typedef int QElemType;
typedef enum{
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct LinkQueue{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue q);
Status DestroyQueue(LinkQueue q);
Status EnQueue(LinkQueue *q,QElemType e);
bool QueueEmpty(LinkQueue q);
Status DeQueue(LinkQueue *q,QElemType *e);
Status CleanQueue(LinkQueue q);
int QueueLength(LinkQueue q);
Status GetHead(LinkQueue q,QElemType *e);
Status TraverseQueue(LinkQueue q);