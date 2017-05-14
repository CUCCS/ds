#include <stdio.h>
#include <string.h>
//头文件
typedef int QElemType;
//定义一个新类型
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
//结构体：队列
typedef struct LinkQueue{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//链队列
Status InitQueue(LinkQueue q);
Status DestroyQueue(LinkQueue q);
Status EnQueue(LinkQueue *q,QElemType e);
bool QueueEmpty(LinkQueue q);
Status DeQueue(LinkQueue *q,QElemType *e);
Status CleanQueue(LinkQueue q);
int QueueLength(LinkQueue q);
Status GetHead(LinkQueue q,QElemType *e);
Status TraverseQueue(LinkQueue q);
//所有的函数声明