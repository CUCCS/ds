#include "evaluation.h"
#include <string.h>  
#include <stdlib.h>  
#include <math.h>  
#include <conio.h>  

char ops[7] = { '+','-','*','/','(',')','#' };  /*运算符数组*/

int  cmp[7][7] = { { 2,2,1,1,1,2,2 },    /*用来进行比较运算符优先级的矩阵,3代表'=',2代表'>',1代表'<',0代表不可比*/
{ 2,2,1,1,1,2,2 },
{ 2,2,2,2,1,2,2 },
{ 2,2,2,2,1,2,2 },
{ 1,1,1,1,1,3,0 },
{ 2,2,2,2,0,2,2 },
{ 1,1,1,1,1,0,3 } };
void InitStack(SeqStack *S)   /*初始化运算符栈*/
{
	S->top = -1;
}

void InitStackn(nSeqStack *S)   /*初始化运算数栈*/
{
	S->top = -1;
}

int IsEmpty(SeqStack *S)    /*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

int IsEmptyn(nSeqStack *S)    /*判断栈S为空栈时返回值为真，反之为假*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

/*判栈满*/
int IsFull(SeqStack *S)     /*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}

int IsFulln(nSeqStack *S)       /*判断栈S为满栈时返回值为真，反之为假*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}

int Push(SeqStack *S, char x)   /*运算符栈入栈函数*/
{
	if (S->top == Stack_Size - 1)
	{
		printf("Stack is full!\n");
		return FALSE;
	}
	else
	{
		S->top++;
		S->elem[S->top] = x;
		return TRUE;
	}
}

int Pushn(nSeqStack *S, int x)   /*运算数栈入栈函数*/
{
	if (S->top == Stack_Size - 1)
	{
		printf("Stack is full!\n");
		return FALSE;
	}
	else
	{
		S->top++;
		S->elem[S->top] = x;
		return TRUE;
	}
}

int Pop(SeqStack *S, char *x)    /*运算符栈出栈函数*/
{
	if (S->top == -1)
	{
		printf("运算符栈空!\n");
		return FALSE;
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return TRUE;
	}
}

int Popn(nSeqStack *S, int *x)    /*运算数栈出栈函数*/
{
	if (S->top == -1)
	{
		printf("运算符栈空!\n");
		return FALSE;
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return TRUE;
	}
}

char GetTop(SeqStack *S)    /*运算符栈取栈顶元素函数*/
{
	if (S->top == -1)
	{
		printf("运算符栈为空!\n");
		return FALSE;
	}
	else
	{
		return (S->elem[S->top]);
	}
}

int GetTopn(nSeqStack *S)    /*运算数栈取栈顶元素函数*/
{
	if (S->top == -1)
	{
		printf("运算符栈为空!\n");
		return FALSE;
	}
	else
	{
		return (S->elem[S->top]);
	}
}


int Isoperator(char ch)        /*判断输入字符是否为运算符函数,是返回TRUE,不是返回FALSE*/
{
	int i;
	for (i = 0; i<7; i++)
	{
		if (ch == ops[i])
			return TRUE;
	}
	return FALSE;
}

/*
int isvariable(char ch)
{ if (ch>='a'&&ch<='z')
return true;
else
return false;
}*/


char Compare(char ch1, char ch2)   /*比较运算符优先级函数*/
{
	int i, m, n;
	char pri;                     /*保存优先级比较后的结果'>'、'<'、'='*/
	int priority;                 /*优先级比较矩阵中的结果*/
	for (i = 0; i<7; i++)              /*找到相比较的两个运算符在比较矩阵里的相对位置*/
	{
		if (ch1 == ops[i])
			m = i;
		if (ch2 == ops[i])
			n = i;
	}

	priority = cmp[m][n];
	switch (priority)
	{
	case 1:
		pri = '<';
		break;
	case 2:
		pri = '>';
		break;
	case 3:
		pri = '=';
		break;
	case 0:
		pri = '$';
		printf("表达式错误!\n");
		break;
	}
	return pri;
}

int Execute(int a, char op, int b)    /*运算函数*/
{
	int result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}

int ExpEvaluation()
/*读入一个简单算术表达式并计算其值。optr和operand分别为运算符栈和运算数栈，OPS为运算符集合*/
{
	int a, b, v, temp;
	char ch, op;
	char *str;
	int i = 0;

	SeqStack optr;                                   /*运算符栈*/
	nSeqStack operand;                               /*运算数栈*/

	InitStack(&optr);
	InitStackn(&operand);
	Push(&optr, '#');
	printf("请输入表达式(以#结束):\n");            /*表达式输入*/
	str = (char *)malloc(50 * sizeof(char));
	gets(str);                                     /*取得一行表达式至字符串中*/

	ch = str[i];
	i++;
	while (ch != '#' || GetTop(&optr) != '#')
	{
		if (!Isoperator(ch))
		{
			temp = ch - '0';    /*将字符转换为十进制数*/
			ch = str[i];
			i++;
			while (!Isoperator(ch))
			{
				temp = temp * 10 + ch - '0'; /*将逐个读入运算数的各位转化为十进制数*/
				ch = str[i];
				i++;
			}
			Pushn(&operand, temp);
		}
		else
		{
			switch (Compare(GetTop(&optr), ch))
			{
			case '<':
				Push(&optr, ch);
				ch = str[i];
				i++;
				break;
			case '=':
				Pop(&optr, &op);
				ch = str[i];
				i++;
				break;
			case '>':
				Pop(&optr, &op);
				Popn(&operand, &b);
				Popn(&operand, &a);
				v = Execute(a, op, b);  /* 对a和b进行op运算 */
				Pushn(&operand, v);
				break;
			}
		}
	}
	v = GetTopn(&operand);
	return v;
}