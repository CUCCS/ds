#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

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
}SqStack;
typedef enum
{
	true,
	false
}bool;

//对随机产生的非负十进制整数，打印输出的与其等值的进制数；
Status conversion(SqStack*, SElemType, int);
//创建一个空栈
Status InitStack(SqStack *);
//插入新的栈顶元素
Status Push(SqStack*, SElemType);
//判断是否是空栈，若非空，用e返回其值，并返回OK，否则，返回ERROR；
Status Pop(SqStack*, SElemType*e);

bool StackEmpty(SqStack*s);