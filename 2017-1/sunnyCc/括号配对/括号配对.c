/*������ԣ��������һ������0��5֮�䣩�������Ӧ�����ţ�������Լ���*/
#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //�õ���time���� ,���������0��1,2,3,4,5,�ֱ��Ӧ������������������[������]������{������}��


void main()
{
	int a[10];
	char b[10];
	int i, number;
	srand((unsigned)time(NULL));//�������������
	for (i = 0; i<10; i++)
	{
		number = rand() % 6;  //����0-5�������
		a[i] = number;
		printf("%d ", number);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (a[i] == 0)
			b[i] = '(';
		if (a[i] == 1)
			b[i] = ')';
		if (a[i] == 2)
			b[i] = '[';
		if (a[i] == 3)
			b[i] = ']';
		if (a[i] == 4)
			b[i] = '{';
		if (a[i] == 5)
			b[i] = '}';
		printf("%c", b[i]);
	}
	printf("\n");

	char *p;
	SqStack s;

	InitStack(&s);  //��ʼ����ջ  
	p = b; //ָ��pָ���ַ�����ch

    pair(s,p);//�����������
	DestoryStack(&s);//��ջ����
	return 0;
}

