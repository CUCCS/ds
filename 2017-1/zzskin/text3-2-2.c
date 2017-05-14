#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INIT_SIZE 100    //存储空间初始分配量
#define STACK_SIZE 100            //存储空间分配增量
#define STACKINCREMENT 10         //存储空间分配增量

typedef char SElemType ;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //枚举定义（返回状态）

typedef enum{
	False,
	True
}Bool;                            //定义布尔类型

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;                          //顺序栈的定义

Status InitStack(SqStack *S,int size);
Status Push(SqStack *S,SElemType e);
Bool IsStackEmpty(SqStack *S);
SElemType GetTop(SqStack *S,SElemType *e);
Status Pop(SqStack *S,SElemType *e);
void DestroyStack(SqStack *S);
Status matching(SqStack S, char *exp);

Status InitStack(SqStack *S,int size)       //构造顺序栈
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
	    return  OVERFLOW; 
	}//存储分配失败
	S->top = S->base;
	S->stacksize = size;
	return OK;
}

Status Push(SqStack *S,SElemType e)//插入元素为e的新的栈顶元素
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Bool IsStackEmpty(SqStack *S)//判断栈顶是否为空；
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

SElemType GetTop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status Pop(SqStack *S,SElemType *e)//若栈不为空，则删除s的栈顶元素，用e返回值，并返回OK，否则返回ERROR；
{
	if(IsStackEmpty(S))
	{
		return ERROR;

	}
	*e = *--S->top;

	return OK;
}

void DestroyStack(SqStack *S)//销毁栈s，s不存在
{
	if(S)
	{
		S = NULL;
	}
	free(S);
}
Status matching(SqStack S, char *exp)//括号是否匹配
{
	int state = 1;
	int i = 0;
	int flag = 0;
	SElemType e;
	while(exp[i]!='\0')
	{
		switch(exp[i])
		{
		case '(':
			Push(&S,exp[i]);
			break;
		case '[':
			Push(&S, exp[i]);
			break;
		case '{':
			Push(&S, exp[i]);
			break;

		case ')':
			{
					Pop(&S ,&e);
					if(e != '(')
						flag = 1;
			}
			break;
				
		case ']':
			{
					Pop(&S ,&e);
					if(e != '[')
						flag = 1;
			}
			break;
		case '}':
			{
					Pop(&S ,&e);
					if(e != '{')
						flag = 1;
			}
			break;
		}
		i++;
	}
		if(IsStackEmpty(&S) && state) 
			return OK;
		else
			return ERROR;
}
int main()
{
	SqStack S;
	Status ret;//cserfsedc
	char test[100];
	scanf("%s",&test);
	InitStack(&S,STACK_SIZE);
	ret = matching(S ,test);

	if(ret == OK)
	{
		printf("匹配成功！\n");
	}
	else 
	{
		printf("匹配失败！\n");
	}
	return 0;
}