//�������޸�����������Ͳ���������ѧ���ʽ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3.2.5+.h"

Status InitOptrStack(OptrStack *S) { //����յ������ջ
	S->base = (ElemType_Optr *)malloc(STACK_INIT_SIZE * sizeof(ElemType_Optr));
	if (!(S->base)) {
		printf("Initiate stack failed.\n");
		return ERROR;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
Status GetOptrTop(OptrStack S, ElemType_Optr *e) { //��e����ջ��Ԫ�أ��������
	if (OptrStackEmpty(S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status PushOptr(OptrStack *S, ElemType_Optr e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
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
Status PopOptr(OptrStack *S, ElemType_Optr *e) { //��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (OptrStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OptrStackEmpty(OptrStack S) { //�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status InitOpndStack(OpndStack *S) { //����յĲ�����ջ
	S->base = (ElemType_Opnd *)malloc(STACK_INIT_SIZE * sizeof(ElemType_Opnd));
	if (!(S->base)) {
		printf("Initiate stack failed.\n");
		return ERROR;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
Status GetOpndTop(OpndStack S, ElemType_Opnd *e) { //��e����ջ��Ԫ�أ���������
	if (OpndStackEmpty(S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status PushOpnd(OpndStack *S, ElemType_Opnd e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
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
Status PopOpnd(OpndStack *S, ElemType_Opnd *e) { //��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (OpndStackEmpty(*S)) {
		printf("Error, the stack is empty\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
};
bool OpndStackEmpty(OpndStack S) { //�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};

Status Standard(char *exp) { //��Ϊ�������ʽ,ɾ������Ŀո�
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
	*p = '\0';
	return OK;
}
bool Precede(ElemType_Optr a, ElemType_Optr b) { //�ж�����������ȼ�
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
bool IN(char c) { //�ж��Ƿ�Ϊ�����
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
ElemType_Opnd Operate(ElemType_Opnd a, ElemType_Optr op, ElemType_Opnd b) { //��������,�����opֻ��Ϊ+��-��*��/
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

Status Evaluate(char suffix[][5]) { //�������
	OpndStack OPND;
	int i, num; //iΪ��������num�ݴ������
	int temp1, temp2, result; //��������������������������
	i = temp1 = temp2 = result = 0;

	if (!InitOpndStack(&OPND)) {
		printf("ERROR! Initate stack failed.\n");
		return ERROR;
	}
	while (suffix[i][0]!= '#') {
		if (!IN(suffix[i][0])) {
			num = atoi(suffix[i]);
			PushOpnd(&OPND, num);
		}
		else {
			if (!OpndStackEmpty(OPND)) {
				PopOpnd(&OPND, &temp1);
				PopOpnd(&OPND, &temp2);
				result = Operate(temp2, suffix[i][0], temp1);
				PushOpnd(&OPND, result);
			}
		}
		i++;
	}
	if (result == 0 && temp1 == 0 && temp2 == 0) {
		printf("The expression is wrong��\n");
		return ERROR;
	}
	else {
		printf("The result of the expression is : %d\n\n", result);
		return OK;
	}
};
Status Pass(char suffix[50][5], char *c) { //�����׺ʽ
	static int j;
	if (*c != '\0') {
		strcpy(suffix[j], c);
		j++;
		suffix[j][0] = '#';
	}
	return OK;
};
Status Transform(char suffix[50][5], char exp[]) { //���׺ʽ��suffix�����׺ʽ��exp�����ԭ���ʽ
	OptrStack S; //�ݴ��������ջ
	char *p;
	char temp[5] = { '\0' }; //�ݴ������
	int i = 0;
	char ch, c;
	if (!InitOptrStack(&S)) {
		printf("ERROR! Initate stack failed.\n");
		return ERROR;
	};
	PushOptr(&S, '#');
	p = exp;
	ch = *p;
	while ((!OptrStackEmpty(S)) && (*p != '\0')) {
		if (!IN(ch)) {
			temp[i] = ch;
			i++;
		}
		else {
			if (i != 0) {
				temp[i] = '\0';
				Pass(suffix, temp); //�����������׺���ʽ
				i = 0;
			}
			switch (ch) {
			case '(':
				PushOptr(&S, ch);
				break;
			case ')':
				PopOptr(&S, &c);
				while (c != '(') {
					temp[0] = c;
					temp[1] = '\0';
					Pass(suffix, temp); //����������׺���ʽ
					PopOptr(&S, &c);
				}
				break;
			default:
				// Precede�������ж��������ջ������������������֮�����ȹ�ϵ�ĺ���
				while ((GetOptrTop(S,&c)) && (Precede(c, ch))) {
					temp[0] = c;
					temp[1] = '\0';
					Pass(suffix, temp); //����������׺���ʽ
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
			temp[0] = c;
			temp[1] = '\0';
			Pass(suffix, temp);
		}
	} // while
	if (i != 0) {
		temp[i] = '\0';
		Pass(suffix, temp);
	}
	while (!OptrStackEmpty(S)) {
		PopOptr(&S, &c);
		if (c != '#') {
			temp[0] = c;
			temp[1] = '\0';
			Pass(suffix, temp);
		}
		else {
			break;
		}
	}
} // transform

int main() {
	char exp[50]; //�洢���ʽ
	char suffix[50][5] = { '\0' }; //���׺ʽ,������+�������������<=100
	int i, result = 0; //i������result�洢���ʽ���

	//printf("Please input an expression: ");
	//scanf("%s",exp);

	//Standard(exp); //��׼��
	//Transform(suffix, exp); //���׺���ʽ

	//if (exp[0] == '#') {
	//	printf("Error, the expression was wrong\n");
	//}
	//else {
	//printf("The Original expression is: %s\n", exp);
	//	printf("The suffix type of the expression:");
	//	for (i = 0; suffix[i][0] != '#'; i++) {
	//		printf("%s", suffix[i]);
	//	}
	//	printf("\nThe excuation of the expression:\n");
	//	Evaluate(suffix); //�����׺ʽ
	//}

	//for (int i = 0; i < 50; i++) { //���suffix
	//	for (int j = 0; j < 5; j++) {
	//		suffix[i][j] = '\0';
	//	}
	//}

	char exp1[50] = { '9','+','1','1','-','(','2','*','2',')','\0' };
	char exp2[50] = { '3','*','1','0','-','(','5','+','6','/','2',')','\0' };

	printf("The Original expression is: %s\n", exp1);
	Standard(exp1);
	Transform(suffix, exp1);
	printf("The suffix type of the expression:");
	for (i = 0; suffix[i][0] != '#'; i++) {
		printf("%s", suffix[i]);
	}
	printf("\nThe excuation of the expression:\n");
	Evaluate(suffix); //�����׺ʽ

	for (int i = 0; i < 50; i++) { //���suffix
		for (int j = 0; j < 5; j++) {
			suffix[i][j] = '\0';
		}
	}

	printf("The Original expression is: %s\n", exp2);
	Standard(exp2);
	Transform(suffix, exp2);
	printf("The suffix type of the expression:");
	for (i = 0; suffix[i][0] != '#'; i++) {
		printf("%s", suffix[i]);
	}
	printf("\nThe excuation of the expression:\n");
	Evaluate(suffix); //�����׺ʽ

	return 0;
}