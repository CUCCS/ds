
#include "expresion.h"

//����һ����ջ
PSeqStack createEmptyStack_seq()
{
	PSeqStack pastack;
	pastack = (SeqStack*)malloc(sizeof(SeqStack));

	if (pastack == NULL)
	{
		printf("�ռ䲻��!!\n");
	}
	else
	{
		pastack->t = -1;
	}
	return pastack;//���ؿ�ջ�� 
}


//���ջ
int isEmptyStack_seq(PSeqStack pastack)
{
	return pastack->t == -1;

}


//��ջ
void push_seq(PSeqStack pastack, DataType x)
{
	if (pastack->t >= MAXNUM - 1)

		printf("\n");
	else
	{
		pastack->t = pastack->t + 1;
		pastack->s[pastack->t] = x;
	}
}

//��ջ
void pop_seq(PSeqStack pastack)
{
	if (pastack->t == -1)
	{
		printf("\n");
	}
	else
	{
		pastack->t = pastack->t - 1;
	}
}

//����ջ��Ԫ�ص�ֵ
DataType top_seq(PSeqStack pastack)
{
	return pastack->s[pastack->t];
}



/*����׺���ʽת��Ϊ��׺���ʽ��˳��ת������true����ת�������з�����׺���ʽ�Ƿ��򷵻�false*/
int infixtoSuffix(const char* infix, char* suffix)
{
	int state_int = FALSE; /*state_int��¼״̬������true��ʾ�ն�����������ַ�������false��ʾ�ն�������������
						   �������������Ϊ����ÿ���һ�����������һ���ո��������������������������һ��*/
	char c, c2;
	PSeqStack ps = createEmptyStack_seq(); /*����һ�������ջ*/
	int i, j = 0;
	if (infix[0] == '\0')
	{
		return FALSE; /*��������ֿձ��ʽ*/
	}
	for (i = 0; infix[i] != '\0'; i++)
	{
		c = infix[i];

		switch (c)
		{
		case ' ':
		case '\t':
		case '\n':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';/*״̬��trueת��Ϊfalseʱ���һ���ո�*/
			}
			state_int = FALSE;
			break; /*�����ո���Ʊ������*/
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			state_int = TRUE;
			suffix[j++] = c; /*�����������*/
			break;
		case '(':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';/*״̬��trueת��Ϊfalseʱ���һ���ո�*/
			}
			state_int = FALSE;

			push_seq(ps, c); /*���������ţ���ջ*/
			break;
		case ')':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';/*״̬��trueת��Ϊfalseʱ���һ���ո�*/
			}
			state_int = FALSE;
			c2 = ')';
			while (!isEmptyStack_seq(ps))
			{
				c2 = top_seq(ps);/*ȡջ��*/
				pop_seq(ps); /*��ջ*/
				if (c2 == '(')
				{
					break;
				}
				suffix[j++] = c2;
			}
			if (c2 != '(')
			{
				free(ps);
				suffix[j++] = '\0';
				return FALSE;
			}
			break;
		case '+':
		case '-':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';
			}
			state_int = FALSE;
			while (!isEmptyStack_seq(ps))
			{
				c2 = top_seq(ps);
				if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/')
				{
					pop_seq(ps);
					suffix[j++] = c2;
				}
				else if (c2 == '(')
				{
					break;
				}
			}
			push_seq(ps, c);
			break;
		case '*':
		case '/':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';
			}
			state_int = FALSE;
			while (!isEmptyStack_seq(ps))
			{
				c2 = top_seq(ps);
				if (c2 == '*' || c2 == '/')
				{
					pop_seq(ps);
					suffix[j++] = c2;
				}
				else if (c2 == '+' || c2 == '-' || c2 == '(')
				{
					break;
				}
			}
			push_seq(ps, c);
			break;
		default:
			free(ps);
			suffix[j++] = '\0';
			return FALSE;
		}
	}
	if (state_int == TRUE)
	{
		suffix[j++] = ' ';
	}
	while (!isEmptyStack_seq(ps))
	{
		c2 = top_seq(ps);
		pop_seq(ps);
		if (c2 == '(')
		{
			free(ps);
			suffix[j++] = '\0';
			return FALSE;
		}
		suffix[j++] = c2;
	}
	free(ps);
	suffix[j++] = '\0';
	return TRUE;
}


//�����׺
int calculateSuffix(const char * suffix, int * presult)
{

	int state_int = FALSE;
	PSeqStack ps = createEmptyStack_seq();
	int num = 0, num1, num2;
	int i;
	char c;
	for (i = 0; suffix[i] != '\0'; i++)
	{
		c = suffix[i];
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (state_int == TRUE)
			{
				num = num * 10 + c - '0';
			}
			else
			{
				num = c - '0';
			}
			state_int = TRUE;
			break;
		case ' ':
		case'\t':
		case '\n':
			if (state_int == TRUE)
			{
				push_seq(ps, num);
				state_int = FALSE;
			}
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			if (state_int == TRUE)
			{
				push_seq(ps, num);
				state_int = FALSE;
			}
			if (isEmptyStack_seq(ps))
			{
				free(ps);
				return FALSE;
			}
			num2 = top_seq(ps);
			pop_seq(ps);
			if (isEmptyStack_seq(ps))
			{
				free(ps);
				return FALSE;
			}
			num1 = top_seq(ps);
			pop_seq(ps);
			if (c == '+')
			{
				push_seq(ps, num1 + num2);
			}
			if (c == '-')
			{
				push_seq(ps, num1 - num2);
			}
			if (c == '*')
			{
				push_seq(ps, num1 * num2);
			}
			if (c == '/')
			{
				push_seq(ps, num1 / num2);
			}
			break;
		default:
			free(ps);
			return FALSE;
		}
	}
	*presult = top_seq(ps);
	pop_seq(ps);
	if (!isEmptyStack_seq(ps))
	{
		free(ps);
		return FALSE;
	}
	free(ps);
	return TRUE;
}
void getline(char* line, int limit)
{
	char c;
	int i = 0;
	while (i<limit - 1 && (c = getchar()) != EOF&&c != '\n')
	{
		line[i++] = c;
	}
	line[i] = '\0';
}


//������
int main()
{
	char c, infix[MAXNUM], suffix[MAXNUM];
	int result;
	int flag = TRUE;
	while (flag == TRUE)
	{
		printf("����������һ�������������ʽ:\n");
		getline(infix, MAXNUM);
		if (infixtoSuffix(infix, suffix) == TRUE)
		{
			printf("���к�׺Ϊ:%s\n", suffix);
		}
		else
		{
			printf("��Ч׺!\n");
			continue;
		}

		if (calculateSuffix(suffix, &result) == TRUE)
		{
			printf("���Ϊ:%d\n", result);
		}
		else
		{
			printf("�Ƿ���׺!\n");
		}
	}
	return 0;
}