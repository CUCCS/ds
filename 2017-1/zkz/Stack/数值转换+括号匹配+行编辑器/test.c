#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Status.h"
#include "Stack.h"

#define DEBUG 1
#define pare(l,r) \
		case (l):\
			DEBUG && printf("入栈 \n");\
			Push(S, *brackets);\
			break;\
		case (r):\
			DEBUG && printf("出栈 , ");\
			Pop(S, &bracket);\
			DEBUG && printf("结果为 %c \n",bracket);\
			if (bracket != (*brackets == ')' ? '(' : *brackets == ']' ? '[' : '{')) {\
				DEBUG && printf("    配对失败\n");\
				*pResult = 0;\
				return;\
			}\
			break;//end pare(l,r)
#define check(s) \
	printf("对\"%s\" 进行匹配\n", (s));\
	checkBrackets((s), &result);\
	printf("  \"%s\" 的配对结果为 %d \n", (s), result);\

int testStack() {
	printf("=== 基础测试 ===\n");
	Stack S1 = NULL;
	int n, isEmpty , size;
	CHECK(InitStack(&S1));
	printf("初始化栈\n");
	CHECK(SizeOfStack(S1,&size));
	printf("栈大小为 %d \n",size);
	CHECK(Push(S1, 5));
	printf("数字 5 入栈\n");
	CHECK(SizeOfStack(S1, &size));
	printf("栈大小为 %d \n", size);
	printf("遍历 : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(Push(S1, 9));
	printf("数字 9 入栈\n");
	CHECK(SizeOfStack(S1, &size));
	printf("栈大小为 %d \n", size);
	printf("遍历 : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(IsStackEmpty(S1, &isEmpty));
	printf("此时栈%s为空 \n", isEmpty ? "" : "不");
	CHECK(Pop(S1,&n));
	printf("出栈 , 结果为 %d \n",n);
	printf("遍历 : ");
	CHECK(Traverse(S1));
	printf("\n");
	CHECK(EmptyStack(S1));
	printf("将栈清空\n");
	CHECK(SizeOfStack(S1, &size));
	printf("栈大小为 %d \n", size);
	printf("遍历 : ");
	CHECK(Traverse(S1));
	printf("\n\n");

	return 0;
}
void conversion(int n,int d) {
	Stack S;
	int data,isEmpty;
	InitStack(&S);
	DEBUG && printf("    初始化栈\n");
	DEBUG && printf("    n = %d , d = %d \n",n,d);
	while (n) {
		Push(S, n%d);
		DEBUG && printf("    n%%d= %d 入栈 , n/=d \n",n%d);
		n /= d;
	}
	IsStackEmpty(S,&isEmpty);
	DEBUG && !isEmpty && printf("    栈不为空 , 开始输出结果\n");
	while (!isEmpty) {
		Pop(S, &data);
		printf("%d",data);
		IsStackEmpty(S, &isEmpty);
	}
	DEBUG && printf("\n    栈为空 , 循环结束");
}
void checkBrackets(char * brackets,int* pResult) {
	Stack S;
	int bracket,isEmpty;
	InitStack(&S);
	while (*brackets != '\0') {
		DEBUG && printf("    当前括号 %c , ",*brackets);
		switch (*brackets) {
		pare('(',')')
		pare('[',']')
		pare('{','}')
		default:
			break;
		}/*end switch*/
		++brackets;
	}/*end while*/
	IsStackEmpty(S,&isEmpty);
	DEBUG && printf("    匹配结束 , 栈%s为空 \n", isEmpty ? "" : "不");
	*pResult = isEmpty;
}
void lineEdit(char * source , char ** pTarget) {
	Stack S;
	char * p = source;
	int size ,i=0 , isEmpty;
	Elemtype data;
	InitStack(&S);
	DEBUG && printf("    初始化栈 \n");
	do {
		DEBUG && printf("    当前字符为 %c , ",*p);
		if (*p == '#') {
			DEBUG && printf("退格符 , 执行出栈操作 , ");
			Pop(S, &data);
			DEBUG && printf("出栈结果为 %c \n",data);
		}
		else if (*p == '@') {
			DEBUG && printf("退行符 , 执行连续出栈操作 :");
			Push(S, (Elemtype)*p);
			do {
				Pop(S, &data);
				DEBUG && printf(" %c",data);
				IsStackEmpty(S, &isEmpty);
			} while (!isEmpty && data != '\n');
			!isEmpty && Push(S, (Elemtype)'\n');
		}
		else {
			DEBUG && printf("入栈 \n");
			Push(S, (Elemtype)*p);
		}
		++p;
	} while (*p != '\0');
	Push(S, (Elemtype)*p);
	DEBUG && printf("    开始将栈中内容拷入新字符串中\n");
	DEBUG && printf("    出栈结果 :");
	SizeOfStack(S,&size);
	*pTarget = (char*)malloc(size *sizeof(char));
	for (i = size-1; i >= 0; --i) {
		Pop(S,&data);
		DEBUG && printf(" %c",data);
		(*pTarget)[i] = (char)data;
	}
	DEBUG && printf("\n");
}
void doSomeConversion() {
	printf("=== 数制转换 ===\n");
	int n;
	srand((unsigned int)time(NULL));
	n = rand() % 1024;
	printf("n = %d \n",n);
	printf("convert n to Bin : ");
	DEBUG && printf("\n");
	conversion(n, 2);
	printf("\n");
	printf("convert n to Aug : ");
	DEBUG && printf("\n");
	conversion(n, 8);
	printf("\n");
	printf("\n");
}
void doSomeCheckBrackets() {
	printf("=== 括号匹配 ===\n");
	int result;
	check("([]{()})");
	check("}");
	check("({(]");
	printf("\n");
}
void doSomeLineEdit() {
	printf("=== 行编辑器 ===\n");
	char *sa1 = "whli##ilr#e ( s#*s)\noutcha@putchar(*s=#++);";
	char *ta1;
	char *sa2 = "Mrs.##.Zong###hong is the f**king#######most\nugly@handsome man.";
	char *ta2;
	printf("(1) 输入为 : \n%s\n", sa1);
	lineEdit(sa1, &ta1);
	printf("输出为 : \n%s\n", ta1);
	printf("(2) 输入为 : \n%s\n", sa2);
	lineEdit(sa2, &ta2);
	printf("输出为 : \n%s\n", ta2);
}
int main() {
	DEBUG && testStack();
	doSomeConversion();
	doSomeCheckBrackets();
	doSomeLineEdit();
	return 0;
}