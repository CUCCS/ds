//�б༭����
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef int SElemType;

typedef enum {
	false,
	true,
}bool;
typedef enum {
	OK,
	OVERFLOW,
	ERROR,
} Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;


Status InitStack(SqStack *s) {  //��ʼ��ջ
	printf("��ʼ��ʼ��һ��ջ\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("��ʼ��һ��ջ����\n\n");
}

//ѹջ
Status Push(SqStack *s, char e) {  
	printf("����Ԫ�� %cΪջ��Ԫ��\n", e);
	if (s->top - s->base > s->stacksize) {
		return OVERFLOW;
	}
	*s->top++ = e;
	return OK;
}

//��ջ
Status Pop(SqStack *s, char *e) {
	if (StackEmpty(s)) {
		return ERROR;
	}
	printf("���ǰһ��Ԫ��\n");
	*e = *--s->top;
	return OK;
}
//���ջ
bool StackEmpty(SqStack *s) {
	if (s) {
		return s->base == s->top;
	}
	return true;
}
//���ջ��Ԫ��
Status ClearStack(SqStack *s) {
	printf("���ǰ�������Ԫ��\n");
	s->top = s->base;
	return OK;
}
//�ַ�������
Status LineEdit(SqStack *s,char ch) {
	char str[100] = { '\0' };
	char c;
	int i = 0;
	while (ch != ';') {
		while (ch != ';'&&ch != '\n') {
			switch (ch) {
			case '#':Pop(s, &c);
				printf("\n");
				break;
			case '@':ClearStack(s);
				printf("\n");
				break;
			default:
				Push(s, ch);
			}
			ch = getchar();
		}
		while (s->top != s->base) {
			str[i] = *(s->base);
			s->base++;
			i++;
		}
		printf("�����������ַ���:\n");
		puts(str);
		ClearStack(s);
		if (ch != ';') {
			ch = getchar();
		}
	}
	DestroyStack(s);
	return OK;
}
Status DestroyStack(SqStack *s) {
	while (!StackEmpty(s)) {
		free(s->top);
		s->top--;
	}
	s->base = NULL;
	return OK;
}

int main() {
	SqStack s;
	InitStack(&s);
	printf("��ʼ�����ַ���(#Ϊ�˸����@Ϊ���з�):\n");
	char ch;
	ch = getchar();
	LineEdit(&s,ch);
	return 0;
}