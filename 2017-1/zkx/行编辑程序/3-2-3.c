#include "3-2-3.h"

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

Status Pop(SqStack *S, SElemType *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;
}

Status ClearStack(SqStack *S)  
{  
	
	if(S->top == S->base)   
		return ERROR;  
	S->top = S->base;  
	return OK;  
} 
void LineEdit(SqStack *S)
{
	
	char ch,c;
	char *p;
	ch = getchar();
	while (ch != EOF) //EOF为全文结束符
	{ 
		while (ch != '\n')
		{
			switch (ch) 
			{
			case '#' : 
				Pop(S, &c); 
				break;
			case '@': 
				ClearStack(S); 
				break;// 重置S为空栈
			default : 
				Push(S, ch);  
				break;  
			}
			ch = getchar();  // 从终端接收下一个字符
		}
		// 将从栈底到栈顶的字符传送至调用过程的数据区；
		p = S->base;
		while(p<=S->top)
		{
			printf("%c",*p);
			++p;
		}
		ClearStack(S);      // 重置S为空栈
		if (ch != EOF)  
			ch = getchar();
	}
	
}
int main()
{
	SqStack S;
	char *str1=" whli##ilr#e（s#*s)";
	printf("输入为：");
	puts(str1);
	InitStack(&S);
	printf("输出为：");
	LineEdit(&S);
	
return 0;
}
