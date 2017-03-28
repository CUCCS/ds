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

//构造一个空栈；
Status InitStack(SqStack *);
//若栈不为空，删除栈顶元素；
Status Pop(SqStack*, SElemType*e);
//插入元素作为新的栈顶元素；
Status Push(SqStack*, SElemType);
//把s置为空栈，参考网上代码；
Status ClearStack(SqStack*);
//判断s是否为空栈
bool StackEmpty(SqStack*s);
//销毁栈使之不再存在；
Status DistoryStack(SqStack *s);
//利用字符栈，从终端接收一行并传至调用过程的数据区；
Status LineEdit(SqStack*s, char*a);
