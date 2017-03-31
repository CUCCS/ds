#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}Sqstack;
typedef enum
{
	ok, error, overflow
}Status;
typedef enum
{
	false, true
}bool;
//����һ����ջ
Status InitStack(Sqstack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
	{
		return overflow;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return ok;
}
//������Ԫ��
Status Push(Sqstack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return ok;
}
//ȡ��ջ��Ԫ�ز�ɾ��
Status Pop(Sqstack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return error;
	}
	*e = *--S->top;
	return ok;
}
//���S�Ƿ�Ϊ��ջ
bool StackEmpty(Sqstack S)
{
	if (S.top == S.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���н���ת��
void conversion(Sqstack *S, int N, int d)
{
	SElemType *e = (SElemType*)malloc(sizeof(SElemType));
	while (N)
	{
		Push(S, N%d);
		N = N / d;
	}
	while (!StackEmpty(*S))
	{
		Pop(S, e);
		printf("%d", *e);
		
	}
}
int main()
{
	int N, d;
	printf("\n");
	Sqstack S;
	InitStack(&S);
	srand((unsigned)(time)(NULL));
	N = rand() % 1024;
	d = rand() % 10;
	printf("��ʮ������%dת��Ϊ%d������Ϊ��\n", N, d);
	conversion(&S, N, d);
	return 0;
}