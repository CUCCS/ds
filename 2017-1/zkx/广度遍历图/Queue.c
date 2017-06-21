#include "Queue.h"

Status InitQueue(LinkQueue *Q)    // 初始化一个队列Q
{
	Q->front = Q->rear = (QueuePtr )malloc(MAX_SIZE * sizeof(QueuePtr)); //为队头，队尾指针分配内存空间
	if (!Q->front)
	{
		return ERROR;    //存储分配失败
	}
	Q->front->next = Q->rear->next = NULL;
	return OK;
}

bool QueueEmpty(LinkQueue Q)    //判断队列是否为空
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;

}

Status EnQueue(LinkQueue *Q, ElemType e)  // 插入元素e为Q的新的队尾元素
{
	QueuePtr p = (QueuePtr )malloc(MAX_SIZE * sizeof(QueuePtr));  //分配存储空间

	if (!p)
	{
		return OVERFLOW;   //存储分配失败
	}
	p->data = e;
	p->next = NULL;
	p->priou = Q->front;    //插入新的队尾结点时，令其priou域的指针指向刚刚出队列的结点
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e)  //出队列时，仅移动队头指针，而不将队头结点从链表中删除。
{                                                                                
	if (QueueEmpty(*Q)) 
	{
		return ERROR;
	}
	Q->front = Q->front->next;
	*e = Q->front->data;
	return OK;

}