#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
const char OP[7] = { '+','-','*','/','(',')','#' };
const int  PrecedenceTable[7][7] = {
	{1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1},
	{1,1,1,1,0,1,1},
	{1,1,1,1,0,1,1},
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}
};
typedef char SElemType;
typedef struct _SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef struct _COUNT {
	int *base;
	int *top;
	int stacksize;
}COUNT;
typedef enum {
	FALSE,
	OK,
	OVERFLOW,
	TRUE,
	ERROR,
}Status;
Status InitStack(SqStack *S);
Status Pop(SqStack *S, SElemType *e);
Status Push(SqStack *S, SElemType e);
Status StackEmpty(SqStack S);
Status GetTop(SqStack S, SElemType *e);
void transform(char *, char *);//中缀式转化为后缀式
int IN(char);
void Pass(char *, char);
int Precede(char, char);
int  count(char *suffix);
int operate(char, int, int);
Status nInitStack(COUNT *S);
Status nStackEmpty(COUNT S);
Status nPop(COUNT *S, int *e);
Status nPush(COUNT *S, int e);
Status nGetTop(COUNT S, int *e);