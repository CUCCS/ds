#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3-4.h"


int main(){
	int a;
	char str[20]={"3*(7-2)"};
	char str1[20]={"6+9/3+6*2-1"};
	printf("开始进行%s的计算\n",str);
	EvaluateExpression(str);
	printf("计算完毕\n\n");
	printf("开始进行%s的计算\n",str1);
	EvaluateExpression(str1);
	printf("计算完毕\n\n");
	return 0;
}
