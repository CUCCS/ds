#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define QSIZE 10
typedef int QElemType;
typedef enum{
    ERROR,
	OK,
	OVERFLOW
}Status;
typedef struct QNode {
    QElemType data;
	struct QNode *next;
}QNode, * QueuePtr;
typedef struct {
    QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//构造一个空队列Q
Status InitQueue(LinkQueue *Q)
{
	Q->front =	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
	{
		return OVERFLOW;
	}
	Q->front->next = NULL;
	return OK;
}

//销毁队列Q
Status DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	printf("DestroyQueue called.\n");
	return OK;
}

//将Q清空为空队列
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr i;
	i=Q->front;
    while ( i != Q->rear)
    {
        i=0;
        i++;
    }
    Q->front = Q->rear = NULL;
	printf("ClearQueue called.\n");
	return OK;
}

//若队列Q为空队列，则返回TRUE，否则返回FALSE
Status QueueEmpty(LinkQueue *Q)
{
	if(Q->rear==Q->front)
	{
		return OK;
	}
	return ERROR;
}

//返回Q的元素个数，即为队列的长度
int QueueLength(LinkQueue Q)
{
	int count = 0;
	QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        //printf("%d",p->data);
        p=p->next;
		count++;
     }
	 return count;
}

//若队列不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
Status GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front==Q.rear)
	{
		return ERROR;
	}
	*e = Q.front->next->data;
    return OK;
}

//插入元素e为Q的新队尾元素
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
	{
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
Status DeQueue(LinkQueue *Q )
{
	QNode *p;
	QElemType e;
	if(Q->front==Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	e = p->data;
	printf("%d was deleted.\n", e);
	Q->front->next = p->next;
	if(Q->rear==p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

//队列遍历
Status TraverseQueue(LinkQueue Q)  
{  
	QueuePtr p;
    QElemType e;
    p=Q.front->next;
    while(p)
    {
        e=p->data;
        printf("%d",e);
        //printf("%d",p->data);
        printf("   ");
        p=p->next;
     }
     printf("\n");
	 return OK;
}

int main()
{
	LinkQueue Lq;
	QElemType e;
	QElemType *q = NULL;
	int i;//loop counter
	printf("Create a new queue:\n");

	//test InitQueue
	InitQueue(&Lq);
	printf("Create random elements:\n");

	for( i = 0; i < QSIZE; i++ )
	{
        srand((int)time(NULL));
	    e = rand()%100 + i;
		printf("%d ",e);
		//test EnQueue;
		EnQueue(&Lq, e);
	}

	//test QueueLength
	printf("\nThe length of the queue is: %d\n", QueueLength(Lq));

	//test QueueEmpty
	if(QueueEmpty(&Lq))
	{
		printf("\nThe queue is empty.\n");
	}
	else
	{
		printf("\nThe queue is not empty.\n");
	}

	printf("Get the head of the queue:\n");
	//test GetHead
	GetHead(Lq,&e);
	printf("%d\n", e);

	printf("Traverse of queue here:\n");
	//test TraverseQueue
	TraverseQueue(Lq);

	printf("Dequeue here:\n");
	//test DeQueue
	for( i = 0; i < QSIZE; i++ )
	{
		DeQueue(&Lq);
	}

	//test clearQueue
	ClearQueue(&Lq);

	//test DestroyQueue
	DestroyQueue(&Lq);

	return 0;
}