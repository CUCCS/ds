#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef  char  SElemType;

typedef enum _bool 
{ 
	false,
	true 
}bool;

typedef enum  
{
	ERROR,
	OVERFLOW,
	OK
} Status;

typedef struct Stack
{
	SElemType *base;   //Õ»µ×Ö¸Õë
	SElemType *top;     //Õ»¶¥Ö¸Õë
	int stacksize; 
} SqStack;


Status  InitStack (SqStack* pS);

Status Push (SqStack *S , SElemType e);

Status GetTop(SqStack *S , SElemType *e);

int StackEmpty (SqStack *S);

Status Pop (SqStack *S , SElemType *e);

bool In(char c);

SElemType Precede(SElemType c1, SElemType c2);

void transform(char *suffix, char *exp);

Status Pass(char *suffix, char ch);

SElemType Operate(SElemType a, SElemType ch, SElemType b);

int EvaluateExpression(char *suffix);

void Traverse(char *suffix);

