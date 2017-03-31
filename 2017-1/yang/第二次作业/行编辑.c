
#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCRESE 10
typedef char SElemType;
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;
}Sqstack;
typedef enum
{
	error, ok
}Status;
//创建栈
Status Initstack(Sqstack*S)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
	{
		return error;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return ok;
}
//判断栈是否为空
Status StackEmpty(Sqstack *S)
{
	if (S->top == S->base)
	{
		return ok;
	}
	else return error;
}
//插入栈顶元素
Status Push(Sqstack*S, SElemType e)
{
	if (S->top - S->base == S->stacksize)
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCRESE) * sizeof(SElemType));
		S->top = S->base + S->stacksize;
		S->base = S->base + STACKINCRESE;
	}
	*S->top++ = e;
	return ok;
}
//出栈
Status Pop(Sqstack *S, SElemType*e)
{
	if (S->top == S->base)
	{
		return error;
	}
	*e = *--S->top;
	return ok;
}
// 栈清空
Status ClearStack(Sqstack*S)
{
	S->top = S->base;
	return ok;
}
//销毁栈
Status DestroyStack(Sqstack*S)
{
	S->top = S->base;
	free(S->base);
	return ok;
}
void LineEdit(Sqstack *S)
{
	int i = 0;

	SElemType  *c = (SElemType*)malloc(sizeof(SElemType));
	SElemType ch;
	SElemType *p = (SElemType*)malloc(sizeof(SElemType));
	ch = getchar();
	while (ch != EOF)
	{
		while (ch != '\n')
		{
			switch (ch)
			{
			case '#': Pop(S, c); break;//退栈
			case '@':ClearStack(S); break;//清空栈
			default:Push(S, ch);//有效字符进栈
			}
			ch = getchar();
		}
		p = S->base;
		while(p!=S->top)
		{
			printf("%c", *p);
			p++;
		}
		ClearStack(S);
		if (ch != EOF)
		{
			ch = getchar();
		}

	}
	DestroyStack(S);
}
int main()
{
	printf("#删去前一个字符\n@删去前一行字符\n");
	Sqstack S;
	Initstack(&S);
	LineEdit(&S);
}