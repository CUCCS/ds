//�б༭����
#include <stdio.h>
#include <stdlib.h>
#include "3.2.2and3.2.3.h"

Status InitStack(SqStack *S) { //�����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
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
Status ClearStack(SqStack *S) { //���ջ
	if (StackEmpty(*S)) {
		return ERROR;
	}
	S->top = S->base;
	return OK;
};
bool StackEmpty(SqStack S) { //�ж��Ƿ�Ϊ��ջ
	if (S.top == S.base) {
		return true;
	}
	return false;
};
int StackLength(SqStack S) { //����ջ�ĳ���
	if (StackEmpty(S)) {
		return ERROR;
	}
	return S.stacksize;
};
Status GetTop(SqStack S, SElemType *e) { //��e����ջ��Ԫ��
	if (StackEmpty(S)) {
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
};
Status Push(SqStack *S, SElemType e) { //ѹջ������Ԫ��eΪ�µ�ջ��Ԫ�أ�
	if ((S->top) - (S->base) >= (S->stacksize)) {
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!(S->base)) {
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top)++ = e;
	return OK;
};
Status Pop(SqStack *S, SElemType *e) { //��ջ��ɾ��ջ��Ԫ�أ�����e������ֵ��
	if (StackEmpty(*S)) {
		return ERROR;
	}
	*e = *--(S->top);
	return OK;
};
Status StackTraverse(SqStack S, Status(*visit)()) { //����ջ��Ԫ�أ�����ÿ��Ԫ�ص���visit����
	if (StackEmpty(S)) {
		return ERROR;
	}
	while (S.top > S.base) {
		visit(*S.base++);
	}
	printf("\n");
	return OK;
};
Status visit(SElemType e) { //���Ԫ��
	printf("%c", e);
	return OK;
};

Status LineEdit(char *p) {
	SqStack S;
	int i = 0;
	char c;
	if (InitStack(&S)) { //�����ջ
		printf("Initialize stack failed.\n");
		return ERROR;
	};
	while (p[i] != '\0') {
		switch (p[i]) {
		case'#':
			Pop(&S, &c); //����ջ�ǿ�ʱ��ջ
			break;
		case'@':
			ClearStack(&S); //����Ϊ��ջ
			break;
		default:
			Push(&S,p[i]); //��Ч�ַ���ջ
			break;
		}
		i++;
	}
	printf("��������");
	StackTraverse(S, visit);
	printf("\n");
	ClearStack(&S);
	DestoryStack(&S);
	return OK;
};

int main() {
	char string1[] = "whli##ilr#e(s#*s)";
	char string2[] = "outcha@putchar(*s=#++)";

	printf("��������һ��whli##ilr#e(s#*s)\n");
	LineEdit(string1);

	printf("������������outcha@putchar(*s=#++)\n");
	LineEdit(string2);

	return 0;
}
