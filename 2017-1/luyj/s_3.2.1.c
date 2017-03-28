#include "3.2.1.h"
int main()
{
	SqStack S;
	srand(time(0));
	int d;
	d = rand() % 10;
	printf("随机生成进制数\n%d\n", d);
	int input;
	input = rand();
	printf("参数随机数\n%d\n", input);
	InitStack(&S);
	conversion(&S, input, d);
	return 0;
}