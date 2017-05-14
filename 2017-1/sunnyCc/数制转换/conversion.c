#include "conversion.h"
#include <stdlib.h>
#define MAX 1000
//初始化顺序栈  
int InitStack(SqStack *S) {
	S->base = (int*)malloc(MAX);
	if (!S->base) {
		return 0;//存储空间分配失败   
	}
	S->top = S->base;
	S->stacksize = MAX;
	return 1;
};

//判断栈是否为空  
int IsEmpty(SqStack *S) {
	if (S->base == S->top) {
		return 1;//栈空   
	}
	else {
		return 0;//栈非空   
	}
};

//入栈  
int Push(SqStack *S, int e) {
	if (S->top - S->base == S->stacksize) {
		return 0;//栈满   
	}
	*S->top++ = e;  //插入e为新的栈顶元素
	return 1;
};

//出栈   
int Pop(SqStack *S, int *e) {
	if (S->top == S->base) {
		return 0;//栈空   
				 //printf("栈空\n");  
	}
	*e = *--S->top;//删除S的栈顶元素，弹出原顶部，再把指针指向e  
	return 1;
	//printf("%d",e);  
};
//销毁栈
int DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	printf("释放栈空间\n");
	return 1;
}
//数制转换  
void conversion(SqStack *S, int n, int m) {
	//n表示待转换的数，m表示输出的数的进制   
	InitStack(S);
	while (n) {
		Push(S, n%m); //进站 
		n = n / m;
	}

	while (!IsEmpty(S)) {
		int e;
		Pop(S, &e);  //出栈
		printf("%d", e);
	}
	//如果栈为空，释放栈空间
	if (NULL != S)
	{
		free(S);
		S = NULL;
	}
};
