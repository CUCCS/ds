//matching


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef enum
{
	false,
	true
}bool;


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

bool StackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return true;
	else
		return false;
}

Status GetTop(SqStack *S,char *e)
{
	if(S->top == S->base)
		return ERROR;
	*e = *(S->top - 1);
	return OK;
}

Status matching (char *e,SqStack *S) 
{
	int state = 1;
	int i=0;
	char z;
	while ( e[i] != '\0') 
	{
        switch (e[i]) 
		{
		case '(':
		case '{':
		case '[': 
			{ 
                Push(S, e[i]);
				i++;
				break ;
            }
		case ')':
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '(')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		case '}':
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '{')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		case ']': 
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '[')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		}
	}
	if(StackEmpty(S) && state)//空栈且state不为0则全部匹配
	{
        printf("括号全部匹配\n");
	    return OK;
	}
    else
	{
         printf("括号不匹配\n");
		 return ERROR;
	}
}
			

int main()
{
	char test[]="(){}[]";
	char hhhh[]="({}{";
	SqStack S,B;
	InitStack(&S);
	InitStack(&B);
	printf("测试用例：");
	puts(test);
	matching(test,&S);
	printf("测试用例：");
	puts(hhhh);
	matching(hhhh,&B);
	return 0;
}