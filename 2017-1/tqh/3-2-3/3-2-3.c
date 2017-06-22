#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10

typedef char SElemType;
typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
//定义stack结构体类型

Status InitStack(SqStack *S);
Status Push(SqStack *S,SElemType e);
Status Pop(SqStack *S,SElemType *e);
Status ClearStack(SqStack *S);
Status DestroyStack(SqStack *S) ;
void LineEdit(SqStack *S);

Status InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base) {
		return OVERFLOW;
	}

	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}//初始化栈
Status Push(SqStack *S,SElemType e) {
	if((S->top-S->base)>=S->stacksize) {
		S->base = (SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base) {
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//入栈
Status Pop(SqStack *S,SElemType *e) {
	if(S->top  == S->base) 
		return ERROR;
	*e = *--S->top;
	return OK;
}//出栈
Status ClearStack(SqStack *S) {
	S->top = S->base;
	return OK;
}
//清空栈
Status DestroyStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}//销毁栈
void LineEdit(SqStack *S)
{
	//利用字符栈s，从终端接收一行并传送至调用过程的数据区
	char ch,c,*b;
	InitStack(S);
	ch = getchar();
	while( ch != EOF)
	{
		while(ch != EOF&&ch!='\n')
		{
			switch(ch)
			{
			case '#':Pop(S,&c);
				break;
			case '@':ClearStack(S);
				break;
			default : 
				Push(S, ch);
			}
			ch = getchar();
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
	SqStack s;
	printf("input:\n");
	LineEdit(&s);
	DestroyStack(&s);
	return 0;
}
