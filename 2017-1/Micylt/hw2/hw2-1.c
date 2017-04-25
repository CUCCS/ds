//����ת������
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
	printf("��ʼ��һ��ջ\n");
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
	printf("����Ԫ�� %d ��Ϊջ��Ԫ��\n", e);
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
	printf("ת���������:\n");
	while (!StackEmpty(s)) 
	{
		Pop(s, &e);
		printf("%d", e);
	}
	printf("\n");
	printf("ת������\n");
}

int main() 
{
	SqStack s;
	int input;
	int d;
	printf("������Ҫת�������ݣ�");
	scanf("%d", &input);
	printf("������Ҫת���Ľ��ƣ�");
	scanf("%d", &d);
	if (d>10) {
		printf("��������ֲ�����ת�����Ƶ�Ҫ��\n");
		printf("����������Ҫת������\n");
		scanf("%d", &d);
	}
	printf("Ҫת��������:%d\n", input);
	printf("Ҫת���Ľ���:%d\n", d);
	InitStack(&s);//��ʼ��һ��ջ
	conversion(&s, input, d);
	return 0;
}