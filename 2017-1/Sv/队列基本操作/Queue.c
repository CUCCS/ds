#include"Queue.h"
Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);
	Q->front->Next = NULL;
	return OK;
}
Status DestroyQueue(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->Next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
Status ClearQueue(LinkQueue *Q) {
	QNode *p, *next;
	p = Q->front;
	while (p!=Q->rear) {
		next = p->Next;
		free(p);
		p = next;
	}
	
	free(p);
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	//Q->front->Next = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)return TRUE;
	else return FALSE;
}
int QueueLength(LinkQueue Q) {
	QNode *p;
	p = Q.front;
	int k = 1;
	while (p != Q.rear) {
		p = p->Next;
		k++;
	}
	return k-1;
}
Status GetHead(LinkQueue Q, QElemType *e) {
	if (QueueEmpty(Q) == FALSE) {
		*e = Q.front->Next->data;
		return OK;
	}
	else {
		return ERROR;
	}
}
Status EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->Next = NULL;
	Q->rear->Next = p;
	Q->rear = p;
	return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e) {
	if (Q->front == Q->rear)return ERROR;
	QueuePtr p;
	p = Q->front->Next;
	*e = p->data;
	Q->front->Next = p->Next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}
Status QueueTraverse(LinkQueue Q) {
	QNode *p;
	p = Q.front->Next;
	while (p != Q.rear) {
		printf("%d ", p->data);
		p = p->Next;
	}
	printf("%d ", p->data);
	return OK;
}