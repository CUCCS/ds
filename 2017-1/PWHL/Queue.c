#include "Queue.h"
int main()
{
	LinkQueue  q;
	InitQueue(&q);
	QElemType x[10] = { 'a','b','c','d','e','f','h','i','j','k' };
	QElemType e;
	int i;
	for (i = 0; i < 10; i++)
	{
		EnQueue(&q, x[i]);
	}
	printf("   1.������ɵĶ���Ϊ\n");
	QueueTraverse(q);
	printf("\n   2.���еĳ���Ϊ %d\n\n", QueueLength(q));
	printf("   3.�ж϶����Ƿ�Ϊ�ղ����ض�ͷԪ��\n\n");
	if (GetHead(q, &e))
	{
		printf("   ���в�Ϊ�գ���ջ��Ԫ��Ϊ%c\n", e);
	}
	printf("\n   4.����ɾ������\n\n");
	while (!QueueEmpty(q))
	{
		DeQueue(&q, &e);
		printf("   ��ɾ����Ԫ��Ϊ%c\n", e);
		printf("   ɾ����Ķ���Ϊ\n");
		QueueTraverse(q);
	}
	printf("\n   5.���еĳ���Ϊ %d\n\n", QueueLength(q));
	printf("   6.���ٶ���\n");
	DestroyQueue(&q);
	return 0;
}
Status InitQueue(LinkQueue *Q)//����ն���
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
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
Status ClearQueue(LinkQueue *Q)//��ն���
{
	QueuePtr p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	p = NULL;
	Q->front = Q->rear = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q)//������Ϊ�գ�����TRUE�����򷵻�FALSE
{
	if (Q.front == Q.rear)
	{
		return TRUE;
	}
	return FALSE;
}
int QueueLength(LinkQueue Q)//����г���
{
	int i = 0;
	while (Q.front != Q.rear)
	{
		i++;
		Q.front = Q.front->next;
	}
	return i;
}
Status GetHead(LinkQueue Q, QElemType *e)//�����в��գ���e����Q�Ķ�ͷԪ�أ�������OK �����򷵻�ERROR
{
	QueuePtr p;
	if (Q.front == Q.rear)
	{
		return 0;
	}
	p = Q.front->next;
	*e = p->data;
	return TRUE;
}
Status EnQueue(LinkQueue *Q, QElemType e)//����Ԫ��eΪQ���µĶ�βԪ��
{
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(struct QNode))))
	{
		return 0;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e)//�����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
{
	QueuePtr p;
	if (Q->front == Q->rear)
	{
		return 0;
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
Status QueueTraverse(LinkQueue Q)// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi().
{
	Q.front = Q.front->next;
	while (visit(Q.front))
	{
		Q.front = Q.front->next;
	}
	printf("\n");
	return OK;
}
int visit(QueuePtr p)//���ʲ���ӡÿһ������Ԫ��
{
	if (NULL != p)
	{
		char x = p->data;
		printf("  %c ", x);
		return OK;
	}
	return 0;
}