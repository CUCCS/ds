//����ƥ�����
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
	while (S.top > S.base){
		visit(*S.base++);
	}
	printf("\n");
	return OK;
};
Status visit(SElemType e) { //���Ԫ��
	printf("%c", e);
	return OK;
};

void Matching(SqStack *S, SElemType *p) {
	//��������������ջ������������Ѱ������ƥ��������ţ��ҵ��������ų�ջ������ƥ��
	int state = 1;
	int i = 0;
	SElemType c;
	while (state && p[i] != '\0') {
		switch (p[i]) {
		case'{': {
			Push(S, p[i]);
			i++;
			break;
		}
		case'}': {
			GetTop(*S, &c);
			if (!StackEmpty(*S) && c == '{') {
				Pop(S, &c);
				i++;
			}
			else {
				state = 0;
			}
			break;
		}
		case'[': {
			Push(S, p[i]);
			i++;
			break;
		}
		case']': {
			GetTop(*S, &c);
			if (!StackEmpty(*S) && c == '[') {
				Pop(S, &c);
				i++;
			}
			else {
				state = 0;
			}
			break;
		}
		case'(': {
			Push(S, p[i]);
			i++;
			break;
		}
		case')': {
			GetTop(*S, &c);
			if (!StackEmpty(*S) && c == '(') {
				Pop(S, &c);
				i++;
			}
			else {
				state = 0;
			}
			break;
		}
		}
	}
	if (StackEmpty(*S) && state) { //��ջΪ�������Ŷ�ƥ���꣬ƥ��ɹ�������ƥ��ʧ��
		printf("Matched!\n");
	}
	else {
		printf("Not Matched!\n");
	}
	printf("\n");
}

int main() {
	SqStack S;
	if (InitStack(&S)) { //�����ջ
		printf("Initialize stack failed.\n");
	}
	else {
		printf("����(��ȷ)����һ�� {{{[[[((()))]]]}}}\n");
		Matching(&S, "{{{[[[((()))]]]}}}");

		printf("����(��ȷ)�������� {[()]}\n");
		Matching(&S, "{[()]}");

		printf("����(����)����һ�� {{{[[[((()))]]]}}}}\n");
		Matching(&S, "{{{[[[((()))]]]}}}}");

		printf("����(����)�������� {)]]]}}}}\n");
		Matching(&S, "{)]]]}}}}");
	};
	
	return 0;
}