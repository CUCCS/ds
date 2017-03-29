#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  
#define S_SIZE 100   //ջ�Ŀռ��С  
#define STACKINCREAMENT 10//���ӿռ�  A

//��ʼ����ջ
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(S_SIZE * sizeof(int));
	S->stacksize = S_SIZE;
	S->top = S->base;
};
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
};

//��ջ
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

//��ջ
void pop(SqStack *S, int *e)
{
	if (S->base != S->top)
	{
		S->top--;
		*e = *S->top;
	}
};
