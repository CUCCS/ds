#include "evaluation.h"
#include <string.h>  
#include <stdlib.h>  
#include <math.h>  
#include <conio.h>  

char ops[7] = { '+','-','*','/','(',')','#' };  /*���������*/

int  cmp[7][7] = { { 2,2,1,1,1,2,2 },    /*�������бȽ���������ȼ��ľ���,3����'=',2����'>',1����'<',0�����ɱ�*/
{ 2,2,1,1,1,2,2 },
{ 2,2,2,2,1,2,2 },
{ 2,2,2,2,1,2,2 },
{ 1,1,1,1,1,3,0 },
{ 2,2,2,2,0,2,2 },
{ 1,1,1,1,1,0,3 } };
void InitStack(SeqStack *S)   /*��ʼ�������ջ*/
{
	S->top = -1;
}

void InitStackn(nSeqStack *S)   /*��ʼ��������ջ*/
{
	S->top = -1;
}

int IsEmpty(SeqStack *S)    /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

int IsEmptyn(nSeqStack *S)    /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == -1 ? TRUE : FALSE);
}

/*��ջ��*/
int IsFull(SeqStack *S)     /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}

int IsFulln(nSeqStack *S)       /*�ж�ջSΪ��ջʱ����ֵΪ�棬��֮Ϊ��*/
{
	return(S->top == Stack_Size - 1 ? TRUE : FALSE);
}

int Push(SeqStack *S, char x)   /*�����ջ��ջ����*/
{
	if (S->top == Stack_Size - 1)
	{
		printf("Stack is full!\n");
		return FALSE;
	}
	else
	{
		S->top++;
		S->elem[S->top] = x;
		return TRUE;
	}
}

int Pushn(nSeqStack *S, int x)   /*������ջ��ջ����*/
{
	if (S->top == Stack_Size - 1)
	{
		printf("Stack is full!\n");
		return FALSE;
	}
	else
	{
		S->top++;
		S->elem[S->top] = x;
		return TRUE;
	}
}

int Pop(SeqStack *S, char *x)    /*�����ջ��ջ����*/
{
	if (S->top == -1)
	{
		printf("�����ջ��!\n");
		return FALSE;
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return TRUE;
	}
}

int Popn(nSeqStack *S, int *x)    /*������ջ��ջ����*/
{
	if (S->top == -1)
	{
		printf("�����ջ��!\n");
		return FALSE;
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return TRUE;
	}
}

char GetTop(SeqStack *S)    /*�����ջȡջ��Ԫ�غ���*/
{
	if (S->top == -1)
	{
		printf("�����ջΪ��!\n");
		return FALSE;
	}
	else
	{
		return (S->elem[S->top]);
	}
}

int GetTopn(nSeqStack *S)    /*������ջȡջ��Ԫ�غ���*/
{
	if (S->top == -1)
	{
		printf("�����ջΪ��!\n");
		return FALSE;
	}
	else
	{
		return (S->elem[S->top]);
	}
}


int Isoperator(char ch)        /*�ж������ַ��Ƿ�Ϊ���������,�Ƿ���TRUE,���Ƿ���FALSE*/
{
	int i;
	for (i = 0; i<7; i++)
	{
		if (ch == ops[i])
			return TRUE;
	}
	return FALSE;
}

/*
int isvariable(char ch)
{ if (ch>='a'&&ch<='z')
return true;
else
return false;
}*/


char Compare(char ch1, char ch2)   /*�Ƚ���������ȼ�����*/
{
	int i, m, n;
	char pri;                     /*�������ȼ��ȽϺ�Ľ��'>'��'<'��'='*/
	int priority;                 /*���ȼ��ȽϾ����еĽ��*/
	for (i = 0; i<7; i++)              /*�ҵ���Ƚϵ�����������ڱȽϾ���������λ��*/
	{
		if (ch1 == ops[i])
			m = i;
		if (ch2 == ops[i])
			n = i;
	}

	priority = cmp[m][n];
	switch (priority)
	{
	case 1:
		pri = '<';
		break;
	case 2:
		pri = '>';
		break;
	case 3:
		pri = '=';
		break;
	case 0:
		pri = '$';
		printf("���ʽ����!\n");
		break;
	}
	return pri;
}

int Execute(int a, char op, int b)    /*���㺯��*/
{
	int result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}

int ExpEvaluation()
/*����һ�����������ʽ��������ֵ��optr��operand�ֱ�Ϊ�����ջ��������ջ��OPSΪ���������*/
{
	int a, b, v, temp;
	char ch, op;
	char *str;
	int i = 0;

	SeqStack optr;                                   /*�����ջ*/
	nSeqStack operand;                               /*������ջ*/

	InitStack(&optr);
	InitStackn(&operand);
	Push(&optr, '#');
	printf("��������ʽ(��#����):\n");            /*���ʽ����*/
	str = (char *)malloc(50 * sizeof(char));
	gets(str);                                     /*ȡ��һ�б��ʽ���ַ�����*/

	ch = str[i];
	i++;
	while (ch != '#' || GetTop(&optr) != '#')
	{
		if (!Isoperator(ch))
		{
			temp = ch - '0';    /*���ַ�ת��Ϊʮ������*/
			ch = str[i];
			i++;
			while (!Isoperator(ch))
			{
				temp = temp * 10 + ch - '0'; /*����������������ĸ�λת��Ϊʮ������*/
				ch = str[i];
				i++;
			}
			Pushn(&operand, temp);
		}
		else
		{
			switch (Compare(GetTop(&optr), ch))
			{
			case '<':
				Push(&optr, ch);
				ch = str[i];
				i++;
				break;
			case '=':
				Pop(&optr, &op);
				ch = str[i];
				i++;
				break;
			case '>':
				Pop(&optr, &op);
				Popn(&operand, &b);
				Popn(&operand, &a);
				v = Execute(a, op, b);  /* ��a��b����op���� */
				Pushn(&operand, v);
				break;
			}
		}
	}
	v = GetTopn(&operand);
	return v;
}