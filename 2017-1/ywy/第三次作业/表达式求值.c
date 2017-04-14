#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2
#define ok 1
#define error 0
typedef char SElemtype;
typedef int Elemtype;
typedef struct {
	SElemtype*base;
	SElemtype*top;
	int stacksize;
}SqstackOptr;//运算符栈
typedef struct {
	Elemtype*base;
	Elemtype*top;
	int stacksize;
}SqstackOpnd;//运算数栈
//运算符栈
int InitstackOptr(SqstackOptr*s);//初始化栈
SElemtype GettopOptr(SqstackOptr*s);//获取栈顶元素
int PushOptr(SqstackOptr*s, SElemtype e);//入栈
int PopOptr(SqstackOptr*s, SElemtype *e);//删除栈中元素
int DestorystackOptr(SqstackOptr*s);//销毁栈
//运算数栈
int InitstackOpnd(SqstackOpnd*s);
Elemtype GettopOpnd(SqstackOpnd*s);
int PushOpnd(SqstackOpnd*s, Elemtype e);
int PopOpnd(SqstackOpnd*s, Elemtype*e);
int DestorystackOpnd(SqstackOpnd*s);
//表达式求值
//输入表达式并计算
Elemtype EvaluateExpression(SqstackOptr*OPTR, SqstackOpnd*OPND);
SElemtype Precede(char topc, char c);//判断运算符优先级
Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b);//计算部分表达式的值
Elemtype In(char c, char op[]);//判断输入的字符是不是运算符
// 初始化栈
int InitstackOptr(SqstackOptr*s) {
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	    if (!s->base) {
	    return overflow;
	}
	    s->top = s->base;
	     s->stacksize = STACK_INIT_SIZE;
	    return ok;
}
int InitstackOpnd(SqstackOpnd*s)
{
	s->base = (Elemtype*)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!s->base)
	{
		return overflow;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return ok;
}
//获取栈顶元素
SElemtype GettopOptr(SqstackOptr*s)
{
	if(s->top==s->base)
	{
		return error;
	}
	return *(s->top - 1);
}
Elemtype GettopOpnd(SqstackOpnd*s)
{
	if(s->top==s->base)
	{
		return error;
	}
	return *(s->top - 1);
}
//入栈
int PushOptr(SqstackOptr*s, SElemtype e)
{
	if ((s->top - s->base) >= s->stacksize)
	{
		s->base = (SElemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemtype));
	if(!s->base)
	{
		return error;
	}
	s->top = s->base + s->stacksize;
	s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return ok;
}
int PushOpnd(SqstackOpnd*s, Elemtype e)
{
	if ((s->top - s->base) >= s->stacksize)
	{
		s->base = (Elemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Elemtype));
		if (!s->base)
		{
			return error;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return ok;
}
//删除元素
int PopOptr(SqstackOptr*s, SElemtype*e)
{
	if(s->top==s->base)
	{
		return error;
	}
	*e = *--s->top;
	return ok;
}
int PopOpnd(SqstackOpnd*s, Elemtype*e)
{
	if(s->top==s->base)
	{
		return error;
	}
	*e = *--s->top;
	return ok;
}
//销毁栈
int DestorystackOptr(SqstackOptr*s)
{
	s->top = s->base;
	free(s->base); 
	s->top = NULL;
	s->base = NULL;
	return ok;
}
int DestorystackOpnd(SqstackOpnd*s)
{
	s->top = s->base;
	free(s->base);
	s->top = NULL;
	s->base = NULL;
	return ok;
}
//判断输入的字符是不是运算符
Elemtype In(char c, char op[])
{
	int i, f = 0;
	for (i = 0; i < 7; i++)
	{
		if (c == op[i])
		{
			f = i;
			break;
		}
	}
	if (f == 0)
	{
		return 0;
	}
	else return 1;
}
//比较运算符优先级
SElemtype Precede(char topc, char c)
{
	if (topc == '+' || topc == '-')
	{
		if (c == '+' || c == '-' || c == ')' || c == '#')
		{
			return '>';
		}
		else return '<';
	}
	if (topc == '*' || topc == '/')
	{
		if (c == '(')
		{
			return '<';
		}
		else return '>';
}
	if (topc == '(')
	{
		if (c == ')')
		{
			return '=';
		}
		else return '<';
	}
	if (topc == ')')
	{
		return ')';
	}
	if (topc == '#')
	{
		if (c == '#')
		{
			return '=';
		}
		else return '<';
	}
}
//求值
Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b)
{
	switch (theta)
	{
	case '+':return a + b; break;
	case '-':return a - b; break;
	case'*':return a*b; break;
	case'/':return a / b; break;
	}
}
//算法
Elemtype EvaluateExpression(SqstackOptr*OPTR, SqstackOpnd*OPND)
{
	SElemtype c, theta, x;
	Elemtype a, b,v;
	SElemtype op[7] = { '+','-','*','/','(',')','#' };
	InitstackOptr(OPTR);
	InitstackOpnd(OPND);
	PushOptr(OPTR, '#');
	printf("输入表达式: ");
	c = getchar();
	while (c != '#' || GettopOptr(OPTR) != '#')
	{
		if (!In(c, op))
		{
			PushOpnd(OPND, c - '0');
			c = getchar();
		}
		else
		{
			switch (Precede(GettopOptr(OPTR), c))
			{
			case'<'://栈顶元素优先级低
				PushOptr(OPTR, c);
				c = getchar();
				break;
			case'>'://栈顶元素优先级高
				PopOptr(OPTR, &theta);
				PopOpnd(OPND, &b);
				PopOpnd(OPND, &a);
				v = Operate(a, theta, b);
				PushOpnd(OPND, v);
				break;
			case'=':
				PopOptr(OPTR, &x);
				c = getchar();
				break;
			}
		}
	}
	return GettopOpnd(OPND);
}
int main()
{
	SqstackOpnd OPND;
	SqstackOptr OPTR;
	int result;
	result = EvaluateExpression(&OPTR, &OPND);
	printf("表达式结果为： %d\n", result);
	system("pause");
	return 0;
}
//算法部分和运算符比较部分参考较多