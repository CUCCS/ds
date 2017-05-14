#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef int SElemType;
typedef enum{
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *s);
Status Push(SqStack *s,SElemType e);
Status Pop(SqStack *s,SElemType *e);
bool StackEmpty(SqStack *s);
Status DestroyStack(SqStack *s);
Status ClearStack(SqStack *s);
Status LineEdit(SqStack *s);