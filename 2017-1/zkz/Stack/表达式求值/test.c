#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Status.h"
#include "Stack.h"

#define DEBUG 1
#define debug_print( ... ) if(DEBUG)printf(__VA_ARGS__)

/*以下几个函数用于判断一个字符是操作数还是操作符*/
bool isOperand(char c) {
	return c >= '0' && c <= '9';
}
bool isLv1Operator(char c) {
	return c == '+' || c == '-';
}
bool isLv2Operator(char c) {
	return c == 'x' || c == '*' || c == '/';
}
bool isLv3Operator(char c) {
	return c == '(' || c == ')';
}
/*获取操作符的优先级*/
int getLevel(char c) {
	if (isOperand(c)) return 0;
	if (isLv1Operator(c)) return 1;
	if (isLv2Operator(c)) return 2;
	if (isLv3Operator(c)) return 3;
	return -1;
}
/*判断操作符ope1的优先级是否高于ope2*/
bool isPriorityHigher(const char ope1, const char ope2) {
	return getLevel(ope1) > getLevel(ope2);
}

/*将中缀表达式转换为后缀表达式*/
/*注 : 没有做参数合法性检查*/
/*source : 待转换的中缀表达式*/
/*pTarget : 用来存放指向后缀表达式指针的地址*/
void transformToSuffix(const char * source, char ** pTarget) {
	/*变量声明*/
	Stack operatorStack;/*操作符栈*/
	Stack suffixStack;
	const char * p;/*指针，用于遍历source以及将处理好的数据传入*pTarget中 */
	int i;/*循环变量*/
	int size/*用于记录处理好的数据的大小*/;

	debug_print("=====中缀转后缀=====\n");
	debug_print("%s \n",source);
	/*初始化栈*/
	InitStack(&operatorStack);
	InitStack(&suffixStack);

	/*遍历source*/
	for (p = source; *p != '\0'; ++p) {
		debug_print("Output : ");
		DEBUG && Traverse(suffixStack);
		debug_print("\nOperatorStack : ");
		DEBUG && Traverse(operatorStack);
		debug_print("\n\n");
		/*如果当前字符是操作数*/
		if (isOperand(*p)) {
			debug_print("%c 是操作数 \n", *p);
			Push(suffixStack, *p);
			Push(suffixStack, ' ');
			continue;
		}
		/*如果当前字符是右括号*/
		if (*p == ')') {
			debug_print("%c 是右括号 \n", *p);
			while (getTop(operatorStack) != '(') {
				Push(suffixStack, pop(operatorStack));
			}
			pop(operatorStack);
			continue;
		}
		/*如果遇到其他操作符*/
		if (1) {
			debug_print("%c 是其他操作符 \n", *p);
			while (!isStackEmpty(operatorStack) && !isPriorityHigher(*p, getTop(operatorStack)) && getTop(operatorStack) != '(') {
				Push(suffixStack, pop(operatorStack));
			}
			Push(operatorStack, *p);
			continue;
		}
	}/*end for*/
	debug_print("Output : ");
	DEBUG && Traverse(suffixStack);
	debug_print("\nOperatorStack : ");
	DEBUG && Traverse(operatorStack);
	debug_print("\n\n");

	if (!isStackEmpty(operatorStack)) {
		debug_print("操作符栈非空 , 将剩余操作符传送到结果栈 \n");
	}
	while (!isStackEmpty(operatorStack)) {
		Push(suffixStack, pop(operatorStack));
	}
	debug_print("Output : ");
	DEBUG && Traverse(suffixStack);
	debug_print("\nOperatorStack : ");
	DEBUG && Traverse(operatorStack);
	debug_print("\n\n");

	size = sizeOfStack(suffixStack);
	debug_print("输出大小 : %d \n\n", size);
	*pTarget = (char*)malloc((size + 1) * sizeof(char));
	(*pTarget)[size] = '\0';
	/*将处理好的数据传入*pTarget中 */
	for (i = size - 1; i >= 0; --i) {
		(*pTarget)[i] = pop(suffixStack);
	}
}
/*计算后缀表达式的值*/
/*p : 后缀表达式*/
/*pResult : 指向用于保存结果的变量的指针*/
void calculateSuffix(char* p,int* pResult) {
	Stack S;
	int a, b;

	debug_print("\n\n=====计算后缀表达式=====\n");
	debug_print("%s \n",p);
	InitStack(&S);
	for (; *p != '\0'; ++p) {
		if (*p == ' ') {
			continue;
		}
		if (isOperand(*p)) {
			debug_print(" %c 是操作数 , 入栈 \n",*p);
			Push(S, *p);
		}
		else {
			debug_print(" %c 是操作符 , 两次出栈 \n",*p);
			b = pop(S) - '0';
			a = pop(S) - '0';
			debug_print(" 出栈结果 : %d %d \n",a,b);
			switch (*p) {
			case '+':
				Push(S, a + b + '0');
				break;
			case '-':
				Push(S, a - b + '0');
				break;
			case 'x':
			case '*':
				Push(S, a*b + '0');
				break;
			case '/':
				Push(S, a / b + '0');
				break;
			default:
				break;
			}/*end swtich*/
			debug_print("结果为 %d , 入栈\n",getTop(S)-'0');
		}/*end if else*/
	}/*end for*/

	*pResult =  getTop(S)-'0';
}
int main() {
	char source[256] = "5*((5+6)*2+3)";
	char* target;
	int result;

	transformToSuffix(source, &target);
	printf("将中缀表达式\n%s\n处理为后缀表达式 : \n%s\n", source, target);
	calculateSuffix(target, &result);
	printf("对其进行计算，结果为 : \n%d \n", result);
}