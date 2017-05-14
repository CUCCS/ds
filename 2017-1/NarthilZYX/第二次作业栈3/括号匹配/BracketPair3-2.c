#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXNUM 100
typedef char SElemType ;
typedef enum{
    ERROR,
	OK,
	OVERFLOW
}Status;
typedef struct {
    SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//create a new stack
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
}//end of InitStack

Status Push(SqStack *S, SElemType e)//
{
	if(S->top - S->base >= S->stacksize)
	{
      S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
	  if(!S->base)
	  {
		  return OVERFLOW;
	  }
      S->top = S->base + S->stacksize;
      S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//end of Push

Status Pop(SqStack *S, SElemType e) 
{
	if(S->top == S->base) 
	{
		return ERROR;
	}
	e = * --S->top;
	return OK;
}//end of Pop

//判断空栈
Status StackEmpty(SqStack *S)
{
	if(S->base == S->top)
	{
		return OK;
	}
	else{
		return ERROR;
	}
}//end of StackEmpty

//获取栈顶元素的函数
Status GetTop(SqStack *S, SElemType *e)
{
	if(S->top == S->base){
	    return ERROR;
	}
	*e = *(S->top-1);
	return OK;
}

Status matching(SqStack *S, char *c) {
    int state = 1;
	int i = 0;
	SElemType e;
    while ( c[i]!='\0' && state ) {
        switch(c[i]) 
		{
            case '(': {
                Push(S, c[i]); 
				i++;
				break;
					  }
            case ')': {
				GetTop(S,&e);
                if(! StackEmpty(S) && e == '(') {
                    Pop(S,e);
                } else {
                    state = 0;
                }
				i++;
                break;  
            }
			case '{': { 
                Push(S, c[i]); 
				i++;
				break;
            }
			case '}': {
				GetTop(S,&e);
				if(! StackEmpty(S) && e == '{') {
                    Pop(S,e); 
                } else {
                    state = 0;
                }
				i++;
                break; 
					  }
			case '[': { 
                Push(S, c[i]); 
				i++;
				break;
            }
            case ']': {
				GetTop(S,&e);
                if(! StackEmpty(S) && e == '[') {
                    Pop(S,e);  
                } else {
                    state = 0;
                }
				i++;
                break;  
					  }
        }
		
	}
    if ( StackEmpty(S) && state) 
	{
		return OK;
	}
	else
	{
		return ERROR;
    }
}

int main()
{
	SqStack S;
	char c[MAXNUM];
	int flag=0;
	InitStack(&S);
	printf("Input a group of brackets as you like!\n");
	scanf("%s",c);
	flag = matching(&S,c);
	if(matching(&S,c)){
		printf("Matching succeed!");
	}
	else{
		printf("Matching fail!");
	}
	return 0;
}