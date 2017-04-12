#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Status.h"
#include "Stack.h"

#define INPUT 0
#define DEBUG 0
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
bool isOperator(char c) {
	return getLevel(c) >= 1;
}
/*判断操作符ope1的优先级是否高于ope2*/
bool isPriorityHigher(const char ope1, const char ope2) {
	return getLevel(ope1) > getLevel(ope2);
}

/*将中缀表达式转换为后缀表达式*/
/*注 : 没有做参数合法性检查*/
/*source : 待转换的中缀表达式*/
/*pTarget : 用来存放指向后缀表达式指针的地址*/
void transformToSuffix(char const * const source, char ** pTarget) {
	debug_print("====中缀转后缀====\n");
	char  * cleanSource;/*用于记录去除非法字符后的source*/
	const char * p;/*用于遍历source*/
	Stack S;
	char num[256];/*用于存放获取到的数字*/
	int size=0;/*用于记录结果字符串的大小*/

	InitStack(&S);

	debug_print("\nStep 1 : 清除中缀式中的非法字符\n");
	/*清除source中的非法字符*/
	for (cleanSource = source; *cleanSource != '\0'; ++cleanSource) {
		if (getLevel(*cleanSource) != -1) {
			Push(S,(*cleanSource));
		}
	}
	debug_print("待处理中缀式 : \n%s \n",source);
	size = sizeOfStack(S);/*此处借用size存放栈S的大小*/
	cleanSource = (char*)malloc((size + 1) * sizeof(char));
	cleanSource[size] = '\0';
	while (!isStackEmpty(S)) {
		/*然后再借用size做循环变量*/
		cleanSource[size - 1] = (char)pop(S);
		--size;
	}
	debug_print("去除非法字符后 : \n%s \n", cleanSource);

	/*其实size的大小一开始就可以求得*/
	/*即遍历source，如果不是括号则++size*/
	/*如果是操作符，则再++size,用于给区分多位数的空格留出空间*/
	for (p = cleanSource; *p != '\0'; ++p) {
		/*如果*p不是括号*/
		if (getLevel(*p) != 3) {
			++size;
		}
		/*如果*p是加减乘除*/
		if (getLevel(*p) == 1 || getLevel(*p) == 2) {
			++size;
		}
	}
	/*求出size后即可对*pTarget进行malloc*/
	/*末尾留出空间放'\0'*/
	*pTarget = (char*)malloc((size+1)*sizeof(char));
	(*pTarget)[0] = '\0';

	debug_print("\nStep2 : 遍历中缀式\n");
	/*遍历source*/
	for (p = cleanSource; *p != '\0'; ++p) {
		/*如果是数字则直接传送到*pTarget*/
		if (!isOperator(*p)) {
			_itoa_s(atoi(p),num,256,10);
			debug_print("操作数 %d : 传送至输出区 \n",atoi(num));
			p += strlen(num);
			strcat_s(*pTarget, size+2,num);
			strcpy_s(num, 256, "");
			strcat_s(*pTarget,size+2," ");
			p -= 1;
		}
		else {
			/*如果当前操作符是右括号*/
			if (*p == ')') {
				debug_print("操作符 ) : 开始连续出栈 \n");
				/*依次将操作符传到*pTarget直到遇到左括号*/
				while (getTop(S) != '(') {
					debug_print("操作符 %c : 传送至输出区 \n", getTop(S));
					/*此处借用num来完成将操作符传入*pTarget的操作 */
					num[0] = pop(S);
					num[1] = '\0';
					strcat_s(*pTarget, size + 1,num);
				}
				/*删掉左括号*/
				debug_print("遭遇操作符 ( ，连续出栈停止 \n操作符 ( : 被删除 \n");
				pop(S);
			}
			/*如果栈空或者当前操作符优先级比栈顶操作符更高*/
			else if (isStackEmpty(S) ||  isPriorityHigher(*p,getTop(S))) {
				debug_print("操作符 %c : 入栈 \n", *p);
				Push(S, *p);
			}
			/*如果当前操作符优先级更低*/
			/*则连续出栈直到栈空或自己优先级并不更低*/
			/*然后将自己入栈*/
			else {
				/*依次将操作符传到*pTarget*/
				/*直到栈空或自己优先级 ?不更低*/
				debug_print("操作符 %c : 开始连续出栈 \n", *p);
				while (!isStackEmpty(S) && !isPriorityHigher(*p,getTop(S)) && getTop(S)!='(') {
					/*此处借用num来完成将操作符传入*pTarget的操作 */
					debug_print("操作符 %c : 传送至输出区 \n", getTop(S));
					num[0] = pop(S);
					num[1] = '\0';
					strcat_s(*pTarget, size + 1, num);
				}
				if (isStackEmpty(S)) {
					debug_print("栈空，连续出栈停止");
				}
				else if ( getTop(S) == '(') {
					debug_print("遭遇操作符 ( ，连续出栈停止 \n");
				}
				else if (isPriorityHigher(*p,getTop(S))) {
					debug_print("栈顶操作符 %c 优先级 < %c，连续出栈停止 \n",getTop(S),*p);
				}
				/*然后将自己入栈*/
				debug_print("操作符 %c : 入栈 \n", *p);
				Push(S, *p);
			}/*end if*/
		}/*end if*/
	}/*end for*/
	debug_print("中缀式遍历完毕 \n");

	/*如果栈非空，则将剩余操作符挨个传入*pTarget*/
	while (!isStackEmpty(S)) {
		debug_print("栈非空 : 将剩余字符传送至输出区 \n", *p);
		/*此处借用num来完成将操作符传入*pTarget的操作 */
		debug_print("操作符 %c : 传送至输出区 \n", getTop(S));
		num[0] = pop(S);
		num[1] = '\0';
		strcat_s(*pTarget, size+2, num);
	}
	debug_print("转换好的后缀式为 : \n%s\n\n",*pTarget);
}
/*计算后缀表达式的值*/
/*exp : 后缀表达式*/
/*pResult : 指向用于保存结果的变量的指针*/
void calculateSuffix(const char const* exp, int* pResult) {
	debug_print("\n====计算后缀式====\n");
	debug_print("待计算的后缀式 : \n%s\n",exp);
	const char * p;/*用于遍历source*/
	Stack S;
	int num;/*用于存放获取到的数字*/
	int a, b;/*用于暂存计算时pop出来的数字*/

	*pResult = 0;
	InitStack(&S);
	/*遍历exp*/
	for (p = exp; *p != '\0'; ++p) {
		/*如果是操作数，入栈*/
		if (isOperand(*p)) {
			num = atoi(p);
			debug_print("操作数 %d : 入栈 \n",num);
			Push(S, num);
			while (num > 0) {
				++p;
				num /= 10;
			}
		}
		else {
			debug_print("操作符 %c : 两次出栈 \n", *p);
			b = pop(S);
			a = pop(S);
			debug_print("出栈结果为 %d , %d \n",a,b);
			switch (*p) {
			case '+':*pResult = a + b; break;
			case '-':*pResult = a - b; break;
			case 'x':
			case '*':*pResult = a * b; break;
			case '/':*pResult = a / b; break;
			default: 
				printf("Error : What THe F**K is THAT ???");
				return;
				break;
			}/*end switch*/
			debug_print("计算结果为 %d %c %d = %d , 入栈 \n",a,*p,b,*pResult);
			Push(S, *pResult);
		}/*end if else*/
	}/*end for*/
	*pResult = pop(S);
	debug_print("最后结果 : %d \n\n\n",*pResult);
}
int main() {
	char source[256] = "1+(15-6)*9*((12*100+34)*10000+79+40*((16/4)*35))";
	char* target;
	int result;

	if (INPUT) {
		gets_s(source, 256);
	}
	transformToSuffix(source, &target);
	calculateSuffix(target, &result);
	printf("将中缀表达式\n%s\n处理为后缀表达式 : \n%s\n", source, target);
	printf("对其进行计算，结果为 : \n%d \n", result);
}