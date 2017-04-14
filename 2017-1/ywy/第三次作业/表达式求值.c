#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2
#define ok 1
#define error 0
typedef char SElemtype;
typedef int Elemtype;
typedef struct {
	SElemtype*base;
	SElemtype*top;
	int stacksize;
}SqstackOptr;//�����ջ
typedef struct {
	Elemtype*base;
	Elemtype*top;
	int stacksize;
}SqstackOpnd;//������ջ
//�����ջ
int InitstackOptr(SqstackOptr*s);//��ʼ��ջ
SElemtype GettopOptr(SqstackOptr*s);//��ȡջ��Ԫ��
int PushOptr(SqstackOptr*s, SElemtype e);//��ջ
int PopOptr(SqstackOptr*s, SElemtype *e);//ɾ��ջ��Ԫ��
int DestorystackOptr(SqstackOptr*s);//����ջ
//������ջ
int InitstackOpnd(SqstackOpnd*s);
Elemtype GettopOpnd(SqstackOpnd*s);
int PushOpnd(SqstackOpnd*s, Elemtype e);
int PopOpnd(SqstackOpnd*s, Elemtype*e);
int DestorystackOpnd(SqstackOpnd*s);
//���ʽ��ֵ
//������ʽ������
Elemtype EvaluateExpression(SqstackOptr*OPTR, SqstackOpnd*OPND);
SElemtype Precede(char topc, char c);//�ж���������ȼ�
Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b);//���㲿�ֱ��ʽ��ֵ
Elemtype In(char c, char op[]);//�ж�������ַ��ǲ��������
// ��ʼ��ջ
int InitstackOptr(SqstackOptr*s) {
	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));
	    if (!s->base) {
	    return overflow;
	}
	    s->top = s->base;
	     s->stacksize = STACK_INIT_SIZE;
	    return ok;
}
int InitstackOpnd(SqstackOpnd*s)
{
	s->base = (Elemtype*)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!s->base)
	{
		return overflow;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return ok;
}
//��ȡջ��Ԫ��
SElemtype GettopOptr(SqstackOptr*s)
{
	if(s->top==s->base)
	{
		return error;
	}
	return *(s->top - 1);
}
Elemtype GettopOpnd(SqstackOpnd*s)
{
	if(s->top==s->base)
	{
		return error;
	}
	return *(s->top - 1);
}
//��ջ
int PushOptr(SqstackOptr*s, SElemtype e)
{
	if ((s->top - s->base) >= s->stacksize)
	{
		s->base = (SElemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemtype));
	if(!s->base)
	{
		return error;
	}
	s->top = s->base + s->stacksize;
	s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return ok;
}
int PushOpnd(SqstackOpnd*s, Elemtype e)
{
	if ((s->top - s->base) >= s->stacksize)
	{
		s->base = (Elemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(Elemtype));
		if (!s->base)
		{
			return error;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top++ = e;
	return ok;
}
//ɾ��Ԫ��
int PopOptr(SqstackOptr*s, SElemtype*e)
{
	if(s->top==s->base)
	{
		return error;
	}
	*e = *--s->top;
	return ok;
}
int PopOpnd(SqstackOpnd*s, Elemtype*e)
{
	if(s->top==s->base)
	{
		return error;
	}
	*e = *--s->top;
	return ok;
}
//����ջ
int DestorystackOptr(SqstackOptr*s)
{
	s->top = s->base;
	free(s->base); 
	s->top = NULL;
	s->base = NULL;
	return ok;
}
int DestorystackOpnd(SqstackOpnd*s)
{
	s->top = s->base;
	free(s->base);
	s->top = NULL;
	s->base = NULL;
	return ok;
}
//�ж�������ַ��ǲ��������
Elemtype In(char c, char op[])
{
	int i, f = 0;
	for (i = 0; i < 7; i++)
	{
		if (c == op[i])
		{
			f = i;
			break;
		}
	}
	if (f == 0)
	{
		return 0;
	}
	else return 1;
}
//�Ƚ���������ȼ�
SElemtype Precede(char topc, char c)
{
	if (topc == '+' || topc == '-')
	{
		if (c == '+' || c == '-' || c == ')' || c == '#')
		{
			return '>';
		}
		else return '<';
	}
	if (topc == '*' || topc == '/')
	{
		if (c == '(')
		{
			return '<';
		}
		else return '>';
}
	if (topc == '(')
	{
		if (c == ')')
		{
			return '=';
		}
		else return '<';
	}
	if (topc == ')')
	{
		return ')';
	}
	if (topc == '#')
	{
		if (c == '#')
		{
			return '=';
		}
		else return '<';
	}
}
//��ֵ
Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b)
{
	switch (theta)
	{
	case '+':return a + b; break;
	case '-':return a - b; break;
	case'*':return a*b; break;
	case'/':return a / b; break;
	}
}
//�㷨
Elemtype EvaluateExpression(SqstackOptr*OPTR, SqstackOpnd*OPND)
{
	SElemtype c, theta, x;
	Elemtype a, b,v;
	SElemtype op[7] = { '+','-','*','/','(',')','#' };
	InitstackOptr(OPTR);
	InitstackOpnd(OPND);
	PushOptr(OPTR, '#');
	printf("������ʽ: ");
	c = getchar();
	while (c != '#' || GettopOptr(OPTR) != '#')
	{
		if (!In(c, op))
		{
			PushOpnd(OPND, c - '0');
			c = getchar();
		}
		else
		{
			switch (Precede(GettopOptr(OPTR), c))
			{
			case'<'://ջ��Ԫ�����ȼ���
				PushOptr(OPTR, c);
				c = getchar();
				break;
			case'>'://ջ��Ԫ�����ȼ���
				PopOptr(OPTR, &theta);
				PopOpnd(OPND, &b);
				PopOpnd(OPND, &a);
				v = Operate(a, theta, b);
				PushOpnd(OPND, v);
				break;
			case'=':
				PopOptr(OPTR, &x);
				c = getchar();
				break;
			}
		}
	}
	return GettopOpnd(OPND);
}
int main()
{
	SqstackOpnd OPND;
	SqstackOptr OPTR;
	int result;
	result = EvaluateExpression(&OPTR, &OPND);
	printf("���ʽ���Ϊ�� %d\n", result);
	system("pause");
	return 0;
}
//�㷨���ֺ�������Ƚϲ��ֲο��϶�