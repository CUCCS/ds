#include <stdio.h>
#include <stdlib.h>
#define NUM 10//宏常量NUM为10
typedef char QElmtype;//定义QElmtype为字符串
typedef int Status;//定义Status为整数
typedef struct QNode{
	QElmtype data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct{
	Queueptr front;//队头指针
	Queueptr rear;//队尾指针
}LinkQueue;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status InitQueue (LinkQueue *Q);//构造一个空队列Q
Status DestoryQueue (LinkQueue *Q);//销毁队列Q，Q不再存在
Status ClearQueue (LinkQueue *Q);//将Q清为空队列
Status QueueEmpty (LinkQueue Q);//若队列Q为空队列，则返回TRUE，否则返回FALSE
int QueueLength (LinkQueue Q);//返回Q的元素个数，即为队列的长度
Status GetHead (LinkQueue Q, QElmtype *e);//若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
Status EnQueue (LinkQueue *Q, QElmtype e);//插入元素e为Q的新队尾元素 
Status DeQueue (LinkQueue *Q, QElmtype *e);//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR；
Status QueueTraverse (LinkQueue Q);//从队头到队尾依次对队列Q中每个元素调用visit（）。一旦visit失败，则操作失败
int visit(Queueptr);//访问并打印每一个队列元素