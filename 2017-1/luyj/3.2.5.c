#include "3.2.5.h"

//�洢�ַ������ݵ�ջ��
Status Pop(SqStack*s, SElemType*e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	else
	{
		*e = *--s->top;
		return OK;
	}

}
bool StackEmpty(SqStack*s)
{
	if (s->base == s->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status InitStack(SqStack*s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack*s, SElemType e)
{
	if (s->top - s->base > s->stacksize)
	{
		s->base = (SElemType*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElemType));
		if (!s->base)
		{
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += 2 * STACK_INIT_SIZE;
	}
	*s->top = e;
	s->top++;
	return OK;

}

Status GetTop(SqStack *s, SElemType *e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	*e = *(s->top - 1);
	return OK;
}

Status DistoryStack(SqStack *s)
{
	while (StackEmpty(s) == false)
	{
		s->top = NULL;
		s->top--;
	}
	s->base = NULL;
	free(s->base);
	free(s->top);
	return OK;
}


//�洢�������ݵ�ջ��
Status Pop1(SqStack1*s, SElem*e)
{
	if (s->top == s->base)
	{
		return ERROR;
	}
	else
	{
		*e = *--s->top;
		return OK;
	}

}
bool StackEmpty1(SqStack1*s)
{
	if (s->base == s->top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Status InitStack1(SqStack1*s)
{
	s->base = (SElem*)malloc(STACK_INIT_SIZE * sizeof(SElem));
	if (!s->base)
	{
		return OVERFLOW;
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push1(SqStack1*s, SElem e)
{
	if (s->top - s->base > s->stacksize)
	{
		s->base = (SElem*)realloc(s->base, (s->stacksize + 2 * STACK_INIT_SIZE) * sizeof(SElem));
		if (!s->base)
		{
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;
		s->stacksize += 2 * STACK_INIT_SIZE;
	}
	*s->top = e;
	s->top++;
	return OK;

}

Status DistoryStack1(SqStack1 *s)
{
	while (StackEmpty(s) == false)
	{
		s->top = NULL;
		s->top--;
	}
	s->base = NULL;
	free(s->base);
	free(s->top);
	return OK;
}



//�ж�����������ȼ���
int Level(char character)
{
	int num;
	switch (character)
	{
	case'(':
		num = 9;
		break;
	case')':
		num = 1;
		break;
	case'*':
		num = 3;
		break;
	case'/':
		num = 4;
		break;
	case'+':
		num = 5;
		break;
	case'-':
		num = 6;
		break;
	case'#':
		num = 8;
		break;
	default:
		num = 0;
		break;
	}
	return num;
}

bool Precede(SElemType*c, char ch)
{
	int i = 0, j = 0;
	if (Level(*c) != 0 && Level(ch) != 0)
	{
		if (Level(*c) - Level(ch)>1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}


//�ж������Ƿ�Ϊ0-9�Ĳ�������
bool IN(char ch)
{
	if (ch >= '0'&&ch <= '9')
	{
		return false;
	}
	else
	{
		return true;
	}
}

//���׺ʽ������������ݣ�
Status Pass(char suffix[50], char ch)
{
	static int i = 0;
	if (i <= 50)
	{
		suffix[i] = ch;
		suffix[i + 1] = '\0';
		i++;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//������׺ʽ��
void transform(char suffix[100], char exp[100], SqStack*s)
{
	Push(s, '#');
	char*p = exp;
	char ch;
	ch = *p;
	int i = 0;
	SElemType c;
	while (StackEmpty(s) == false)
	{
		if (IN(ch) == false)//�ж��Ƿ�Ϊ��������
		{
			Pass(suffix, ch);
		}
		else
		{
			switch (ch)
			{
			case'(':
				Push(s, ch);
				break;
			case ')':
				Pop(s, &c);
				while (c != '(')
				{
					Pass(suffix, c);
					Pop(s, &c);
					while (suffix[i] != '\0')
					{
						printf("%c", suffix[i]);
						i++;
					}
					printf("\n");
					i = 0;
				}
				break;
			default:
				GetTop(s, &c);
				while (Precede(&c, ch) == true && ch != '\0')
				{
					Pass(suffix, c);
					Pop(s, &c);
					GetTop(s, &c);
					while (suffix[i] != 0)
					{
						printf("%c", suffix[i]);
						i++;
					}
					printf("\n");
					i = 0;
				}
				if (ch != '\0')
				{
					Push(s, ch);
					while (suffix[i] != 0)
					{
						printf("%c", suffix[i]);
						i++;
					}
					i = 0;
					printf("\n");
				}
				break;
			}

		}
		if (ch != '\0')
		{
			p++;
			ch = *p;
		}
		else
		{
			while (*s->top != '#')
			{
				Pop(s, &ch);
				if (ch != '#')
				{
					Pass(suffix, ch);
					while (suffix[i] != 0)
					{
						printf("%c", suffix[i]);
						i++;
					}
					i = 0;
					printf("\n");
				}
			}
		}
	}
}


//���ú�׺ʽ���ݼ�����ջ�ͷ���ջ����0-9���ݵļ�+-*/���㣻
void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[100])
{
	//char a[5] = {'*','/','+','-','#' };
	double x = 0;
	double y = 0;
	char z;
	int i = 0;
	int j = 0;
	int q = 0;
	char*p = suffix;
	char ch;
	Push(s2, '#');
	while (StackEmpty(s2) == false)
	{
		ch = *p;
		if (IN(ch) == false)//�ж��Ƿ�Ϊ��������
		{
			Push1(s3, ch - '0');
			i++;
		}
		else
		{
			Push(s2, ch);
			j++;
		}
		if (i >= 2 && j>0)
		{
			Pop1(s3, &x);
			Pop1(s3, &y);
			Pop(s2, &z);
			q = Level(z);
			switch (q)
			{
			case 5:
				x = y + x;
				Push1(s3, x);
				break;
			case 6:
				x = y - x;
				Push1(s3, x);
				break;
			case 3:
				x = (y) * (x);
				Push1(s3, x);
				break;
			case 4:
				x = y / x;
				Push1(s3, x);
				break;
			default:
				break;
			}
			i--;
			j--;
		}
		p++;
		if (*p == '\0')
		{
			break;
		}
	}
}
