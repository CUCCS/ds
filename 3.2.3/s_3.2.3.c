#include "3.2.3.h"
//检测函数
int main()
{
	int i;
	char a[100];

	SqStack s;
	InitStack(&s);
	printf("请输入字符，其中“#”为退格符，“@”为退行符\n");
	LineEdit(&s, a);
	DistoryStack(&s);


	return 0;
}