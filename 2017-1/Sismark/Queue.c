#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
#define CREAT 10
#define OVERFLOW -1
#define OK 0
#define ERROR -1
#define FALSE 0
#define TRUE 1

typedef int Status;
typedef char QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode,*Queueptr;

typedef struct {
	Queueptr front;
	Queueptr rear;
}LinkQueue;

Status InitQueue(LinkQueue *pQ) {
	//构造一个空队列Q
	(*pQ).front = (*pQ).rear=	(*pQ).rear = (Queueptr)malloc(sizeof(QNode));
	if (!(*pQ).front) exit(OVERFLOW);
	(*pQ).front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue *pQ,QElemType e) {
	//插入元素e为Q的新的队尾元素
	Queueptr p;
	p = (Queueptr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e; p->next = NULL;
	(*pQ).rear->next = p;
	(*pQ).rear = p;
	return OK;
}

Status DeQueue(LinkQueue *pQ, QElemType *e) {
	Queueptr p;
	if ((*pQ).front == (*pQ).rear) return ERROR;
	p = (*pQ).front->next;
	*e = p->data;
	(*pQ).front->next = p->next;
	if ((*pQ).rear == p) (*pQ).rear = (*pQ).front;
	free(p);
	return *e;
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) return TRUE;
	else return FALSE;
}

void queue() {
	LinkQueue Q;
	QElemType e;
	InitQueue(&Q);
	char a[100]="sajnxskajnknc";
	int i = 0;
	while (a[i]!='\0')
	{
		EnQueue(&Q,a[i]);
		i++;
	}
	printf("\n出队列:");
	while (!QueueEmpty(Q)) {
		DeQueue(&Q,&e);
		printf("%c",e);
	}
}
int main() {
	queue();
	return 0;
}