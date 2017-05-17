#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef int SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
enum bool{ false, true };
typedef struct _SqStack{
	SElemType   *base;
	//造之前和销毁之后，base的值为NULL
	SElemType *top; //栈顶指针
	int stracksize;
}SqStack;
Status InitStack(SqStack *S){
	//构建一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e){
	//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stracksize){//栈满，追加存储空间
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//存储分配失败
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//为空
	else
		return false;//不为空
}
void conversation(SqStack *S, int input, int d){
	SElemType e;
	InitStack(S);
	while (input)
	{
		Push(S, input%d);
		input = input / d;
	}
	while (!StackEmpty(S)){
		Pop(S, &e);
		printf("%d", e);
	}
}
void DestroyStack(SqStack *stack)//销毁已经存在的栈3
{
   free(stack->base);
    stack->top=stack->base;
}
int main(int argc, char *argv[])
{
	SqStack S;
	InitStack(&S);
	srand((unsigned)time(NULL));
	int input, num;
	input = rand();
	printf("需要转换的数字为：\n%d\n", input);
	num = rand() % 11;
	printf("转化为%d进制为：\n", num);
	conversation(&S, input, num);
}

