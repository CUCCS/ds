

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef enum
{Error,OK}Status;
//#define Status int
//#define Error 0
//#define OK 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
 int *base;
 int *top;
 int stacksize;
}SqStack;
Status InitStack(SqStack *s)
{
	s->base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!s->base)
		return Error;
	else
	{
		s->top=s->base;
		s->stacksize=STACK_INIT_SIZE;
		return OK;
	}
}
Status Push(SqStack *s,int e)
{
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(int*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(int));
		if(!s->base)
			return Error;
		s->top=s->base+s->stacksize;
		s->stacksize+=STACKINCREMENT;
	}
	*s->top=e;
	s->top++;
	return OK;
}
int StackEmpty(SqStack *s)
{
	if(s->top==s->base)
	{
		return 0;
	}
	else 
		return 1;
}
int Pop(SqStack *s)
{
	if(s->top==s->base)
		return 0;
	else
	{
		s->top--;
		return *s->top;
	}
}
int main()
{
	int n;
	SqStack S;
	InitStack(&S);
	srand(time(NULL));
	n = rand() % 1024;
	printf("zhuan huan\n", n);
	while(n)
	{
		Push(&S,n%8);
		n=n/8;
	}
	while(StackEmpty(&S))
	{
		printf("%d",Pop(&S));
	}
	return 0;
}
