#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define STACK_INIT_SIZE 100    //存储空间初始分配量
#define STACK_SIZE 100            //存储空间分配增量
#define STACKINCREMENT 10         //存储空间分配增量

typedef char SElemType ;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //枚举定义（返回状态）

typedef enum{
	False,
	True
}Bool;                            //定义布尔类型

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;                          //顺序栈的定义

Status InitStack(SqStack *S);
Status DestroyStack (SqStack *S);
Status Pop(SqStack *S,SElemType *e);
Bool IsStackEmpty(SqStack *S);
Status ClearStack(SqStack *S);
Status Push(SqStack *S,SElemType e);
SElemType GetTop(SqStack *S,SElemType *e);
void LineEdit(SqStack *S);


Status InitStack(SqStack *S)       //构造顺序栈
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
		return  OVERFLOW; 
	}//存储分配失败
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


Status DestroyStack (SqStack *S)//销毁栈s，s不存在
{
	S->top = S->base;
	free(S->base);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK; 
}

Status Pop(SqStack *S,SElemType *e)//若栈不为空，则删除s的栈顶元素，用e返回值，并返回OK，否则返回ERROR；
{
	if(IsStackEmpty(S))
	{
		return OK;
	}
	*e = *--S->top;
	return ERROR;
}

Bool IsStackEmpty(SqStack *S)//判断栈顶是否为空；
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status ClearStack(SqStack *S)//清空栈
{ 
		SElemType *e=(SElemType*)malloc(sizeof(SElemType));
	if (IsStackEmpty(S))
		return OK;
	else
	{
		while (*--S->top != ' ')
			Pop(S, e);
		return ERROR;
	}
} 

Status Push(SqStack *S,SElemType e)//插入元素为e的新的栈顶元素
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

SElemType GetTop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

void LineEdit(SqStack *S)
{
	SElemType  *c = (SElemType*)malloc(sizeof(SElemType));
	char ch;
	//利用字符栈S，从终端接收一行并传送至调用过程得数据区
	InitStack(S);
	ch = getchar();//接收第一个字母
	while(ch != EOF)
	{
		while(ch != EOF && ch != '\n')
		{
			switch(ch)
			{
			case '#':
				Pop(S,c);    
				break;//仅当栈非空时退栈
			case '@':
				ClearStack(S);   
				break;//重置S为空栈
			default:
				Push(S,ch);      
				break;//有效字符进栈，未考虑栈满情形
			}
			ch = getchar();   //从终端接收下一个字符
		}
			while(!IsStackEmpty(S))
		{
			Pop(S,c);
			printf("%c",*c);
		}
		ClearStack(S);
		if ( ch != EOF)
			ch = getchar();
	}
	DestroyStack(S);
}

int main()
{
	SqStack S;
	InitStack(&S);
	printf("输出:\n");
	LineEdit(&S);           //行编辑
	DestroyStack(&S);      //销毁栈
	return 0;
}