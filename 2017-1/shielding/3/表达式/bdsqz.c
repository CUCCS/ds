#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool IsOperator(char ch)
{
	char ops[] = "+-*/";
	for (int i = 0; i < sizeof(ops) / sizeof(char); i++)
	{
		if (ch == ops[i])
			return TRUE;
	}
	return FALSE;
}

// 比较两个操作符的优先级
int Precedence(char op1, char op2)
{
	if (op1 == '(')
	{
		return -1;
	}

	if (op1 == '+' || op1 == '-')
	{
		if (op2 == '*' || op2 == '/')
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	if (op1 == '*' || op1 == '/')
	{
		if (op2 == '+' || op2 == '-')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
// 中缀表达式转换成后缀表达式
void inFix2PostFix(char* inFix, char* postFix)
{
	int j = 0, len;
	char c;
	SqStack *st=NULL;
	InitStack(st);
	SElemType *e;
	len = strlen(inFix);

	for (int i = 0; i < len; i++)
	{
		c = inFix[i];

		if (c == '(')
			Push(st, c);
		else if (c == ')')
		{
			GetTop(st, e);
			while (e != '(')
			{
				GetTop(st, e);
				postFix[j++] = e;
				Pop(st, e);
			}
			Pop(st, e);
		}
		else
		{
			if (!IsOperator(c))
				Push(st, c);
			else
			{
				while (!StackEmpty(st)
					&& Precedence(e, c) >= 0)
				{
					GetTop(st, e);
					postFix[j++] = *e;
					Pop(st, e);
				}
				Push(st, c);
			}
		}
	}

	while (!StackEmpty(st))
	{
		GetTop(st, e);
		postFix[j++] = *e;
		Pop(st, e);
	}
	postFix[j] = 0;
}
// 后缀表达式求值程序
double postFixEval(char* postFix)
{
	SqStack* st;
	InitStack(st);
	int len = strlen(postFix);
	char c;

	for (int i = 0; i < len; i++)
	{
		c = postFix[i];
		if (IsOperator(c) == FALSE)
		{
			Push(st, c - '0');
		}
		else
		{
			SElemType *o1, *o2, *e;
			int val;

			GetTop(st, o1);
			Pop(st, e);
			GetTop(st, o2);
			Pop(st, e);

			int op1 = *o1 - '0';
			int op2 = *o2 - '0';
			switch (c)
			{
			case '+':
				val = op1 + op2;
				break;
			case '-':
				val = op2 - op1;
				break;
			case '*':
				val = op1 * op2;
				break;
			case '/':
				val = op2 / op1;
				break;
			}
			Push(st, val);
		}
	}
	SElemType *e;
	GetTop(st, e);
	return *e;
}

int main()
{
	char inFix[100];
	char postFix[100];
	double val;

	while (1)
	{
		printf("enter an expression:");
		gets(inFix);
		if (strlen(inFix) == 0)
			continue;

		printf("\n%s = ", inFix);
		inFix2PostFix(inFix, postFix);
		printf("%s = ", postFix);
		val = postFixEval(postFix);
		printf("%.3f\n", val);
	}

	return 0;
}