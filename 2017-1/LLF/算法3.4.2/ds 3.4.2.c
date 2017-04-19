#include<stdio.h>
#include<stdlib.h>
typedef int	QelemType;

typedef struct QNode
{
	QelemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��

}LinkQueue;

typedef enum
{
	OK,//OK=0
	ERROR,//ERROR=1
	OVERFLOW//OVERFLOW=2
}Status;

typedef enum
{
	true,
	false
}bool;

Status InitQueue(LinkQueue *Q)//����һ���ն���Q
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW); //�洢����ʧ��
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)//���ٶ���Q
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)//��Q��Ϊ�ն���
{
	QNode *p = Q->front;
	while (p != NULL)//����ɾ�������е�ÿһ����㣬���ʹ����ָ��Ϊ��
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->rear = NULL;
	return OK;
}

bool QueueEmpty(LinkQueue *Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->front == NULL)
	{
		return false;
	}
	else return true;
}

int QueueLength(LinkQueue *Q)//����Ԫ�ظ����������г���
{
	QueuePtr p;
	p = Q->front->next;
	int i = 1;
	while (p != Q->rear)

	{
		i++;
		p = p->next;
	}
	return i;

}

QelemType GetHead(LinkQueue *Q, QelemType *e)
//�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
{
	if (Q->front == NULL)
	{
		exit(ERROR);
	}
	
	return  *e=Q->front->next->data;
	
}

Status EnQueue(LinkQueue *Q, QelemType e)//����Ԫ��eΪQ���µĶ�βԪ��
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);//�洢����ʧ��
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QelemType *e)
//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
//���򷵻�ERROR
{
	QNode *p;
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	QelemType e;
	p = Q.front->next;
	while (p)
	{
		e = p->data;
		printf("%d", e);
		printf("   ");
		p = p->next;
	}
	printf("\n");
	return OK;
}


void main()
{
	LinkQueue q;
	InitQueue(&q);
	QelemType a[] = { 1,2,3,4,5,6 };
	QelemType e;
	for (int i = 0; i < 6; i++)
	{
		EnQueue(&q, a[i]);
	}
	if (!QueueEmpty(&q)) printf("���зǿ�\n");
	printf("������ɣ�");
	QueueTraverse(q);
	printf("\n���еĳ��ȣ� %d\n", QueueLength(&q));
	GetHead(&q, &e);
	printf("��ͷԪ�أ�%d\n", e);
	DeQueue(&q,&e);
	printf("ɾ����ͷԪ�� %d �� ��",e);
	QueueTraverse(q);
	if (!ClearQueue(&q))printf("\n��ն��гɹ�");
	if(!DestroyQueue(&q))
	printf("\n���ٶ��гɹ�");
}
