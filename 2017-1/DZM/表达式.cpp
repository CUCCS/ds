#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define SIZE 50

/********************�������ջ********************/
typedef struct stack
{   //����ջָ��
	char *base; //ջ�� 
	char *top;  //ջ�� 
}SqStack;       

int InitStack(SqStack &S)
{   //��ʼ��ջ
	S.base = (char *)malloc(SIZE*sizeof(char));   
	S.top = S.base;
	return 0;
}

char GetTop(SqStack S)
{   //��ȡջ��ֵ�����ظ�e
	char e;
	e = *(S.top - 1);
	return e;
}

int Push(SqStack &S, char e)
{   //��ջ
	*S.top = e;
	S.top++;
	return 0;
}

char Pop(SqStack &S)
{   //��ջ
	char e;
	S.top--;
	e = *S.top;
	return e;
}

bool isEmpty(SqStack S)
{   //�ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base)
		return true;
	else 
		return false;
}

/********************������ջ********************/
typedef struct Istack
{   //����ջָ��
	double *base; //ջ�� 
	double *top;  //ջ�� 
}Istack; 


int InitStack(Istack &S)
{   //ջ��ʼ��
	S.base = (double *)malloc(SIZE*sizeof(double));
	S.top = S.base;
	return 0;
}

double GetTop(Istack S)
{   //��ȡջ��ֵ�����ظ�e
    double e;
	e = *(S.top - 1);
	return e;
}

int Push(Istack &S, float e)
{   //��ջ
	*S.top = e;
	S.top++;
	return 0;
}

double Pop(Istack &S)
{  //��ջ
	double e;
	S.top--;
	e = *S.top;
	return e;
}

bool isEmpty(Istack S)
{   //�ж�ջ�Ƿ�Ϊ��
	if (S.top == S.base)
		return true;
	else 
		return false;
}

int Change(char S[],char OPS[],int &len)   //SΪ�������׺���ʽ��OPSΪת����ĺ�׺���ʽ
{   //����׺���ʽת��Ϊ��׺���ʽ�ĺ���
	SqStack OPE;         //����OPEΪ�����ջ
	InitStack (OPE);     //��ʼ��OPE
	int i,j=0;
	for (i = 0; i < strlen(S); i++)
	{
		switch (S[i])
		{
		case'+':
		case'-':          //��Ϊ��+������-������ִ��
			if (GetTop(OPE) == '*' || GetTop(OPE) == '/')    //��ջ���ǳ˳��ţ�����������ջ�������
			{
				OPS[j++] = Pop(OPE);                         //����׺ʽ����ջ��ջ,�����׺ʽ��
				i--;
			}
			else
				Push(OPE, S[i]);                             //������������ջ������������ջ
			break;
		case'*':
		case'/':
			Push(OPE, S[i]);
			break;
		case'(':
			Push(OPE, S[i]);
			break;
		case')':
			while (GetTop(OPE) != '(')
			{
				OPS[j++] = Pop(OPE);
			}
			Pop(OPE);
			break;
		default:
			while (S[i] >= '0'&&S[i] <= '9' || S[i] == '.')  //��������ֱ�ӷ����׺ʽ
			{
				OPS[j++] = S[i];
				i++;
			}
			i--;
			OPS[j++] = '#';  //�����еļ����
			break;
		}
	}
	while (!isEmpty(OPE))   //��ʣ��Ĳ����������׺ʽ
	{
		OPS[j++] = Pop(OPE);
	}
	len = j;                //lenΪ��׺���ʽ�ĳ���
	return 0;
}

int EXchange(char B[], int len, double &result,bool &flag)  //BΪ��׺ʽ,lenΪ��׺���ʽ�ĳ���
{   //ͨ����׺���ʽ��ֵ�ĺ���
	int i;
	double a;
	double b;
	double c;
	Istack SZ;
	InitStack(SZ);

	for (i = 0; i < len; i++)
	{
		switch (B[i])
		{
		   case'+':
		   {
			a = Pop(SZ);    //��������ջ1
			b = Pop(SZ);    //��������ջ2
			c = b + a;      //���
			Push(SZ, c);    //�����֮����ջ
		    }
			   break;
		   case'-':
		   {
			  a = Pop(SZ);  //��������ջ1
			  b = Pop(SZ);  //��������ջ2
			  c = b - a;    //���
			  Push(SZ, c);  //������ջ
		   }
			   break;
		   case'*':
		   {
			  a = Pop(SZ);  //��������ջ1
			  b = Pop(SZ);  //��������ջ2
			  c = b * a;    //���
			  Push(SZ, c);  //������ջ
		   }
			   break;
		   case'/':
		   {
			  a = Pop(SZ);  //��������ջ1
			  b = Pop(SZ);  //��������ջ2
			  if (a == 0)   //��������Ϊ0�����
			  {
				  flag = false;
				  return 0;
			  }
			  c = b / a;    //���
			  Push(SZ, c);  //��ջ
		   }
			   break;
		   default:
			   int j = 0;
			   float d;
			   char *st = new char[10];
			   while (B[i] != '#')
			   {  
				   st[j++] = B[i];
				   i++;
			   }	
			   d = atof(st);
			   Push(SZ, d);
			   delete st;
			   break;
		}
	}
	result=GetTop(SZ);    //��ջ��Ԫ�ط��ظ����
	return 0;
}

int main()
{
		char S[SIZE];       //������׺���ʽ
		char B[SIZE];
		int len;
		bool flag = true;
		double result;

		cout <<"������ʽ,������#����(ע�����Ŵ�Сд)"<<endl;
		cin >> S;           //������ʽ
		Change(S,B,len);  
		EXchange(B, len, result,flag); 

		if (flag)
			cout << result;
		else 
			cout << "The expression is not vaild" << endl;
		system("pause");
		return 0;
}
