#pragma once
#include "Queue.h"

/*��ʼ������*/
Status InitQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) {
		exit(OVERFLOW);
	}
	q->front->next = NULL;
	q->rear->next = NULL;
	return OK;
}

/*���һ��Ԫ�أ���e������ֵ*/
Status EnQueue(LinkQueue *q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	return OK;
}

/*�������Ƿ�Ϊ��*/
bool QueueEmpty(LinkQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	else {
		return false;
	}
}

/*ɾ����ͷԪ�أ� ��e������ֵ*/
Status DeQueue(LinkQueue *q, QElemType *e) {
	if (QueueEmpty(*q)) {
		return ERROR;
	}
	QueuePtr p;
	p = q->front->next;//q->frontΪͷ�ڵ㣬q->front->nextΪ��ͷԪ��
	e = p->data;
	q->front->next = p->next;
	if (q->rear == p)//���ɾ�����Ƕ��е����һ��Ԫ�أ���Ҫ�޸�βָ��
		q->rear = q->front;
	return OK;
}

/*��������*/
Status TraverseQueue(LinkQueue q) {
	QueuePtr p;
	if (QueueEmpty(q)) {
		printf("����Ϊ��\n");
		return OK;
	}
	p = q.front->next;
	while (p != q.rear) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("%d", p->data);
	printf("\n");
	return OK;
}

/*���ٶ���*/
Status DestroyQueue(LinkQueue *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}

/*������q���Ϊ�ն���*/
Status ClearQueue(LinkQueue *q) {
	if (!QueueEmpty(*q)) {
		q->rear = q->front;
		return OK;
	}
	return false;
}

/*���ض��еĳ���*/
int QueueLength(LinkQueue *q) {
	int l;
	QueuePtr lq;
	for (l = 0, lq = q->front->next; lq != q->rear; l++) {
		lq = lq->next;
	}
	return l + 1;
}

/*���ض��еĶ�ͷԪ��*/
Status GetHead(LinkQueue *q, QElemType *e) {
	if (!QueueEmpty(*q)) {
		*e = q->front->next->data;
		return OK;
	}
	return false;
}