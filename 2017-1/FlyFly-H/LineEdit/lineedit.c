//lineedit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Status ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

Status DestroyStack(SqStack *S)
{
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	S->stacksize = 0;
	return OK;
}

Status LineEdit (SqStack *S)
{
	char ch,c;
	char *p;
	ch = getchar();
	while (ch != EOF)
	{
		while (ch != '\n')
		{
			switch (ch)
			{
			    case '#':
			    {
				   Pop(S,&c);
				   break;
			    }
			    case '@':
			    {   
				   ClearStack(S);
				   break;
			     }
			     default:
			    {
				   Push(S,ch);
				   break;
			     }
			}
			ch = getchar();
		}
		p = S->base;
          while(p <= S->top) 
		  {
              printf("%c",*p);
              ++p;
          }
          ClearStack(S);
          if(ch!=EOF) 
			  ch = getchar();
      }
	return OK;
  }



int main()
{
	SqStack S;
	InitStack(&S);
	LineEdit(&S);//�������б༭
    DestroyStack(&S);//��ջ����
}
