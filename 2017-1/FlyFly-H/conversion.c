//数制转换


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100  //存储空间初始分配量
#define STACKINCREMENT  10  //存储空间分配增量

typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef enum
{
	false,
	true
}bool;

typedef struct
{
	int  *base;
	int  *top;
	int  stacksize;
} SqStack;

Status InitStack (SqStack *S)   //函数功能为构造一个空栈
{
    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S->base) 
	{
		return (OVERFLOW);//分配失败
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push (SqStack *S,int e)  //插入元素e为新的栈顶元素
{
	if( S->top - S->base >= S->stacksize) //栈满，追加存储空间；
	{
		S->base = (int *) realloc (S->base,(S->stacksize + STACKINCREMENT) * sizeof(int));
	    if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}

Status Pop (SqStack *S,int* pa)  //若栈不为空，删除S的栈顶元素，用e返回其值，并返回OK ;否则返回ERROR;
{
	if(S->top == S->base)
		return ERROR;
	*pa =*(--S->top);
	return OK;
}

bool StackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return true;
	else
		return false;
}

void conversion (SqStack *S,int input,int d)
{
	int e;
	while (input)
	{
		Push( S,input % d);
		input = input/d;
	}
	while (!StackEmpty(S))
	{
		Pop(S,&e);
		printf("%d",e);
	}
}

int main()
{
	int n;
    int d;
	SqStack S;
	srand( (unsigned int)time(NULL));
	n = rand()%1024;
	printf("随机生成检测数字为：");
	printf("%d\n",n);
	printf("随机生成进制数为：\n");
	d = rand()%17;
	printf("%d\n",d);
	InitStack(&S);  //构造一个空栈；
	conversion(&S,n,d);
}


