#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2
#define ok 1
#define error 0
typedef int Status;
typedef char SElemtype;
typedef int Elemtype;
typedef struct {

	SElemtype*base;

	SElemtype*top;

	int stacksize;

}OPTR;//�����ջ

typedef struct {

	Elemtype*base;

	Elemtype*top;

	int stacksize;

}OPND;//������ջ

//�����ջ
//Status Initstack(OPTR*s);//��ʼ��ջ
//
//Status Gettop(OPTR*s);//��ȡջ��Ԫ��
//
//Status Push(OPTR*s, SElemtype e);//��ջ
//
//Status Pop(OPTR*s, SElemtype *e);//ɾ��ջ��Ԫ��
//
//Status Destorystack(OPTR*s);//����ջ
//
////������ջ
//Status Initstack(OPND*s);//��ʼ��ջ
//
//Status Gettop(OPND*s);//��ȡջ��Ԫ��
//
//Status Push(OPND*s, SElemtype e);//��ջ
//
//Status Pop(OPND*s, SElemtype *e);//ɾ��ջ��Ԫ��
//
//Status Destorystack(OPND*s);//����ջ
//
//
////���ʽ��ֵ
//
////������ʽ������
//
//Elemtype EvaluateExpression(OPTR*OPTR, OPND*OPND);
//
//SElemtype Precede(char topc, char c);//�ж���������ȼ�
//
//Elemtype Operate(Elemtype a, SElemtype theta, Elemtype b);//���㲿�ֱ��ʽ��ֵ
//
//Elemtype In(char c, char op[]);//�ж�������ַ��ǲ��������

// ��ʼ������ջ
Status InitstackTR(OPTR*s) {

	s->base = (SElemtype *)malloc(STACK_INIT_SIZE * sizeof(SElemtype));

	if (!s->base) {

		return overflow;

	}

	s->top = s->base;

	s->stacksize = STACK_INIT_SIZE;

	return ok;

}

Status InitstackND(OPND*s)

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

Status GettopTR(OPTR*s)

{

	if (s->top == s->base)

	{

		return error;

	}

	return *(s->top - 1);

}

Status GettopND(OPND*s)

{

	if (s->top == s->base)

	{

		return error;

	}

	return *(s->top - 1);

}

//��ջ

Status  PushTR(OPTR*s, SElemtype e)

{

	if ((s->top - s->base) >= s->stacksize)

	{

		s->base = (SElemtype*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemtype));

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

Status PushND(OPND*s, SElemtype e)

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

Status PopTR(OPTR*s, SElemtype*e)

{

	if (s->top == s->base)

	{

		return error;

	}

	*e = *--s->top;

	return ok;

}

Status PopND(OPND*s, SElemtype*e)

{

	if (s->top == s->base)

	{

		return error;

	}

	*e = *--s->top;

	return ok;

}

//����ջ

Status DestorystackTR(OPTR*s)

{

	s->top = s->base;

	free(s->base);

	s->top = NULL;

	s->base = NULL;

	return ok;

}

Status DestorystackND(OPND*s)


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
		//������ַ������ݿ��е��ַ����жԱ�
}

	if (f == 0)

	{
return 0;
}
else return 1;

}

//���ݱ�Ƚ���������ȼ�

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

//�Ա��ʽ������ֵ

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

//�����������㷨

Elemtype EvaluateExpression(OPTR*OPTR, OPND*OPND)

{

	SElemtype c, theta, x;

	Elemtype a, b, v;

	SElemtype op[7] = { '+','-','*','/','(',')','#' };

	InitstackTR(OPTR);

	InitstackND(OPND);

	PushTR(OPTR, '#');

	printf("������ʽ: ");

	c = getchar();

	while (c != '#' || GettopTR(OPTR) != '#')

	{

		if (!In(c, op))

		{

			PushND(OPND, c - '0');

			c = getchar();

		}

		else

		{

			switch (Precede(GettopTR(OPTR), c))

			{

			case'<'://ջ��Ԫ�����ȼ���

				PushTR(OPTR, c);

				c = getchar();

				break;

			case'>'://ջ��Ԫ�����ȼ���

				PopTR(OPTR, &theta);

				PopND(OPND, &b);

				PopND(OPND, &a);

				v = Operate(a, theta, b);

				PushND(OPND, v);

				break;

			case'=':

				PopTR(OPTR, &x);

				c = getchar();

				break;

			}

		}

	}

	return GettopND(OPND);

}

int main()

{

	OPND OPND;

	OPTR OPTR;

	int result;

	result = EvaluateExpression(&OPTR, &OPND);

	printf("���ʽ���Ϊ�� %d\n", result);

	system("pause");

	return 0;

}