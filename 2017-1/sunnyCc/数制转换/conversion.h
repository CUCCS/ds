#include <stdio.h>

//����һ��˳��ջ�Ľṹ  
typedef struct {
	int *base;//ջ��ָ��   
	int *top;//ջ��ָ��  
	int stacksize;
}SqStack;

int InitStack(SqStack *S);
int IsEmpty(SqStack *S);
int Push(SqStack *S, int e);
int Pop(SqStack *S, int *e);
void conversion(SqStack *S, int n, int m);

