#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

typedef int QElemType;
typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef enum
{ 
	false,
	true
}bool;

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}*QueuePtr,QNode;
typedef struct LinkQueue
{
	QueuePtr front, rear;//��ͷ����βָ��
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{//��ʼ��һ������
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)//����ͷ���ʧ��
		return OVERFLOW;
	Q->front->next = NULL;
	return OK;
}
Status DestoryQueue(LinkQueue *Q)
{ //���ٶ���
	while (Q->front)
	{
		Q->rear = Q->front->next;//Q.rearָ��Q.front����һ�����
		free(Q->front);//�ͷ�Q.front��ָ���
		Q->front = Q->rear;//Q.frontָ��Q.front����һ�����
	}
	return OK;
}
Status ClearQueue(LinkQueue *Q)
{ //��������Ϊ��
	DestoryQueue(Q);//���ٶ���
	InitQueue(Q);//���¹������
	return OK;
}
bool QueueEmpty(LinkQueue Q)
{ //�ж϶����Ƿ�Ϊ��
	if (Q.front->next == NULL)
		return true;
	else return false;
}
int QueueLength(LinkQueue Q)
{ //����еĳ���
	int i = 0;//��������0
	QueuePtr p = Q.front;//pָ����
	while (Q.rear != p)//p��ָ��Ĳ���β���
	{
		i++;//��������1
		p = p->next;
	}
	return i;
}
Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if (Q.front == Q.rear) return ERROR;
	p = Q.front->next;//pָ���ͷ���
	*e = p->data;//����ͷԪ�ص�ֵ����e
	return OK;
}
Status EnQueue(LinkQueue *Q, QElemType e)
{ //����Ԫ��eΪ����Q���µĶ�βԪ��
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	//��̬�����½��
	if (!p)
		exit(OVERFLOW);
	p->data = e;//��e��ֵ�����½��
	p->next = NULL;//�½���ָ��Ϊ��
	Q->rear->next = p;//ԭ��β����ָ����Ϊָ���½��
	Q->rear = p;//βָ��ָ���½��
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e)
{ //�����в�Ϊ�գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	QueuePtr p;
	if (Q->front == Q->rear)//����Ϊ��
		return ERROR;
	p = Q->front->next;//pָ���ͷ���
	*e = p->data;//��ͷԪ�ظ���e
	Q->front->next = p->next;//ͷ���ָ����һ�����
	if (Q->rear == p)//���ɾ���Ķ�β���
		Q->rear = Q->front;//�޸Ķ�βָ��ָ��ͷ���
	free(p);
	return OK;
}
Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType))
{ //�Զ�ͷ����β���ζԶ�����ÿ��Ԫ�ص��ú���visit()
	QueuePtr p = Q.front->next;
	while (p)
	{
		visit(p->data);//��p��ָԪ�ص���visit()
		p = p->next;
	}
	printf("\n");
	return OK;
}
Status print(QElemType e)
{
	printf("%2d", e);
	printf("  ");
	return OK;
}


int main()
{
	int i, k,s,cha;
	QElemType d;
	LinkQueue q;
	InitQueue(&q);//����һ����ջ
	srand((unsigned)time(NULL));
	s = rand() % 21+1;
	for (i = 1; i <= s; i++)
	{
		EnQueue(&q, rand()%101);
	}
	printf("������һ����ջ\n");
	printf("ջ��Ԫ��Ϊ:");
	QueueTraverse(q, print);
	k = QueueEmpty(q);
	printf("�ж�ջ�Ƿ�Ϊ��:");
	if (k == 0)
		printf(" ��Ϊ��\n");
	else
		printf(" Ϊ��\n");
	k = GetHead(q, &d);
	printf("��ʱ��ͷԪ��Ϊ: %d\n", d);
	printf("ɾ�������ͷԪ��\n");
	DeQueue(&q, &d);
	k = GetHead(q, &d);
	printf("ɾ�����µĶ�ͷԪ��Ϊ��%d\n", d);
	printf("��ʱ���еĳ���Ϊ%d\n", QueueLength(q));
	cha = rand() % 101;
	EnQueue(&q, cha);
	printf("����һ���µ�Ԫ�أ�%d\n", cha);
	printf("��ʱջ��Ԫ��Ϊ:");
	QueueTraverse(q, print);
	ClearQueue(&q);
	printf("��ն��к�q.front=%u,q.rear=%u,q.front->next=%u", q.front, q.rear, q.front->next);
	QueueTraverse(q, print);
	k = QueueEmpty(q);
	printf("�ж�ջ�Ƿ�Ϊ��:");
	if (k == 0)
		printf(" ��Ϊ��\n");
	else
		printf(" Ϊ��\n");
	DestoryQueue(&q);
	printf("���ٶ��к�,q.front=%u,q.rear=%u\n", q.front, q.rear);
}
