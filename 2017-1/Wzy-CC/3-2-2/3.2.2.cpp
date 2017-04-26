//算法3.2.2
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType;

typedef struct {
	SElemType *elem;
	int length;
	int listsize;
} SqList;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base = (SElemType*)malloc(100 * sizeof(SElemType));
	if (!S->base)exit(OVERFLOW);//储存分配失败
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base)
		return ERROR;
	e = S.top - 1;
	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)//栈满，追加储存空间
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)exit(OVERFLOW);//储存分配失败
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//push

Status Pop(SqStack *S, SElemType *e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if (S->top == S->base)
		return ERROR;
	e = --S->top;
	return OK;
}

bool StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}//为空elsereturn false;//不为空} 

Status MatchCheck(SqList exp)
/* 顺序表exp表示表达式；                        */
/* 若exp中的括号配对，则返回TRUE，否则返回FALSE */
{
	SqStack s;
	char e;
	//逐个读入括号
	for (int i = 0; i<exp.listsize; i++)
	{
		if (exp.elem[i] == '(' || exp.elem[i] == '{' || exp.elem[i] == '[')//若遇左括号，则直接入栈
		{
			Push(s, exp.elem[i]);
		}
		else if (exp.elem[i] == ')')//若遇右圆括号，则尝试匹配栈顶括号
		{
			if (GetTop(s, e))
			{
				if (e == '(')//匹配成功，左圆括号出栈
				{
					Pop(s, e);
				}
				else//匹配不成功，右圆括号入栈
				{
					Push(s, exp.elem[i]);
				}
			}
			else//栈为空，则将右括号入栈
			{
				Push(s, exp.elem[i]);
			}
		}
		else if (exp.elem[i] == '}')//若遇右花括号，则尝试匹配栈顶括号
		{
			if (GetTop(s, e))
			{
				if (e == '{')//匹配成功，左花括号出栈
				{
					Pop(s, e);
				}
				else//匹配不成功，右花括号入栈
				{
					Push(s, exp.elem[i]);
				}
			}
			else
			{
				Push(s, exp.elem[i]);
			}
		}
		else if (exp.elem[i] == ']')//若遇右方括号，则尝试匹配栈顶括号
		{
			if (GetTop(s, e))
			{
				if (e == '[')//匹配成功，左方括号出栈
				{
					Pop(s, e);
				}
				else//匹配不成功，右方括号入栈
				{
					Push(s, exp.elem[i]);
				}
			}
			else
			{
				Push(s, exp.elem[i]);
			}
		}
	}
	if (StackEmpty(s))//当所有括号匹配成功时，栈应为空
	{
		printf("匹配，为正确的格式");
		//return OK;
	}
	else             //栈里有一堆括号，没有清空
	{
		printf("不匹配，为错误的格式");
		//return ERROR;
	}
}

int main()
{
	Status MatchCheck();
	return OK;
}


