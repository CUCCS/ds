//ʵ�ֲ�����Ϊʮ���ڵı��ʽ��ֵ,���������Ϊ����
#include <stdio.h>
#include <stdlib.h>
#include "3.2.5.h"

Status InitStack(SqStack *S) { //�����ջ
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!(S->base)) {
		return OVERFLOW;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
bool StackEmpty(SqStack S) { //�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};
Status GetTop(SqStack S, ElemType *e) { //��e����ջ��Ԫ��
	if (StackEmpty(S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status Push(SqStack *S, ElemType e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!(S->base)) {
			printf("The increment of the stack failed.\n");
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
};
Status Pop(SqStack *S, ElemType *e) { //��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (StackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *--S->top;
	return OK;
};

bool Precede(char a,char b){ //�ж�����������ȼ�
	int i, j;
	char pre[][7] = {
		// +   -   *   /   (   )   #
		{ '>','>','<','<','<','>','>' }, // +
		{ '>','>','<','<','<','>','>' }, // -
		{ '>','>','>','>','<','>','>' }, // *
		{ '>','>','>','>','<','>','>' }, // /
		{ '<','<','<','<','<','=','0' }, // (
		{ '>','>','>','>','0','>','>' }, // )
		{ '<','<','<','<','<','0','=' }  // #
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

	if (pre[i][j] == '>') {
		return true;
	}
	else {
		return false;
	}
};
bool IN(char c) {
	//�ж��Ƿ�Ϊ�����
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
Status Pass(char *suffix, char c) { //�����׺ʽ
	int i = 0;
	while (suffix[i] != '\0') {
		i++;
	}
	suffix[i] = c;
	suffix[i + 1] = '\0';
};
Status Evaluate(char *suffix) { //����׺ʽ���м���
	SqStack OPND;
	char *p = suffix;
	char c, ch;
	int temp1, temp2, result;
	ch = *p;
	temp1 = temp2 = result = 0;
	if (InitStack(&OPND)) {
		printf("ERROR! Initate stack failed.\n");
		exit(0);
	}
	while (ch != '\0') {
		if (!IN(ch)) {
			Push(&OPND, ch);
		}
		else {		
			if (!StackEmpty(OPND)){
				Pop(&OPND, &c);
				temp1 = c - '0';
				if (!StackEmpty(OPND)) {
					Pop(&OPND, &c);
					temp2 = c - '0';
					result = Operate(temp2, ch, temp1);
					c = result + '0';
					Push(&OPND, c);
				}
			}
		}
		p++;
		ch = *p;
	}
	if (result == 0 && temp1 == 0 && temp2 == 0) {
		printf("The expression was wrong��\n");
		return ERROR;
	}
	else {
		printf("The result of the expression is��%d\n\n", result);
		return OK;
	}
};
Status Transform(char *suffix, char exp[]) { //���׺ʽ��suffix�����׺ʽ��exp�����ԭ���ʽ
	SqStack S; //�ݴ��������ջ
	char *p;
	char ch, c;
	if (InitStack(&S)) {
		printf("Initiate stack failed.\n");
		return ERROR;
	};
	Push(&S, '#');
	p = exp;
	ch = *p;
	while ((!StackEmpty(S)) && (*p != '\0')) {
		if (!IN(ch)) {
			Pass(suffix, ch);
		}
		else {
			switch (ch) {
			case '(':
				Push(&S, ch);
				break;
			case ')':
				Pop(&S, &c);
				while (c != '(') {
					Pass(suffix, c);
					Pop(&S, &c);
				}
				break;
			default:
				// Precede�������ж��������ջ������������������֮�����ȹ�ϵ�ĺ���
				while ((!GetTop(S, &c)) && (Precede(c, ch))) {
					Pass(suffix, c);
					Pop(&S, &c);
				}
				if (ch != '#') {
					Push(&S, ch);
				}
				break;
			} // switch
		}

		if (ch != '#') {
			p++;
			ch = *p;
		}
		else {
			Pop(&S, &c);
			Pass(suffix, c);
		}
	} // while
	while (!StackEmpty(S)) {
		Pop(&S, &c);
		if (c != '#') {
			Pass(suffix, c);
		}
		else {
			break;
		}
	}
} // transform
int Operate(int a, char op, int b) { //��������,opֻ��Ϊ+��-��*��/
	int result;
	switch (op){
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
	    }
		break;
	}
	printf("%d %c %d = %d \n", a, op, b, result);
	return result;
};

int main() {
	//char exp[50];//��ԭ���ʽ
	char exp1[]= { '3','+','9','-','(','2','*','2',')','\0' }; 
	char exp2[] = { '5','*','3','-','(','2','+','6',')','\0' };
	char suffix[50] = { '\0' }; //���׺ʽ

	/*printf("Please input an expression:");
	scanf("%s", exp);
	printf("The Original expression is: %s\n", exp);
	Transform(suffix, exp);
	printf("The suffix type of the expression:%s\n", suffix);
	printf("The excuation of the expression:\n");
	Evaluate(suffix);*/


	printf("The Original expression is: %s\n", exp1);
	Transform(suffix, exp1);
	printf("The suffix type of the expression:%s\n", suffix);
	printf("The excuation of the expression:\n");
	Evaluate(suffix);

	for (int i = 0; i < 50; i++) {
		suffix[i] = '\0';
	}

	printf("The Original expression is: %s\n", exp2);
	Transform(suffix, exp2);
	printf("The suffix type of the expression:%s\n", suffix);
	printf("The excuation of the expression:\n");
	Evaluate(suffix);

	return 0;
}