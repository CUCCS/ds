#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_INIT_SIZE 100 //�洢�ռ��ʼ������
#define STACKINCREMENT 10 //�洢�ռ��������
#define DEBUG 1

typedef enum  
{ ERROR,
  OVERFLOW,
  OK}
Status;

typedef char SElemType;  
//��˳��ջ���ж���
typedef struct  
{  
    SElemType *base;  
    SElemType *top;  
    int stacksize;  
}SqStack;  

Status  InitStack (SqStack* pS);//����һ����ջ
Status Push (SqStack *S , SElemType e);
int StackEmpty (SqStack *S);
Status Pop (SqStack S , int *e);
void Match(SqStack *S , char *p);


//����һ����ջ

Status  InitStack (SqStack* pS)    
{
	pS->base=(SElemType *)malloc(STACK_INIT_SIZE * 
		sizeof(SElemType));

	if(! pS->base) 
	{
		return OVERFLOW;
	}

	pS->top =(*pS).base;
	pS->stacksize = STACK_INIT_SIZE;

	return OK;
}
//��һ���µ�Ԫ����ӵ�ջ��
Status Push(SqStack *S,SElemType e)
{
	if(S->top-S->base>=S->stacksize)
	{
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S->base)
			return OVERFLOW;
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return OK;

}

int StackEmpty(SqStack *S)
{
	if (S)
		return S->base==S->top;
	return 1;
}
//ɾ��ջ����Ԫ��,����e������ֵ
Status Pop(SqStack *S,int *e)
{
	if(StackEmpty(S))
	{
		return ERROR;
	}
	*e=*--S->top;
	return OK;
}
//�Զ��庯���������Ž����ж���
void Match(SqStack *S , char *p)
{
	    int i=0;
		int bracket;
		InitStack(S); //����һ����ջ
		while(p[i] != '\0')  
		{  
			DEBUG && printf("��ǰ���� '%c' ", p[i]);
			switch(p[i])  
			{  
			case '(':
				DEBUG && printf(" '%c' ��ջ \n", p[i]);
				Push(S,p[i]); //��ջʱ���һ���µ�Ԫ��
				break; 

			case ')':  
				DEBUG && printf("  ��ջ  ");
                Pop(S,&bracket);//��ջʱɾ��ջ��Ԫ��
				printf("�����  '%c' \n",bracket);
					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("ƥ��ʧ��\n");
						return;
					}//��ջ��Ԫ�ز������Ӧ
				
					break;
			case '[':  
				DEBUG && printf(" '%c' ��ջ \n", p[i]);
				Push(S,p[i]); 
				break; 

			case ']':  
				DEBUG && printf("  ��ջ  ");
                Pop(S,&bracket);
				printf("�����  '%c' \n",bracket);

					if (bracket != (p[i] == ')' ? '(' : p[i] == ']' ? '[' : '{')) 
					{
						DEBUG && printf("ƥ��ʧ��\n");
						return;
					}
				
					break;
			default:  
				break;  
				}   
			i++;//ѭ��ִ�У�������ʱ
			}   //while ѭ��������
		StackEmpty(S);//�ж��Ƿ�ѭ����
		DEBUG && printf("ƥ��ɹ� \n\n");//��debug�ɹ���OK����������������


}


int main()
{
	char str1[10]="([()])";  
	char str2[10]="[([][])]";
	char str3[10]="[((]])";
    SqStack S; 

	printf("��ʼƥ���һ�� :");
	puts(str1);
    Match(&S,str1);  

	printf("��ʼƥ��ڶ��� :");
	puts(str2);
    Match(&S,str2);

	printf("��ʼƥ������� :");
	puts(str3);
    Match(&S,str3);
    return 0;  
}//�����˵һ��mmp������ȥ��һ���������������

