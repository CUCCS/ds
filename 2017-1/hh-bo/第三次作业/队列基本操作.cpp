//���в����Ļ���ʵ��

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
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}Linkqueue;
Status InitQueue(Linkqueue *q)//����һ���ն���
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		return Error;
	q->front->next = NULL;
	return OK;
}
Status DestroyQueue(Linkqueue *q)//���ٶ���
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}
Status EnQueue(Linkqueue *q, QelemType e)//����Ԫ��
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
Status QueueEmpty(Linkqueue *q)//�ж϶����Ƿ�Ϊ�գ����򷵻�OK,���򷵻�Error
{
	if (q->front == q->rear)
		return OK;
	else
		return Error;
}
QelemType DeQueue(Linkqueue *q)//�����в��գ�ɾ����ͷԪ�أ���������ֵ�����򷵻�Error
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
Status ClearQueue(Linkqueue *q)//��Q��Ϊ�ն���
{
	q->front = q->rear;
	return OK;
}
int QueueLength(Linkqueue*q)//����Q��Ԫ�ظ���
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
QelemType GetHead(Linkqueue*q)//�����в��գ�����e���ض�ͷԪ�أ����򷵻�Error
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
	//������ɶ��г���
	int num = rand() % 5;
	int i;
	for (i = 0;i < num;i++)
	{
		//������ɶ�������
		QelemType a;
		a = rand() % 10;
		EnQueue(&Q, a);
	}
	//���㲢������г���
	printf("The length of the queue is:");
	printf("%d\n", QueueLength(&Q));
	//��ӡ���ö���
	printf("Print the queue:\n");
	QueueTraverse(&Q);
	//���ٶ���
	//DestroyQueue(&Q);��Ϊ�ڴ�ӡ�Ĺ����е�����DeQueue����������������޷���ȷ�������ٺ���
	return 0;


}