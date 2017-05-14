#include <stdio.h>
#include <stdlib.h>

#include "3-4QUEEN.h"

Status InitQueue(LinkQueue q){
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q.front){
		exit(OVERFLOW);
	}
	q.front->next = NULL;
	printf("初始化完毕\n");
	return OK;
}
Status DestroyQueue(LinkQueue q){
	while(q.front){
		q.rear = q.front->next;
		free(q.front);
		q.front =  q.rear;
	}
	return OK;
}
Status EnQueue(LinkQueue *q,QElemType e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p){
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear->data = p->data;
	q->rear = p;
	return OK;
}
bool QueueEmpty(LinkQueue q){
	if(q.front == q.rear){
		return true;
	}
	else{
		return false;
	}
}
Status DeQueue(LinkQueue *q,QElemType *e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(q->front == q->rear){
		return ERROR;
	}
	p = q->front;
	*e = p->data;
	q->front = q->front->next;
	if(q->rear == p){
		q->rear = q->front;
	}
	free(p);
	return OK;
}
Status CleanQueue(LinkQueue q){
	QueuePtr p;
	QueuePtr next;
	if(QueueEmpty(q)){
		printf("将队列清空为空对列\n");
		return OK;
	}
	else{
		for(p = q.front; p; p = next){
			next = p->next;
			free(p);
			p = next;
		}
	}
	printf("将队列清空为空对列\n");
	return OK;
}
int QueueLength(LinkQueue q){
	QueuePtr p;
	QueuePtr next;
	int length = 0;
	p = q.front;
	while(p != q.rear){
		p = p->next;
		length++;
	}
	return length;
}
Status GetHead(LinkQueue q,QElemType *e){
	*e = q.front->data;
	printf("此时队头元素为%d\n",*e);
	return OK;
}
Status TraverseQueue(LinkQueue q){
	QueuePtr p;
	printf("开始遍历:\n");
	if(QueueEmpty(q)){
		printf("此时队列里不存在元素\n");
		return OK;
	}
	p = q.front;
	while(p != q.rear){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}