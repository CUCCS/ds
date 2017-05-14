
#include "3-2-2.h"

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

Status Pop(SqStack *S,int *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;
}

void Match(SqStack *S , char *p)
{
	    int i=0;
		int bracket;
		InitStack(S); 
		while(p[i] != '\0')  
		{  
			DEBUG && printf("当前括号 '%c' ", p[i]);
			switch(p[i])  
			{  
			case '(':
				DEBUG && printf(" '%c' 入栈 \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ')':  
				DEBUG && printf("  出栈  ");
                Pop(S,&bracket);
				printf("结果是  '%c' \n",bracket);
					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("匹配失败\n");
						return;
					}
				
					break;
			case '[':  
				DEBUG && printf(" '%c' 入栈 \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ']':  
				DEBUG && printf("  出栈  ");
                Pop(S,&bracket);
				printf("结果是  '%c' \n",bracket);

					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("匹配失败\n");
						return;
					}
				
					break;
			default:  
				break;  
				}   
			i++;
			}   
		StackEmpty(S);
		DEBUG && printf("匹配成功 \n\n");

}


int main()
{
	char str1[10]="([()])";  
	char str2[10]="[([][])]";
	char str3[10]="[((]])";
    SqStack S; 

	printf("开始匹配第一组 :");
	puts(str1);
    Match(&S,str1);  

	printf("开始匹配第二组 :");
	puts(str2);
    Match(&S,str2);

	printf("开始匹配第三组 :");
	puts(str3);
    Match(&S,str3);
    return 0;  
}

