
//main 3.2.1.cpp
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"ds 3.2.h"

int main(int argc, char* argv[])
{
	SqStack S;
	int input;
	int d;
	
	srand((unsigned)time(NULL));//��ʱ������
	input= (int)rand() % 5000;//������ɲ�������
	d= (int)rand() % 9;//�������ת������
	printf("%d\n%d\n", input, d);

	conversion(&S, input, d);

	return 0;
}


