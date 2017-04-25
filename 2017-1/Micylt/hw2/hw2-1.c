//进制转换程序
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10


typedef enum 
{
	false,
	true,
}bool;

typedef enum 
{
	OK,
	OVERFLOW,
	ERROR,
} Status;

typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}SqStack;


Status InitStack(SqStack *s) 
{
	printf("初始化一个栈\n");
	s->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}

Status Push(SqStack *s, int e) 
{
	if (s->top - s->base > s->stacksize) 
	{
		return OVERFLOW;
	}
	printf("插入元素 %d 作为栈顶元素\n", e);
	*s->top++ = e;
	return OK;
}

Status Pop(SqStack *s, int *e) 
{
	if (StackEmpty(s)) 
	{
		return ERROR;
	}
	*e = *--s->top;
	return OK;
}

bool StackEmpty(SqStack *s) 
{
	if (s)
	{
		return s->base == s->top;
	}
	return true;
}

Status conversion(SqStack *s, int input, int d) 
{
	int e;

	if (d > 10) 
	{
		return ERROR;
	}
	while (input) 
	{
		Push(s, input % d);
		input = input / d;
	}
	printf("转化后的数字:\n");
	while (!StackEmpty(s)) 
	{
		Pop(s, &e);
		printf("%d", e);
	}
	printf("\n");
	printf("转化结束\n");
}

int main() 
{
	SqStack s;
	int input;
	int d;
	printf("请输入要转化的数据：");
	scanf("%d", &input);
	printf("请输入要转化的进制：");
	scanf("%d", &d);
	if (d>10) {
		printf("输入的数字不符合转换进制的要求\n");
		printf("请重新输入要转换的数\n");
		scanf("%d", &d);
	}
	printf("要转换的数据:%d\n", input);
	printf("要转化的进制:%d\n", d);
	InitStack(&s);//初始化一个栈
	conversion(&s, input, d);
	return 0;
}