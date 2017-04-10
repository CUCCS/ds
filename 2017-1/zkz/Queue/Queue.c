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
	printf("\t[%s] Create new node p at %p\n",__FUNCTION__,p);
	p->data = data;
	if (isQueueEmpty(*pQ)) {
		printf("\t[%s] Queue is empty . Set p->next and p->prev as NULL\n", __FUNCTION__);
		printf("\t[%s] Set Q.rear and Q.head as p \n", __FUNCTION__);
		p->next = p->prev = NULL;
		(*pQ).rear = (*pQ).head = p;
		return OK;
	}
	else {
		printf("\t[%s] Queue is not empty . Set p->next as NULL and p->prev as Q.rear \n",__FUNCTION__);
		p->next = NULL;
		p->prev = (*pQ).rear;
		printf("\t[%s] Set Q.rear->next as p and Q.rear as p \n",__FUNCTION__);
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
		printf("\t[%s] The size of queue is 1 . Delete Q.head and set Q.rear and Q.head as NULL \n",__FUNCTION__);
		free(pQ->head);
		pQ->rear = NULL;
		pQ->head = NULL;
		return OK;
	}
	else {
		printf("\t[%s] The size of queue is bigger than 1 . Set Q.head as Q.head->next and delete Q.head->prev \n", __FUNCTION__);
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