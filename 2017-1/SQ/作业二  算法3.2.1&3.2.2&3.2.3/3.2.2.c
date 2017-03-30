//括号匹配检验
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
	while (S.top > S.base){
		visit(*S.base++);
	}
	printf("\n");
	return OK;
};
Status visit(SElemType e) { //输出元素
	printf("%c", e);
	return OK;
};

void Matching(SqStack *S, SElemType *p) {
	//遇到左括号则入栈，遇到右括号寻找与其匹配的左括号，找到则左括号出栈，否则不匹配
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
	if (StackEmpty(*S) && state) { //若栈为空且括号都匹配完，匹配成功，否则匹配失败
		printf("Matched!\n");
	}
	else {
		printf("Not Matched!\n");
	}
	printf("\n");
}

int main() {
	SqStack S;
	if (InitStack(&S)) { //构造空栈
		printf("Initialize stack failed.\n");
	}
	else {
		printf("测试(正确)用例一： {{{[[[((()))]]]}}}\n");
		Matching(&S, "{{{[[[((()))]]]}}}");

		printf("测试(正确)用例二： {[()]}\n");
		Matching(&S, "{[()]}");

		printf("测试(错误)用例一： {{{[[[((()))]]]}}}}\n");
		Matching(&S, "{{{[[[((()))]]]}}}}");

		printf("测试(错误)用例二： {)]]]}}}}\n");
		Matching(&S, "{)]]]}}}}");
	};
	
	return 0;
}