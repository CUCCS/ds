#include "3.2.2.h"
int main()
{
	SqStack s;
	Status ret;
	int x = 0;
	int i;
	srand(time(0));
	x = rand() % 9+1;
	char test[10];
	char s_test[6] = { '(',')','{','}','[',']' };
	for (i = 0; i < x; i++)
	{
		test[i] = s_test[rand() % 6];
	}
	test[x] = '\0';
	printf("��������ַ�����\n");
	puts(test);
	printf("����\n");
	//scanf("%s", &test);
	InitStack(&s);
	ret = Marry(&s, test);
	printf("ƥ����\n");
	if (ret == OK)
	{
		printf("matched!");
	}
	else
	{
		printf("not matched!");
	}
}