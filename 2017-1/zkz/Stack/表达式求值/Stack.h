#pragma once

#include <stdlib.h>
#include "Status.h"

/*��Щ�ͺ���ͬ������ĸСд�ĺ�����
�ڼ򻯺������ù��̵�ͬʱ
���ı亯������ķ���ֵ���β�����*/
/*��������globalVariable��ͷ�ı������ʹ��*/
#define isStackEmpty(S) (IsStackEmpty((S),&globalVariable_isStackEmpty),globalVariable_isStackEmpty)
#define getTop(S) (GetTop(S,&globalVariable_getTop),globalVariable_getTop)
#define pop(S) (Pop(S,&globalVariable_pop),globalVariable_pop)
#define sizeOfStack(S) (SizeOfStack(S,&globalVariable_sizeOfStack),globalVariable_sizeOfStack)

typedef int Elemtype;
/*�Զ���bool����*/
typedef enum _bool { false, true }bool;

typedef struct _Node {
	Elemtype data;
	struct _Node* next;
} Node, *Stack;

/*��Щ��globalVariable��ͷ�ı���
������
�ͺ���ͬ������ĸСд�ĺ�
���ʹ��*/
bool globalVariable_isStackEmpty;
Elemtype globalVariable_getTop;
Elemtype globalVariable_pop;
int globalVariable_sizeOfStack;

Status InitStack(Stack *);
Status Push(Stack, Elemtype);
Status Pop(Stack, Elemtype *);
/*Traverse : ��ջ����ջ�ױ���*/
Status Traverse(const Stack);
Status DeleteStack(Stack *);
Status EmptyStack(Stack);
Status IsStackEmpty(Stack, bool *);
Status SizeOfStack(const Stack, int *);
Status GetTop(const Stack, Elemtype *);