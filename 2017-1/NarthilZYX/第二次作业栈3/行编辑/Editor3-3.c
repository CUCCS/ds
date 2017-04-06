#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

Status Push(SqStack *S, SElemType e)
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

Status Pop(SqStack *S, SElemType *e) 
{
	if(S->top == S->base) 
	{
		return ERROR;
	}
	*e = * --S->top;
	return OK;
}//end of Pop

//�жϿ�ջ
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

//��ȡջ��Ԫ�صĺ���
Status GetTop(SqStack *S, SElemType *e)
{
	if(S->top == S->base){
	    return ERROR;
	}
	*e = *(S->top-1);
	return OK;
}//end of GetTop

//���ջ
Status ClearStack(SqStack *S)
{
	if(S->top==S->base)
		return ERROR;
    S->top=S->base;
	return OK;
}//end of ClearStack

//����ջ
Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}//end of destroy Stack

Status LineEdit(SqStack *S)
{
	SElemType e;//ջ��Ԫ��
	SElemType *b;//ָ��ջ�ף��������
	char ch;
	ch = getchar();
	while(ch != EOF)
	{
		while(ch!=EOF&&ch!='\n')
		{
			switch(ch){
			case '#':
				Pop(S,&e);
				break;
			case '@':
				ClearStack(S);
				break;
			default:
				Push(S,ch);
				break;
			}
			ch = getchar();
		}
		b = S->base;
	    while(b!=S->top)
	    {
		    printf("%c",*b);
		    ++b;
	    }
		ClearStack(S);
        if( ch!=EOF )
		    ch = getchar();
	}
	return OK;
}//end of LineEdit

int main()
{
	SqStack S;
	InitStack(&S);
	printf("Create a statement as you like!\n");
	LineEdit(&S);
	return 0;
}
//whil##ilr#e(s#*s)
//outcha@putchar(*s=#++)