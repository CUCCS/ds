#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  
#include <math.h>     //含有overflow  
#include <process.h>  //exit()  

#define S_SIZE 100   //栈的空间大小  
#define STACKINCREAMENT 10//增加空间  A

//初始化空栈
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(S_SIZE * sizeof(int));
	S->stacksize = S_SIZE;
	S->top = S->base;
};
//判断栈是否为空
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
	{
		return 1;
	}

	else
		return 0;
};

//进栈
void push(SqStack *S, int e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREAMENT) * sizeof(int));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREAMENT;
	}
	*(S->top) = e;
	S->top++;
};

//出栈
void pop(SqStack *S, int *e)
{
	if (S->base != S->top)
	{
		S->top--;
		*e = *S->top;
	}
};
//销毁栈
int DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	printf("释放栈空间\n");
	return 1;
}
void pair(SqStack s, char *p)
{
	int e;
	while (*p)
	{
		switch (*p)
		{
			//s只要是左括号就入栈  		
		case '{':	case '[':case '(':
		{
			push(&s, *p++);
			break;
		}

		//s只要是右括号就与栈中的左括号e配对	
		case '}':case ']':case ')':
		{
			pop(&s, &e);
			if ((e == '{' && *p == '}') || (e == '[' && *p == ']') || (e == '(' && *p == ')'))
			{
				p++;
			}
			else
			{
				printf("括号不匹配!\n");
				return OVERFLOW;//返回OVERFLOW的值给主调进程
			}
			break;
		}

		default:
		{
			p++;
		}//其他字符就后移  
		}//end switch

	}//end while

	if (StackEmpty(s))
	{
		printf("括号匹配成功");
	}//出入栈完成后检查栈是否为空,若为空则代表所有括号都匹配成功
	else
	{
		printf("缺少右括号！");
	}//否则栈中有剩余的左括号，配对不成功
	printf("\n");
};
