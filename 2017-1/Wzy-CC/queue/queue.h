#define QUEUE_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef int QElemType;

typedef enum {

	false,

	true,

}bool;

typedef enum {

	OK,

	ERROR,

	OVERFLOW

} Status;

typedef struct QNode {

	QElemType data;

	struct QNode *next;

}QNode, *QueuePtr;

typedef struct _LinkQueue {

	QueuePtr front;

	QueuePtr rear;

}LinkQueue;



/*��ʼ������*/

Status InitQueue(LinkQueue *q);

/*���һ����㣬��e������ֵ*/

Status EnQueue(LinkQueue *q, QElemType e);

/*�������Ƿ�Ϊ��*/

bool QueueEmpty(LinkQueue q);

/*ɾ��һ����㣬 ��e������ֵ*/

Status DeQueue(LinkQueue *q, QElemType *e);

/*��������*/

Status TraverseQueue(LinkQueue q);

/*���ٶ���*/

Status DestroyQueue(LinkQueue *q);

/*������q���Ϊ�ն���*/

Status ClearQueue(LinkQueue *q);

/*���ض��еĳ���*/

int QueueLength(LinkQueue *q);

/*���ض��еĶ�ͷԪ��*/

Status GetHead(LinkQueue *q, QElemType *e);

#endif 