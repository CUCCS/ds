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



/*初始化队列*/

Status InitQueue(LinkQueue *q);

/*添加一个结点，用e传递其值*/

Status EnQueue(LinkQueue *q, QElemType e);

/*检查队列是否为空*/

bool QueueEmpty(LinkQueue q);

/*删除一个结点， 用e返回其值*/

Status DeQueue(LinkQueue *q, QElemType *e);

/*遍历队列*/

Status TraverseQueue(LinkQueue q);

/*销毁队列*/

Status DestroyQueue(LinkQueue *q);

/*将队列q清空为空队列*/

Status ClearQueue(LinkQueue *q);

/*返回队列的长度*/

int QueueLength(LinkQueue *q);

/*返回队列的队头元素*/

Status GetHead(LinkQueue *q, QElemType *e);

#endif 