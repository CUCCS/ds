#include "3.2.5.h"

int main()
{
	int i = 0, j = 0;
	SqStack s1;
	SqStack s2;
	SqStack1 s3;

	InitStack(&s1);
	InitStack(&s2);
	InitStack1(&s3);

	char suffix[50];
	char exp[50];
	printf("请输入0-9以内数的简单运算式\n");
	gets(exp);
	while (exp[i] != '\0')
	{
		if (exp[i] == '/'&&exp[i + 1] == '0')
		{
			printf("ERROR\n");
			printf("请重新输入\n");
			gets(exp);

		}
		i++;
	}
	printf("\n");
	/*for (i = 0; i < 50; i++)
	{
	exp[i] = '#';
	}*/
	printf("后缀式形成过程:\n");
	transform(suffix, exp, &s1);
	EvaluateExpression(&s2, &s3, suffix);
	printf("结果:");
	printf("%2lf", *s3.base);

	return 0;
}














