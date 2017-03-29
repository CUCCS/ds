//lineedit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_INIT_SIZE 100  //存储空间初始分配量
#define STACKINCREMENT  10  //存储空间分配增量

typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef struct
{
	char  *base;
	char  *top;
	char  stacksize;
} SqStack;

Status InitStack (SqStack *S)   //函数功能为构造一个空栈
{
    S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S->base) 
	{
		return (OVERFLOW);//分配失败
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push (SqStack *S,char e)  //插入元素e为新的栈顶元素
{
	if( S->top - S->base >= S->stacksize) //栈满，追加存储空间；
	{
		S->base = (char *) realloc (S->base,(S->stacksize + STACKINCREMENT) * sizeof(char));
	    if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}

Status Pop (SqStack *S,char* pa)  //若栈不为空，删除S的栈顶元素，用e返回其值，并返回OK ;否则返回ERROR;
{
	if(S->top == S->base)
		return ERROR;
	*pa =*(--S->top);
	return OK;
}

Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	S->stacksize = 0;
	return OK;
}

Status LineEdit (SqStack *S)
{
	char ch,c;
	char *p;
	ch = getchar();
	while (ch != EOF)
	{
		while (ch != '\n')
		{
			switch (ch)
			{
			    case '#':
			    {
				   Pop(S,&c);
				   break;
			    }
			    case '@':
			    {   
				   ClearStack(S);
				   break;
			     }
			     default:
			    {
				   Push(S,ch);
				   break;
			     }
			}
			ch = getchar();
		}
		p = S->base;
          while(p <= S->top) 
		  {
              printf("%c",*p);
              ++p;
          }
          ClearStack(S);
          if(ch!=EOF) 
			  ch = getchar();
      }
	return OK;
  }



int main()
{
	SqStack S;
	InitStack(&S);
	LineEdit(&S);//进行括行编辑
    DestroyStack(&S);//将栈销毁
}
