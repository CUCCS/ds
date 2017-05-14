#include "Queue.h"
int main()
{
	LinkQueue  q;
	InitQueue(&q);
	QElemType x[10] = { 'a','b','c','d','e','f','h','i','j','k' };
	QElemType e;
	int i;
	for (i = 0; i < 10; i++)
	{
		EnQueue(&q, x[i]);
	}
	printf("   1.插入完成的队列为\n");
	QueueTraverse(q);
	printf("\n   2.队列的长度为 %d\n\n", QueueLength(q));
	printf("   3.判断队列是否为空并返回队头元素\n\n");
	if (GetHead(q, &e))
	{
		printf("   队列不为空，且栈顶元素为%c\n", e);
	}
	printf("\n   4.依次删除队列\n\n");
	while (!QueueEmpty(q))
	{
		DeQueue(&q, &e);
		printf("   被删除的元素为%c\n", e);
		printf("   删除后的队列为\n");
		QueueTraverse(q);
	}
	printf("\n   5.队列的长度为 %d\n\n", QueueLength(q));
	printf("   6.销毁队列\n");
	DestroyQueue(&q);
	return 0;
}
Status InitQueue(LinkQueue *Q)//构造空队列
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front->next = NULL;
	return OK;
}
Status DestroyQueue(LinkQueue *Q)//销毁队列Q
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
Status ClearQueue(LinkQueue *Q)//清空队列
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	p = NULL;
	Q->front = Q->rear = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q)//若队列为空，返回TRUE，否则返回FALSE
{
	if (Q.front == Q.rear)
	{
		return TRUE;
	}
	return FALSE;
}
int QueueLength(LinkQueue Q)//求队列长度
{
	int i = 0;
	while (Q.front != Q.rear)
	{
		i++;
		Q.front = Q.front->next;
	}
	return i;
}
Status GetHead(LinkQueue Q, QElemType *e)//若队列不空，用e返回Q的队头元素，并返回OK ，否则返回ERROR
{
	QueuePtr p;
	if (Q.front == Q.rear)
	{
		return 0;
	}
	p = Q.front->next;
	*e = p->data;
	return TRUE;
}
Status EnQueue(LinkQueue *Q, QElemType e)//插入元素e为Q的新的队尾元素
{
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(struct QNode))))
	{
		return 0;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e)//若队列不空，删除Q的对头元素，用e返回其值，并返回OK，否则返回ERROR
{
	QueuePtr p;
	if (Q->front == Q->rear)
	{
		return 0;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;

}
Status QueueTraverse(LinkQueue Q)// 从队头到队尾依次对队列Q中每个元素调用函数vi().
{
	Q.front = Q.front->next;
	while (visit(Q.front))
	{
		Q.front = Q.front->next;
	}
	printf("\n");
	return OK;
}
int visit(QueuePtr p)//访问并打印每一个队列元素
{
	if (NULL != p)
	{
		char x = p->data;
		printf("  %c ", x);
		return OK;
	}
	return 0;
}