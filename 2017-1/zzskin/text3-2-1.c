#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STACK_INIT_SIZE 100    //存储空间初始分配量
#define STACKINCREMENT 10         //存储空间分配增量

typedef int SElemType ;
typedef enum{
	False,
	True
}Bool;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //枚举定义（返回状态）

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;                          //顺序栈的定义

Status InitStack(SqStack *S)       //构造顺序栈
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
	    return  OVERFLOW; 
	}//存储分配失败
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Bool IsStackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;

	}
	*e = *--S->top;

	return OK;
}

Status conversion(SqStack *S,int input,int d)
{
	SElemType e;
	if(d > 10)
	{
		return ERROR;
	}
	while(input)
	{
		Push(S,input % d);
		input = input / d;
	}
	while(!IsStackEmpty(S))
	{
		Pop(S,&e);
		printf("%d",e);

	}
	printf("\n");
	return OK;
}

int main()
{	
	SqStack S;
	int input;
	int d ;
   srand(time(NULL));
	input = rand() % 1024;
	d = 8;
	InitStack(&S);

	printf("input  =  %d\n",input);
    conversion(&S, input,d);
	return 0;
}