
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef char SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
typedef enum bool{ false, true }bool;
typedef struct _SqStack {
	SElemType   *base;
	//��֮ǰ������֮��base��ֵΪNULL
	SElemType *top; //ջ��ָ��
	int stracksize;
}SqStack;
Status InitStack(SqStack *S) {
	//����һ����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S->top - S->base >= S->stracksize) {//ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//�洢����ʧ��
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S) {

	if (S->top == S->base)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}
void conversation(SqStack *S, int input, int d) {
	SElemType e;
	InitStack(S);
	while (input)
	{
		Push(S, input%d);
		input = input / d;
	}
	while (!StackEmpty(S)) {
		Pop(S, &e);
		printf("%d", e);
	}
}
void DestroyStack(SqStack *stack)//�����Ѿ����ڵ�ջ3
{
	free(stack->base);
	stack->top = stack->base;
}
Status GetTop(SqStack s, char *e) {
	if (s.top == s.base) {
		return ERROR;
	}
	*e = *(s.top - 1);
	printf("ջ���ַ�Ϊ %c\n", *e);
	return OK;
}
void Traverse(SqStack s) {
	printf("��ʼ����:\n");
	while (!StackEmpty(&s)) {
		printf("%c\n", *(s.top - 1));
		--s.top;
	}
}
bool IN(char ch) {
	if (ch <= '100'&&ch >= '0') {
		return false;
	}
	else {
		return true;
	}
}
char Precede(char exist, char read) {
	switch (exist) {
	case '+':
		if (read == '+' || read == '-' || read == ')' || read == '#') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '-':
		if (read == '+' || read == '-' || read == ')' || read == '#') {
			return '>';
		}
		else {
			return '<';
		}
		break;
	case '*':
		if (read == '(') {
			return '<';
		}
		else {
			return '>';
		}
		break;
	case '/':
		if (read == '(') {
			return '<';
		}
		else {
			return '>';
		}
		break;
	case '(':
		if (read == ')') {
			return '=';
		}
		else {
			return '<';
		}
		break;
	case ')':
		return '>';
		break;
	case '#':
		if (read == '#') {
			return '=';
		}
		else {
			return '<';
		}
		break;
	}
	return OK;
}
char Operate(char a, char thete, char b) {
	switch (thete) {
	case '+':
		return (a - '0') + (b - '0') + '0';
		break;
	case '-':
		return (a - '0') - (b - '0') + '0';
		break;
	case '*':
		return (a - '0')*(b - '0') + '0';
		break;
	case '/':
		return (a - '0') / (b - '0') + '0';
		break;
	}
}
int EvaluateExpression(char *exp) {
	SqStack OPTR;
	SqStack OPND;
	char e;
	char a, b, theta;
	char x;
	int len;
	int i = 0;
	len = strlen(exp);
	exp[len] = '#';

	InitStack(&OPTR);
	InitStack(&OPND);
	Push(&OPTR, '#');
	GetTop(OPTR, &e);
	while (exp[i] != '#' || e != '#') {
		if (!IN(exp[i])) {
			printf("���� %c ��������ջ��\n", exp[i]);
			Push(&OPND, exp[i]);
			i++;
		}
		else {
			switch (Precede(e, exp[i])) {
			case '<':
				printf("���� %c �������ջ��\n", exp[i]);
				Push(&OPTR, exp[i]);
				i++;
				break;
			case '=':
				Pop(&OPTR, &x);
				printf("�� %c ����ջ����\n", x);
				i++;
				break;
			case '>':
				printf("\n���кϲ�ǰ���б���:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				Pop(&OPTR, &theta);
				if (*(OPTR.top - 1) == '(') {
					Pop(&OPTR, &x);
					exp[i] = '#';
				}
				printf("�� %c ����ջ����\n", theta);
				Pop(&OPND, &b);
				printf("�� %c ����ջ����\n", b);
				Pop(&OPND, &a);
				printf("�� %c ����ջ����\n", a);
				Push(&OPND, Operate(a, theta, b));
				printf("\n���кϲ�����б���:\n");
				printf("------------------------------------\n");
				Traverse(OPTR);
				Traverse(OPND);
				printf("------------------------------------\n\n");
				if (OPTR.base == OPTR.top) {
					exp[i] = '#';
				}
				break;
			}
		}
		GetTop(OPTR, &e);
	}
	GetTop(OPND, &e);
	printf("������Ϊ%d\n", e - '0');
	return e - '0';
}

int main() {
	int a;
	char str[20] = { "3+2*5-4+7*(3+5)" };
	char str1[20] = { "5+3*6-2" };
	printf("��ʼ����%s�ļ���\n", str);
	EvaluateExpression(str);
	printf("�������\n\n");
	printf("��ʼ����%s�ļ���\n", str1);
	EvaluateExpression(str1);
	printf("�������\n\n");
	return 0;
}