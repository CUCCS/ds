#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ����
#define STACKINCREMENT 10  //�洢�ռ��������
#define OVERFLOW -2
  

typedef struct
{
	char *base;    //��ջ����֮ǰ������֮��base��ֵΪNULL
	char *top;    //ջ��ָ��
	char StackSize;        //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;


//����һ����ջ
int InitStack (SqStack *S)
{
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));    //��������ռ�
	if(!S->base)            //�ж��Ƿ����ɹ�
		return OVERFLOW;
	S->top = S->base;        //ָ��ջ��
	S->StackSize = STACKINCREMENT;    //��ʼ������󳤶�
	return 0;
}


//��SΪ��ջ����OK ���򷵻�ERROR
int StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 1;
	else
		return 0;
}


//��ջ��������e����ջ�����ݲ�����OK���򷵻�ERROR
int GetTop(SqStack *S, char *e)
{
    if(S->top == S->base)
		return 1;
	*e = *(S->top - 1);
	return 0;
}

//�����µ�ջ������
int Push(SqStack *S, int e)
{
	if(S->top - S->base >=S->StackSize)    //�ռ䲻��
	{
		S->base = (char *)realloc(S->base, (S->StackSize + STACKINCREMENT) * sizeof(char));
		if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->StackSize;
		S->StackSize += STACKINCREMENT;
	}
	S->top++;
	*S->top = e;
	return 0;
}

//��ջ���� ��ɾ��ջ�����ݲ���e�����ҷ���OK ���򷵻�ERROR
int Pop(SqStack *S,char *e)
{
	if(StackEmpty(*S))    //��ջ
		return 1;
	*e = *--S->top;
	return 0;
}


void Matching(char e[])
{
	unsigned int i = 0;
	int state = 1;
	char z;
    SqStack S;
	
	while((int)(i <= strlen(e)) && state && e[i] != '\0')    //�������� �������鳤�Ȼ�stateΪ0���ַ�������
    {
        switch(e[i])
        {
        case '(':
        case '{':
            Push(&S,e[i]);    //����({���ջ
            i++;
            break;
        case ')':
            GetTop(&S,&z);
            if(!StackEmpty(S) && z == '(')    //����)���ж�ջ���ǲ���(���ǵĻ���ջ��������ƥ��
            {
                Pop(&S,&z);
                i++;
            }
            else
                state = 0;
            break;
        case '}':
            GetTop(&S,&z);
            if(!StackEmpty(S) && z == '{')//����}���ж�ջ���ǲ���{�������ջ��������ƥ��
            {
                Pop(&S,&z);
                i++;
            }
            else
                state = 0;
            break;
        }
    }
    if(StackEmpty(S) && state)    //��ջ��state��Ϊ0��ȫ��ƥ��
        printf("����ȫ��ƥ��\n");
    else
        printf("���Ų�ƥ��\n");
}

int main()
{   
	char test[100];
	SqStack S;
	InitStack(&S);
	printf("����������:");
    scanf_s("%s",test);
    Matching(test);

	return 0;
}