#pragma once

#include <stdlib.h>
#include "Status.h"

/*这些和函数同名首字母小写的宏用于
在简化函数调用过程的同时
不改变函数本身的返回值与形参类型*/
/*与下面以globalVariable开头的变量配合使用*/
#define isStackEmpty(S) (IsStackEmpty((S),&globalVariable_isStackEmpty),globalVariable_isStackEmpty)
#define getTop(S) (GetTop(S,&globalVariable_getTop),globalVariable_getTop)
#define pop(S) (Pop(S,&globalVariable_pop),globalVariable_pop)
#define sizeOfStack(S) (SizeOfStack(S,&globalVariable_sizeOfStack),globalVariable_sizeOfStack)

typedef int Elemtype;
/*自定义bool类型*/
typedef enum _bool { false, true }bool;

typedef struct _Node {
	Elemtype data;
	struct _Node* next;
} Node, *Stack;

/*这些以globalVariable开头的变量
与上面
和函数同名首字母小写的宏
配合使用*/
bool globalVariable_isStackEmpty;
Elemtype globalVariable_getTop;
Elemtype globalVariable_pop;
int globalVariable_sizeOfStack;

Status InitStack(Stack *);
Status Push(Stack, Elemtype);
Status Pop(Stack, Elemtype *);
/*Traverse : 从栈顶向栈底遍历*/
Status Traverse(const Stack);
Status DeleteStack(Stack *);
Status EmptyStack(Stack);
Status IsStackEmpty(Stack, bool *);
Status SizeOfStack(const Stack, int *);
Status GetTop(const Stack, Elemtype *);