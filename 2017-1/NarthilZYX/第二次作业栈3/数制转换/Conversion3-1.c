#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {
    ERROR, 
	OK, 
	OVERFLOW
}Status;

typedef int SElemType;

typedef struct {
    SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

Status InitStack(SqStack *S)
{
	//need free
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));
	if(!S->base) {
		return OVERFLOW;//fail to allocate memory
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}
Status Push(SqStack *S, SElemType e)//
{
	if(S->top - S->base >= S->stacksize) {
			return OVERFLOW;
	}
	*S->top++ = e;
	return OK;
}
Status Pop(SqStack *S, SElemType &e) 
{
	if(S->top == S->base){
		return ERROR;
	}
	e = * --S->top;
	return OK;
}
Status StackEmpty(SqStack *S)
{
	if(S->base == S->top){
		return OK;
	}
	else{
		return ERROR;
	}
}

Status ModConvert(int input, SqStack *S , int d)
{
	SElemType e;
	e = *S->top;
	if(d > 10) {
		return ERROR;
	}
	while(input) {
		Push(S, input % d);
		input = input / d;
	}
	while(!StackEmpty(S)){
		Pop(S, e);
		printf("%d", e);
	}
	return OK;
}

int main()
{
    SqStack S;
	InitStack(&S);
	int num;
	int d = 8;
	srand((int)time(NULL));
	num = rand()%10001;//create random number
	printf("%d\n",num);
	ModConvert(num, &S, d);
	system("pause");
	return 0;
}