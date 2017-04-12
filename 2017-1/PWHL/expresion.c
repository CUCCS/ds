
#include "expresion.h"

//构造一个空栈
PSeqStack createEmptyStack_seq()
{
	PSeqStack pastack;
	pastack = (SeqStack*)malloc(sizeof(SeqStack));

	if (pastack == NULL)
	{
		printf("空间不够!!\n");
	}
	else
	{
		pastack->t = -1;
	}
	return pastack;//返回空栈顶 
}


//清空栈
int isEmptyStack_seq(PSeqStack pastack)
{
	return pastack->t == -1;

}


//入栈
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

//出栈
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

//返回栈顶元素的值
DataType top_seq(PSeqStack pastack)
{
	return pastack->s[pastack->t];
}



/*将中缀表达式转换为后缀表达式，顺利转换返回true，若转换过程中发现中缀表达式非法则返回false*/
int infixtoSuffix(const char* infix, char* suffix)
{
	int state_int = FALSE; /*state_int记录状态，等于true表示刚读入的是数字字符，等于false表示刚读入的是运算符，
						   设置这个变量是为了在每输出一个整数后输出一个空格，以免连续输出的两个整数混在一起。*/
	char c, c2;
	PSeqStack ps = createEmptyStack_seq(); /*构造一个运算符栈*/
	int i, j = 0;
	if (infix[0] == '\0')
	{
		return FALSE; /*不允许出现空表达式*/
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
				suffix[j++] = ' ';/*状态从true转换为false时输出一个空格*/
			}
			state_int = FALSE;
			break; /*遇到空格或制表符忽略*/
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
			suffix[j++] = c; /*遇到数字输出*/
			break;
		case '(':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';/*状态从true转换为false时输出一个空格*/
			}
			state_int = FALSE;

			push_seq(ps, c); /*遇到左括号，入栈*/
			break;
		case ')':
			if (state_int == TRUE)
			{
				suffix[j++] = ' ';/*状态从true转换为false时输出一个空格*/
			}
			state_int = FALSE;
			c2 = ')';
			while (!isEmptyStack_seq(ps))
			{
				c2 = top_seq(ps);/*取栈顶*/
				pop_seq(ps); /*出栈*/
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


//计算后缀
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


//主函数
int main()
{
	char c, infix[MAXNUM], suffix[MAXNUM];
	int result;
	int flag = TRUE;
	while (flag == TRUE)
	{
		printf("请输入任意一个整数算术表达式:\n");
		getline(infix, MAXNUM);
		if (infixtoSuffix(infix, suffix) == TRUE)
		{
			printf("所有后缀为:%s\n", suffix);
		}
		else
		{
			printf("无效缀!\n");
			continue;
		}

		if (calculateSuffix(suffix, &result) == TRUE)
		{
			printf("结果为:%d\n", result);
		}
		else
		{
			printf("非法后缀!\n");
		}
	}
	return 0;
}