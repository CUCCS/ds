#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������ 
#define STACKINCREMENT 2 // �洢�ռ��������

typedef char SElemType;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status;

typedef enum{
	FALSE,
	TRUE
}bool;

typedef struct SqStack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S){ 
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)
		return OVERFLOW; 
	S->top = (*S).base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status DestroyStack(SqStack *S){
	free((*S).base);
	(*S).base = NULL;
	(*S).top = NULL;
	(*S).stacksize = 0;
	return OK;
}

Status ClearStack(SqStack *S){ 
	(*S).top = (*S).base;
	return OK;
}

Status StackEmpty(SqStack *S){
	if ((*S).top == (*S).base)
		return TRUE;
	else
		return FALSE;
}// ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE 

int StackLength(SqStack S){
	return S.top - S.base;
}// ����S��Ԫ�ظ�������ջ�ĳ���

Status GetTop(SqStack *S, SElemType *e){
	if ((*S).top>(*S).base){
		*e = *((*S).top - 1);
		return OK;
	}
	else
		return ERROR;
}// ��ջ���գ�����e����S��ջ��Ԫ��

Status Push(SqStack *S, SElemType e){
	if ((*S).top - (*S).base >= (*S).stacksize){//ջ��
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base){
			exit(OVERFLOW);
		}//����ʧ��
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return OK;
}// ����Ԫ��eΪ�µ�ջ��Ԫ��

Status Pop(SqStack *S, SElemType *e){
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *--(*S).top;
	return OK;
} // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR 

Status StackTraverse(SqStack S, Status(*visit)(SElemType)){
	while (S.top>S.base)
		visit(*S.base++);
	printf("\n");
	return OK;
}// ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()


Status visit(SElemType c){
	printf("%c ", c);
	return OK;
}
