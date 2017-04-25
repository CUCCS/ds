//行编辑程序。
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


Status InitStack(SqStack *s) {  //初始化栈
	printf("开始初始化一个栈\n");
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)
		return OVERFLOW;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	printf("初始化一个栈结束\n\n");
}

//压栈
Status Push(SqStack *s, char e) {  
	printf("插入元素 %c为栈顶元素\n", e);
	if (s->top - s->base > s->stacksize) {
		return OVERFLOW;
	}
	*s->top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack *s, char *e) {
	if (StackEmpty(s)) {
		return ERROR;
	}
	printf("清除前一个元素\n");
	*e = *--s->top;
	return OK;
}
//清空栈
bool StackEmpty(SqStack *s) {
	if (s) {
		return s->base == s->top;
	}
	return true;
}
//清除栈内元素
Status ClearStack(SqStack *s) {
	printf("清除前面的所有元素\n");
	s->top = s->base;
	return OK;
}
//字符串处理
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
		printf("经过整理后的字符串:\n");
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
	printf("开始输入字符串(#为退格符，@为退行符):\n");
	char ch;
	ch = getchar();
	LineEdit(&s,ch);
	return 0;
}