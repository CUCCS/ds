#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define QElemType int 

typedef struct QNode 
{ 
	QElemType data; 
	struct QNode *next; 
}QNode, *QueuePtr; 
typedef struct 
{ 
	QueuePtr front; 
	QueuePtr rear;
}LinkQueue; 

typedef enum 
{ 
	OK, 
	ERROR, 
	OVERFLOW 
}Status; 

Status InitQueue(LinkQueue *Q) //构造空队列
{ 
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode)); 
	if (!Q->front) 
	{ 
		return ERROR; 
	} 
	Q->front->next = NULL; 
	return OK; 
} 
Status DestroyQueue(LinkQueue *Q) //销毁队列
{ 
	while (Q->front) 
	{ 

		Q->rear = Q->front->next; 
		free(Q->front); 
		Q->front = Q->rear; 
	} 
	return OK; 
} 
Status EnQueue(LinkQueue *Q, QElemType e) // 插入元素e为Q的新的队尾元素 
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
	return OK;
} 

Status DeQueue(LinkQueue *Q, QElemType *e)  // 若队列不空，则删除Q的队头元素
{ 
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); 
	if (Q->front == Q->rear) 
	{ 
		return ERROR; 
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

int QueueEmpty(LinkQueue*Q) //判断队列是否为空
{ 
	if (Q->front == Q->rear) 
	{ 
		return 1; 
	} 
	else 
	{ 
		return 0; 
	}
} 
Status ClearQueue(LinkQueue*Q) //清空队列
{ 
	QElemType e; 
	if (QueueEmpty(Q)) 
	{ 
		return ERROR; 
	} 

	while (!QueueEmpty(Q)) 
	{ 
		DeQueue(Q,&e); 
	} 
	return OK;
} 
int QueueLength(LinkQueue Q) //求队列长度
{ 
	int i = 0; 
	while (!QueueEmpty(&Q)) 
	{ 
		Q.front = Q.front->next; 
		i++; 
	} 
	return i;
} 
Status GetHead(LinkQueue Q, QElemType *e) //返回队列头元素 
{ 
	if (QueueEmpty(&Q) == 1) 
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

Status QueueTraverse (LinkQueue *Q )//遍历队列
{
	QueuePtr p = Q->front->next;
	if (Q->front == Q->rear)
	{
		printf("队列为空!\n");
		return ERROR;
	}
	else 
	{
		while (p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
		return OK;
	}
}

int main() 
{ 
	int n, n1; 
	int i; 
	QElemType e = 0; 
	LinkQueue q; 
	InitQueue(&q); 
	srand(time(0)); 
	n = rand() % 9 + 1; //生成随机数
	for (i = 0; i < n; i++) 
	{ 
		n1 = rand() % 9 + 1; 
		EnQueue(&q, n1); 
	} 
	printf("随机生成队列q:\n"); 
	QueueTraverse(&q); 
	printf("\n"); 
	printf("队列长度(加上头结点)：\n");
	printf("%d", QueueLength(q)); 
	printf("\n队列q队头元素为：\n"); 
	GetHead(q, &e); 
	printf("%d\n", e); 
	printf("删除队头元素，新队列为:\n"); 
	DeQueue(&q, &e); 
	QueueTraverse(&q); 
	printf("\n"); 
	if (!QueueEmpty(&q) ) 
	{ 
		printf("目前队列不为空\n"); 
	} 
	printf("清空队列\n"); 
	{ 
		ClearQueue(&q); 
	} 
	if (QueueEmpty(&q)) 
	{ 
		printf("目前队列为空\n"); 
	}
}