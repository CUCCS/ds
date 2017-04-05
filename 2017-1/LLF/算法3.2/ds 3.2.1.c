//ds 3.2.cpp
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef int SElemType;

typedef struct {
	SElemType *base;//在构造前和销毁后，base的值为NULL
	SElemType *top;//栈顶指针
	int stacksize;//当前已分配的空间，以元素为单位
}SqStack;//定义栈

typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;//定义返回值的枚举类型

typedef enum {
	false,
	true
} bool;//定义返回值

	   //栈的基本操作函数声明

Status InitStack(SqStack *S);
//构造一个空栈S

Status DestroyStack(SqStack *S);
//销毁S

Status ClearStack(SqStack *S);
//把S置为空栈

bool StackEmpty(SqStack *S);
//若S为空栈则返回TRUE,否则返回FALSE

int StackLength(SqStack *S);
//返回S的元素个数，即栈的长度

Status GetTop(SqStack *S, SElemType e);
//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR

Status Push(SqStack *S, SElemType e);
//插入元素e为新的栈顶元素

Status Pop(SqStack *S, SElemType *e);
//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR

Status StackTraverse(SqStack *S, Status(*visit)(SElemType));
//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败,则操作失败

Status visit(SElemType e);
//打印栈中元素

Status conversion(SqStack *S, int input, int d);
//实现数制转换




//栈的基本操作函数定义

Status InitStack(SqStack *S)//构造一个空栈S
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base) {
		return(OVERFLOW);//存储分配失败
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;

}//InitStack

Status DestroyStack(SqStack *S)//销毁S
{
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
}


Status ClearStack(SqStack *S)//把S置为空栈
{
	S->top = NULL;
	return OK;
}

bool StackEmpty(SqStack *S)//若S为空栈则返回TRUE,否则返回FALSE
{
	if (S->base==S->top)
		return true;
	else
		return false;
}

int StackLength(SqStack *S)//返回S的元素个数，即栈的长度
{
	return *S->top + 1;
}

Status GetTop(SqStack *S, SElemType e)//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
{
	if (S->top == S->base)return ERROR;
	e = *(S->top - 1);
	return OK;
}//GetTop

Status Push(SqStack *S, SElemType e)//插入元素e为新的栈顶元素
{
	if (S->top - S->base >= S->stacksize) {//栈满，追加存储空间
											//暂时不用
											//S->base=(SElemaType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
											//if(!S->base){
		return(OVERFLOW);//存储分配失败
						 //}
						 //S->top=S->base+S->stacksize;
						 //S->stacksize+=STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push

Status Pop(SqStack *S, SElemType *e)//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
	if (StackEmpty(S))return ERROR;
	*e = *--S->top;
	return OK;
}//Pop

 

Status StackTraverse(SqStack *S, Status(*visit)(SElemType))//从栈底到栈顶依次对栈中每个元素调用函数visit()。一旦visit()失败,则操作失败
{
	while (S->top > S->base)
		visit(*S->base++);
	printf("\n");
	return OK;
}//StackTraverse

Status visit(SElemType e) //打印栈中元素
{
	printf("%d ", e);
	return OK;
}  //visit

Status conversion(SqStack *S, int input, int d)//实现数制转换
{
	int output;
	InitStack(S);
	while (input) {
		Push(S, input%d);
		input = input / d;
	}
	while (!StackEmpty(S))
	{
		Pop(S, &output);
		printf("%d", output);
	}

	return OK;

}//conversion


int main(int argc, char* argv[])
{
	SqStack S;
	int input;
	int d;

	srand((unsigned)time(NULL));//用时间做种
	input = (int)rand() % 5000;//随机生成测试数据
	d = (int)rand() % 9;//随机生成转换数制
	printf("%d\n%d\n", input, d);

	conversion(&S, input, d);

	return 0;
}