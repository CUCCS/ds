#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <time.h>

#define STACK_INIT_SIZE 100  //存储空间初始分配
#define STACKINCREMENT  10  //存储空间分配增量

#define OVERFLOW -2

typedef struct{
	int *base;   //在栈构造之前和销毁之后base的值为NULL
	int *top;      //栈顶指针
	int sackbase;   //当前已分配的存储空间，以元素为单位
}SqStack;


//构造一个空栈
int InitStack(SqStack *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));   //分配基本空间
	if(!S->base)
	{
		return(OVERFLOW);  
	}//判断是否分配成功
	S->top = S->base;              //指向栈顶
	S->sackbase = STACK_INIT_SIZE;         //初始链表最大长度
	return 0;
}



//若S为空栈返回OK 否则返回ERROR
int StackEmpty(SqStack *S)
{
	if(S->top == S->base)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//插入新的栈顶数据
int Push(SqStack *S,int e)
{
	if(S->top - S->base >= S->sackbase)//空间不足
	{
		S->base = (int*)realloc(S->base,(S->sackbase+STACKINCREMENT)*sizeof(int));
		if(!S->base)
		{
			return(OVERFLOW);
		}
		S->top = S->base + S->sackbase;
		S->sackbase += STACKINCREMENT;
	}
	*S->top ++= e;
	return 0;
}



//若栈不空 则删除栈顶数据并用e返回且返回OK 否则返回ERROR
int Pop(SqStack *S,int *e)
{
	if(S->top == S->base)
	{
		return 1;
	}
	*e=*--S->top;//删除S的栈顶元素，弹出原顶部，再把指针指向e 
	{
		return 0;
	}
}


void convertion(SqStack *S,int d,int N)
{
	//N为待转换的数,d为需转换成的数制
	InitStack(S);

	while(N)
	{
		Push(S,N%d);
		N = N/d;
	}
	while(!StackEmpty(S))
	{
		int e;
		Pop(S,&e);
		printf("%d",e);
	}
}


void main()
{
	int N;int d;
	SqStack S;
	InitStack(&S);
	srand((unsigned)time(NULL));
	printf("要转换的数：\n");
	N = rand()%1024;
	printf("%d\n",N);
	printf("输入要转换成的数制：\n");
	scanf_s("%d",&d);
	printf("转换数字后的数为:\n");
	convertion(&S,d,N);
	printf("\n");

}

