#include "Calculate.h"

Status  InitStack(SqStack *S)    //����һ����ջ
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));

	if (!S->base)      //����洢�ռ�ʧ��
	{
		return OVERFLOW;
	}

	S->top = S->base;     //��ʼ��
	S->stacksize = STACK_INIT_SIZE;

	return OK;
}

Status Push(SqStack *S, SElemType e)    //����Ԫ�� e Ϊ�µ�ջ��Ԫ�ء�
{
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return OVERFLOW;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;

}
int StackEmpty(SqStack *S)     //�ж�ջ�Ƿ�Ϊ��
{
	if (S)
		return S->base == S->top;
	return 1;
}

Status Pop(SqStack *S, SElemType *e)   //ɾ�� S ��ջ��Ԫ�أ����� e ������ֵ��
{
	if (StackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status GetTop(SqStack *S, SElemType *e)    //�� e ���� S ��ջ��Ԫ�ء�
{
	if (S->top == S->base)
		return ERROR;
	*e = *(S->top - 1);
	return OK;
}

bool In(SElemType c)    //�ж������ַ�c�Ƿ�Ϊ�����
{
	switch (c)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':     
		return true;
	default:
		return false;
	}
}

SElemType Precede(SElemType c1, SElemType c2) //�ж��������ջ������������������֮�����ȹ�ϵ�ĺ���
{    //������53ҳ��3.1 ���������ȹ�ϵȷ��
	SElemType judge;
	switch (c2)
	{
	case '+':
	case '-':   //��+������-��Ϊͬ��
		if (c1 == '(' || c1 == '#')
		{
	         judge = '<';
		}
		else
		{
             judge = '>';
		}
		break;
	case '*':
	case '/':   //��*������/��Ϊͬ��
		if (c1 == '*' || c1 == '/' || c1 == ')')
		{
			judge = '>';
		}
		else
		{
			judge = '<';
		}
		break;
	case '(':
		if (c1 == ')')
		{
			return ERROR;
		}
		else
		{
			judge = '<';
		}
		break;
	case ')':
		switch (c1)
		{
		case '(':
			judge = '=';
			break;
		case '#':
			return ERROR;
		default:
			judge = '>';
		}
		break;
	case '#':
		switch (c1)
		{
		case '#':
			judge = '=';
			break;
		case '(':
			return ERROR;
		default:
			judge = '>';
		}
	}
	return judge;
}

SElemType Operate(SElemType a, char ch, SElemType b)  //����ջ������������������м���
{
	SElemType c;
	a -= 48;
	b -= 48;
	switch (ch)
	{
	case'+':
		c = a + b + 48;
		break;
	case'-':
		c = a - b + 48;
		break;
	case'*':
		c = a * b + 48;
		break;
	case'/':
		c = a / b + 48;
		break;
	}
	return c;
}
int EvaluateExpression(char *suffix)
{
	SqStack OPTR,OPND;
	char ch;
	char a, b, x, theta;
	int i = 0;
	InitStack(&OPTR);
	InitStack(&OPND);

	Push(&OPTR, '#');   //��#��Ϊջ��Ԫ��
	GetTop(&OPTR, &ch);   //  ��ȡջ��Ԫ��
	while (suffix[i] != '#' || ch != '#') 
	{
		if (!In(suffix[i]))
		{
			Push(&OPND, suffix[i]);
			i++;
		}
		else 
		{
			switch (Precede(ch, suffix[i])) 
			{
			case '<':  //����suffix[i]�������ջ�� 
				Push(&OPTR, suffix[i]);
				i++;
				break;
			case '=':
				Pop(&OPTR, &x); //�� x ����ջ����
				i++;
				break;
			case '>':
				Pop(&OPTR, &theta);
				if (*(OPTR.top - 1) == '(') {
					Pop(&OPTR, &x);
					suffix[i] = '#';
				}
				Pop(&OPND, &b);
				Pop(&OPND, &a);
				Push(&OPND, Operate(a, theta, b));
				if (OPTR.base == OPTR.top) {
					suffix[i] = '#';
				}
				break;
			}
		}
		GetTop(&OPTR, &ch);
	}
	GetTop(&OPND, &ch);
	printf("������Ϊ%d\n", ch - '0');
	return ch - '0';
}
int main()
{
	char str1[20] = { "3*6+(7-8/4)*3" };
	char str2[20] = { "8+7*4/2*(5-2)" };

	printf("��ʼ����%s�ļ���\n", str1);
	EvaluateExpression(str1);

	printf("��ʼ����%s�ļ���\n", str2);
	EvaluateExpression(str2);

	return 0;

}
