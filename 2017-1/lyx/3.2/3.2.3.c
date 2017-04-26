#include"3.2.3.h"
int main()
{
	int i;//定义整数类型变量i
	char a[100];//定义大小为100的字符串，命名为a
	SqStack s;//s为结构体
	InitStack(&s);//构造空栈
	printf("请输入字符，其中“#”为退格符，“@”为退行符\n");
	LineEdit(&s,a);//文本编译器函数
	DistoryStack(&s);//销毁栈s
	return 0;
}