#include "Calculate.h"

Status  InitStack(SqStack *S)    //构造一个空栈
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));

	if (!S->base)      //分配存储空间失败
	{
		return OVERFLOW;
	}

	S->top = S->base;     //初始化
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status Push(SqStack *S, SElemType e)    //插入元素 e 为新的栈顶元素。
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;

}
int StackEmpty(SqStack *S)     //判断栈是否为空
{
	if (S)
		return S->base == S->top;
	return 1;
}

Status Pop(SqStack *S, SElemType *e)   //删除 S 的栈顶元素，并用 e 返回其值。
{
	if (StackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status GetTop(SqStack *S, SElemType *e)    //用 e 返回 S 的栈顶元素。
{
	if (S->top == S->base)
		return ERROR;
	*e = *(S->top - 1);
	return OK;
}

bool In(SElemType c)    //判断输入字符c是否为运算符
{
	switch (c)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':     
		return true;
	default:
		return false;
	}
}

SElemType Precede(SElemType c1, SElemType c2) //判定运算符的栈顶运算符与读入的运算符之间优先关系的函数
{    //根据书53页表3.1 算符间的优先关系确定
	SElemType judge;
	switch (c2)
	{
	case '+':
	case '-':   //‘+’，‘-’为同类
		if (c1 == '(' || c1 == '#')
		{
	         judge = '<';
		}
		else
		{
             judge = '>';
		}
		break;
	case '*':
	case '/':   //‘*’，‘/’为同类
		if (c1 == '*' || c1 == '/' || c1 == ')')
		{
			judge = '>';
		}
		else
		{
			judge = '<';
		}
		break;
	case '(':
		if (c1 == ')')
		{
			return ERROR;
		}
		else
		{
			judge = '<';
		}
		break;
	case ')':
		switch (c1)
		{
		case '(':
			judge = '=';
			break;
		case '#':
			return ERROR;
		default:
			judge = '>';
		}
		break;
	case '#':
		switch (c1)
		{
		case '#':
			judge = '=';
			break;
		case '(':
			return ERROR;
		default:
			judge = '>';
		}
	}
	return judge;
}

SElemType Operate(SElemType a, char ch, SElemType b)  //将出栈的运算符和运算数进行计算
{
	SElemType c;
	a -= 48;
	b -= 48;
	switch (ch)
	{
	case'+':
		c = a + b + 48;
		break;
	case'-':
		c = a - b + 48;
		break;
	case'*':
		c = a * b + 48;
		break;
	case'/':
		c = a / b + 48;
		break;
	}
	return c;
}
int EvaluateExpression(char *suffix)
{
	SqStack OPTR,OPND;
	char ch;
	char a, b, x, theta;
	int i = 0;
	InitStack(&OPTR);
	InitStack(&OPND);

	Push(&OPTR, '#');   //将#作为栈底元素
	GetTop(&OPTR, &ch);   //  获取栈顶元素
	while (suffix[i] != '#' || ch != '#') 
	{
		if (!In(suffix[i]))
		{
			Push(&OPND, suffix[i]);
			i++;
		}
		else 
		{
			switch (Precede(ch, suffix[i])) 
			{
			case '<':  //插入suffix[i]到运算符栈中 
				Push(&OPTR, suffix[i]);
				i++;
				break;
			case '=':
				Pop(&OPTR, &x); //将 x 作出栈处理
				i++;
				break;
			case '>':
				Pop(&OPTR, &theta);
				if (*(OPTR.top - 1) == '(') {
					Pop(&OPTR, &x);
					suffix[i] = '#';
				}
				Pop(&OPND, &b);
				Pop(&OPND, &a);
				Push(&OPND, Operate(a, theta, b));
				if (OPTR.base == OPTR.top) {
					suffix[i] = '#';
				}
				break;
			}
		}
		GetTop(&OPTR, &ch);
	}
	GetTop(&OPND, &ch);
	printf("运算结果为%d\n", ch - '0');
	return ch - '0';
}
int main()
{
	char str1[20] = { "3*6+(7-8/4)*3" };
	char str2[20] = { "8+7*4/2*(5-2)" };

	printf("开始进行%s的计算\n", str1);
	EvaluateExpression(str1);

	printf("开始进行%s的计算\n", str2);
	EvaluateExpression(str2);

	return 0;

}
