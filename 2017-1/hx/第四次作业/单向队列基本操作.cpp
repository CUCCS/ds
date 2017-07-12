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

Status InitStack(SqStack *S)
{
    int i;
    S->top = 0;
    for (i = 0;i < STACK_INIT_SIZE;i++)
    {
        S->data[i] = 0;
    }
    return OK;
}
Status EmptyStack(SqStack *S)
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
Status GetTop(SqStack S,SElemType *e)
{
    if(S.top <= 0)
    {
        printf("’ª“—æ≠ø’£°\n");
        return ERROR;
    }
    else
    {
        *e = S.stack[S.top-1];
        return OK;
    }
}
Status Push(SqStack *S,SElemType e)

{
    if(S->top >= STACK_INIT_SIZE-1)
    {
        printf("’ª“—¬˙£¨≤ªƒ‹»Î’ª£°");
        return ERROR;
    }
    else
    {
        S->stack[S->top] = e;
        S->top++;
        return OK;
    }
}
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top <= 0)
    {
        printf("’ª“—æ≠√ª”–‘™Àÿ£¨≤ªƒ‹≥ˆ’ª£°\n");
        return ERROR;
    }
    else
    {
        S->top--;
        *e = S->stack[S->top];
        return OK;
    }
}
int GetLength(SqStack S)
{
    return S.top;
}
Status ClearStack(SqStack *S)
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
                Pop(&s,&e);
                break;
            case '+' :
            case '-' :
                while (GetTop(s,&e) && e !='(')
                {
                    Pop(&s,&e);
                    s2[j]= e;
                    j++;
                }
                Push(&s,ch);
                break;
            case '*' :
            case '/' :
                while(!EmptyStack(&s) && GetTop(s,&e) && e == '/' || e == '*')
                {
                    Pop(&s,&e);
                    s2[j]= e;
                    j++;
                }
                Push(&s,ch);
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
        
    }
    while(!EmptyStack(&s))
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
    printf("请输入一个表达式");
    gets(a);
    TranslateExpress(a,b);
    printf("后缀表达式是：%s\n",b);
    f = ComputeExpress(b);
    printf("计算结果是：%.2lf\n",f);
    return 0;
}
