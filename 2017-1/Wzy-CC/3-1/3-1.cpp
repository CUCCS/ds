//�㷨3.1
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

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
}SqStack;//�ṹ�壺ջ
		 //typedef struct _SqStack *Sq;

Status InitStack(SqStack* pS)
{
	(pS)->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(pS)->base)
	{
		exit(OVERFLOW);
	}//�������ʧ��
	(pS)->top = (pS)->base;
	(pS)->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base)
		return ERROR;
	e = S.top - 1;
	return OK;
}

Status Push(SqStack* S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)//ջ����׷�Ӵ���ռ�
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)exit(OVERFLOW);//�������ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//push

Status Pop(SqStack *S, SElemType &e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S->top == S->base)
	{
		return ERROR;
	}
	e = *(--S->top);
	return OK;
}

bool StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}//Ϊ��elsereturn false;//��Ϊ��} 

void conversion()
{
	SqStack S;
	SElemType e;
	//����ʮ������������˽�����
	InitStack(&S); //��ʼ��
	int N;
	scanf("%d", &N);
	while (N)
	{
		Push(&S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S))
	{
		Pop(&S, e);
		printf("%d", e);
	}
} // conversion

int main()
{
	conversion();
	return OK;
}