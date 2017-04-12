#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>//�������ֵ
//��׺���ʽ��ֵ  
//��תΪ��׺���ʽ����ֵ��Ϊ�������ʹ��ջ��ѭ��洢�ṹʵ��  

//ջ��˳��洢�ṹ����һά����ʵ��  
#define OK 1  
#define ERROR -1  
#define TRUE 1  
#define FALSE 0  
#define MAXSIZE 10  
typedef int Status;  
typedef char ElemType;  
typedef struct 
{  
	ElemType data[MAXSIZE];  
	int top;//ջ��ָ��  
}Stack;  

Status InitStack(Stack *S)
{  //��ʼ��
	int i;  
	for(i=0;i<MAXSIZE;i++)  
    {
		S->data[i]=NULL;  //��ʼ��Ϊ��
    }
	S->top=-1;  
	return OK;  
}  
 
Status CreateStack(Stack *S,int n)
{  //����һ������Ϊn�Ķ�ջ 
	if(n>MAXSIZE || n<1)
	{  
		printf("���볤������\n");  
		return ERROR;  
	}  
	srand(time(0));  
	int i;  
	for(i=0;i<n;i++)
	{  
		S->data[i]=rand()%100+1;//�������Ԫ��  
	}  
	S->top=n-1;  
	return OK;  
}  

Status push(Stack *S,ElemType e)
{//ѹջ����  
	if(MAXSIZE-1==S->top)//�ж��Ƿ�ջ��
	{  
		printf("ջ����\n");  
		return ERROR;  
	}  
	//ջ��ָ���Ԫ����ֵ  
	++(S->top);  
	S->data[S->top]=e;  
	return OK;  
}  

Status pop(Stack *S,ElemType *e)
{//��ջ  
	//��ջ��Ԫ�س�ջ������e  
	if(-1==S->top)
	{  
		printf("ջΪ�գ�\n");  
		return ERROR;  
	}  
	*e=S->data[S->top];  
	--(S->top);  
	return OK;  
}  

int MidToFinal(char *mid,char *final)
{//��׺���ʽת��׺���ʽ   
	//��׺���ʽΪmiddle��Ҫת���ɺ�׺���ʽ����last  
	//�½�һ��ջ�����洢����  
	char e;  
	Stack S;  
	if(OK!=InitStack(&S))
	{  
		printf("��ʼ��ջʧ�ܣ�\n");  
	}  
	//����ת�����ַ���*midδ��ֹʱ��ѭ������  
	while(*mid)
	{//��������֣���ֱ�����  
		if(*mid>='0' && *mid<='9')
		{  
			*(final++)=*(mid++);  
			continue;  
		}
		else if(*mid=='+' || *mid=='-' || *mid=='*' || *mid=='/' || *mid=='(' || *mid==')')
		{//������ǺϷ��������,�Ƚ�֮ǰ�Ƿ��и������ȼ��ķ���  
			if(S.top==-1 || '('==*mid)
			{  
				//������ջΪ�ջ�����������ʱ��������ջ  
				push(&S,*(mid++));  
				continue;  
			}  
			if(')'==*mid)
			{  
				//����������ʱ��ջ��Ԫ�����γ�ջ��ֱ��������һ��������ʱ����  
				pop(&S,&e);  
				*(final++)=e;  
				while(pop(&S,&e) && e!='(')
				{  
					*(final++)=e;  
				}  
				// printf("%c\n",e);  
				mid++;  
				continue;  
			}  
			//�����Ĵ���Ҫȡ����ʱ��ջ��Ԫ�أ��뵱ǰ����ķ���*mid��Ƚϣ�
			//����ʱջ��Ԫ�����ȼ����ڵ���������ŵ����ȼ�ʱ����ջ��
			//���������ջ���Ѿ�����һ�����ǵðѵ�����Ԫ��Ҳ��ջ��  
			pop(&S,&e);  
			if('+'==*mid || '-'==*mid)
			{  
				if(e=='(')
				{  
					push(&S,'(');  
					push(&S,*(mid++));  
					continue;  
				}
				else
				{  
					*(final++)=e;  
					push(&S,*(mid++));  
					continue;  
				}  
			}
			else if('*'==*mid || '/'==*mid)
			{  
				if('*'==e || '/'==e)
				{  
					*(final++)=e;  
					push(&S,*(mid++));  
					continue;  
				}
				else
				{  
					push(&S,e);  
					push(&S,*(mid++));  
					continue;  
				}  
			}  

		}
		else
		{  
			printf("������ַ����Ϸ���%c\n",*mid);  
			return ERROR;  
		}  
	}  
	//����ת�����ַ��Ѿ�����ʱ������ջ���ٻ���һ��Ԫ�أ���׺���ʽ���ص㣺���ֽ�β����׺���ʽ�Է��Ž�β������ջ�е�Ԫ�����γ�ջ  
	while(S.top!=-1)
	{  
		pop(&S,&e);  
		*(final++)=e;  
	}  
	//�ַ����Ľ�������  
	*final='\0';  
}  

int main()  
{  
	char data[]="3+(5*6-7/1)*9";  
	char final[]="";  
	MidToFinal(data,final);  
	printf("%s\n",final);  
	return 0;  
}  