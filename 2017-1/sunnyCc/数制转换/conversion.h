#include <stdio.h>

//定义一个顺序栈的结构  
typedef struct {
	int *base;//栈底指针   
	int *top;//栈顶指针  
	int stacksize;
}SqStack;

int InitStack(SqStack *S);
int IsEmpty(SqStack *S);
int Push(SqStack *S, int e);
int Pop(SqStack *S, int *e);
void conversion(SqStack *S, int n, int m);

