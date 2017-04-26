#pragma once
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
#define STACKINCREMENT 10
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
Status InitStackn(COUNT *S);

Status Pop(SqStack *S, SElemType *e);
Status Popn(COUNT *S, int *e);

Status Push(SqStack *S, SElemType e);
Status Pushn(COUNT *S, int e);

Status StackEmpty(SqStack S);
Status StackEmptyn(COUNT S);

Status GetTop(SqStack S, SElemType *e);
Status GetTopn(COUNT S, int *e);

void transform(char *, char *);
int IN(char);
void Pass(char *, char);
int Precede(char c, char ch);
int  count(char *suffix);
int operate(char, int, int);
