#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCRESE 10
typedef char SElemType;
typedef struct
{
	SElemType*base;
	SElemType*top;
	int stacksize;
}Sqstack;
typedef enum
{
	error, ok
}Status;
//����ջ
Status Initstack(Sqstack*S)
{
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S->base)
		return error;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return ok;
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(Sqstack *S)
{
	if (S->top == S->base)
		return ok;
	else return error;
}
//����ջ��Ԫ��
Status Push(Sqstack*S, SElemType e)
{
	if (S->top - S->base == S->stacksize)
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCRESE) * sizeof(SElemType));
		S->top = S->base + S->stacksize;
		S->base = S->base + STACKINCRESE;
	}
	*S->top++ = e;
	return ok;
}
//��ջ
Status Pop(Sqstack *S, SElemType*e)
{
	if (S->top == S->base)
		return error;
	*e = *--S->top;
	return ok;
}
// ջ���
Status qingkong (Sqstack*S)
{
	SElemType*e=(SElemType*)malloc(sizeof(SElemType));
	if (StackEmpty(S))
		return ok;
	else
	{
		while (*--S->top != ' ')
			Pop(S, e);
	}
		
}
//����ջ
Status DestroyStack(Sqstack*S)
{
	free(S->base);
	return ok;
}
void LineEdit(Sqstack *S)
{
	int i = 0;

	SElemType  *c = (SElemType*)malloc(sizeof(SElemType));
	SElemType ch;
	char v[50];
	ch = getchar();
	while (ch!=EOF)
	{
		while (ch!= '\n')
		{
			switch (ch)
			{
			case '#': Pop(S, c); break;//��ջ
			case '@':qingkong(S); break;//���ջ
			default:Push(S, ch);//��Ч�ַ���ջ
			}
			ch = getchar();
		}
while (!StackEmpty(S))
	{
		Pop(S, c);
		printf("%c", *c);
	}
qingkong(S);
if (ch != EOF)
ch = getchar();

	}	
	DestroyStack(S);
}
int main()
{
	printf("#ɾȥǰһ���ַ�\n@ɾȥǰһ���ַ�\n");
	Sqstack S;
	Initstack(&S);
	LineEdit(&S);
}