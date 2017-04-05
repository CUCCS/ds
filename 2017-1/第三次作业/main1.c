
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef char SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
typedef enum bool{ false, true }bool;
typedef struct _SqStack {
	SElemType   *base;
	//造之前和销毁之后，base的值为NULL
	SElemType *top; //栈顶指针
	int stracksize;
}SqStack;
Status InitStack(SqStack *S) {
	//构建一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e) {
	//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stracksize) {//栈满，追加存储空间
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//存储分配失败
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S) {

	if (S->top == S->base)
		return true;//为空
	else
		return false;//不为空
}
void conversation(SqStack *S, int input, int d) {
	SElemType e;
	InitStack(S);
	while (input)
	{
		Push(S, input%d);
		input = input / d;
	}
	while (!StackEmpty(S)) {
		Pop(S, &e);
		printf("%d", e);
	}
}
void DestroyStack(SqStack *stack)//销毁已经存在的栈3
{
	free(stack->base);
	stack->top = stack->base;
}
Status GetTop(SqStack s, char *e) {
	if (s.top == s.base) {
		return ERROR;
	}
	*e = *(s.top - 1);
	printf("栈顶字符为 %c\n", *e);
	return OK;
}
void Traverse(SqStack s) {
	printf("开始遍历:\n");
	while (!StackEmpty(&s)) {
		printf("%c\n", *(s.top - 1));
		--s.top;
	}
}
bool IN(char ch) {
	if (ch <= '100'&&ch >= '0') {
		return false;
	}
	else {
		return true;
	}
}
char Precede(char exist, char read) {
	switch (exist) {
	case '+':
		if (read == '+' || read == '-' || read == ')' || read == '#') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '-':
		if (read == '+' || read == '-' || read == ')' || read == '#') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '*':
		if (read == '(') {
			return '<';
		}
		else {
			return '>';
		}
		break;
	case '/':
		if (read == '(') {
			return '<';
		}
		else {
			return '>';
		}
		break;
	case '(':
		if (read == ')') {
			return '=';
		}
		else {
			return '<';
		}
		break;
	case ')':
		return '>';
		break;
	case '#':
		if (read == '#') {
			return '=';
		}
		else {
			return '<';
		}
		break;
	}
	return OK;
}
char Operate(char a, char thete, char b) {
	switch (thete) {
	case '+':
		return (a - '0') + (b - '0') + '0';
		break;
	case '-':
		return (a - '0') - (b - '0') + '0';
		break;
	case '*':
		return (a - '0')*(b - '0') + '0';
		break;
	case '/':
		return (a - '0') / (b - '0') + '0';
		break;
	}
}
int EvaluateExpression(char *exp) {
	SqStack OPTR;
	SqStack OPND;
	char e;
	char a, b, theta;
	char x;
	int len;
	int i = 0;
	len = strlen(exp);
	exp[len] = '#';

	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR, '#');
	GetTop(OPTR, &e);
	while (exp[i] != '#' || e != '#') {
		if (!IN(exp[i])) {
			printf("插入 %c 到操作数栈中\n", exp[i]);
			Push(&OPND, exp[i]);
			i++;
		}
		else {
			switch (Precede(e, exp[i])) {
			case '<':
				printf("插入 %c 到运算符栈中\n", exp[i]);
				Push(&OPTR, exp[i]);
				i++;
				break;
			case '=':
				Pop(&OPTR, &x);
				printf("将 %c 作出栈处理\n", x);
				i++;
				break;
			case '>':
				printf("\n进行合并前进行遍历:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				Pop(&OPTR, &theta);
				if (*(OPTR.top - 1) == '(') {
					Pop(&OPTR, &x);
					exp[i] = '#';
				}
				printf("将 %c 作出栈处理\n", theta);
				Pop(&OPND, &b);
				printf("将 %c 作出栈处理\n", b);
				Pop(&OPND, &a);
				printf("将 %c 作出栈处理\n", a);
				Push(&OPND, Operate(a, theta, b));
				printf("\n进行合并后进行遍历:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				if (OPTR.base == OPTR.top) {
					exp[i] = '#';
				}
				break;
			}
		}
		GetTop(OPTR, &e);
	}
	GetTop(OPND, &e);
	printf("运算结果为%d\n", e - '0');
	return e - '0';
}

int main() {
	int a;
	char str[20] = { "3+2*5-4+7*(3+5)" };
	char str1[20] = { "5+3*6-2" };
	printf("开始进行%s的计算\n", str);
	EvaluateExpression(str);
	printf("计算完毕\n\n");
	printf("开始进行%s的计算\n", str1);
	EvaluateExpression(str1);
	printf("计算完毕\n\n");
	return 0;
}