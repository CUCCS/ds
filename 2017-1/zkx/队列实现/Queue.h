#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int QElemType;

typedef enum  
{
	ERROR,
	OVERFLOW,
	OK,
	TRUE,
	FALSE
} Status;

typedef struct _QNode    // 结点类型
{ 
    QElemType      data;
    struct QNode  *next;
} QNode, *QueuePtr;

typedef struct _LinkQueue  // 链队列类型
{       
	QueuePtr  front;  // 队头指针
	QueuePtr  rear;   // 队尾指针
} LinkQueue;

Status InitQueue (LinkQueue *Q);

Status DestroyQueue (LinkQueue *Q);

Status ClearQueue (LinkQueue Q);

Status QueueEmpty (LinkQueue *Q);

void GetHead(LinkQueue *Q, QElemType e);

int QueueLength (LinkQueue *Q);

Status EnQueue (LinkQueue *Q, QElemType e);

Status DeQueue(LinkQueue *Q, QElemType *e);

Status QueueTraverse(LinkQueue *Q);


