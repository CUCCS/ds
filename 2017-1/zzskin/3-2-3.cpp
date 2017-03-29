#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INIT_SIZE 100   
#define STACKINCREMENT 10 

typedef char SElemType; 

typedef enum{
	False,
	True
}Bool;                            //定义布尔类型

typedef enum{ 
	ERROR, 
	OK, 
	OVERFLOW 
}Status;  //枚举定义（返回状态）

typedef struct { 
	SElemType *base; 
	SElemType *top; 
	int stacksize; 
}SqStack;      //顺序栈的定义

Status InitStack(SqStack *S)      //构造顺序栈
{ 
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType)); 
	if(!S->base) 
	{ 
		return OVERFLOW; 
	} //存储分配失败
	S->top = S->base; 
	S->stacksize = STACK_INIT_SIZE; 
    return OK; 
}

Bool IsStackEmpty(SqStack *S)//判断栈顶是否为空；
{
	if(S->top == S->base)
		return True;
	else
		return False;
}

Status Push(SqStack *S,SElemType e) //插入元素为e的新的栈顶元素
{ 
	if((S->top - S->base) >= S->stacksize) 
	{ 
		S->base = (SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType)); 
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

Status Pop(SqStack *S,SElemType *e)//若栈不为空，则删除s的栈顶元素，用e返回值，并返回OK，否则返回ERROR；
{ 
	if(IsStackEmpty(S))  
		return ERROR; 
	*e = *--S->top; 
	return OK; 
}

Status ClearStack(SqStack *S) //清空栈
{ 
	S->top = S->base; 
	return OK; 
} 

Status DestroyStack(SqStack *S) //销毁栈s，s不存在
{ 
	S->top = S->base; 
	free(S->base); 
	S->top = NULL; 
	S->base = NULL; 
	S->stacksize = 0;
	return OK; 
}

void LineEdit(SqStack *S) 
{ 
	//利用字符栈s，从终端接收一行并传送至调用过程的数据区 
	char ch,c;
	SElemType *b; 
	InitStack(S); 
	ch = getchar(); //接收第一个字母
	while( ch != EOF) 
	{ 
		while(ch != EOF&&ch!='\n') 
		{ 
			switch(ch) 
			{ 
			case '#':Pop(S,&c); 
				break; //仅当栈非空时退栈
			case '@':ClearStack(S); 
				break; //重置S为空栈
			default :  
				Push(S, ch); //有效字符进栈，未考虑栈满情形
			} 
			ch = getchar(); //从终端接收下一个字符
		} 
		b = S->base; 
		while(b != S->top) 
		{ 
			printf("%c",*b); 
			b++; 
		} 
		ClearStack(S); 
		if( ch!=EOF) 
			ch = getchar(); 
	} 
	DestroyStack(S); 
} 
int main() 
{ 
	SqStack S; 
	printf("输出:\n"); 
	LineEdit(&S); 
	DestroyStack(&S); 
	return 0; 
} 