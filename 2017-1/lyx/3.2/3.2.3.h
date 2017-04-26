#include<stdio.h>
#include<stdlib.h>
#include<time.h>//生成随机数

#define STACK_INIT_SIZE 100//定义宏常量

typedef char SElemType;//定义SElemType为字符串

typedef enum//枚举类型
{
	OK,
	ERROR,
	OVERFLOW
}Status;
typedef struct _SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;//构造结构体
typedef enum
{
	true,
	false
}bool;//构造bool

Status InitStack(SqStack *s);//构造一个空栈
bool StackEmpty(SqStack *s);//若栈s为空栈，则返回TRUE，否则返回FALSE
Status Pop(SqStack *s,SElemType *e);//若栈不空，则删除s的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status GetTop(SqStack *s,SElemType *e);//若栈不空，则用e返回s的栈顶元素，并返回OK；否则返回ERROR
Status Push(SqStack *s,SElemType e);//插入元素e为新的栈顶元素
Status ClearStack(SqStack *s);//把S置为空栈
Status DistoryStack(SqStack *s);//销毁栈s，s不再存在
Status LineEdit(SqStack *s,char *a);//文本编辑器函数