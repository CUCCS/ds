#include "3.2.3.h"
//��⺯��
int main()
{
	int i;
	char a[100];

	SqStack s;
	InitStack(&s);
	printf("�������ַ������С�#��Ϊ�˸������@��Ϊ���з�\n");
	LineEdit(&s, a);
	DistoryStack(&s);


	return 0;
}