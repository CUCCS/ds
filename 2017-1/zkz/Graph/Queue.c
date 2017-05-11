#include "Queue.h"
Queue newQueue() {
	Queue q;
	q.front = q.rear = q.lastOut = NULL;
	return q;
}
bool isEmpty(Queue q) {
	return !q.front && !q.rear;
}
void EnQueue(Queue* q, Elemtype data) {
	/*Step 1 �����½ڵ�*/
	Node* temp = (Node*)malloc(sizeof(Node));
	/*Step 2 Ϊ�½ڵ㸳ֵ*/
	temp->data = data;
	temp->next = NULL;
	temp->prior = q->lastOut;
	/*Step 3 ���½ڵ������*/
	if (isEmpty(*q)) {
		q->front = q->rear = temp;
	}
	else {
		q->rear->next = temp;
		q->rear = temp;
	}
}
void DeQueue(Queue*q) {
	q->lastOut = q->front;
	if (q->front->next == NULL) {
		q->rear = NULL;
	}
	q->front = q->front->next;
}
void TraverseQueue(Queue q) {
	Node*p = q.front;
	printf("\n q : ");
	if (!p) {
		printf("(empty)");
	}
	else {
		do {
			printf("%d ", p->data);
			p = p->next;
		} while (p);
	}
	printf("\n");
}