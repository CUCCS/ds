#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10

typedef int SElemType;
typedef struct _SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
typedef enum {
	false ,
	true
}bool;

typedef enum {
	OK,
	ERROR,
	OVERFLOW
} Status;

Status InitStack (SqStack *S);
Status conversion (SqStack *, int , int);
Status Push (SqStack *S, SElemType e);
Status Pop (SqStack *S,SElemType *e);
bool IsStackEmpty (SqStack *S);

Status InitStack (SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE *
		sizeof(SElemType));
	if(!S->base) {
		return OVERFLOW;
	}

	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}//初始化栈

Status Push (SqStack *S,SElemType e) {
	if((S->top-S->base)>=S->stacksize) {
		return ERROR;
	}
	*S->top++ = e;
	return OK;
}//入栈

Status Pop (SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}

	*e = *--S->top;
	return OK;
}//出栈

bool IsStackEmpty (SqStack *S)
{
	if(S) {
		return S->base ==S->top;
	}
	return true;
}//判断栈是否为空

Status conversion (SqStack *S, int input, int d)
{
	SElemType e;
	if(d > 10) {
		return ERROR;
	}

	while (input)
	{
		Push(S,input % d);
		input = input / d;
	}
	while (!IsStackEmpty(S)) 
	{
		Pop(S,&e);
		printf("%d", e);
	}
	printf("\n\n");
	return OK;
}//数制转换的实现

int main(int argc,char* argv[])
{
	SqStack S;
	int input=1348;
	int d,i;
	srand(time(NULL));
	//随机进行五次进制转换
	for(i = 0;i < 5;i ++) {
		d = rand ()%8+2;//d的取值应为小于10大于1的整数
		input = rand()%1024;

		printf("随机十进制数为:%d\n",input);
		printf("需要转化为%d进制\n",d);
		InitStack(&S);
		printf("转化后为:");
		conversion (&S, input, d);
	}
	return 0;
}

