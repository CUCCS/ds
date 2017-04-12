#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
typedef char QElemType;
typedef int Status;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct Queue
{
	QueuePtr front;//对头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue *Q);//构造空队列
Status DestroyQueue(LinkQueue *Q);//销毁队列Q
Status ClearQueue(LinkQueue *Q);//清空队列
Status QueueEmpty(LinkQueue Q);//若队列为空，返回TRUE，否则返回FALSE
int QueueLength(LinkQueue Q);//求队列长度
Status GetHead(LinkQueue Q, QElemType *e);//若队列不空，用e返回Q的队头元素，并返回OK ，否则返回ERROR
Status EnQueue(LinkQueue *Q, QElemType e);//插入元素e为Q的新的队尾元素
Status DeQueue(LinkQueue *Q, QElemType *e);//若队列不空，删除Q的对头元素，用e返回其值，并返回OK，否则返回ERROR
Status QueueTraverse(LinkQueue Q);// 从队头到队尾依次对队列Q中每个元素调用函数vi().
int visit(Queueptr);//访问并打印每一个队列元素
