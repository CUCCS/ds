#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  
#define S_SIZE 100   //栈的空间大小  
#define STACKINCREAMENT 10//增加空间  A

//初始化空栈
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(S_SIZE * sizeof(int));
	S->stacksize = S_SIZE;
	S->top = S->base;
};
//判断栈是否为空
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
};

//进栈
void push(SqStack *S, int e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREAMENT) * sizeof(int));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREAMENT;
	}
	*(S->top) = e;
	S->top++;
};

//出栈
void pop(SqStack *S, int *e)
{
	if (S->base != S->top)
	{
		S->top--;
		*e = *S->top;
	}
};
