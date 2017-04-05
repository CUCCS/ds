#pragma once
#define TRUE 1  
#define FALSE 0  
#define Stack_Size 50  

typedef struct
{
	char elem[Stack_Size];
	int top;
}SeqStack;     /*运算符栈的定义*/

typedef struct
{
	int elem[Stack_Size];
	int top;
}nSeqStack;   /* 运算数栈的定义*/

void InitStack(SeqStack *S);  /*初始化运算符栈*/
void InitStackn(nSeqStack *S); /*初始化运算数栈*/
int IsEmpty(SeqStack *S); /*判断栈S为空栈时返回值为真，反之为假*/
int IsEmptyn(nSeqStack *S); /*判断栈S为空栈时返回值为真，反之为假*/
int IsFull(SeqStack *S); /*判断栈S为满栈时返回值为真，反之为假*/
int IsFulln(nSeqStack *S);   /*判断栈S为满栈时返回值为真，反之为假*/
int Push(SeqStack *S, char x);   /*运算符栈入栈函数*/
int Pushn(nSeqStack *S, int x); /*运算数栈入栈函数*/
int Pop(SeqStack *S, char *x);  /*运算符栈出栈函数*/
int Popn(nSeqStack *S, int *x);  /*运算数栈出栈函数*/
char GetTop(SeqStack *S);  /*运算符栈取栈顶元素函数*/
int GetTopn(nSeqStack *S);  /*运算数栈取栈顶元素函数*/
int Isoperator(char ch);   /*判断输入字符是否为运算符函数,是返回TRUE,不是返回FALSE*/
char Compare(char ch1, char ch2);  /*比较运算符优先级函数*/
int Execute(int a, char op, int b);  /*运算函数*/
int ExpEvaluation(); /*读入一个简单算术表达式并计算其值。optr和operand分别为运算符栈和运算数栈，OPS为运算符集合*/
