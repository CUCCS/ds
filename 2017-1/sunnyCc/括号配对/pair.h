#pragma once
#include <stdio.h>

typedef struct SqStack {
	int *base; //栈底  
	int *top;  //栈顶  
	int stacksize;   //栈当前的存储空间  
}SqStack;

void InitStack(SqStack *S);//初始化空栈  
int StackEmpty(SqStack S);//判空  
void push(SqStack *S, int e);//进栈  
void pop(SqStack *S, int *e);//出栈  
