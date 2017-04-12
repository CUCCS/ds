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
	printf("\n���г�ʼ�����\n");
	return OK;
}; //����ն���
Status DestoryQueue(LinkQueue *Q) {
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	printf("�������ٳɹ�\n\n");
	return OK;
}; //���ٶ���
Status ClearQueue(LinkQueue *Q) {
	Q->rear = Q->front = NULL;
	printf("\n����������\n");
	return OK;
}; //��ն���
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}; //�ж��Ƿ�Ϊ�ն���
Status GetHead(LinkQueue Q, QElemType *e) { //�����
	if (QueueEmpty(Q)) {
		printf("���󣡿ն���!\n");
		return ERROR;
	}
	*e = Q.front->next->data;
}; //���ض�ͷԪ��
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
}; //�����µĶ�βԪ��
Status DeQueue(LinkQueue *Q, QElemType *e) {
	QueuePtr p = NULL;
	if (QueueEmpty(*Q)) {
		printf("���󣡿ն���!\n");
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
}; //ɾ����ͷԪ�أ�����e������ֵ
Status QueueTraverse(LinkQueue Q) {
	QueuePtr p;
	int i = 1;
	p = Q.front->next;
	if (QueueEmpty(Q)) {
		printf("���󣡿ն���!\n");
		return ERROR;
	}
	while (p) {
		printf("%d ", p->data);
		p = p->next;
		i++;
	}
	printf("\n����������\n");
	return OK;
}; //���������е�Ԫ��,���������
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

	printf("\n�ö��е�Ԫ��Ϊ��");
	QueueTraverse(Q);

	GetHead(Q, &e);
	printf("\n�����е�һ��Ԫ��Ϊ��%d\n", e);
	printf("\n");

	for (i = 0; i < n; i++) {
		DeQueue(&Q, &e);
		printf("ɾ����%d����Ԫ�أ�%d", i + 1, e);
		printf("\n�ö��е�Ԫ��Ϊ��");
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
	printf("����������еĴ�С�����С��1~20֮��\n");
	printf("\n������еĴ�С�� %d",n);

	CreateQueue(n);
	
	return 0;
}