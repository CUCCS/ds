//��ͷβָ�����ʽӳ��ʵ�ֵĵ�����е����л�������
#include <stdio.h>
#include <string.h>

typedef int QElemType;

typedef enum 
{
	false,
	true,
}bool;
typedef enum 
{
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct QNode 
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


Status InitQueue(LinkQueue q) //��ʼ������
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) 
	{
		exit(OVERFLOW);
	}
	q.front->next = NULL;
	printf("��ʼ�����\n");
	return OK;
}
Status DestroyQueue(LinkQueue q) //���ٶ���
{
	while (q.front) 
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
	return OK;
}
Status EnQueue(LinkQueue *q, QElemType e) //����в���Ԫ��
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) 
	{
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear->data = p->data;
	q->rear = p;
	return OK;
}
bool QueueEmpty(LinkQueue q) 
{
	if (q.front == q.rear) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
Status DeQueue(LinkQueue *q, QElemType *e) //ɾ����ͷԪ��
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (q->front == q->rear) 
	{
		return ERROR;
	}
	p = q->front;
	*e = p->data;
	q->front = q->front->next;
	if (q->rear == p) 
	{
		q->rear = q->front;
	}
	free(p);
	return OK;
}
Status CleanQueue(LinkQueue q) //��ն���
{
	QueuePtr p;
	QueuePtr next;
	if (QueueEmpty(q))
	{
		printf("���������Ϊ�ն���\n");
		return OK;
	}
	else 
	{
		for (p = q.front; p; p = next) 
		{
			next = p->next;
			free(p);
			p = next;
		}
	}
	printf("���������Ϊ�ն���\n");
	return OK;
}
int QueueLength(LinkQueue q)  //����г���
{
	QueuePtr p;
	QueuePtr next;
	int length = 0;
	p = q.front;
	while (p != q.rear) 
	{
		p = p->next;
		length++;
	}
	return length;
}
Status GetHead(LinkQueue q, QElemType *e) //���ͷԪ��
{
	*e = q.front->data;
	printf("��ʱ��ͷԪ��Ϊ%d\n", *e);
	return OK;
}
Status TraverseQueue(LinkQueue q)  //��������
{
	QueuePtr p;
	printf("��ʼ����:\n");
	if (QueueEmpty(q))
	{
		printf("��ʱ�����ﲻ����Ԫ��\n");
		return OK;
	}
	p = q.front;
	while (p != q.rear) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int main() 
{
	LinkQueue a;
	QElemType e;
	int len;
	int n;
	int num;
	int flag = 1;
	a.front = a.rear = (QueuePtr)malloc(sizeof(QNode));
	do
	{


	printf("----------���л�����������:---------\n");
	printf("-----------1.��ʼ������-------------\n");
	printf("-----------2.������в���Ԫ��-------\n");
	printf("-----------3.����г���-------------\n");
	printf("-----------4.ɾ����ͷԪ��(�ն�����Ч)\n");
	printf("-----------5.��������---------------\n");
	printf("-----------6.�˳�-------------------\n");
	printf("��ѡ�����Ĳ�����");
	scanf("%d",&n);
	switch (n)
	{
	case 1:
			InitQueue(a);
			TraverseQueue(a);
			len = QueueLength(a);
			printf("��ʱ���г���Ϊ %d\n\n", len);
			break;
	case 2:
			
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &num);
			EnQueue(&a, num);
			TraverseQueue(a);
			len = QueueLength(a);
			printf("��ʱ���г���Ϊ %d\n\n", len);
			break;

	case 3:
		    len = QueueLength(a);
			printf("��ʱ���г���Ϊ %d\n\n", len);
			break;

	case 4:
			GetHead(a, &e);
			DeQueue(&a, &e);
			printf("��ʱ���в�Ϊ�գ�ɾ����ͷԪ��%d\n", e);
			TraverseQueue(a);
			printf("\n");
			break;
	case 5:
		  TraverseQueue(a);
		  break;
	default:
		flag = 0;
		break;
	}
} while (flag==1);
	return 0;
}