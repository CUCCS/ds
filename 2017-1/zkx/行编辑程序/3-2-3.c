#include "3-2-3.h"

Status  InitStack (SqStack* pS)    //����һ����ջ
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
	while (ch != EOF) //EOFΪȫ�Ľ�����
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
				break;// ����SΪ��ջ
			default : 
				Push(S, ch);  
				break;  
			}
			ch = getchar();  // ���ն˽�����һ���ַ�
		}
		// ����ջ�׵�ջ�����ַ����������ù��̵���������
		p = S->base;
		while(p<=S->top)
		{
			printf("%c",*p);
			++p;
		}
		ClearStack(S);      // ����SΪ��ջ
		if (ch != EOF)  
			ch = getchar();
	}
	
}
int main()
{
	SqStack S;
	char *str1=" whli##ilr#e��s#*s)";
	printf("����Ϊ��");
	puts(str1);
	InitStack(&S);
	printf("���Ϊ��");
	LineEdit(&S);
	
return 0;
}
