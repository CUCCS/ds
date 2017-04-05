//队列操作的基本实现

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define QelemType int
typedef enum
{
	Error, OK
}Status;
typedef struct QNode
{
	QelemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}Linkqueue;
Status InitQueue(Linkqueue *q)//构造一个空队列
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		return Error;
	q->front->next = NULL;
	return OK;
}
Status DestroyQueue(Linkqueue *q)//销毁队列
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}
Status EnQueue(Linkqueue *q, QelemType e)//插入元素
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return Error;
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return OK;
}
Status QueueEmpty(Linkqueue *q)//判断队列是否为空，是则返回OK,非则返回Error
{
	if (q->front == q->rear)
		return OK;
	else
		return Error;
}
QelemType DeQueue(Linkqueue *q)//若队列不空，删除队头元素，并返回其值，否则返回Error
{
	if (QueueEmpty(q))
		return Error;
	QueuePtr p;
	p = q->front->next;
	QelemType e;
	e = p->data;
	q->front->next=p->next;
	free(p);
	if (q->rear == p)
		q->front = q->rear;
	return e;
}
Status ClearQueue(Linkqueue *q)//将Q清为空队列
{
	q->front = q->rear;
	return OK;
}
int QueueLength(Linkqueue*q)//返回Q的元素个数
{
	int count = 1;
	QueuePtr p;
	p = q->front->next;
	while (p != q->rear)
	{
		count++;
		p = p->next;
	}
	return count;
}
QelemType GetHead(Linkqueue*q)//若队列不空，则用e返回队头元素，否则返回Error
{
	if (QueueEmpty(q))
		return Error;
	QueuePtr p;
	p = q->front->next;
	QelemType e;
	e = p->data;
	return e;
}
Status QueueTraverse(Linkqueue *q)
{
	QelemType e;
	while (!QueueEmpty(q))
	{
		e = DeQueue(q);
		printf("%d ", e);
	}
	return OK;
}
int main()
{
	Linkqueue Q;
	InitQueue(&Q);
	srand(time(NULL));
	//随机生成队列长度
	int num = rand() % 5;
	int i;
	for (i = 0;i < num;i++)
	{
		//随机生成队列数据
		QelemType a;
		a = rand() % 10;
		EnQueue(&Q, a);
	}
	//计算并输出队列长度
	printf("The length of the queue is:");
	printf("%d\n", QueueLength(&Q));
	//打印出该队列
	printf("Print the queue:\n");
	QueueTraverse(&Q);
	//销毁队列
	//DestroyQueue(&Q);
	return 0;


}