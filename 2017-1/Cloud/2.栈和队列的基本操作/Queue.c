#pragma once
#include "Queue.h"

/*初始化队列*/
Status InitQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) {
		exit(OVERFLOW);
	}
	q->front->next = NULL;
	q->rear->next = NULL;
	return OK;
}

/*添加一个元素，用e传递其值*/
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

/*检查队列是否为空*/
bool QueueEmpty(LinkQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	else {
		return false;
	}
}

/*删除队头元素， 用e返回其值*/
Status DeQueue(LinkQueue *q, QElemType *e) {
	if (QueueEmpty(*q)) {
		return ERROR;
	}
	QueuePtr p;
	p = q->front->next;//q->front为头节点，q->front->next为队头元素
	e = p->data;
	q->front->next = p->next;
	if (q->rear == p)//如果删除的是队列的最后一个元素，需要修改尾指针
		q->rear = q->front;
	return OK;
}

/*遍历队列*/
Status TraverseQueue(LinkQueue q) {
	QueuePtr p;
	if (QueueEmpty(q)) {
		printf("队列为空\n");
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

/*销毁队列*/
Status DestroyQueue(LinkQueue *q) {
	while (q->front) {
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
	return OK;
}

/*将队列q清空为空队列*/
Status ClearQueue(LinkQueue *q) {
	if (!QueueEmpty(*q)) {
		q->rear = q->front;
		return OK;
	}
	return false;
}

/*返回队列的长度*/
int QueueLength(LinkQueue *q) {
	int l;
	QueuePtr lq;
	for (l = 0, lq = q->front->next; lq != q->rear; l++) {
		lq = lq->next;
	}
	return l + 1;
}

/*返回队列的队头元素*/
Status GetHead(LinkQueue *q, QElemType *e) {
	if (!QueueEmpty(*q)) {
		*e = q->front->next->data;
		return OK;
	}
	return false;
}