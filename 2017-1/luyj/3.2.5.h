#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100

typedef char SElemType;
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

Status Pop(SqStack*s, SElemType*e);
bool StackEmpty(SqStack*s);
Status InitStack(SqStack*s);
Status Push(SqStack*s, SElemType e);
Status GetTop(SqStack *s, SElemType *e);


Status Pop1(SqStack1*s, SElem*e);
bool StackEmpty1(SqStack1*s);
Status InitStack1(SqStack1*s);
Status Push1(SqStack1*s, SElem e);


int Level(char character);
bool IN(char ch);
Status Pass(char suffix[50], char ch);
bool Precede(SElemType*c, char ch);

void transform(char suffix[100], char exp[100], SqStack*s);

void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100]);
