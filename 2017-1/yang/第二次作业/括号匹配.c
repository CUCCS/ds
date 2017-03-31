#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCRESE 10
typedef char SElemType;
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;
}Sqstack;
typedef enum
{
	error, ok
}Status;
//创建栈
Status Initstack(Sqstack*S)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
	{
		return error;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return ok;
}
//判断栈是否为空
Status StackEmpty(Sqstack *S)
{
	if (S->top == S->base)
	{
		return ok;
	}
	else return error;
}
//插入栈顶元素
Status Push(Sqstack*S, SElemType e)
{
	if (S->top - S->base == S->stacksize)
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCRESE) * sizeof(SElemType));
		S->top = S->base + S->stacksize;
		S->base = S->base + STACKINCRESE;
	}
	*S->top++ = e;
	return ok;
}
//出栈
Status Pop(Sqstack *S, SElemType*e)
{
	if (S->top == S->base)
	{
		return error;
	}
	*e = *--S->top;
	return ok;
}
//括号匹配，匹配函数写的并不好，只有可以匹配的括号连续出现才可以正确匹配
Status cout(Sqstack *S, SElemType*str)
{
	int i = 0, flag = 0;
	SElemType e;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '(':
			Push(S, str[i]);
			break;

		case '{':
			Push(S, str[i]);
			break;
		case '[':
			Push(S, str[i]);
			break;
		case ')':
		{
			Pop(S, &e);
			if (e != '(')
			{
				flag = 1;
			}
		}
		break;
		case ']':
		{
			Pop(S, &e);
			if (e != '[')
			{
				flag = 1;
			}
		}
		break;
		case '}':
		{
			Pop(S, &e);
			if (e != '{')
			{
				flag = 1;
			}
		}
		break;
		}
		i++;
	}
	if (!flag&&StackEmpty(S))
	{
		printf("匹配成功！\n");
	}
	else
		printf("匹配失败！\n");

	return ok;
}
int main()
{
	printf("输入要匹配的括号：");
	SElemType str[20];
	Sqstack S;
	Initstack(&S);
	scanf("%s", str);
	cout(&S, str);
}