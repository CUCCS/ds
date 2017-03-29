#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量
typedef char SElemType;
typedef enum {
	OK,
	OVERFLOW,
	ERROR
}Status;
enum bool{ false, true };
typedef struct _SqStack{
	SElemType   *base;
	//造之前和销毁之后，base的值为NULL
	SElemType *top; //栈顶指针
	int stracksize;
}SqStack;
Status InitStack(SqStack *S){
	//构建一个空栈
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return
		OVERFLOW;
	S->top = S->base;
	S->stracksize = STACK_INIT_SIZE;
	return  OK;
}//InitStack
Status Push(SqStack *S, SElemType e){
	//插入元素e为新的栈顶元素
	if (S->top - S->base >= S->stracksize){//栈满，追加存储空间
		S->base = (SElemType *)realloc(S->base, (S->stracksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)
			return
			OVERFLOW;//存储分配失败
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
Status ClearStack(SqStack *S)
{ 
 S->top = S->base; 
 return OK; 
} 
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//为空
	else
		return false;//不为空
}
Status DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}
void DestroyStack(SqStack *stack)//销毁已经存在的栈3
{
   free(stack->base);
    stack->top=stack->base;
}
void LineEdit(SqStack *S) {
	SElemType *p,ch,c;
	InitStack(S);
	ch = getchar();
	while(ch != EOF) {
		while(ch!=EOF&&ch!='\n') {
			switch(ch) {
			case '#':Pop(S,&c);break;//仅当栈非空时退栈
			case '@':ClearStack(S);break;//重置S为空栈
			default:Push(S,ch);break;//有效字符进栈，未考虑栈满情况
			}
			ch = getchar();//从终端接收下一个字符
		}
		p = S->base;
		while(p!=S->top) {
			printf("%c",*p);
			++p;
		}
		//将从栈底到栈顶的站内字符传送至调用过程的数据区
		ClearStack(S);//重置S为空栈
		if(ch!=EOF) ch = getchar();
	}
DestoryStack(&S);
}

int main(int argc, char *argv[])
{
	SqStack S;
printf("输入任意字符，'#'为删除字符，'@'可以删除整行\n");
    LineEdit(&S);
   return 0;

}
