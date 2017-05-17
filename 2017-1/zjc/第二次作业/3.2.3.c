#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������
typedef char SElemType;
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
Status ClearStack(SqStack *S)
{ 
 S->top = S->base; 
 return OK; 
} 
enum bool StackEmpty(SqStack *S){

	if (S->top == S->base)
		return true;//Ϊ��
	else
		return false;//��Ϊ��
}
Status DestoryStack(SqStack *S) {
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}
void DestroyStack(SqStack *stack)//�����Ѿ����ڵ�ջ3
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
			case '#':Pop(S,&c);break;//����ջ�ǿ�ʱ��ջ
			case '@':ClearStack(S);break;//����SΪ��ջ
			default:Push(S,ch);break;//��Ч�ַ���ջ��δ����ջ�����
			}
			ch = getchar();//���ն˽�����һ���ַ�
		}
		p = S->base;
		while(p!=S->top) {
			printf("%c",*p);
			++p;
		}
		//����ջ�׵�ջ����վ���ַ����������ù��̵�������
		ClearStack(S);//����SΪ��ջ
		if(ch!=EOF) ch = getchar();
	}
DestoryStack(&S);
}

int main(int argc, char *argv[])
{
	SqStack S;
printf("���������ַ���'#'Ϊɾ���ַ���'@'����ɾ������\n");
    LineEdit(&S);
   return 0;

}
