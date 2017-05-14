#include "3.2.1.h"
Status Pop(SqStack*s, SElemType*e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	else
	{
		*e = *--s->top;
		return OK;
	}

}
bool StackEmpty(SqStack*s)
{
	if(s->base==s->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status conversion(SqStack *s, SElemType input, int d)
{
	SElemType e;
	SElemType a = 0;
	//if (d == 0)
	//{
	//	return ERROR;
	//}已将随机数设定在1~9范围内；
	printf("转换结果\n");
	while (input)
	{
		a = input % d;
		Push(s,a);
		input = input / d;
	}
	while (StackEmpty(s)==false)
	{
		Pop(s, &e);
		printf("%d", e);
	}
 	printf("\n");
	return OK;
}

Status InitStack(SqStack*s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack*s, SElemType e)
{
	if (s->top - s->base > s->stacksize)
	{
		s->base = (SElemType*)realloc(s->base, (s->stacksize +2*STACK_INIT_SIZE) * sizeof(SElemType));
		if (!s->base)
		{
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += 2*STACK_INIT_SIZE;
	}
	*s->top = e;
	s->top++;
	return OK;

}
 
