#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10

typedef char SElemType;

typedef enum{
	ERROR,
	OK,
	OVERFLOW
}Status; 
 typedef struct {
	 int top;
     int stacksize;
	 SElemType stack[STACK_INIT_SIZE];  
	 double data[STACK_INIT_SIZE];
 }SqStack;
 //����stack�ṹ������
 Status InitStack(SqStack *S);
 Status Push(SqStack *S,SElemType e);
 Status Pop(SqStack *S,SElemType *e);
 Status ClearStack(SqStack *S);
 Status DestroyStack(SqStack *S) ;
 Status GetTop(SqStack *S,SElemType );
 Status EmptyStack(SqStack *S);
 int GetLength(SqStack S);
 void TranslateExpress(char s1[],char s2[]);  
 double ComputeExpress(char a[]);  

Status InitStack(SqStack *S)//��ջS��ʼ��Ϊ��ջ  
{  
	int i;
    S->top = 0;  
	for (i = 0;i < STACK_INIT_SIZE;i++)
	{
		S->data[i] = 0;
	}
	return OK;
}  
Status EmptyStack(SqStack *S)//�ж�ջ�Ƿ�Ϊ�գ�ջΪ�շ���1�����򷵻�0  
{  
    if(0 == S->top)  
    {  
        return OK;  
    }  
    else  
    {  
        return ERROR;  
    }  
}  
Status GetTop(SqStack S,SElemType *e)//ȡջ��Ԫ�أ���ջ��Ԫ��ֵ���ظ�e��������1��ʾ�ɹ�������0��ʾʧ��  
{  
    if(S.top <= 0)  
    {  
        printf("ջ�Ѿ��գ�\n");  
        return ERROR;  
    }  
    else  
    {  
        *e = S.stack[S.top-1];//ȡջ��Ԫ��  
        return OK;  
    }  
}  
Status Push(SqStack *S,SElemType e)//��ջ����  
//��Ԫ��e��ջ��Ԫ�ؽ�ջ�ɹ�����1�����򷵻�0  
{  
    if(S->top >= STACK_INIT_SIZE-1)  
    {  
        printf("ջ������������ջ��");  
        return ERROR;  
    }  
    else  
    {  
        S->stack[S->top] = e;  
        S->top++;  
        return OK;  
    }  
}  
Status Pop(SqStack *S,SElemType *e)//��ջ����  
{  
    if(S->top <= 0)  
    {  
        printf("ջ�Ѿ�û��Ԫ�أ����ܳ�ջ��\n");  
        return ERROR;  
    }  
    else  
    {  
        S->top--;  
        *e = S->stack[S->top];  
        return OK;  
    }  
}  
int GetLength(SqStack S)//����ջ����  
{  
    return S.top;  
}  
Status ClearStack(SqStack *S)//���ջ  
{  
    S->top = 0;
	return OK;
}  
void TranslateExpress(SElemType s1[],SElemType s2[])
{
	SqStack s;
	char ch;
	SElemType e;
	int i = 0,j = 0;
	InitStack(&s);
	ch = s1[i];
	i++;
	while( ch != '\0')
	{
		switch(ch){
			case '(' :
				Push(&s,ch);
				break;
			case ')' :
				while(GetTop(s,&e) && e != '(')  
				{  
					Pop(&s,&e);  
					s2[j] = e;  
					j++;  
				}  
				 Pop(&s,&e);//�������ų�ջ  
            break;
			case '+' :
			case '-' :
				while (GetTop(s,&e) && e !='(')
				{
					Pop(&s,&e);  
					s2[j]= e;  
					j++;  
				}  
				Push(&s,ch);//��ǰ�������ջ  
				break;
			case '*' :
			case '/' :
				while(!EmptyStack(&s) && GetTop(s,&e) && e == '/' || e == '*')  
				{  
					Pop(&s,&e);  
					s2[j]= e;  
					j++;  
				}  
				Push(&s,ch);//��ǰ�������ջ  
				break;  
			default :
				while(ch >= '0'&&ch <= '9')  
				{  
					s2[j] = ch;  
					j++;  
					ch = s1[i];  
					i++;
				}  
				i--;
				s2[j] = ' ';  
				j++;  
			}  
		ch = s1[i];
		i++;
		//������һ���ַ���׼������ 
	}  
	 while(!EmptyStack(&s))//��ջ������ʣ����������ջ����������s2��  
    {  
        Pop(&s,&e);  
        s2[j]= e;  
        j++;  
    }  
    s2[j]= '\0';  
}  
double ComputeExpress(SElemType a[])
{
	double val,num1,num2,result;
	int i = 0;
	SqStack s;
	s.top = -1;
	while (a[i] != '\0')
	{
		if (a[i] !=' ' && a[i] >='0' &&a[i] <='9')
		{
			val = 0;
			while (a[i] != ' ')
			{
				val = val*10 + a[i]- '0';
				i ++;
			}
			s.top++;
			s.data[s.top] = val;
		}
		else
		{
			switch(a[i])
			 { 
            case '+':  
                num1 = s.data[s.top];  
                s.top--;  
                num2 = s.data[s.top];  
                s.top--;  
                result = num1+num2;  
                s.top++;  
                s.data[s.top] = result;  
                break;  
            case '-':  
                num1 = s.data[s.top];  
                s.top--;  
                num2 = s.data[s.top];  
                s.top--;  
                result = num2-num1;  
                s.top++;  
                s.data[s.top] = result;  
                break;  
            case '*':  
                num1 = s.data[s.top];  
                s.top--;  
                num2 = s.data[s.top];  
                s.top--;  
                result = num1*num2;  
                s.top++;  
                s.data[s.top] = result;  
                break;  
            case '/':  
                num1 = s.data[s.top];  
                s.top--;  
                num2 = s.data[s.top];  
                s.top--;  
                result = num2/num1;  
                s.top++;  
                s.data[s.top] = result;  
                break;  
            }  
            i++;  
        }  
    }  
    return result;  
}  
int main()  
{  
    SElemType a[STACK_INIT_SIZE],b[STACK_INIT_SIZE];  
    double f;  
    printf("������һ�����ʽ��");  
    gets(a);  
    TranslateExpress(a,b);  
    printf("��׺���ʽ�ǣ�%s\n",b);  
    f = ComputeExpress(b);  
    printf("�������ǣ�%.2lf\n",f);  
    return 0;  
}  
