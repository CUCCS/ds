#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "3-4.h"


int main(){
	int a;
	char str[20]={"3*(7-2)"};
	char str1[20]={"6+9/3+6*2-1"};
	printf("��ʼ����%s�ļ���\n",str);
	EvaluateExpression(str);
	printf("�������\n\n");
	printf("��ʼ����%s�ļ���\n",str1);
	EvaluateExpression(str1);
	printf("�������\n\n");
	return 0;
}
