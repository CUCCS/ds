
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char *SElemType;
typedef double SElem;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

typedef struct _SqStack1
{
	SElem *base;
	SElem *top;
	int stacksize;
}SqStack1;

typedef enum
{
	true,
	false
}bool;


//若栈不为空，删除栈顶元素，用e做返回值；
Status Pop(SqStack*s, SElemType*e);

//判断栈是否为空；
bool StackEmpty(SqStack*s);

//创建一个空栈；
Status InitStack(SqStack*s);

//插入元素e为新的栈顶元素；
Status Push(SqStack*s, SElemType e);

//若栈不为空，用e返回栈顶元素；
Status GetTop(SqStack *s, SElemType *e);


Status Pop1(SqStack1*s, SElem*e);
bool StackEmpty1(SqStack1*s);
Status InitStack1(SqStack1*s);
Status Push1(SqStack1*s, SElem e);

//判断运算符的优先级；
int Level(char character);
bool Precede(SElemType*c, char ch);

//判断是否为运算符；
bool IN(char ch);

//将ch入数组；
Status Pass(char suffix[50], char ch);

//实现后缀式；
void transform(char suffix[100], char exp[50][50], SqStack*s);

//利用后缀式数据及数据栈和符号栈进行数据的简单+-*/运算；
void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100]);