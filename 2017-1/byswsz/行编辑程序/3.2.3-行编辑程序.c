#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100 //存储空间初始分配量

#define STACKINCREMENT 10 //存储空间分配增量
typedef int Status;
typedef char SElemType;
//对顺序栈进行定义
typedef struct Sq_Stack {

	SElemType *base;

	SElemType *top;

	int stacksize;
} SqStack;
//申明
typedef enum {

	OK,
	ERROR,
	OVERFLOW,
    TRUE,
	FALSE ,
} Status;




/*#define OVERFLOW 
#define OK 
#define 
#define  
#define ERROR*/ 
Status InitStack(SqStack *pS);//构造空栈
SElemType Pop(SqStack *pS, SElemType *pe);//返回栈顶元素；
Status Push(SqStack *pS, SElemType e);//插入新元素；
Status StackEmpty(SqStack *pS);//遇上@之后清空栈之后判断是否清空完
Status DestroyStack(SqStack *pS);//遇上#，销毁栈；

Status InitStack(SqStack *pS) {

	(*pS).base = (SElemType *)malloc(SIZE * sizeof(SElemType));

	if (!(*pS).base) 
		exit (OVERFLOW); //存储分配失败

	(*pS).top = (*pS).base;

	(*pS).stacksize = SIZE;

	return OK;

}



SElemType Pop(SqStack *pS, SElemType *pe) {

	if ((*pS).top == (*pS).base) return ERROR;
	
	pe = --(*pS).top;

	return *pe;
}



Status Push(SqStack *pS, SElemType e) {

	if ((*pS).top - (*pS).base >= (*pS).stacksize) {

		(*pS).base = (SElemType *)realloc((*pS).base, ((*pS).stacksize + STACKINCREMENT) * sizeof(SElemType));

		if (!(*pS).base) exit (OVERFLOW);

		(*pS).top = (*pS).base + (*pS).stacksize;

		(*pS).stacksize += STACKINCREMENT;

	}

	*(*pS).top++ = e;

	return OK;

}



Status DestroyStack(SqStack *pS) {

	(*pS).top = NULL;

	(*pS).stacksize = 0;

	free((*pS).base);

	return OK;

}



Status StackEmpty(SqStack *pS) {

	if ((*pS).base == (*pS).top) return TRUE;

	else return FALSE;

}
//
void Lineedit() {

	int i = 0;  

	char ch[200] = "whli##ilr#e(s#*s)\noutchar@\nputchar(*s=#++)\0";
	//拟输入
	SqStack S;

	SElemType e = ch[i];

	InitStack(&S); //构造空栈

	while (ch[i] != '\0') {

		e = ch[i];

		switch (ch[i]) {

		case '#':

			Pop(&S, &e);               break;

		case '@': {

			if (StackEmpty(&S)) break;

			while (e != '\n') { Pop(&S, &e); };

			if (StackEmpty(&S) || e == '\n') { Push(&S, e); break; }     break;

		}//重置为空栈

		default:

			Push(&S, ch[i]);             break;//有效字符进栈

		};

		i++;

		//将从栈底到栈顶的栈内字符传送至调用过程的数据区

	

	};

	char pa[100];

	int j = 0;

	while (!StackEmpty(&S)) {

		pa[j] = Pop(&S, &e);

		j++;

	};//排除#和@情况之后对其进行输入到缓冲区

	do {

		j--;

		printf("%c", pa[j]);

	} while (j >= 0);

	DestroyStack(&S);

}//将合格的字符进行输出

int main() {

	Lineedit();

	return OK;

}




