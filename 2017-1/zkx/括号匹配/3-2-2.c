
#include "3-2-2.h"

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
			DEBUG && printf("��ǰ���� '%c' ", p[i]);
			switch(p[i])  
			{  
			case '(':
				DEBUG && printf(" '%c' ��ջ \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ')':  
				DEBUG && printf("  ��ջ  ");
                Pop(S,&bracket);
				printf("�����  '%c' \n",bracket);
					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("ƥ��ʧ��\n");
						return;
					}
				
					break;
			case '[':  
				DEBUG && printf(" '%c' ��ջ \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ']':  
				DEBUG && printf("  ��ջ  ");
                Pop(S,&bracket);
				printf("�����  '%c' \n",bracket);

					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("ƥ��ʧ��\n");
						return;
					}
				
					break;
			default:  
				break;  
				}   
			i++;
			}   
		StackEmpty(S);
		DEBUG && printf("ƥ��ɹ� \n\n");

}


int main()
{
	char str1[10]="([()])";  
	char str2[10]="[([][])]";
	char str3[10]="[((]])";
    SqStack S; 

	printf("��ʼƥ���һ�� :");
	puts(str1);
    Match(&S,str1);  

	printf("��ʼƥ��ڶ��� :");
	puts(str2);
    Match(&S,str2);

	printf("��ʼƥ������� :");
	puts(str3);
    Match(&S,str3);
    return 0;  
}

