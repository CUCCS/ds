#include"3.2.3.h"
int main()
{
	int i;//�����������ͱ���i
	char a[100];//�����СΪ100���ַ���������Ϊa
	SqStack s;//sΪ�ṹ��
	InitStack(&s);//�����ջ
	printf("�������ַ������С�#��Ϊ�˸������@��Ϊ���з�\n");
	LineEdit(&s,a);//�ı�����������
	DistoryStack(&s);//����ջs
	return 0;
}