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
//��ʼ��һ������
Status InitQueue(LinkQueue *Q)
{
	printf("��ʼ��һ������\n");
	Q->front = Q->rear = (QNodePtr)malloc(sizeof(QNode));
	if (!Q->front)
	{
		return false;
	}
	Q->front->next = NULL;
	return true;
}

//�����β������Ԫ��e
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
//�����в��գ���ɾ������ͷԪ�أ�����e����
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
	printf("���ٵ�ͷԪ��Ϊ��%d\n", *e);
	free(p);
	return true;
}
//����һ������
Status Destory(LinkQueue*Q)
{
	printf("���ٶ���\n");
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
	printf("�������У�\n");
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
		EnQueue(&Q, i);//�����β�����Ԫ��
	}
	Traverse(&Q);//��һ�α���
	DeQueue(&Q, &result);//���ٶ���ͷԪ��
	Traverse(&Q);//�ڶ��α���
	Destory(&Q);//���ٶ���
	Traverse(&Q);//�����α���
	return 0;
}