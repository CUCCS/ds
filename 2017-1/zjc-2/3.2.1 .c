#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef int SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
enum bool{ false, true };
typedef struct _SqStack{
	SElemType   *base;
	//��֮ǰ������֮��base��ֵΪNULL
	SElemType *top; //ջ��ָ��
	int stracksize;
}SqStack;
Status InitStack(SqStack *S){
	//����һ����ջ
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e){
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S->top - S->base >= S->stracksize){//ջ����׷�Ӵ洢�ռ�
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//�洢����ʧ��
		S->top = S->base + S->stracksize;
		S->stracksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//Push
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == S->base)
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}
void conversation(SqStack *S, int input, int d){
	SElemType e;
	InitStack(S);
	while (input)
	{
		Push(S, input%d);
		input = input / d;
	}
	while (!StackEmpty(S)){
		Pop(S, &e);
		printf("%d", e);
	}
}
void DestroyStack(SqStack *stack)//�����Ѿ����ڵ�ջ3
{
   free(stack->base);
    stack->top=stack->base;
}
int main(int argc, char *argv[])
{
	SqStack S;
	InitStack(&S);
	srand((unsigned)time(NULL));
	int input, num;
	input = rand();
	printf("��Ҫת��������Ϊ��\n%d\n", input);
	num = rand() % 11;
	printf("ת��Ϊ%d����Ϊ��\n", num);
	conversation(&S, input, num);
}

