#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量

typedef int SElemType;
//对顺序栈进行定义
typedef struct Sq_Stack
{
    SElemType *base;
    SElemType *top;
    int stacksize;

}SqStack;
typedef enum
{      OK,
    ERROR,
    OVERFLOW,

}Status;


//Status InitStack(SqStack*S);//构造一个空栈
////void DestroyStack(SqStack*S);//销毁已经存在的栈
//Status Push(SqStack*S,SElemType e);//把一个新的元素添加到栈中
//Status Pop(SqStack*S,SElemType *e);//删除栈顶的元素,并用e返回其值
//bool StackEmpty(SqStack*S);//判断一个栈是否为空
////Status GetTop(SqStack S);
//void Conversion(SqStack*S,SElemType input,SElemType mod);


//构造一个空栈S
Status  InitStack (SqStack* pS)    //构造一个空栈
{
	pS->base=(SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));

	if(! pS->base) 
	{
		return OVERFLOW;
	}

	pS->top =(*pS).base;
	pS->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;

}
int StackEmpty(SqStack *S)
{
	if (S)
		return S->base==S->top;
	return 1;
}

Status Pop(SqStack *S,SElemType *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;

}

void conversion (SqStack *S,int n,int d) 
{
	SElemType e;
	while (n) 
	{
		Push(S, n % d);
		n = n / d;
	}
	while (!StackEmpty(S)) 
	{
		Pop(S, &e);
		printf ( "%d", e );
	}

	printf("\n");
} // conversion
int main()
{
	int n;
	int d;
	SqStack S;
	srand(time(0));

	n=rand()%1024;
	printf("待转换数据 ：%d\n",n);
	d=rand()%10+1;
	printf("转换进制 ：%d\n",d);
	
	InitStack(&S);
	conversion(&S,n,d);
	return 0;
}