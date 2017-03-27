//matching


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ������
#define STACKINCREMENT  10  //�洢�ռ��������

typedef enum 
{
   OK ,
   OVERFLOW,
   ERROR
} Status;

typedef struct
{
	char  *base;
	char  *top;
	char  stacksize;
} SqStack;

typedef enum
{
	false,
	true
}bool;


Status InitStack (SqStack *S)   //��������Ϊ����һ����ջ
{
    S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S->base) 
	{
		return (OVERFLOW);//����ʧ��
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push (SqStack *S,char e)  //����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if( S->top - S->base >= S->stacksize) //ջ����׷�Ӵ洢�ռ䣻
	{
		S->base = (char *) realloc (S->base,(S->stacksize + STACKINCREMENT) * sizeof(char));
	    if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
}

Status Pop (SqStack *S,char* pa)  //��ջ��Ϊ�գ�ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK ;���򷵻�ERROR;
{
	if(S->top == S->base)
		return ERROR;
	*pa =*(--S->top);
	return OK;
}

bool StackEmpty(SqStack *S)
{
	if(S->top == S->base)
		return true;
	else
		return false;
}

Status GetTop(SqStack *S,char *e)
{
	if(S->top == S->base)
		return ERROR;
	*e = *(S->top - 1);
	return OK;
}

Status matching (char *e,SqStack *S) 
{
	int state = 1;
	int i=0;
	char z;
	while ( e[i] != '\0') 
	{
        switch (e[i]) 
		{
		case '(':
		case '{':
		case '[': 
			{ 
                Push(S, e[i]);
				i++;
				break ;
            }
		case ')':
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '(')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		case '}':
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '{')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		case ']': 
			{
			    GetTop(S,&z);
                if(!StackEmpty(S) && z == '[')    
                {
                   Pop(S,&z);
                   i++;
                }
                else
                   state = 0;
                break;
			}
		}
	}
	if(StackEmpty(S) && state)//��ջ��state��Ϊ0��ȫ��ƥ��
	{
        printf("����ȫ��ƥ��\n");
	    return OK;
	}
    else
	{
         printf("���Ų�ƥ��\n");
		 return ERROR;
	}
}
			

int main()
{
	char test[]="(){}[]";
	char hhhh[]="({}{";
	SqStack S,B;
	InitStack(&S);
	InitStack(&B);
	printf("����������");
	puts(test);
	matching(test,&S);
	printf("����������");
	puts(hhhh);
	matching(hhhh,&B);
	return 0;
}