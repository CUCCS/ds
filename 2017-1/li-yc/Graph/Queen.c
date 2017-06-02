#include "Queen.h"

Status InitQueue(LinkQueue q) {
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q.front) {
		exit(OVERFLOW);
	}
	q.front->next = q.rear->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue *q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	p->prious = q->front;
	q->rear->next = p;
	q->rear = p;
	return OK;
}

bool QueueEmpty(LinkQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	else {
		return false;
	}
}

Status DeQueue(LinkQueue *q, QElemType *e) {
	if (QueueEmpty(*q)) {
		return ERROR;
	}
	q->front = q->front->next;
	*e = q->front->data;
	return OK;
}

Status TraverseQueue(LinkQueue q) {
	QueuePtr p;
	printf("开始遍历:\n");
	if (QueueEmpty(q)) {
		printf("此时队列里不存在元素\n");
		return OK;
	}
	p = q.front;
	while (p != q.rear) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
