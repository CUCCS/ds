#include "3.2.5.h"

//
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

char* Pop2(SqStack*s)
{
	char e[10];

	s->top--;
	strcpy(e, *s->top);
	return e;

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


//存储整型数据的栈；
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



//判断运算符的优先级；
int Level(char *character)
{
	int num;
	switch (*character)
	{

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
	case'(':
		num = 9;
		break;
	default:
		num = 0;
		break;
	}
	return num;
}

bool Precede(SElemType*c, char *ch)
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


bool IN(char *ch)
{
	switch (*ch)
	{
	case '+':
		return true;
		break;
	case'-':
		return true;
		break;
	case '*':
		return true;
		break;
	case'/':
		return true;
		break;
	case '#':
		return true;
		break;
	case'(':
		return true;
		break;
	case')':
		return true;
		break;
	default:
		return false;
		break;
	}
}
bool IN1(char ch)
{
	if (ch>='0'&&ch<='9')
	{
		return false;
	}
	else
	{
		return true;
	}
}

//向后缀式数组中填充数据；
Status Pass(char q[50], char *ch)
{
	//char *p=suffix;
	static int i = 0;

	if (i <= 50)
	{
		strcpy(q, ch);
		return OK;
	}
	else
	{
		return ERROR;
	}
}

//建立后缀式；
void transform(char suffix[50][50], char exp[50][50], SqStack*s)
{
	Push(s, "#");
	char(*p)[50] = exp;
	char *ch;
	char(*q)[50] = suffix;
	char(*x)[50] =q;//用于打印栈；
	ch = p;
	int i = 0;
	SElemType c;
	while (StackEmpty(s) == false)
	{
		if (IN(ch) == false && strcmp(ch,"\0")!=0)//判断是否为操作数；
		{
			Pass(q, ch);
			q++;
			Pass(q, "#");
			while (strcmp(*x, "#") != 0)
			{
				printf("%s", *x);
				x++;
			}
			printf("\n");
			x = suffix;
		}
		else if (strcmp(ch,"\0")!=0)
		{
			switch (*ch)
			{
			case'(':
				Push(s, ch);
				break;
			case ')':
				Pop(s, &c);
				while (strcmp(c, "(") != 0)
				{
					Pass(q, c);
					q++;
					Pop(s, &c);
					Pass(q, "#");
					while (strcmp(*x, "#") != 0)
					{
						printf("%s", *x);
						x++;
					}
					printf("\n");
					x = suffix;
				}
				break;
			default:
				GetTop(s, &c);
				while (Precede(&c, ch) == true && strcmp(ch,"\0")!=0)
				{
					Pass(q, c);
 					Pop(s, &c);
					GetTop(s, &c);
					q++;
					Pass(q, "#");
					while (strcmp(*(x), "#") != 0)
					{
						printf("%s", *x);
						x++;
					}
					printf("\n");
					x = suffix;
				}
				if (strcmp(ch, "\0") != 0)
				{
					Push(s, ch);
				}
				break;
			}

		}
		if (strcmp(ch, "\0") != 0)
		{
			p++;
			ch = *p;
		}
		else
		{
			while (s->top-1!=s->base)
			{
				Pop(s, &ch);
				if (strcmp(ch, "#") != 0)
				{
					Pass(q, ch);
					q++;
					Pass(q, "#");
					while (strcmp(*x, "#") != 0)
					{
						printf("%s", *x);
						x++;
					}
					printf("\n");
					x = suffix;
				}
			}
			Pass(q, "#");
			while (strcmp(*(x), "#") != 0)
			{
				printf("%s", *x);
				x++;
			}
			printf("\n");
			break;
		}
	}
}


//利用后缀式数据及数据栈和符号栈进行数据的简单+-*/运算；
void EvaluateExpression(SqStack *s2, SqStack1*s3, char suffix[50][50])
{
	//char a[5] = {'*','/','+','-','#' };
	double x = 0;
	double y = 0;
	char z[10];
	int i = 0;
	int j = 0;
	int q = 0;
	char(*p)[50] = suffix;
	char *ch;
	Push(s2, "#");
	while (StackEmpty(s2) == false)
	{
		ch = p;
		if (IN(ch) == false)//判断是否为操作数；
		{
			Push1(s3, atoi(ch));
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
			strcpy(z, Pop2(s2));
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
				x = y * (x);
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
		if (strcmp(ch,"#")==0)
		{
			break;
		}
	}
}

