#include <stdio.h>
#include <stdlib.h>
#include "3.2.5+.h"

Status InitOptrStack(OptrStack *S) {
	//构造空栈
	S->base = (ElemType_Optr *)malloc(STACK_INIT_SIZE * sizeof(ElemType_Optr));
	if (!(S->base)) {
		printf("Initiate stack failed.\n");
		return ERROR;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
ElemType_Optr GetOptrTop(OptrStack S) {
	//用e返回栈顶元素（运算符）
	ElemType_Optr e;
	if (OptrStackEmpty(S)) {
		printf("Error, the stack is empty\n");
	}
	else {
		e = *(S.top - 1);
	}
	return e;
};
Status PushOptr(OptrStack *S, ElemType_Optr e) {
	//压栈（插入元素e为新的栈顶元素）
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (ElemType_Optr *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType_Optr));
		if (!(S->base)) {
			printf("The increment of the stack failed.\n");
			return ERROR;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
};
Status PopOptr(OptrStack *S, ElemType_Optr *e) {
	//出栈（删除栈顶元素，并用e返回其值）
	if (OptrStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OptrStackEmpty(OptrStack S) {
	//判断是否为空栈
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status InitOpndStack(OpndStack *S) {
	//构造空栈
	S->base = (ElemType_Opnd *)malloc(STACK_INIT_SIZE * sizeof(ElemType_Opnd));
	if (!(S->base)) {
		printf("Initiate stack failed.\n");
		return ERROR;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
Status GetOpndTop(OpndStack S, ElemType_Opnd *e) {
	//用e返回栈顶元素（操作数）
	if (OpndStackEmpty(S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status PushOpnd(OpndStack *S, ElemType_Opnd e) {
	//压栈（插入元素e为新的栈顶元素）
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (ElemType_Opnd *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType_Opnd));
		if (!(S->base)) {
			printf("The increment of the stack failed.\n");
			return ERROR;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
};
Status PopOpnd(OpndStack *S, ElemType_Opnd *e) {
	//出栈（删除栈顶元素，并用e返回其值）
	if (OpndStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OpndStackEmpty(OpndStack S) {
	//判断是否为空栈
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status Standard(char *exp) {
	//化为算术表达式,删除多余的空格
	char *q, *p;
	p = exp;
	while (*p != '\0') { //遍历字符串  
		if (*p == ' ') { //如果是空格，删除  
			q = p;
			do {
				*q = *(q + 1);
				q++;
			} while (*q != '\0');
		}
		p++;
	}
	*p++ = '#';
	*p = '\0';
	return OK;
}
char Precede(ElemType_Optr a, ElemType_Optr b) {
	//判断运算符的优先级
	int i, j;
	char pre[][7] = {
		// +   -   *   /   (   )   #
		{ '>','>','<','<','<','>','>' }, // +
		{ '>','>','<','<','<','>','>' }, // -
		{ '>','>','>','>','<','>','>' }, // *
		{ '>','>','>','>','<','>','>' }, // /
		{ '<','<','<','<','<','=','<' }, // (
		{ '>','>','>','>','>','>','>' }, // )
		{ '<','<','<','<','<','<','=' }  // #
	};

	switch (a) {
	case '+':
		i = 0;
		break;
	case '-':
		i = 1;
		break;
	case '*':
		i = 2;
		break;
	case '/':
		i = 3;
		break;
	case '(':
		i = 4;
		break;
	case ')':
		i = 5;
		break;
	case '#':
		i = 6;
		break;
	}
	switch (b) {
	case '+':
		j = 0;
		break;
	case '-':
		j = 1;
		break;
	case '*':
		j = 2;
		break;
	case '/':
		j = 3;
		break;
	case '(':
		j = 4;
		break;
	case ')':
		j = 5;
		break;
	case '#':
		j = 6;
		break;
	}
	return pre[i][j];
};
bool IN(char c) {
	//判断是否为运算符
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return true;
		break;
	default:
		return false;
		break;
	}
};
ElemType_Opnd Operate(ElemType_Opnd a, ElemType_Optr op, ElemType_Opnd b) {
	//进行运算,运算符op只能为+、-、*、/
	ElemType_Opnd result = 0;
	switch (op) {
	case'+':
		result = a + b;
		break;
	case'-':
		result = a - b;
		break;
	case'*':
		result = a * b;
		break;
	case'/': {
		if (b == 0) {
			printf("Error, the  divisor can't be 0\n");
			exit(0);
		}
		result = a / b;
		break;
	}
	default:
		break;
	}
	printf("%d %c %d = %d \n", a, op, b, result);
	return result;
};
const char *GetOpnd(const char *p, ElemType_Opnd *op) {
	//获得以*c开始的操作数，返回后c为操作符  
	int temp, sum = 0;
	while (!IN(*p)) {
		temp = *p - '0';
		sum = sum * 10 + temp;
		p++;
	}
	*op = sum;
	return p;
}
ElemType_Opnd Evaluate(char *exp) {
	//计算过程
	OpndStack OPND;
	OptrStack OPTR;
	ElemType_Optr ch, op; //ch暂存从栈中返回的值，op暂存操作符
	ElemType_Opnd a, b, num, result;
	char *p = exp;
	if (!InitOpndStack(&OPND) || !InitOptrStack(&OPTR)) {
		printf("ERROR! Initate stack failed.\n");
		exit(0);
	}
	PushOptr(&OPTR, '#'); //将匹配符号'#'入栈
	while (*p != '#' || GetOptrTop(OPTR, &ch) != '#') {
		if (*p == '\0')
			break;
		if (!IN(*p)) {
			p = GetOpnd(p, &num);
			PushOpnd(&OPND, num);
		}
		else {
			switch (Precede(GetOptrTop(OPTR), *p)) {
			case '>':
				PopOptr(&OPTR, &op);
				PopOpnd(&OPND, &b);
				PopOpnd(&OPND, &a);
				result = Operate(a, op, b);
				PushOpnd(&OPND, result);
				break;
			case '<':
				PushOptr(&OPTR, *p);
				p++;
				break;
			case '=':
				PopOptr(&OPTR, &ch);
				p++;
				break;
			default:
				break;
			}
		}
	}
	GetOpndTop(OPND, &result);

	return result;
};
Status Pass(char *suffix, char c) { //构造后缀式
	int i = 0;
	while (suffix[i] != '\0') {
		i++;
	}
	if (c != '#') {
		suffix[i] = c;
		suffix[i + 1] = '\0';
	}
	else
		suffix[i] = '\0';
};
Status Transform(char *suffix, char exp[]) {   //求后缀式，suffix储存后缀式，exp输入的原表达式
	OptrStack S; //暂存运算符的栈
	char *p;
	char ch, c;
	if (!InitOptrStack(&S)) {
		printf("栈初始化失败\n");
		return ERROR;
	};
	PushOptr(&S, '#');
	p = exp;
	ch = *p;
	while ((!OptrStackEmpty(S)) && (*p != '\0')) {
		if (!IN(ch)) {
			Pass(suffix, ch);
		}
		else {
			switch (ch) {
			case '(':
				PushOptr(&S, ch);
				break;
			case ')':
				PopOptr(&S, &c);
				while (c != '(') {
					Pass(suffix, c);
					PopOptr(&S, &c);
				}
				break;
			default:
				// Precede函数是判定运算符的栈顶运算符与读入的运算符之间优先关系的函数
				while ((!GetOptrTop(S)) && (Precede(c, ch))) {
					Pass(suffix, c);
					PopOptr(&S, &c);
				}
				if (ch != '#') {
					PushOptr(&S, ch);
				}
				break;
			} // switch
		}

		if (ch != '#') {
			p++;
			ch = *p;
		}
		else {
			PopOptr(&S, &c);
			Pass(suffix, c);
		}
	} // while

	while (!OptrStackEmpty(S)) {
		PopOptr(&S, &c);
		if (c != '#') {
			Pass(suffix, c);
		}
		else {
			break;
		}
	}
} // transform

int main() {
	char exp[100]; //存储表达式
	char suffix[100] = { '\0' }; //存后缀式
	int result = 0; //存储表达式结果

	printf("Please input an expression:");
	gets(exp);

	Standard(exp);
	Transform(suffix, exp);

	if (exp[0] == '#') {
		printf("Error, the expression was wrong\n");
	}
	else {
		printf("\nThe suffix type of the expression:%s\n", suffix);
		printf("\nThe excuation of the expression:\n");
		result = Evaluate(exp);
		printf("\nThe result of the expression:%d", result);
	}

	return 0;
}