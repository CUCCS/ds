//实现括号配对
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>


#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef char SElemType;

typedef struct {
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

Status StackTraverse(SqStack *S, Status(*visit)(SElemType));
//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败,则操作失败

Status visit(SElemType e);
//打印栈中元素

Status matching(SElemType *exp);
//实现括号的匹配


#pragma once

//栈的基本操作函数定义

Status InitStack(SqStack *S)//构造一个空栈S
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) {
		return(OVERFLOW);//存储分配失败
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;

}//InitStack

Status DestrpoyStack(SqStack *S)//销毁S
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}


Status ClearStack(SqStack *S)//把S置为空栈
{
	S->top = NULL;
	return OK;
}

bool StackEmpty(SqStack *S)//若S为空栈则返回TRUE,否则返回FALSE
{
	if (S->base == S->top)
		return true;
	else
		return false;
}

int StackLength(SqStack *S)//返回S的元素个数，即栈的长度
{
	return *S->top + 1;
}

Status GetTop(SqStack *S, SElemType e)//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
{
	if (S->top == S->base)return ERROR;
	e = *(S->top - 1);
	return OK;
}//GetTop

Status Push(SqStack *S, SElemType e)//插入元素e为新的栈顶元素
{
	if (S->top - S->base >= S->stacksize) 
	{
		return(OVERFLOW);//存储分配失败
	}
	*S->top++ = e;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
	if (StackEmpty(S))return ERROR;
	*e = *--S->top;
	return OK;
}//Pop



Status StackTraverse(SqStack *S, Status(*visit)(SElemType))//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败,则操作失败
{
	while (S->top > S->base)
		visit(*S->base++);
	printf("\n");
	return OK;
}//StackTraverse

Status visit(SElemType e) //打印栈中元素
{
	printf("%d ", e);
	return OK;
}  //visit


Status matching(SElemType *exp) //实现括号的匹配
{
	SqStack S;
	InitStack(&S);
	int i = 0, flag = 0;
	SElemType e;
	while (exp[i] != '\0')
	{
		switch (exp[i])
		{
		case '(':
			Push(&S, exp[i]);
			break;
		case '{':
			Push(&S, exp[i]);
			break;
		case '[':
			Push(&S, exp[i]);
			break;
		case ')':
		{
			Pop(&S, &e);
			if (e != '(')
				flag = 1;
		}
		break;
		case '}':
		{
			Pop(&S, &e);
			if (e != '{')
				flag = 1;
		}
		break;
		case ']':
		{
			Pop(&S, &e);
			if (e != '[')
				flag = 1;
		}
		break;
		default:
			break;
		}
		if (flag)
			break;
		i++;
	}
	DestrpoyStack(&S);
	if (!flag)
		printf("括号匹配成功!\n");
	else
		printf("括号匹配失败!\n");
	return OK;
}

int main()
{

	SElemType exp1[] = { "{([])}" }, exp2[] = {"({])"};
	printf("EXP1：");
	matching(exp1);
	printf("EXP2：");
	matching(exp2);
	
	return 0;
}
	