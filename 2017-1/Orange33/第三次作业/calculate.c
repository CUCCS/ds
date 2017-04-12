#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量 
#define STACKINCREMENT 10 //存储空间分配增量 

typedef char SElemType;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct SqStack 
{
	SElemType *base;
	SElemType *top;
	int stacksize;
} SqStack;

int InitStack(SqStack *stack)//构造空栈 
{

	stack->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(int));
	if (!stack->base)  // 分配存储空间失败 
	{
		return OVERFLOW;
	}                   
	stack->stacksize = STACK_INIT_SIZE;
	stack->top = stack->base;
	return OK;
}

void DestroyStack(SqStack *stack)   //毁栈 
{
	//stack = NULL;
}

int StackEmpty(SqStack *stack)   //判断栈是否为空
{
	if (stack->base == stack->top)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}


int Push(SqStack *stack, SElemType e)  //压栈
{
	if (stack->top - stack->base > stack->stacksize)
	{   
		stack->base = (SElemType *)realloc(stack->base,
			(stack->stacksize + STACKINCREMENT) * sizeof(SElemType *));
		if (!stack->base)
		{
			return OVERFLOW;
		}
		stack->top = stack->base + stack->stacksize;
		stack->stacksize = stack->stacksize + STACKINCREMENT;
	}
	*stack->top = e;
	stack->top++;
	return OK;
}


int Pop(SqStack *stack, SElemType *e) 
{
	if (StackEmpty(stack)) 
	{
		return ERROR;
	}
	stack->top--;
	*e = *stack->top;
	return OK;
}


SElemType GetTop(SqStack stack) //返回栈顶元素 
{
	if (!StackEmpty(&stack))
	{ 
		stack.top--; 
	} 
	return *stack.top; 
} 


int IsOperator(SElemType e)    //判断读入字符是否为运算符 
{
	if (e == '+'||e == '-'||e == '*'||e == '/'||e == '('||e == ')'||e == '#')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


SElemType Precede(SElemType a, SElemType b)//比较运算符优先级 
{
	SElemType ch;
	switch (a)
	{
	case '+':
	case '-':
		{
			if (b == '+' || b == '-' || b == ')' || b == '#')
			{
				ch = '>';
			}
			else if (b == '*' || b == '/' || b == '(')
			{
				ch = '<';
			}
		}
		break;
	case '*':
	case '/':
		{
			if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
			{
				ch = '>';
			}
			else if (b == '(')
			{
				ch = '<';
			}
		}
		break;

	case '(':
		{
			if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
			{
				ch = '<';
			}
			else if (b == ')')
			{
				ch = '=';
			}
		}
		break;

	case ')':
		{
			if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
			{
				ch = '>';
			}
		}
		break;

	case '#':
		{
			if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
			{
				ch = '<';
			}
			else if (b == '#')
			{
				ch = '=';
			}
		}
		break;
	}
	return ch;
}


SElemType Operate(SElemType a, SElemType Operator, SElemType b)//运算 
{
	SElemType ch;
	a = a - 48;    // 转化成int类 
	b = b - 48;   //转化成int类 
	switch(Operator)
	{
	case '+':
		ch = a + b + 48;
		break;
	case '-':
		ch = a - b + 48;
		break;
	case '*':
		ch = a * b + 48;
		break;
	case '/':
		ch = a / b + 48;
		break;
	}
	return ch;
}


int calculate()
{
	SqStack Operator,Oprand;
	SElemType ch,a,b,theta,x; 
	InitStack(&Operator);       //初始化操作符栈 
	InitStack(&Oprand);        //初始化操作数栈 
	Push(&Operator,'#'); 
	ch=getchar(); 
	while(ch!='#'||GetTop(Operator)!='#') 
	{ 
		if(!IsOperator(ch)) 
		{ 
			Push(&Oprand,ch); 
			ch=getchar(); 
		} 
		else 
		{ 
			switch(Precede(GetTop(Operator),ch)) 
			{ 
			case '<': 
				Push(&Operator,ch); 
				ch=getchar(); 

				break; 
			case '>': 
				Pop(&Operator,&theta); 
				Pop(&Oprand,&b); 
				Pop(&Oprand,&a); 
				Push(&Oprand,Operate(a,theta,b)); 
				break; 
			case '=': 
				Pop(&Operator,&x); 
				ch=getchar(); 
				break; 
			} 
		} 

	} 

	return GetTop(Oprand)-'0'; 
} 


void main()
{
	printf("请输入算术表达式,输入#结束\n"); 
	printf("结果是: %d\n",calculate());
}