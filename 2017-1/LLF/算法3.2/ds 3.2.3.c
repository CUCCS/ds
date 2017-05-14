//实现行编辑程序
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef char SElemType;

typedef struct 
{
	SElemType *base;//在构造前和销毁后，base的值为NULL
	SElemType *top;//栈顶指针
	int stacksize;//当前已分配的空间，以元素为单位
}SqStack;//定义栈

typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;//定义返回值的枚举类型


typedef enum {
	false,
	true
} bool;//定义返回值

	   //栈的基本操作函数声明

Status InitStack(SqStack *S);
//构造一个空栈S

Status DestroyStack(SqStack *S);
//销毁S

Status ClearStack(SqStack *S);
//把S置为空栈

bool StackEmpty(SqStack *S);
//若S为空栈则返回TRUE,否则返回FALSE

int StackLength(SqStack *S);
//返回S的元素个数，即栈的长度

Status GetTop(SqStack *S, SElemType e);
//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR

Status Push(SqStack *S, SElemType e);
//插入元素e为新的栈顶元素

Status Pop(SqStack *S, SElemType *e);
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR

Status StackTraverse(SqStack *S);

Status LineEdit(SqStack *s);
// 利用字符栈s，从终端接收一行并送至调用过程的数据区。
//栈的基本操作函数定义

Status InitStack(SqStack *S)//构造一个空栈S
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) 
	{
		return(OVERFLOW);//存储分配失败
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;

}//InitStack


Status DestroyStack(SqStack *S)//销毁S
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}


Status ClearStack(SqStack *S)//把S置为空栈
{
	S->top = S->base;	//栈底栈顶相同为空栈 
	return OK;
}

bool StackEmpty(SqStack *S)//若S为空栈则返回TRUE,否则返回FALSE
{
	if (S->base == S->top)
		return true;
	else
		return false;
}


Status Push(SqStack *S, SElemType e)//插入元素e为新的栈顶元素
{
	if (S->top - S->base >= S->stacksize) {//栈满，追加存储空间
										   //暂时不用
										   //S->base=(SElemaType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
										   //if(!S->base){
		return(OVERFLOW);//存储分配失败
						 //}
						 //S->top=S->base+S->stacksize;
						 //S->stacksize+=STACKINCREMENT;
	}
	*(S->top)++ = e;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
	if (StackEmpty(S))return ERROR;
	*e = *--(S->top);
	return OK;
}//Pop



Status StackTraverse(SqStack *S)
{
	char *p;
	p = S->base;
	while (p != S->top)
	{
		printf("%c", *p);
		p++;
	}
	return OK;
}//StackTraverse



// 利用字符栈s，从终端接收一行并送至调用过程的数据区。
Status LineEdit(SqStack *S)
{
	char str,e;
	scanf_s("%c", &str);
	while (str != '/')
	{
		while (str != '/'&&str != '\n')
		{
			switch (str)
			{
			case '#':
				Pop(S,&e);
				break;
			case '@':
				ClearStack(S);
				break;
			default:
				Push(S, str);
				break;
			}
			scanf_s("%c", &str);
		}
		StackTraverse(S);
		printf("\n");
		if (str != '/')
			scanf_s("%c", &str);
	}
	return OK;
}

int main()
{
	SqStack s;
	InitStack(&s);
	LineEdit(&s);
	return 0;
}
