#include "3.2.5.h"

int main()
{
	int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, p = 0;
	SqStack s1;
	SqStack s2;
	SqStack1 s3;

	InitStack(&s1);
	InitStack(&s2);
	InitStack1(&s3);

	char suffix[50][50];
	char exp[50][50];
	char exp1[50];
	char ch;
	printf("�������������ļ�����ʽ\n");
	gets(exp1);
	while (exp1[i] != '\0')
	{
		if (exp1[i] == '/'&&exp1[i + 1] == '0')
		{
			printf("ERROR\n");
			printf("����������\n");
			gets(exp);

		}
		i++;
	}

	printf("\n");
	for (k = 0; k <= i; k++)
	{
		ch = exp1[k];
		if (IN1(ch) == true)
		{
			l = 1;
		}
		if (l == 1)
		{
			while (p < k)
			{
				exp[m][n] = exp1[p];
				n++;
				p++;
			}
			if (n != 0)
			{
				exp[m][n] = '\0';
				m++;
			}
			n = 0;
			exp[m][0] = exp1[k];
			exp[m][1] = '\0';
			p++;
			m++;
		}
		l = 0;
	}
	exp[m][0] = '\0';
	/*for (i = 0; i < 50; i++)
	{
	exp[i] = '#';
	}*/
	printf("��׺ʽ�γɹ���:\n");
	transform(suffix, exp, &s1);
	EvaluateExpression(&s2, &s3, suffix);
	printf("���:");
	printf("%lf", *s3.base);

	return 0;
}
