#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
#define SIZE 50

/********************运算符的栈********************/
typedef struct stack
{   //定义栈指针
	char *base; //栈底 
	char *top;  //栈顶 
}SqStack;       

int InitStack(SqStack &S)
{   //初始化栈
	S.base = (char *)malloc(SIZE*sizeof(char));   
	S.top = S.base;
	return 0;
}

char GetTop(SqStack S)
{   //获取栈顶值并返回给e
	char e;
	e = *(S.top - 1);
	return e;
}

int Push(SqStack &S, char e)
{   //入栈
	*S.top = e;
	S.top++;
	return 0;
}

char Pop(SqStack &S)
{   //出栈
	char e;
	S.top--;
	e = *S.top;
	return e;
}

bool isEmpty(SqStack S)
{   //判断栈是否为空
	if (S.top == S.base)
		return true;
	else 
		return false;
}

/********************常量的栈********************/
typedef struct Istack
{   //定义栈指针
	double *base; //栈底 
	double *top;  //栈顶 
}Istack; 


int InitStack(Istack &S)
{   //栈初始化
	S.base = (double *)malloc(SIZE*sizeof(double));
	S.top = S.base;
	return 0;
}

double GetTop(Istack S)
{   //获取栈顶值并返回给e
    double e;
	e = *(S.top - 1);
	return e;
}

int Push(Istack &S, float e)
{   //入栈
	*S.top = e;
	S.top++;
	return 0;
}

double Pop(Istack &S)
{  //出栈
	double e;
	S.top--;
	e = *S.top;
	return e;
}

bool isEmpty(Istack S)
{   //判断栈是否为空
	if (S.top == S.base)
		return true;
	else 
		return false;
}

int Change(char S[],char OPS[],int &len)   //S为输入的中缀表达式，OPS为转化后的后缀表达式
{   //将中缀表达式转化为后缀表达式的函数
	SqStack OPE;         //定义OPE为运算符栈
	InitStack (OPE);     //初始化OPE
	int i,j=0;
	for (i = 0; i < strlen(S); i++)
	{
		switch (S[i])
		{
		case'+':
		case'-':          //若为“+”、“-”，则执行
			if (GetTop(OPE) == '*' || GetTop(OPE) == '/')    //若栈顶是乘除号，优先数低于栈顶运算符
			{
				OPS[j++] = Pop(OPE);                         //则中缀式符号栈出栈,放入后缀式中
				i--;
			}
			else
				Push(OPE, S[i]);                             //若优先数高于栈顶运算符，则进栈
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
			while (S[i] >= '0'&&S[i] <= '9' || S[i] == '.')  //将操作数直接放入后缀式
			{
				OPS[j++] = S[i];
				i++;
			}
			i--;
			OPS[j++] = '#';  //数字中的间隔符
			break;
		}
	}
	while (!isEmpty(OPE))   //将剩余的操作符放入后缀式
	{
		OPS[j++] = Pop(OPE);
	}
	len = j;                //len为后缀表达式的长度
	return 0;
}

int EXchange(char B[], int len, double &result,bool &flag)  //B为后缀式,len为后缀表达式的长度
{   //通过后缀表达式求值的函数
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
			a = Pop(SZ);    //操作数出栈1
			b = Pop(SZ);    //操作数出栈2
			c = b + a;      //相加
			Push(SZ, c);    //将相加之和入栈
		    }
			   break;
		   case'-':
		   {
			  a = Pop(SZ);  //操作数出栈1
			  b = Pop(SZ);  //操作数出栈2
			  c = b - a;    //相减
			  Push(SZ, c);  //将差入栈
		   }
			   break;
		   case'*':
		   {
			  a = Pop(SZ);  //操作数出栈1
			  b = Pop(SZ);  //操作数出栈2
			  c = b * a;    //相乘
			  Push(SZ, c);  //将积入栈
		   }
			   break;
		   case'/':
		   {
			  a = Pop(SZ);  //操作数出栈1
			  b = Pop(SZ);  //操作数出栈2
			  if (a == 0)   //若被除数为0则出错
			  {
				  flag = false;
				  return 0;
			  }
			  c = b / a;    //相除
			  Push(SZ, c);  //入栈
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
	result=GetTop(SZ);    //将栈顶元素返回给结果
	return 0;
}

int main()
{
		char S[SIZE];       //定义中缀表达式
		char B[SIZE];
		int len;
		bool flag = true;
		double result;

		cout <<"输入表达式,不用以#结束(注意括号大小写)"<<endl;
		cin >> S;           //输入表达式
		Change(S,B,len);  
		EXchange(B, len, result,flag); 

		if (flag)
			cout << result;
		else 
			cout << "The expression is not vaild" << endl;
		system("pause");
		return 0;
}
