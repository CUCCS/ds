#pragma once
#include <stdio.h>

typedef struct SqStack {
	int *base; //ջ��  
	int *top;  //ջ��  
	int stacksize;   //ջ��ǰ�Ĵ洢�ռ�  
}SqStack;

void InitStack(SqStack *S);//��ʼ����ջ  
int StackEmpty(SqStack S);//�п�  
void push(SqStack *S, int e);//��ջ  
void pop(SqStack *S, int *e);//��ջ  
