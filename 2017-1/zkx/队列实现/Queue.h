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

typedef struct _QNode    // �������
{ 
    QElemType      data;
    struct QNode  *next;
} QNode, *QueuePtr;

typedef struct _LinkQueue  // ����������
{       
	QueuePtr  front;  // ��ͷָ��
	QueuePtr  rear;   // ��βָ��
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


