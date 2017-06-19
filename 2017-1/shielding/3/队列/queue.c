#include <stdio.h>
#include <stdlib.h>

typedef enum{
	FALSE,
	TRUE
}bool;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;

typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode, *QueueP;

typedef struct{
	QueueP front, rear; /* ��ͷ����βָ�� */
}LinkQueue;
/* �����еĻ�������: */
/* 1.����һ���ն���Q: */
void InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (QueueP) malloc(sizeof(QNode));
	if (!Q->front){
		exit(OVERFLOW);
	}
	Q->front->next = NULL;
}
/*2. ���ٶ���Q:*/
void DestroyQueue(LinkQueue *Q){
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
/*3.��Q��Ϊ�ն���: */
void ClearQueue(LinkQueue *Q){
	QueueP p, q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}
/*4.��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE: */
bool QueueEmpty(LinkQueue Q){
	if (Q.front->next == NULL)
		return TRUE;
	else
		return FALSE;
}
/* 5.����еĳ���:*/
int QueueLength(LinkQueue *Q){
	int i = 0;
	QueueP p;
	p = (*Q).front;
	while ((*Q).rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}
/* 6.�����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR:*/
Status GetHead(LinkQueue Q, QElemType *e){
	QueueP p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}
/* 7.����Ԫ��eΪQ���µĶ�βԪ�� */
void EnQueue(LinkQueue *Q, QElemType e){
	QueueP p = (QueueP)malloc(sizeof(QNode));
	if (!p){
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}
/* 8.ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��������Ϊ���򷵻�ERROR */
Status DeQueue(LinkQueue *Q, QElemType *e){
	QueueP p;
	if (Q->front == Q->rear){
		return ERROR;
	}
	p = Q->front;
	*e = p->data;
	Q->front = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
/* 9.�Ӷ�ͷ����β���ζԶ���Q��ÿ������Ԫ�ص��ú���visit(),������Ϊ�շ���ERROR*/
Status QueueTraverse(LinkQueue Q, void(*visit)(QElemType)){
	if (Q.front == Q.rear)
		return ERROR;
	QueueP p;
	p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
void visit(QElemType e)
{
	printf("%d", e);
}
int main()
{
	LinkQueue *Q = NULL;
	QElemType *e;
	InitQueue(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	DeQueue(Q, e);
	printf("%d", QueueLength(Q));
	return 0;
}
