//˳��ջʵ����׺���ʽת��׺���ʽ��������ʽ��ֵ
//������ʽ �Լ�������
//�ɼ���+-*/���������ŵı��ʽ
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 50//�����ַ�������
#define OK 1  
#define ERROR -1  
#define TRUE 1  
#define FALSE 0  
#define MAXSIZE 50  //ջ����
typedef int Status;
typedef char ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int top;//ջ��ָ��  
}Stack;

// ��ʼ��ջ  
Status InitStack(Stack *S) {
	
	int i;
	for (i = 0; i<MAXSIZE; i++)
		S->data[i] = NULL;
	S->top = -1;
	return OK;
}


//ѹջ 
Status Push(Stack *S, ElemType e) {
	if (MAXSIZE - 1 == S->top)
	{
		
		return ERROR;
	}
	
	++(S->top);
	S->data[S->top] = e;
	return OK;
}

//��ջ  
Status Pop(Stack *S, ElemType *e) {
	//��ջ��Ԫ�س�ջ������e  
	if (-1 == S->top)
	{
		return ERROR;
	}
	*e = S->data[S->top];
	--(S->top);
	return OK;
}

Status Transform(char *mid,char *final)
{
	//��׺���ʽΪmid��ת���ɵĺ�׺���ʽ����final 
	//�½�һ��ջ�����洢�����
	char e;
	Stack S;
	if (OK != InitStack(&S)) 
	{
		return ERROR;
	}
	//���ַ���*midδ��ֹʱ��ѭ��  
	while (*mid) 
	{
		//��������֣���ֱ�����  
		if (*mid >= '0' && *mid <= '9') 
		{
			*(final++) = *(mid++);
			continue;
		}
		else if (*mid == '+' || *mid == '-' || *mid == '*' || *mid == '/' || *mid == '(' || *mid == ')') 
		{
			//�Ƚ�֮ǰ�Ƿ��и������ȼ��ķ���  
			if (S.top == -1 || '(' == *mid) 
			{
				//��ջΪ�ջ�����������ʱ��ֱ����ջ  
				Push(&S, *(mid++));
				continue;
			}
			if (')' == *mid) 
			{
				//����������ʱ��ջ��Ԫ�����γ�ջ��ֱ��������һ��������ʱ����  
				Pop(&S, &e);
				*(final++) = e;
				while (Pop(&S, &e) && e != '(') 
				{
					*(final++) = e;
				}  
				mid++;
				continue;
			}
			//������ȡ����ʱ��ջ��Ԫ�أ��뵱ǰ����ķ���*mid��Ƚϣ���ջ��Ԫ�����ȼ����ڵ���������ŵ����ȼ�ʱ����ջ����*mid��ջ��
			//���������ջ 
			Pop(&S, &e);
			if ('+' == *mid || '-' == *mid) 
			{
				if (e == '(') 
				{
					Push(&S, '(');
					Push(&S, *(mid++));
					continue;
				}
				else 
				{
					*(final++) = e;
					Push(&S, *(mid++));
					continue;
				}
			}
			else if ('*' == *mid || '/' == *mid) 
			{
				if ('*' == e || '/' == e) 
				{
					*(final++) = e;
					Push(&S, *(mid++));
					continue;
				}
				else 
				{
					Push(&S, e);
					Push(&S, *(mid++));
					continue;
				}
			}

		}
		else {
			//������ַ����Ϸ�
			return ERROR;

		}
	}
	//����ת�����ַ��Ѿ�����ʱ������ջӦ���ٻ���һ��Ԫ�أ���ջ�е�Ԫ�����γ�ջ  
	while (S.top != -1) 
	{
		Pop(&S, &e);
		*(final++) = e;
	}
	//final�Ľ�����
	*final = '\0';
}

//�����׺���ʽ��������ֱ�ӽ�ջ��������������������ֳ�ջ����������ջ������ջ��ֻʣ���Ľ��
int Cul(char *a,Stack s)
{
	int e1=0, e2=0,e=0;

	
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] >= '0'&&a[i] <= '9')
			Push(&s,(int)( a[i]-'0'));
		
		else if (a[i] == '+')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			 e = e1 + e2 ;
			Push(&s, e);
		}
		else if (a[i] == '-')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
		    e = e1 - e2;
			Push(&s, e);
		}
		else if (a[i] == '*')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			e = e1 * e2;
			Push(&s, e);
		}
		else if (a[i] == '/')
		{
			Pop(&s, &e2);
			Pop(&s, &e1);
			e = e1 / e2;
			Push(&s, e);
		}
	}
	Pop(&s, &e);
	
	return (int)(e);
				
}


void main()
{
	Stack s;
	InitStack(&s);
	char middle[N];
	char final[N];
	int r;
	printf("Please input an expression:\n");
	gets(middle);
	Transform(middle,final);
	printf("After:\n");
	puts(final);
	r = Cul(final,s);
	printf("The result is %d",r);

}
