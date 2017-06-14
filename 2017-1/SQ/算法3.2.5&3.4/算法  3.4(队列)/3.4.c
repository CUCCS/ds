#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "3.4.h"

Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(MAXQSIZE * sizeof(QNode));
	if (!(Q->front)) {
		return OVERFLOW;
	}
	Q->front->next = NULL;
	Q->rear->next = NULL;
	printf("\n队列初始化完成\n");
	return OK;
}; //构造空队列
Status DestoryQueue(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	printf("队列销毁成功\n\n");
	return OK;
}; //销毁队列
Status ClearQueue(LinkQueue *Q) {
	Q->rear = Q->front = NULL;
	printf("\n队列清空完成\n");
	return OK;
}; //清空队列
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}; //判断是否为空队列
Status GetHead(LinkQueue Q, QElemType *e) { //需更改
	if (QueueEmpty(Q)) {
		printf("错误！空队列!\n");
		return ERROR;
	}
	*e = Q.front->next->data;
}; //返回队头元素
Status EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}; //插入新的队尾元素
Status DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr p = NULL;
	if (QueueEmpty(*Q)) {
		printf("错误！空队列!\n");
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}; //删除队头元素，并用e返回其值
Status QueueTraverse(LinkQueue Q) {
	QueuePtr p;
	int i = 1;
	p = Q.front->next;
	if (QueueEmpty(Q)) {
		printf("错误！空队列!\n");
		return ERROR;
	}
	while (p) {
		printf("%d ", p->data);
		p = p->next;
		i++;
	}
	printf("\n队列输出完毕\n");
	return OK;
}; //遍历队列中的元素,并将其输出
Status CreateQueue(int n){
	LinkQueue Q;
	QElemType e;
	int i, temp;
	if (InitQueue(&Q)) {
		printf("Initialize stack failed.\n");
		return ERROR;
	};
	for (i = 0; i < n; i++) {
		temp = rand() % 1024;
		EnQueue(&Q, temp);
	}

	printf("\n该队列的元素为：");
	QueueTraverse(Q);

	GetHead(Q, &e);
	printf("\n队列中第一个元素为：%d\n", e);
	printf("\n");

	for (i = 0; i < n; i++) {
		DeQueue(&Q, &e);
		printf("删除第%d个的元素：%d", i + 1, e);
		printf("\n该队列的元素为：");
		QueueTraverse(Q);
		printf("\n");
	}

	ClearQueue(&Q);
	DestoryQueue(&Q);

	return OK;
}
int main(){
	LinkQueue Q;
	int n;
	srand(time(NULL));
	n = rand() % 20 + 1;
	printf("随机产生队列的大小，其大小在1~20之间\n");
	printf("\n随机队列的大小： %d",n);

	CreateQueue(n);
	
	return 0;
}