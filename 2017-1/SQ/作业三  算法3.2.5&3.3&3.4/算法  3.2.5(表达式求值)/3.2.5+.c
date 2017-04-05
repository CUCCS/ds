#include <stdio.h>
#include <stdlib.h>
#include "3.2.5+.h"

Status InitOptrStack(OptrStack *S) {
	//�����ջ
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
	//��e����ջ��Ԫ�أ��������
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
	//ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
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
	//��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (OptrStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OptrStackEmpty(OptrStack S) {
	//�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status InitOpndStack(OpndStack *S) {
	//�����ջ
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
	//��e����ջ��Ԫ�أ���������
	if (OpndStackEmpty(S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status PushOpnd(OpndStack *S, ElemType_Opnd e) {
	//ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
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
	//��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (OpndStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OpndStackEmpty(OpndStack S) {
	//�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status Standard(char *exp) {
	//��Ϊ�������ʽ,ɾ������Ŀո�
	char *q, *p;
	p = exp;
	while (*p != '\0') { //�����ַ���  
		if (*p == ' ') { //����ǿո�ɾ��  
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
	//�ж�����������ȼ�
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
ElemType_Opnd Operate(ElemType_Opnd a, ElemType_Optr op, ElemType_Opnd b) {
	//��������,�����opֻ��Ϊ+��-��*��/
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
	//�����*c��ʼ�Ĳ����������غ�cΪ������  
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
	//�������
	OpndStack OPND;
	OptrStack OPTR;
	ElemType_Optr ch, op; //ch�ݴ��ջ�з��ص�ֵ��op�ݴ������
	ElemType_Opnd a, b, num, result;
	char *p = exp;
	if (!InitOpndStack(&OPND) || !InitOptrStack(&OPTR)) {
		printf("ERROR! Initate stack failed.\n");
		exit(0);
	}
	PushOptr(&OPTR, '#'); //��ƥ�����'#'��ջ
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
Status Pass(char *suffix, char c) { //�����׺ʽ
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
Status Transform(char *suffix, char exp[]) {   //���׺ʽ��suffix�����׺ʽ��exp�����ԭ���ʽ
	OptrStack S; //�ݴ��������ջ
	char *p;
	char ch, c;
	if (!InitOptrStack(&S)) {
		printf("ջ��ʼ��ʧ��\n");
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
				// Precede�������ж��������ջ������������������֮�����ȹ�ϵ�ĺ���
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
	char exp[100]; //�洢���ʽ
	char suffix[100] = { '\0' }; //���׺ʽ
	int result = 0; //�洢���ʽ���

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