#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>   //malloc,realloc  
#include <math.h>     //����overflow  
#include <process.h>  //exit()  

#define S_SIZE 100   //ջ�Ŀռ��С  
#define STACKINCREAMENT 10//���ӿռ�  A

//��ʼ����ջ
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(S_SIZE * sizeof(int));
	S->stacksize = S_SIZE;
	S->top = S->base;
};
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)
{
	if (S.base == S.top)
	{
		return 1;
	}

	else
		return 0;
};

//��ջ
void push(SqStack *S, int e)
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (int *)realloc(S->base, (S->stacksize + STACKINCREAMENT) * sizeof(int));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREAMENT;
	}
	*(S->top) = e;
	S->top++;
};

//��ջ
void pop(SqStack *S, int *e)
{
	if (S->base != S->top)
	{
		S->top--;
		*e = *S->top;
	}
};
//����ջ
int DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	printf("�ͷ�ջ�ռ�\n");
	return 1;
}
void pair(SqStack s, char *p)
{
	int e;
	while (*p)
	{
		switch (*p)
		{
			//sֻҪ�������ž���ջ  		
		case '{':	case '[':case '(':
		{
			push(&s, *p++);
			break;
		}

		//sֻҪ�������ž���ջ�е�������e���	
		case '}':case ']':case ')':
		{
			pop(&s, &e);
			if ((e == '{' && *p == '}') || (e == '[' && *p == ']') || (e == '(' && *p == ')'))
			{
				p++;
			}
			else
			{
				printf("���Ų�ƥ��!\n");
				return OVERFLOW;//����OVERFLOW��ֵ����������
			}
			break;
		}

		default:
		{
			p++;
		}//�����ַ��ͺ���  
		}//end switch

	}//end while

	if (StackEmpty(s))
	{
		printf("����ƥ��ɹ�");
	}//����ջ��ɺ���ջ�Ƿ�Ϊ��,��Ϊ��������������Ŷ�ƥ��ɹ�
	else
	{
		printf("ȱ�������ţ�");
	}//����ջ����ʣ��������ţ���Բ��ɹ�
	printf("\n");
};
