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
 //定义stack结构体类型
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

Status InitStack(SqStack *S)//将栈S初始化为空栈  
{  
	int i;
    S->top = 0;  
	for (i = 0;i < STACK_INIT_SIZE;i++)
	{
		S->data[i] = 0;
	}
	return OK;
}  
Status EmptyStack(SqStack *S)//判断栈是否为空，栈为空返回1，否则返回0  
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
Status GetTop(SqStack S,SElemType *e)//取栈顶元素，将栈顶元素值返回给e，并返回1表示成功，返回0表示失败  
{  
    if(S.top <= 0)  
    {  
        printf("栈已经空！\n");  
        return ERROR;  
    }  
    else  
    {  
        *e = S.stack[S.top-1];//取栈顶元素  
        return OK;  
    }  
}  
Status Push(SqStack *S,SElemType e)//进栈操作  
//将元素e进栈，元素进栈成功返回1，否则返回0  
{  
    if(S->top >= STACK_INIT_SIZE-1)  
    {  
        printf("栈已满，不能入栈！");  
        return ERROR;  
    }  
    else  
    {  
        S->stack[S->top] = e;  
        S->top++;  
        return OK;  
    }  
}  
Status Pop(SqStack *S,SElemType *e)//出栈操作  
{  
    if(S->top <= 0)  
    {  
        printf("栈已经没有元素，不能出栈！\n");  
        return ERROR;  
    }  
    else  
    {  
        S->top--;  
        *e = S->stack[S->top];  
        return OK;  
    }  
}  
int GetLength(SqStack S)//返回栈长度  
{  
    return S.top;  
}  
Status ClearStack(SqStack *S)//清空栈  
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
				 Pop(&s,&e);//将左括号出栈  
            break;
			case '+' :
			case '-' :
				while (GetTop(s,&e) && e !='(')
				{
					Pop(&s,&e);  
					s2[j]= e;  
					j++;  
				}  
				Push(&s,ch);//当前运算符进栈  
				break;
			case '*' :
			case '/' :
				while(!EmptyStack(&s) && GetTop(s,&e) && e == '/' || e == '*')  
				{  
					Pop(&s,&e);  
					s2[j]= e;  
					j++;  
				}  
				Push(&s,ch);//当前运算符进栈  
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
		//读入下一个字符，准备处理 
	}  
	 while(!EmptyStack(&s))//将栈中所有剩余的运算符出栈，送入数组s2中  
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
    printf("请输入一个表达式：");  
    gets(a);  
    TranslateExpress(a,b);  
    printf("后缀表达式是：%s\n",b);  
    f = ComputeExpress(b);  
    printf("计算结果是：%.2lf\n",f);  
    return 0;  
}  
