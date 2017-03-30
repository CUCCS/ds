//行编辑程序
#include <stdio.h>
#include <stdlib.h>
#include "3.2.2and3.2.3.h"

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
	free(S);//S->base
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	return OK;
};
Status ClearStack(SqStack *S) { //清空栈
	if (StackEmpty(*S)) {
		return ERROR;
	}
	S->top = S->base;
	return OK;
};
bool StackEmpty(SqStack S) { //判断是否为空栈
	if (S.top == S.base) {
		return true;
	}
	return false;
};
int StackLength(SqStack S) { //返回栈的长度
	if (StackEmpty(S)) {
		return ERROR;
	}
	return S.stacksize;
};
Status GetTop(SqStack S, SElemType *e) { //用e返回栈顶元素
	if (StackEmpty(S)) {
		return ERROR;
	}
	*e = *(S.top - 1);
	return OK;
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
Status StackTraverse(SqStack S, Status(*visit)()) { //遍历栈的元素，并对每个元素调用visit函数
	if (StackEmpty(S)) {
		return ERROR;
	}
	while (S.top > S.base) {
		visit(*S.base++);
	}
	printf("\n");
	return OK;
};
Status visit(SElemType e) { //输出元素
	printf("%c", e);
	return OK;
};

Status LineEdit(char *p) {
	SqStack S;
	int i = 0;
	char c;
	if (InitStack(&S)) { //构造空栈
		printf("Initialize stack failed.\n");
		return ERROR;
	};
	while (p[i] != '\0') {
		switch (p[i]) {
		case'#':
			Pop(&S, &c); //仅当栈非空时出栈
			break;
		case'@':
			ClearStack(&S); //重置为空栈
			break;
		default:
			Push(&S,p[i]); //有效字符进栈
			break;
		}
		i++;
	}
	printf("输出结果：");
	StackTraverse(S, visit);
	printf("\n");
	ClearStack(&S);
	DestoryStack(&S);
	return OK;
};

int main() {
	char string1[] = "whli##ilr#e(s#*s)";
	char string2[] = "outcha@putchar(*s=#++)";

	printf("测试用例一：whli##ilr#e(s#*s)\n");
	LineEdit(string1);

	printf("测试用例二：outcha@putchar(*s=#++)\n");
	LineEdit(string2);

	return 0;
}
