#include <stdio.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ����
#define STACKINCREMENT 10//�洢�ռ��������
#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef char SElemType;

typedef struct {
	SElemType *base; //��ջ����֮ǰ������֮��base��ֵΪNULL
	SElemType *top;//ջ��ָ��
	int stacksize; //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//����һ����ջ
int InitStack(SqStack *S)
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));//��������ռ�
	if(!S->base)
	{
		return OVERFLOW; 
	}//�ж��Ƿ����ɹ�
	S->top = S->base;              //ָ��ջ��
	S->stacksize = STACK_INIT_SIZE;         //��ʼ������󳤶�
	return 0;
}

//�����µ�ջ������
int Push(SqStack *S,SElemType e)
{
	if((S->top-S->base)>=S->stacksize) 
	{
		S->base = (SElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return 0;
}

//��ջ���� ��ɾ��ջ�����ݲ���e�����ҷ���OK ���򷵻�ERROR
int Pop(SqStack *S,SElemType *e) 
{
	if(S->top  == S->base) 
	{
		return ERROR;
	}
	*e = *--S->top;
	return 0;
}

//���ջ�е�Ԫ��
int ClearStack(SqStack *S)
{
	S->top = S->base;
	return OK;
}

//����ջ
int DestoryStack(SqStack *S)
{
	S->top = S->base;
	free(S->base);
	S->top = NULL;
	S->base = NULL;
	return OK;
}

void LineEdit() 
{
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵���������
	char ch,*temp;
	SqStack S;
	InitStack(&S);       //�����ջS
	printf("������һ��(#:�˸�@:����)(����Ctrl+Z��ʱ�����ѭ��):\n");
	ch = getchar();     //���ն˽��յ�һ���ַ�
	while (ch != EOF)  //EOFΪȫ�Ľ�����)
	{ 
		while (ch != EOF && ch != '\n') 
		{
			switch (ch) 
			{
			case '#': 
				Pop(&S, &ch);    
				break;            // ����ջ�ǿ�ʱ��ջ
			case '@':
				ClearStack(&S);
				break;           // ����SΪ��ջ
			default :
				Push(&S, ch);   
				break;            // ��Ч�ַ���ջ,δ����ջ������
			}
			ch = getchar();  // ���ն˽�����һ���ַ�
		}    

		// ����ջ�׵�ջ����ջ���ַ����������ù��̵���������
		temp=S.base;  
		while(temp!=S.top) 
		{
			printf("%c",*temp);    //����������̨����������������              
			++temp;
		}
		ClearStack(&S);      // ����SΪ��ջ
		printf("\n");
		if (ch != EOF)
		{
			printf("������һ��(#:�˸�@:����)(����Ctrl+Z��ʱ�����ѭ��):\n");
			ch = getchar();
		}
	}
	DestoryStack(&S);
}

int main()
{
	LineEdit();
	return 0;
}
