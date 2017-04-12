//����ת��


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ������
#define STACKINCREMENT  10  //�洢�ռ��������

typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef enum
{
	false,
	true
}bool;

typedef struct
{
	int  *base;
	int  *top;
	int  stacksize;
} SqStack;

Status InitStack (SqStack *S)   //��������Ϊ����һ����ջ
{
    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!S->base) 
	{
		return (OVERFLOW);//����ʧ��
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push (SqStack *S,int e)  //����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if( S->top - S->base >= S->stacksize) //ջ����׷�Ӵ洢�ռ䣻
	{
		S->base = (int *) realloc (S->base,(S->stacksize + STACKINCREMENT) * sizeof(int));
	    if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}

Status Pop (SqStack *S,int* pa)  //��ջ��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK ;���򷵻�ERROR;
{
	if(S->top == S->base)
		return ERROR;
	*pa =*(--S->top);
	return OK;
}

bool StackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return true;
	else
		return false;
}

void conversion (SqStack *S,int input,int d)
{
	int e;
	while (input)
	{
		Push( S,input % d);
		input = input/d;
	}
	while (!StackEmpty(S))
	{
		Pop(S,&e);
		printf("%d",e);
	}
}

int main()
{
	int n;
    int d;
	SqStack S;
	srand( (unsigned int)time(NULL));
	n = rand()%1024;
	printf("������ɼ������Ϊ��");
	printf("%d\n",n);
	printf("������ɽ�����Ϊ��\n");
	d = rand()%17;
	printf("%d\n",d);
	InitStack(&S);  //����һ����ջ��
	conversion(&S,n,d);
}


