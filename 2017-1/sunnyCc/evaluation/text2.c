/*读入一个简单算术表达式(以#结束），并计算其值*/

#include "evaluation.h"
#include <stdio.h>  

void main()
{
	int result;
	result = ExpEvaluation();
	printf("\n表达式结果是%d\n", result);
}