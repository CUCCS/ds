//�㷨3.2.2
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType;

typedef struct {
	SElemType *elem;
	int length;
	int listsize;
} SqList;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack *S)
{
	S->base = (SElemType*)malloc(100 * sizeof(SElemType));
	if (!S->base)exit(OVERFLOW);//�������ʧ��
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == S.base)
		return ERROR;
	e = S.top - 1;
	return OK;
}

Status Push(SqStack *S, SElemType e)
{
	if (S->top - S->base >= S->stacksize)//ջ����׷�Ӵ���ռ�
	{
		S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S->base)exit(OVERFLOW);//�������ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}//push

Status Pop(SqStack *S, SElemType *e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S->top == S->base)
		return ERROR;
	e = --S->top;
	return OK;
}

bool StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return true;
	else
		return false;
}//Ϊ��elsereturn false;//��Ϊ��} 

Status MatchCheck(SqList exp)
/* ˳���exp��ʾ���ʽ��                        */
/* ��exp�е�������ԣ��򷵻�TRUE�����򷵻�FALSE */
{
	SqStack s;
	char e;
	//�����������
	for (int i = 0; i<exp.listsize; i++)
	{
		if (exp.elem[i] == '(' || exp.elem[i] == '{' || exp.elem[i] == '[')//���������ţ���ֱ����ջ
		{
			Push(s, exp.elem[i]);
		}
		else if (exp.elem[i] == ')')//������Բ���ţ�����ƥ��ջ������
		{
			if (GetTop(s, e))
			{
				if (e == '(')//ƥ��ɹ�����Բ���ų�ջ
				{
					Pop(s, e);
				}
				else//ƥ�䲻�ɹ�����Բ������ջ
				{
					Push(s, exp.elem[i]);
				}
			}
			else//ջΪ�գ�����������ջ
			{
				Push(s, exp.elem[i]);
			}
		}
		else if (exp.elem[i] == '}')//�����һ����ţ�����ƥ��ջ������
		{
			if (GetTop(s, e))
			{
				if (e == '{')//ƥ��ɹ��������ų�ջ
				{
					Pop(s, e);
				}
				else//ƥ�䲻�ɹ����һ�������ջ
				{
					Push(s, exp.elem[i]);
				}
			}
			else
			{
				Push(s, exp.elem[i]);
			}
		}
		else if (exp.elem[i] == ']')//�����ҷ����ţ�����ƥ��ջ������
		{
			if (GetTop(s, e))
			{
				if (e == '[')//ƥ��ɹ��������ų�ջ
				{
					Pop(s, e);
				}
				else//ƥ�䲻�ɹ����ҷ�������ջ
				{
					Push(s, exp.elem[i]);
				}
			}
			else
			{
				Push(s, exp.elem[i]);
			}
		}
	}
	if (StackEmpty(s))//����������ƥ��ɹ�ʱ��ջӦΪ��
	{
		printf("ƥ�䣬Ϊ��ȷ�ĸ�ʽ");
		//return OK;
	}
	else             //ջ����һ�����ţ�û�����
	{
		printf("��ƥ�䣬Ϊ����ĸ�ʽ");
		//return ERROR;
	}
}

int main()
{
	Status MatchCheck();
	return OK;
}


