#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2
#define ok 1
#define error 0
typedef int Status;
typedef char SElemtype;
typedef int Elemtype;
typedef struct {

	SElemtype*base;

	SElemtype*top;

	int stacksize;

}OPTR;//运算符栈

typedef struct {

	Elemtype*base;

	Elemtype*top;

	int stacksize;

}OPND;//运算数栈

//运算符栈
//Status Initstack(OPTR*s);//初始化栈
//
//Status Gettop(OPTR*s);//获取栈顶元素
//
//Status Push(OPTR*s, SElemtype e);//入栈
//
//Status Pop(OPTR*s, SElemtype *e);//删除栈中元素
//
//Status Destorystack(OPTR*s);//销毁栈
//
////运算数栈
//Status Initstack(OPND*s);//初始化栈
//
//Status Gettop(OPND*s);//获取栈顶元素
//
//Status Push(OPND*s, SElemtype e);//入栈
//
//Status Pop(OPND*s, SElemtype *e);//删除栈中元素
//
//Status Destorystack(OPND*s);//销毁栈
//
//
////表达式求值
//
////输入表达式并计算
//
//Elemtype EvaluateExpression(OPTR*OPTR, OPND*OPND);
//
//SElemtype Precede(char topc, char c);//判断运算符优先级
//
//Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b);//计算部分表达式的值
//
//Elemtype In(char c, char op[]);//判断输入的字符是不是运算符

// 初始化两个栈
Status InitstackTR(OPTR*s) {

	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));

	if (!s->base) {

		return overflow;

	}

	s->top = s->base;

	s->stacksize = STACK_INIT_SIZE;

	return ok;

}

Status InitstackND(OPND*s)

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

Status GettopTR(OPTR*s)

{

	if (s->top == s->base)

	{

		return error;

	}

	return *(s->top - 1);

}

Status GettopND(OPND*s)

{

	if (s->top == s->base)

	{

		return error;

	}

	return *(s->top - 1);

}

//入栈

Status  PushTR(OPTR*s, SElemtype e)

{

	if ((s->top - s->base) >= s->stacksize)

	{

		s->base = (SElemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemtype));

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

Status PushND(OPND*s, SElemtype e)

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

Status PopTR(OPTR*s, SElemtype*e)

{

	if (s->top == s->base)

	{

		return error;

	}

	*e = *--s->top;

	return ok;

}

Status PopND(OPND*s, SElemtype*e)

{

	if (s->top == s->base)

	{

		return error;

	}

	*e = *--s->top;

	return ok;

}

//销毁栈

Status DestorystackTR(OPTR*s)

{

	s->top = s->base;

	free(s->base);

	s->top = NULL;

	s->base = NULL;

	return ok;

}

Status DestorystackND(OPND*s)


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
		//输入的字符与数据库中的字符进行对比
}

	if (f == 0)

	{
return 0;
}
else return 1;

}

//根据表比较运算符优先级

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

//对表达式进行求值

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

//整个的运行算法

Elemtype EvaluateExpression(OPTR*OPTR, OPND*OPND)

{

	SElemtype c, theta, x;

	Elemtype a, b, v;

	SElemtype op[7] = { '+','-','*','/','(',')','#' };

	InitstackTR(OPTR);

	InitstackND(OPND);

	PushTR(OPTR, '#');

	printf("输入表达式: ");

	c = getchar();

	while (c != '#' || GettopTR(OPTR) != '#')

	{

		if (!In(c, op))

		{

			PushND(OPND, c - '0');

			c = getchar();

		}

		else

		{

			switch (Precede(GettopTR(OPTR), c))

			{

			case'<'://栈顶元素优先级低

				PushTR(OPTR, c);

				c = getchar();

				break;

			case'>'://栈顶元素优先级高

				PopTR(OPTR, &theta);

				PopND(OPND, &b);

				PopND(OPND, &a);

				v = Operate(a, theta, b);

				PushND(OPND, v);

				break;

			case'=':

				PopTR(OPTR, &x);

				c = getchar();

				break;

			}

		}

	}

	return GettopND(OPND);

}

int main()

{

	OPND OPND;

	OPTR OPTR;

	int result;

	result = EvaluateExpression(&OPTR, &OPND);

	printf("表达式结果为： %d\n", result);

	system("pause");

	return 0;

}