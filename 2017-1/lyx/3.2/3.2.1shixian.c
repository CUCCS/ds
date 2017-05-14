//ds 3.2.cpp
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

#include "ds 3.2.h"

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
	S->top = NULL;
	return OK;
}

bool StackEmpty(SqStack *S)//若S为空栈则返回TRUE,否则返回FALSE
{
	if (S->base==S->top)
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
	if (S->top - S->base >= S->stacksize) {//栈满，追加存储空间
											//暂时不用
											//S->base=(SElemaType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
											//if(!S->base){
		return(OVERFLOW);//存储分配失败
						 //}
						 //S->top=S->base+S->stacksize;
						 //S->stacksize+=STACKINCREMENT;
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

Status conversion(SqStack *S, int input, int d)//实现数制转换
{
	int output;
	InitStack(S);
	while (input) {
		Push(S, input%d);
		input = input / 8;
	}
	while (!StackEmpty(S))
	{
		Pop(S, &output);
		printf("%d", output);
	}

	return OK;

}//conversion


