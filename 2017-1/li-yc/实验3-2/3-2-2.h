#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef char SElemType;
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
bool isStackEmpty(SqStack *s);
Status GetTop(SqStack s,char *e);
Status matching(char *exp);
void Traverse(char *exp);