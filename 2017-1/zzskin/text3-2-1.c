#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define STACK_INIT_SIZE 100    //�洢�ռ��ʼ������
#define STACKINCREMENT 10         //�洢�ռ��������

typedef int SElemType ;
typedef enum{
	False,
	True
}Bool;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //ö�ٶ��壨����״̬��

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;                          //˳��ջ�Ķ���

Status InitStack(SqStack *S)       //����˳��ջ
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
	    return  OVERFLOW; 
	}//�洢����ʧ��
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Bool IsStackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;

	}
	*e = *--S->top;

	return OK;
}

Status conversion(SqStack *S,int input,int d)
{
	SElemType e;
	if(d > 10)
	{
		return ERROR;
	}
	while(input)
	{
		Push(S,input % d);
		input = input / d;
	}
	while(!IsStackEmpty(S))
	{
		Pop(S,&e);
		printf("%d",e);

	}
	printf("\n");
	return OK;
}

int main()
{	
	SqStack S;
	int input;
	int d ;
   srand(time(NULL));
	input = rand() % 1024;
	d = 8;
	InitStack(&S);

	printf("input  =  %d\n",input);
    conversion(&S, input,d);
	return 0;
}