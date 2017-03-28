#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char SElemType;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum
{
	true,
	false
}bool;
Status InitStack(SqStack*s);
Status Marry(SqStack *s, char*test);
bool StackEmpty(SqStack*s);
Status Pop(SqStack*s, SElemType *e);
Status GetTop(SqStack*s, SElemType* e);
Status Push(SqStack*s, SElemType e);
