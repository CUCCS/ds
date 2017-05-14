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
    QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

//����һ���ն���Q
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

//���ٶ���Q
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

//��Q���Ϊ�ն���
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

//������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
Status QueueEmpty(LinkQueue *Q)
{
	if(Q->rear==Q->front)
	{
		return OK;
	}
	return ERROR;
}

//����Q��Ԫ�ظ�������Ϊ���еĳ���
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

//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
Status GetHead(LinkQueue Q,QElemType *e)
{
    if(Q.front==Q.rear)
	{
		return ERROR;
	}
	*e = Q.front->next->data;
    return OK;
}

//����Ԫ��eΪQ���¶�βԪ��
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

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
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

//���б���
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