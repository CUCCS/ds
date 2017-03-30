#pragma once

#include <stdlib.h>
#include "Status.h"
typedef struct _Point {
	int x;
	int y;
}Point;
typedef Point Elemtype;

typedef struct _Node {
	Elemtype data;
	struct _Node* next;
} Node, *Stack;

Status InitStack(Stack *);
Status Push(Stack, Elemtype);
Status Pop(Stack, Elemtype *);
/*Traverse : ´ÓÕ»¶¥ÏòÕ»µ×±éÀú*/
Status Traverse(const Stack);
Status DeleteStack(Stack *);
Status EmptyStack(Stack);
Status IsStackEmpty(Stack, int *);
Status SizeOfStack(const Stack, int *);
Status GetTop(const Stack, Elemtype *);