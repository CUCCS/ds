#include "Queue.h"

Status InitQueue(Queue* pQ) {
	checkEmpty(pQ, "pQ");

	pQ->rear = pQ->head = NULL;
	return OK;
}
Status IsQueueEmpty(Queue Q, bool* pResult) {
	checkQIllegal(Q);
	checkEmpty(pResult, "pResult");

	*pResult = !Q.rear && !Q.head;
	return OK;
}
Status EnQueue(Queue* pQ, const Elemtype data) {
	Node *p;

	checkEmpty(data, "data");
	checkQIllegal(*pQ);

	p = (Node*)malloc(sizeof(Node));
	if (!p) {
		debug_print("p is NULL , return OVERFLOW \n");
		return OVERFLOW;
	}
	p->data = data;
	if (isQueueEmpty(*pQ)) {
		p->next = p->prev = NULL;
		(*pQ).rear = (*pQ).head = p;
		return OK;
	}
	else {
		p->next = NULL;
		p->prev = (*pQ).rear;

		(*pQ).rear->next = p;
		(*pQ).rear = p;
		return OK;
	}
}
Status DeQueue(Queue* pQ, Elemtype * pData) {
	Node *p;

	checkEmpty(pData, "pData");
	checkQIllegal(*pQ);
	checkQEmpty(*pQ);

	*pData = pQ->head->data;


	if (sizeOfQueue(*pQ) == 1) {
		free(pQ->head);
		pQ->rear = NULL;
		pQ->head = NULL;
		return OK;
	}
	else {
		pQ->head = pQ->head->next;
		free(pQ->head->prev);
		pQ->head->prev = NULL;
		return OK;
	}

}
Status SizeOfQueue(const Queue Q, int* pResult) {
	Node *p;

	checkEmpty(pResult, "pResult");
	checkQIllegal(Q);

	*pResult = 0;
	if (isQueueEmpty(Q)) {
		return OK;
	}
	for (p = Q.rear; p; p = p->prev) {
		(*pResult) += 1;
	}
	return OK;
}
Status TraverseQueue(const Queue Q) {
	Node* p;

	checkQIllegal(Q);

	if (isQueueEmpty(Q)) {
		printf("(empty)");
		return OK;
	}
	for (p = Q.head; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	return OK;
}
Status GetHead(const Queue Q, Elemtype* pData) {
	checkQIllegal(Q);
	checkQEmpty(Q);
	checkEmpty(pData, "pData");

	*pData = Q.head->data;
	return OK;
}
Status ClearQueue(Queue* pQ) {
	Node *next, *p;

	checkEmpty(pQ, "pQ");
	checkQIllegal(*pQ);

	if (isQueueEmpty(*pQ)) {
		return OK;
	}
	for (p = pQ->head; p; p = next) {
		next = p->next;
		free(p);
		p = next;
	}
	pQ->head = pQ->rear = NULL;
	return OK;
}