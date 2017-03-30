//小于十进制转换
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "3.2.1.h"

Status InitStack(SqStack *S) { //构造空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(S->base)) {
		return OVERFLOW;
	}
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
};
Status DestoryStack(SqStack *S) { //销毁栈
	SqStack *p;
	if (StackEmpty(*S)) {
		return ERROR;
	}
	free(S);
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
};
Status StackEmpty(SqStack S) { //判断是否为空栈
	if (S.top == S.base) {
		return true;
	}
	return false;
};
Status Push(SqStack *S, SElemType e) { //压栈（插入元素e为新的栈顶元素）
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
Status Pop(SqStack *S, SElemType *e) { //出栈（删除栈顶元素，并用e返回其值）
	if (StackEmpty(*S)) {
		return ERROR;
	}
	*e = *--(S->top);
	return OK;
};

Status conversation(int d) {
	SqStack S;
	SElemType N, e;
	if (d > 10) {
		printf("ERROR! Please input a number (<=10)\n");
		return ERROR;
	}
	if (InitStack(&S)) { //构造空栈
		printf("Initialize stack failed.\n");
		return ERROR;
	};
	N = (int)rand() % 1024; //产生随机数
	printf("\n整数： %d\n", N);
	while (N) {
		Push(&S, N % d);
		N = N / d;
	}
	printf("对应%d进制数： ",d);
	while (!StackEmpty(S)) {
		Pop(&S, &e);
		printf("%d", e);
	}
	printf("\n");
	DestoryStack(&S);
}

int main() {
	srand(time(NULL));

	conversation(8);
	conversation(2);

	return 0;
}