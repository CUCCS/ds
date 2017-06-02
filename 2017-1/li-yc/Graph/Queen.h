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
	OVERFLOW,
	ERROR,
} Status;
typedef struct QNode {
	QElemType data;
	struct QNode *next;
	struct QNode *prious;
}QNode, *QueuePtr;
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*关于队列的相关操作*/
Status InitQueue(LinkQueue q);//初始化队列
Status EnQueue(LinkQueue *q,QElemType e);//加入一个结点
bool QueueEmpty(LinkQueue q);//检查队列是否为空
Status DeQueue(LinkQueue *q,QElemType *e);//删除一个结点
Status TraverseQueue(LinkQueue q);//遍历队列