#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef char SElemType;
typedef enum{
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *s);
Status Push(SqStack *s,char e);
Status Pop(SqStack *s,char *e);
bool StackEmpty(SqStack *s);
Status GetTop(SqStack s,char *e);
void Traverse(char *exp);
bool IN(char ch);
char Precede(char exist,char read);
int EvaluateExpression(char *exp);
char Operate(char a,char thete,char b);
