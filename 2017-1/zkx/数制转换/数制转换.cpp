#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "����ת��.h"

Status  InitStack (SqStack* pS)    //����һ����ջ
{
	pS->base=(SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));

	if(! pS->base) 
	{
		return OVERFLOW;
	}

	pS->top =(*pS).base;
	pS->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;

}
int StackEmpty(SqStack *S)
{
	if (S)
		return S->base==S->top;
	return 1;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;

}

void conversion (SqStack *S,int n,int d) 
{
	SElemType e;
	while (n) 
	{
		Push(S, n % d);
		n = n / d;
	}
	while (!StackEmpty(S)) 
	{
		Pop(S, &e);
		printf ( "%d", e );
	}

	printf("\n");
} // conversion
int main()
{
	SqStack S;
	srand(time(NULL));

	int n=rand()%1024;
	printf("��ת������ ��%d\n",n);

	printf("ת������ ��");
	int d;
	scanf ("%d", &d);

	InitStack(&S);
	conversion(&S,n,d);
	return 0;
}