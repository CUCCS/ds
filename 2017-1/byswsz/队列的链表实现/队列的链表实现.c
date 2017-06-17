#include<stdio.h>
typedef int  QElemtype;
//���е���ʽ����ṹ
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
//����һ������ն���Q

Status InitQueue(LinkQueue *Q)

{

	printf("��ʼ��һ������\n");

	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));

	if (!Q->front)

	{

		return OVERFLOW;

	}

	Q->front->next = NULL;

	return OK;

}

//����eΪQ���µĶ�βԪ��

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

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ�����e������ֵ�����ҷ���OK
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

	printf("���ٵ�ͷԪ��Ϊ��%d\n", *e);

	free(p);

	return OK;

}

//���ٶ���Q

Status Destory(LinkQueue*Q)

{

	printf("���ٶ���\n");

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

	printf("�������У�\n");

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