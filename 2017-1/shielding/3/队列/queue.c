#include <stdio.h>
#include <stdlib.h>

typedef enum{
	FALSE,
	TRUE
}bool;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;

typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueueP;

typedef struct{
	QueueP front, rear; /* 队头、队尾指针 */
}LinkQueue;
/* 链队列的基本操作: */
/* 1.构造一个空队列Q: */
void InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (QueueP) malloc(sizeof(QNode));
	if (!Q->front){
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
}
/*2. 销毁队列Q:*/
void DestroyQueue(LinkQueue *Q){
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
/*3.将Q清为空队列: */
void ClearQueue(LinkQueue *Q){
	QueueP p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
/*4.若Q为空队列，则返回TRUE，否则返回FALSE: */
bool QueueEmpty(LinkQueue Q){
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}
/* 5.求队列的长度:*/
int QueueLength(LinkQueue *Q){
	int i = 0;
	QueueP p;
	p = (*Q).front;
	while ((*Q).rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/* 6.若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR:*/
Status GetHead(LinkQueue Q, QElemType *e){
	QueueP p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}
/* 7.插入元素e为Q的新的队尾元素 */
void EnQueue(LinkQueue *Q, QElemType e){
	QueueP p = (QueueP)malloc(sizeof(QNode));
	if (!p){
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
/* 8.删除Q的队头元素，用e返回其值，并返回OK，若队列为空则返回ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e){
	QueueP p;
	if (Q->front == Q->rear){
		return ERROR;
	}
	p = Q->front;
	*e = p->data;
	Q->front = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
/* 9.从队头到队尾依次对队列Q中每个数据元素调用函数visit(),若队列为空返回ERROR*/
Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType)){
	if (Q.front == Q.rear)
		return ERROR;
	QueueP p;
	p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
void visit(QElemType e)
{
	printf("%d", e);
}
int main()
{
	LinkQueue *Q = NULL;
	QElemType *e;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	DeQueue(Q, e);
	printf("%d", QueueLength(Q));
	return 0;
}
