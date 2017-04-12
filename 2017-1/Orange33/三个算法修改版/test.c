#include <stdio.h>
#include <malloc.h>

#define STACK_INIT_SIZE 100  //�洢�ռ��ʼ����
#define STACKINCREMENT 10  //�洢�ռ��������
#define OVERFLOW -2

typedef struct SqStack{  
	int *base; //ջ��  
	int *top;  //ջ��  
	int StackSize;   //ջ��ǰ�Ĵ洢�ռ�  
}SqStack;  

//��ʼ����ջ
void InitStack(SqStack *S)  
{
	S->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int)); //��������ռ� 
	S->StackSize=STACK_INIT_SIZE;   //��ʼ������󳤶�
	S->top=S->base;  //ָ��ջ��
};  
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)  
{  
	if(S.base==S.top) 
	{
		return 1;  
	}
	else  
	{
		return 0;  
	}
};

//ѹջ
void push(SqStack *S,int e)  
{  
	if(S->top-S->base>=S->StackSize)  //�ռ䲻��
	{
		S->base=(int *)realloc(S->base,(S->StackSize+STACKINCREMENT)*sizeof(int));  
		S->top=S->base+S->StackSize;  
		S->StackSize+=STACKINCREMENT;
	}  
	*(S->top)=e;  
	S->top++;        
};

//��ջ
void pop(SqStack *S,int *e)  
{  
	if(S->base!=S->top)  
	{
		S->top--;  
		*e=*S->top;
	}  
};  


int main()  
{

	char test[100];
	char *p;
	int e; 
	SqStack S;

	InitStack(&S);  //��ʼ����ջ  
	p=test; //ָ��pָ���ַ�����ch

	printf("����������:"); 
	gets(test);

	while(*p)
	{   
		switch (*p)  
		{  
		case '{':  
		case '[':  
		case '(': push(&S,*p++);break;//ֻҪ�������ž���ջ  
		case '}':  
		case ']':  
		case ')':pop(&S,&e);  //ֻҪ�������ž���ջ�е�������e���
			if ((e=='{' && *p=='}') ||(e=='[' && *p==']') || (e=='(' && *p==')'))  
			{
				p++;  
			}
			else  
			{
				printf("���Ų�ƥ��!");
				return OVERFLOW;
			}
			break;  
		default:
			p++;
		}  
	}  
	if (StackEmpty(S))  
	{
		printf("����ƥ��ɹ�");
	}//���ջ�Ƿ�Ϊ��,��Ϊ��������������Ŷ�ƥ��ɹ�
	else  
	{
		printf("ȱ�������ţ�"); 
	}//����ջ����ʣ���������,ƥ��ʧ��
	printf("\n");  
}

