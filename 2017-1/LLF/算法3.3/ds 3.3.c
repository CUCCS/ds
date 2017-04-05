//实现表达式求值   
//参考了CSDN部分代码
//允许用户输入空格（系统自动删除），只能进行整数的四则运算，支持小括号  
//对不能整除的将按两个整数除法规则进行取整  
//对结果进行分步显示
#include <stdio.h>  
#include <stdlib.h>  
#define OK      1  
#define ERROR   0  
#define TRUE    1  
#define FALSE   0  
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10  
#define BUFFERSIZE 256  

typedef int Status; //函数返回状态  
typedef int OPNDelem;  //操作数元素类型  
typedef struct //操作数栈结构定义 
{ 
	OPNDelem *base;
	OPNDelem *top;
	int Stacksize;
}OPNDStack;

typedef char OPTRelem;//操作符元素类型  

typedef struct //操作符栈结构定义
{  
	OPTRelem *base;
	OPTRelem *top;
	int Stacksize;
}OPTRStack;

Status InitStack_OPND(OPNDStack *S);
//构造一个空栈S  
Status Gettop_OPND(OPNDStack S, OPNDelem *e);
//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE  
Status Push_OPND(OPNDStack *S, OPNDelem e);
//插入元素e为新的栈顶元素  
Status Pop_OPND(OPNDStack *S, OPNDelem *e);
//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  



Status InitStack_OPTR(OPTRStack *S);
//构造一个空栈S  
OPTRelem Gettop_OPTR(OPTRStack S);
//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE  
Status Push_OPTR(OPTRStack *S, OPTRelem e);
//插入元素e为新的栈顶元素  
Status Pop_OPTR(OPTRStack *S, OPTRelem *e);
//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  



void Standard(char *expression);
//将表达式标准化  
OPNDelem EvalueateExpression(const char *expression);
//算数表达式求值  
Status IsOPerator(char c);
//判断c是否是一个操作符  
char Precede(char OP1, char OP2);
//判断OP1和OP2优先级的高低，返回'>','<','='  
OPNDelem OPerate(OPNDelem a, OPTRelem comp, OPNDelem b);
//对操作数a，b进行comp运算  
const char *getopND(const char *c, OPNDelem *OP);
//获得以*c开始的操作数，返回后c为操作符  


Status InitStack_OPND(OPNDStack *S)//构造一个空操作数栈S  
{
	 
	S->base = (OPNDelem *)malloc(STACK_INIT_SIZE * sizeof(OPNDelem));
	if (!S->base)//分配失败  
	{
		printf("分配内存失败.\n");
		exit(0);
	}
	S->top = S->base;
	S->Stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Gettop_OPND(OPNDStack S, OPNDelem *e) {
	//若操作数栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回FALSE  
	if (S.top == S.base) {
		printf("栈为空.\n");
		return FALSE;
	}
	else {
		*e = *(S.top - 1);
		return OK;
	}
}

Status Push_OPND(OPNDStack *S, OPNDelem e) {
	//插入元素e为新的栈顶元素  
	if (S->top - S->base >= S->Stacksize) {//栈已满，追加存储空间  
		S->base = (OPNDelem *)realloc(S->base, (S->Stacksize + STACKINCREMENT) * sizeof(OPNDelem));
		if (!S->base)
		{
			printf("重新申请空间失败.\n");
			exit(0);
		}
		S->top = S->base + S->Stacksize;//更改栈顶指针  
		S->Stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop_OPND(OPNDStack *S, OPNDelem *e) //若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  
{
	
	if (S->top == S->base) {//栈为空  
		printf("栈为空.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}


Status InitStack_OPTR(OPTRStack *S) //构造一个空操作数栈S  
{
	
	S->base = (OPTRelem *)malloc(STACK_INIT_SIZE * sizeof(OPTRelem));
	if (!S->base)//分配失败  
	{
		printf("分配内存失败.\n");
		exit(0);
	}
	S->top = S->base;
	S->Stacksize = STACK_INIT_SIZE;
	return OK;
}

OPTRelem Gettop_OPTR(OPTRStack S)//若操作数栈不为空，则返回S的栈顶元素，并返回OK；否则返回FALSE   
{
	
	OPTRelem e;
	if (S.top == S.base) {
		printf("栈为空.\n");
	}
	else {
		e = *(S.top - 1);
	}
	return e;
}

Status Push_OPTR(OPTRStack *S, OPTRelem e) //插入元素e为新的栈顶元素 
{
	 
	if (S->top - S->base >= S->Stacksize)//栈已满，追加存储空间 
	{ 
		S->base = (OPTRelem *)realloc(S->base, (S->Stacksize + STACKINCREMENT) * sizeof(OPTRelem));
		if (!S->base)
		{
			printf("重新申请空间失败!\n");
			exit(0);
		}
		S->top = S->base + S->Stacksize;//更改栈顶指针  
		S->Stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop_OPTR(OPTRStack *S, OPTRelem *e) {
	//若栈S不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则返回ERROR  
	if (S->top == S->base) //栈为空
	{  
		printf("栈为空.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}


OPNDelem EvalueateExpression(const char *expression)	//对只有四则运算符的算数表达式 expression 求值  
                                                    	//OPTR:操作符栈，OPND:操作数栈   
{
	const char *c = expression;
	OPNDStack OPND;
	OPTRStack OPTR;
	OPTRelem x, comp;
	OPNDelem a, b, num, result;
	InitStack_OPTR(&OPTR);//初始化操作符栈  
	InitStack_OPND(&OPND);//初始化操作数栈  
	Push_OPTR(&OPTR, '#');//首先将匹配符号'#'入栈  
	while (*c != '#' || Gettop_OPTR(OPTR) != '#')
	{
		if (*c == '\0')//遇到回车退出  
			break;
		if (FALSE == IsOPerator(*c)) {
			c = getopND(c, &num);
			Push_OPND(&OPND, num);
	}
		else
			switch (Precede(Gettop_OPTR(OPTR), *c))
			{
			case '<':
				Push_OPTR(&OPTR, *c);
				c++;
				break;
			case '=':
				Pop_OPTR(&OPTR, &x);
				c++;
				break;
			case '>':
				Pop_OPTR(&OPTR, &comp);
				Pop_OPND(&OPND, &b);
				Pop_OPND(&OPND, &a);
				result = OPerate(a, comp, b);
				//printf("temp result is:%d\n",result);  
				Push_OPND(&OPND, result);
				break;
			default:
				//printf("Precede:%c",Precede(Gettop_OPTR(OPTR),*c));  
				break;
			}//switch  
	}//while  
	Gettop_OPND(OPND, &result);
	return result;
}

void Standard(char *expression) //将字符串表达式标准化为算术表达式
{	  
	char *p = expression, *q;
	while (*p != '\0') //遍历字符串 
	{ 
		if (*p == ' ') //如果是空格，删除
		{  
			q = p;
			do 
			{
				*q = *(q + 1);
				q++;
			} while (*q != '\0');
		}
		p++;
	}
	*p++ = '#';
	*p = '\0';
}

const char *getopND(const char *c, OPNDelem *OP) //获得以*c开始的操作数，返回后c为操作符  
{	
	int sum = 0, tmp;
	while (FALSE == IsOPerator(*c)) {//当c不是操作符  
		tmp = *c - '0';
		sum = sum * 10 + tmp;
		//printf("tmp=%d\n",tmp);  
		c++;
	}
	*OP = sum;
	//printf("getopND:%d\n",*OP);  
	return c;
}

Status IsOPerator(char c)//判断c是否是一个运算操作符 
{	  
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return TRUE;
		break;
	default:
		return FALSE;
		break;
	}
}

char Precede(char OP1, char OP2)//判断OP1和OP2优先级的高低，返回'>','<','='   
{
	
	switch (OP1) {
	case '+':
		switch (OP2) {
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '-':
		switch (OP2) {
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '*':
		switch (OP2) {
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '/':
		switch (OP2) {
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '(':
		switch (OP2) {
		case ')':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	case ')':
		switch (OP2) {
		default:
			return '>';
			break;
		}
		break;
	case '#':
		switch (OP2) {
		case '#':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	default:
		return '<';
		break;
	}
}

OPNDelem OPerate(OPNDelem a, OPTRelem comp, OPNDelem b)//对操作数a，b进行comp运算，并返回运算结果   
	                                                   //comp只能是四则运算符号
{
	
	int result;
	switch (comp) {
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
		if (b == 0) {
			printf("ERROR:除数为0!");
			exit(0);
		}
		result = a / b;
		break;
	default:
		printf("It's not a OPerator!\n");
		break;
	}
	printf("%d %c %d = %d\n", a, comp, b, result);
	return result;

}

int main()
{
	OPNDelem result = 0;
	char *expression = (char*)malloc(sizeof(char)*BUFFERSIZE);
	if (expression == NULL) {
		printf("Sorry!Memory initialize ERROR!\n");
		exit(0);
	}
	printf("Please input an expression:\n");
	gets(expression);
	Standard(expression);				
	result = EvalueateExpression(expression);
	printf("The result of the expression:%d\n", result);
	return 0;
}