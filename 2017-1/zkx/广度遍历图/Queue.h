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

typedef struct _QNode    // �������
{
	ElemType      data;      //������
	struct QNode  *next;   //���ָ��
	struct QNode  *priou;  //ǰ��ָ��
} QNode, *QueuePtr;

typedef struct _LinkQueue  // ����������
{
	QueuePtr  front;  // ��ͷָ��
	QueuePtr  rear;   // ��βָ��
} LinkQueue;

Status InitQueue(LinkQueue *Q);

bool QueueEmpty(LinkQueue Q);

Status EnQueue(LinkQueue *Q, ElemType e);

Status DeQueue(LinkQueue *Q, ElemType *e);

Status QueueTraverse(LinkQueue *Q);

