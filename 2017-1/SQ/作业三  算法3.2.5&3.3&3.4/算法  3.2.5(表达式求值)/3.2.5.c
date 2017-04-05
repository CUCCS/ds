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
Status DestoryStack(SqStack *S) { //����ջ
	SqStack *p;
	if (StackEmpty(*S)) {
		return ERROR;
	}
	free(S);//S->base
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
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
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status Push(SqStack *S, ElemType e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (ElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!(S->base)) {
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
		printf("ջ��ʼ��ʧ��\n");
		return ERROR;
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
		printf("���ʽ����\n");
		return ERROR;
	}
	else {
		printf("\n���ʽ�Ľ��Ϊ��%d\n\n", result);
		return OK;
	}
};
Status Transform(char *suffix, char exp[]) {   //���׺ʽ��suffix�����׺ʽ��exp�����ԭ���ʽ
	SqStack S; //�ݴ��������ջ
	char *p;
	char ch, c;
	if (InitStack(&S)) {
		printf("ջ��ʼ��ʧ��\n");
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
			printf("���󣡳�������Ϊ\n");
		}
		result = a / b;
	    }
		break;
	}
	printf("%d %c %d = %d \n", a, op, b, result);
	return result;
};

int main() {
	char exp[100]; //��ԭ���ʽ
	char suffix[100] = { '\0' }; //���׺ʽ

	printf("������ԭ���ʽ��");
	scanf("%s", exp);
	Transform(suffix, exp);
	printf("\n���仯Ϊ��׺ʽ��%s\n", suffix);
	printf("\n�������Ϊ��\n");
	Evaluate(suffix);

	return 0;
}

