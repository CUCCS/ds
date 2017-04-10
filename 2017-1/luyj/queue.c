#include "queue.h"

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return ERROR;
	}
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue*Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status EnQueue(LinkQueue*Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
	{
		return ERROR;
	}
	else
	{
		p->data = e;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
	}
}

Status DeQueue(LinkQueue*Q, QElemType*e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	QNode *p= Q->front->next; //指向队头;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

bool QueueEmpty(LinkQueue*Q)
{
	if (Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status ClearQueue(LinkQueue*Q)
{
	QElemType e;
	if (QueueEmpty(Q)==true)
	{
		return ERROR;
	}
	while (QueueEmpty(Q)==false)
	{
		DeQueue(Q,&e);
	}
}



int QueueLength(LinkQueue Q)
{
	int i = 0;
	while (QueueEmpty(&Q) == false)
	{
		Q.front = Q.front->next;
		i++;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType *e)
{
	if (QueueEmpty(&Q) == true)
	{
		return ERROR;
	}
	else
	{
		QNode *p = Q.front->next;
		*e = p->data;
		return OK;
	}
}

Status QueueTraverse(LinkQueue Q)
{
	if (QueueEmpty(&Q) == true)
	{
		printf("EORROR");
	}
	else
	{
		QNode*p = Q.front->next;
		while (p != Q.rear)
		{
			printf("%d", p->data);
			p = p->next;
		}
		return OK;
	}
}

