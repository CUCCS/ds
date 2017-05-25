#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXNUM 100
const char OP[7] = { '+', '-', '*', '/', '(', ')', '#' };
const int PT[7][7] = {
	{1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1},
	{1,1,1,1,0,1,1},
	{1,1,1,1,0,1,1},
	{0,0,0,0,0,0,0},
	{1,1,1,1,0,0,0},
	{0,0,0,0,0,0,0}
};
typedef char SElemType;
typedef enum {
	ERROR,
	OK,
	OVERFLOW
	
}Status;
typedef enum {
	FALSE,
	TRUE
	
}Bool;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
	
}SqStack;
typedef struct {
	int *base;
	int *top;
	int stacksize;
	
}Number;

//×Ö·ûÕ»
//create a new stack
Status InitStack(SqStack *S)
 {
		//need free
		S->base = (SElemType *)malloc(STACK_INIT_SIZE *
			sizeof(SElemType));
	if (!S->base) {
		return OVERFLOW;//fail to allocate memory
		
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	
		return OK;
	}//end of InitStack

Status Push(SqStack *S, SElemType e)//
 {
	if (S->top - S->base >= S->stacksize)
		 {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			 {
			return OVERFLOW;
			}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
		}//¿Î±¾
	*S->top++ = e;
	return OK;
	}//end of Push

Status Pop(SqStack *S, SElemType *e)
 {
	if (S->top == S->base)
		 {
		return ERROR;
		}
	*e = *--S->top;//´ý¼ì²â
	return OK;
	}//end of Pop

//ÅÐ¶Ï¿ÕÕ»
Status StackEmpty(SqStack *S)
 {
	if (S->base == S->top)
		 {
		return OK;
		}
	else {
		return ERROR;
		
	}
	}//end of StackEmpty

//»ñÈ¡Õ»¶¥ÔªËØµÄº¯Êý
Status GetTop(SqStack *S, SElemType *e)
 {
	if (S->top == S->base) {
		return ERROR;
		
	}
	*e = *(S->top - 1);
	return OK;
	}//end of GetTop

//Êý×ÖÕ»
Status nInitStack(Number *S)
 {
		//need free
		S->base = (int *)malloc(STACK_INIT_SIZE *
			sizeof(int));
	if (!S->base) {
		return OVERFLOW;//fail to allocate memory
		
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	
		return OK;
	}//end of InitStack

Status nPush(Number *S, int e)//
 {
	if (S->top - S->base >= S->stacksize)
		 {
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(int));
		if (!S->base)
			 {
			return OVERFLOW;
			}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
		}
	*S->top++ = e;
	return OK;
	}//end of Push

Status nPop(Number *S, int *e)
 {
	if (S->top == S->base)
		 {
		return ERROR;
		}
	*e = *--S->top;//´ý¼ì²â
	return OK;
	}//end of Pop

//ÅÐ¶Ï¿ÕÕ»
Status nStackEmpty(Number *S)
 {
	if (S->base == S->top)
		 {
		return OK;
		}
	else {
		return ERROR;
		
	}
	}//end of StackEmpty

//»ñÈ¡Õ»¶¥ÔªËØµÄº¯Êý
Status nGetTop(Number *S, int *e)
 {
	if (S->top == S->base) {
		return ERROR;
		
	}
	*e = *(S->top - 1);
	return OK;
	}//end of GetTop

//²Ù×÷·ûµÄÅÐ¶Ïº¯Êý
Bool IN(SElemType ch)
 {
	int j;
	for (j = 0; j < 7; j++)
		 {
		if (ch == OP[j]) {
			return TRUE;
			
		}
		}
	return FALSE;
	}