#include <stdio.h>
typedef char SElemType;

//栈结构体
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack *S);//初始化栈
int Push(SqStack *S, SElemType e);//入栈
int Pop(SqStack *S, SElemType *e);//删除栈中的元素
int DestoryStack(SqStack *S);//销毁栈
void LineEdit(SqStack *S);//行编辑程序
int ClearStack(SqStack *S);//清空栈中的元素