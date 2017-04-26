#include<stdio.h>
typedef int  QElemtype;
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
	true,
	false
}Status;
//初始化一个队列
Status InitQueue(LinkQueue *Q)
{
	printf("初始化一个队列\n");
	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return false;
	}
	Q->front->next = NULL;
	return true;
}

//向队列尾部插入元素e
Status EnQueue(LinkQueue *Q, QElemtype e)
{
	QNodePtr s = (QNodePtr)malloc(sizeof(QNode));
	if (!s)
	{
		return false;
	}
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	return true;
}
//若队列不空，则删除队列头元素，并用e返回
Status DeQueue(LinkQueue *Q, QElemtype *e)
{
	QNodePtr p = NULL;
	if (Q->rear == Q->front)
	{
		return false;
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
	return true;
}
//销毁一个队列
Status Destory(LinkQueue*Q)
{
	printf("销毁队列\n");
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return true;
}
Status Traverse(LinkQueue*Q)
{
	if (Q->rear == Q->front)
	{
		printf("error ,Is a empty queue!\n");
		return false;
	}
	printf("遍历队列：\n");
	QNodePtr p = Q->front->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}
int main()
{
	int i, result;
	LinkQueue Q;
	InitQueue(&Q);
	for (i = 0; i < 5; i++)
	{
		EnQueue(&Q, i);//向队列尾部添加元素
	}
	Traverse(&Q);//第一次遍历
	DeQueue(&Q, &result);//销毁队列头元素
	Traverse(&Q);//第二次遍历
	Destory(&Q);//销毁队列
	Traverse(&Q);//第三次遍历
	return 0;
}