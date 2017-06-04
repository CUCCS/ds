#ifndef H_QUEUE  
#define H_QUEUE

#define MAXQSIZE 100
typedef struct QNode
{
	int data;
	struct QNode *prious;
	struct QNode *next;
}QNode, LinkList, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

#endif 