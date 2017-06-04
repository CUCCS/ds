#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int ElemType;

typedef enum
{
	ERROR,
	OVERFLOW,
	OK
} Status;

typedef enum 
{ 
	false, 
	true 
} bool;

typedef struct _QNode    // 结点类型
{
	ElemType      data;      //数据域
	struct QNode  *next;   //后继指针
	struct QNode  *priou;  //前驱指针
} QNode, *QueuePtr;

typedef struct _LinkQueue  // 链队列类型
{
	QueuePtr  front;  // 队头指针
	QueuePtr  rear;   // 队尾指针
} LinkQueue;

Status InitQueue(LinkQueue *Q);

bool QueueEmpty(LinkQueue Q);

Status EnQueue(LinkQueue *Q, ElemType e);

Status DeQueue(LinkQueue *Q, ElemType *e);

Status QueueTraverse(LinkQueue *Q);

