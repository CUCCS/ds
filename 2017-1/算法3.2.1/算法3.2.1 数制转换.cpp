#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum{
	OK,
	ERROR,
	OVERFLOW
}Status;
Status InitStack(SqStack *);
Status StackEmpty(SqStack );
Status Push(SqStack *,SElemType );
Status Pop(SqStack *,SElemType );
int main()
{
	SElemType e;
	SElemType N;
	SqStack sq;
	SqStack *S;
	S=&sq;

	InitStack(S);
	scanf("%d",&N);
	while(N)
	{
		Push(S,N%8);
		N=N/8;
	}
	while(!StackEmpty(S))
	{
		Pop(S,e);
		printf("%d",e);
	}

	return 0;
}
Status InitStack(SqStack *s)
{
	s->base=(SElemType *)malloc(STACK_INIT_SIZE  * sizeof(SElemType));
	if(!s->base)exit(OVERFLOW);
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE ;
	return OK;
}
Status StackEmpty(SqStack *s)
{
	if(s->base==s->top)
		return OK;
	else
		return ERROR;
}
Status Push(SqStack *s,SElemType e)
{
	if(s->top-s->base>=s->stacksize)//Õ»Âú£¬×·¼Ó´æ´¢¿Õ¼ä
	{
		s->base=(SElemType *)realloc(s->base,(s->stacksize+STACKINCREMENT) * sizeof(SElemType));
	    if(!s->base)
			return OVERFLOW;//´æ´¢·ÖÅäÊ§°Ü
	    s->top=s->base+s->stacksize;
		s->stacksize+=STACKINCREMENT;
	}
	else
	*s->top++=e;


}
Status Pop(SqStack *s,SElemType e)
{
	if(s->top==s->base)//ÅÐ¶ÏÊÇ·ñÎª¿ÕÕ»
		return ERROR;
	e=*(s->top-1);
	return OK;
}