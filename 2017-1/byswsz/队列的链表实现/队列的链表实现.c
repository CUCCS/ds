#include<stdio.h>
typedef int  QElemtype;
//队列的链式储存结构
typedef struct QNode

{

	QElemtype data;

	struct QNode *next;

}QNode, *QNodePtr;

typedef struct

{

	QNodePtr front;

	QNodePtr rear;

}LinkQueue;

typedef enum

{

	OK,

	OVERFLOW

}Status;
//构造一个构造空队列Q

Status InitQueue(LinkQueue *Q)

{

	printf("初始化一个队列\n");

	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));

	if (!Q->front)

	{

		return OVERFLOW;

	}

	Q->front->next = NULL;

	return OK;

}

//插入e为Q的新的队尾元素

Status EnQueue(LinkQueue *Q, QElemtype e)

{

	QNodePtr s = (QNodePtr)malloc(sizeof(QNode));

	if (!s)

	{

		return OVERFLOW;

	}

	s->data = e;

	s->next = NULL;

	Q->rear->next = s;

	Q->rear = s;

	return OK;

}

//若队列不空，则删除Q的队头元素，并用e返回其值，并且返回OK
Status DeQueue(LinkQueue *Q, QElemtype *e)

{

	QNodePtr p = NULL;

	if (Q->rear == Q->front)

	{

		return OVERFLOW;

	}

	p = Q->front->next;

	*e = p->data;

	Q->front->next = p->next;

	if (p == Q->rear)

	{

		Q->rear = Q->front;

	}

	printf("销毁的头元素为：%d\n", *e);

	free(p);

	return OK;

}

//销毁队列Q

Status Destory(LinkQueue*Q)

{

	printf("销毁队列\n");

	while (Q->front)

	{

		Q->rear = Q->front->next;

		free(Q->front);

		Q->front = Q->rear;

	}

	return OK;

}
//
Status Traverse(LinkQueue*Q)

{

	if (Q->front == Q->rear)

	{

		return OVERFLOW;

	}

	printf("遍历队列：\n");

	QNodePtr p = Q->front->next;

	while (p)

	{

		printf("%d ", p->data);

		p = p->next;

	}

	printf("\n");

	return OK
		;

}

int main()

{

	int i, result;

	LinkQueue Q;

	InitQueue(&Q);

	for (i = 0; i < 5; i++)

	{
		EnQueue(&Q, i);
	}
	Traverse(&Q);
	DeQueue(&Q, &result);
	Traverse(&Q);
    return 0;
}