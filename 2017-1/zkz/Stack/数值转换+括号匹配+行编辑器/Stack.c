#include "Stack.h"

Status InitStack(Stack * pS) {
	if (!pS)
		return ERROR;
	/*����top�ڵ�*/
	(*pS) = (Stack)malloc(sizeof(Node));
	if (!*pS)
		return OVERFLOW;
	/*Ϊtop�ڵ㸳ֵ*/
	(*pS)->next = NULL;
	return OK;
}
Status Push(Stack S, Elemtype data) {
	Node * p;
	if (!S)
		return ERROR;
	/*Step 1 �����½ڵ�*/
	p = (Node *)malloc(sizeof(Node));
	if (!p)
		return OVERFLOW;
	/*Step 2 Ϊ�½ڵ㸳ֵ*/
	p->data = data;
	p->next = NULL;
	/*Step 3 ���½ڵ���ջ*/
	p->next = S->next;
	S->next = p;
	return OK;
}
Status Pop(Stack S, Elemtype *pdata) {
	Node * p;
	if (!S || !pdata || !S->next)
		return ERROR;
	/*Step 1 �����ڵ��ջ*/
	p = S->next;
	S->next = p->next;
	/*Step 2 ��ȡ�ڵ�����*/
	*pdata = p->data;
	/*Step 3 ���ٽڵ�*/
	free(p);
	return OK;
}
/*Traverse : ��ջ����ջ�ױ���*/
Status Traverse(const Stack S) {
	if (!S)
		return ERROR;
	if (!S->next)
		printf("(empty)");
	Node *pS = S->next;
	while (pS) {
		printf("%d ", pS->data);
		pS = pS->next;
	}
	return OK;
}
Status DeleteStack(Stack *pS) {
	Node *p, *next;
	if (!pS)
		return ERROR;
	p = (*pS)->next;
	while (p) {
		next = p->next;
		free(p);
		p = next;
	}
	free(*pS);
	*pS = NULL;
	return OK;
}
Status EmptyStack(Stack S) {
	if (!S)
		return ERROR;
	DeleteStack(&S->next);
	return OK;
}
Status IsStackEmpty(Stack S, int *pResult) {
	if (!S)
		return ERROR;
	*pResult = !S->next;
	return OK;
}
Status SizeOfStack(const Stack S, int *pN) {
	if (!S || !pN)
		return ERROR;
	Node *pS = S->next;
	*pN = 0;
	while (pS) {
		++*pN;
		pS = pS->next;
	};
	return OK;
}
Status GetTop(const Stack S, Elemtype *pdata) {
	if (!S || !pdata || !S->next)
		return ERROR;
	*pdata = S->next->data;
	return OK;
}