#include<stdio.h>
#include<stdlib.h>   
#include<string.h>   
#include<math.h>  
#define true 1   
#define false 0   
#define OPSETSIZE 8   
typedef int Status;

unsigned char Prior[8][8] =
{ // 运算符优先级表   
  // '+' '-' '*' '/' '(' ')' '#' '^'   
	/*'+'*/'>','>','<','<','<','>','>','<',
	/*'-'*/'>','>','<','<','<','>','>','<',
	/*'*'*/'>','>','>','>','<','>','>','<',
	/*'/'*/'>','>','>','>','<','>','>','<',
	/*'('*/'<','<','<','<','<','=',' ','<',
	/*')'*/'>','>','>','>',' ','>','>','>',
	/*'#'*/'<','<','<','<','<',' ','=','<',
	/*'^'*/'>','>','>','>','<','>','>','>'
};

//StackChar类型的结点SC，储存运算符  
typedef struct StackChar
{
	char c;
	struct StackChar *next;
}SC;

//StackFloat类型的结点SF，储存运算数  
typedef struct StackFloat
{
	float f;
	struct StackFloat *next;
}SF;

SC*PushC(SC *s, char c)//SC类型运算符入栈Push，返回栈顶  
{
	SC *p = (SC*)malloc(sizeof(SC));
	p->c = c;
	p->next = s;
	return p;
}

SF *PushF(SF *s, float f)//SF类型运算数入栈Push，返回p  
{
	SF *p = (SF*)malloc(sizeof(SF));
	p->f = f;
	p->next = s;
	return p;
}

SC *PopC(SC *s)//SC类型的指针Pop，删除栈顶运算符元素并返回其值
{
	SC *q = s;
	s = s->next;
	free(q);
	return s;
}

SF* PopF(SF *s)//SF类型的指针Pop，删除栈顶运算数元素并返回其值
{
	SF *q = s;
	s = s->next;
	free(q);
	return s;
}

float Operate(float a, unsigned char theta, float b)//用后缀表达式计算函数Operate  
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a*b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: return 0;
	}
}

char OPSET[OPSETSIZE] = { '+','-','*','/','(',')','#','^' };

Status In(char Test, char *TestOp)//判断是否为运算符
{
	int Find = false;
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (Test == TestOp[i])
			Find = true;
	}
	return Find;
}

Status ReturnOpOrd(char op, char *TestOp)//返回是第几个运算符
{
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (op == TestOp[i])
			return i;
	}
}

char precede(char Aop, char Bop)
{
	return Prior[ReturnOpOrd(Aop, OPSET)][ReturnOpOrd(Bop, OPSET)];
}

float EvaluateExpression(char* MyExpression)
{
	// 算术表达式求值的算符优先算法  
	// 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合   
	SC *OPTR = NULL;       // 运算符栈，字符元素   
	SF *OPND = NULL;       // 运算数栈，实数元素   
	char TempData[20];
	float Data, a, b;
	char theta, *c, Dr[] = { '#','\0' };
	OPTR = PushC(OPTR, '#');
	c = strcat(MyExpression, Dr);
	strcpy(TempData, "\0");//字符串拷贝函数   
	while (*c != '#' || OPTR->c != '#')
	{
		if (!In(*c, OPSET))
		{
			Dr[0] = *c;
			strcat(TempData, Dr);           //字符串连接函数   
			c++;
			if (In(*c, OPSET))
			{
				Data = atof(TempData);       //字符串转换函数(double)   
				OPND = PushF(OPND, Data);
				strcpy(TempData, "\0");
			}
		}
		else    // 不是运算符则进栈   
		{
			switch (precede(OPTR->c, *c))
			{
			case '<': // 栈顶元素优先级低   
				OPTR = PushC(OPTR, *c);
				c++;
				break;
			case '=': // 脱括号并接收下一字符   
				OPTR = PopC(OPTR);
				c++;
				break;
			case '>': // 退栈并将运算结果入栈   
				theta = OPTR->c;OPTR = PopC(OPTR);
				b = OPND->f;OPND = PopF(OPND);
				a = OPND->f;OPND = PopF(OPND);
				OPND = PushF(OPND, Operate(a, theta, b));
				break;
			} //switch  
		}
	} //while   
	return OPND->f;
} //EvaluateExpression   

int main(void)
{
	char s[128];
	printf("请输入表达式:");
	gets(s);
	printf("该表达式的值为:");
	printf("%s\b=%g\n", s, EvaluateExpression(s));
	return 0;
}