#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef  int  SElemType;

typedef enum  {ERROR,OVERFLOW,OK} Status;

typedef struct Stack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status  InitStack (SqStack* pS);
Status Push(SqStack *S,SElemType e);
int StackEmpty(SqStack *S);
Status Pop(SqStack S,SElemType *e);
void conversion (SqStack *S,int n,int d);
