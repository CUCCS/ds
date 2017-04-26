//算法3.1
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

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
}SqStack;//结构体：栈
		 //typedef struct _SqStack *Sq;

Status InitStack(SqStack* pS)
{
	(pS)->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(pS)->base)
	{
		exit(OVERFLOW);
	}//储存分配失败
	(pS)->top = (pS)->base;
	(pS)->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base)
		return ERROR;
	e = S.top - 1;
	return OK;
}

Status Push(SqStack* S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)//栈满，追加储存空间
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)exit(OVERFLOW);//储存分配失败
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//push

Status Pop(SqStack *S, SElemType &e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if (S->top == S->base)
	{
		return ERROR;
	}
	e = *(--S->top);
	return OK;
}

bool StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}//为空elsereturn false;//不为空} 

void conversion()
{
	SqStack S;
	SElemType e;
	//输入十进制数，输出八进制数
	InitStack(&S); //初始化
	int N;
	scanf("%d", &N);
	while (N)
	{
		Push(&S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S))
	{
		Pop(&S, e);
		printf("%d", e);
	}
} // conversion

int main()
{
	conversion();
	return OK;
}