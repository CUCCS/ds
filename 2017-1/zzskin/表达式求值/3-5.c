#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100    //�洢�ռ��ʼ������
#define STACK_SIZE 100            //�洢�ռ��������
#define STACKINCREMENT 10         //�洢�ռ��������

struct  //�趨��������ȼ�
{
    char ch;   //�����
    int pri;   //���ȼ�
}
lpri[]= {{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
rpri[]= {{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};

typedef char SElemType ;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;                           //ö�ٶ��壨����״̬��

typedef enum{
	False,
	True
}Bool;                            //���岼������

typedef struct _SqStack{
	SElemType  *base;
	SElemType  *top;
	int      stacksize;
}SqStack;  

Status InitStack(SqStack *S)       //����˳��ջ
{
	S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S->base) 
	{
		return  OVERFLOW; 
	}                         //�洢����ʧ��
	S->top = S->base;         //��ʼ��
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}


Bool IsStackEmpty(SqStack *S)
{
	if(S->top == S->base)
	{
		return True;
	}
	else
	{
		return False;
	}
}

SElemType GetTop(SqStack *S,SElemType *e)
{
	if(IsStackEmpty(S))
	{
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if(S->top - S->base >= S->stacksize)
	{
		S->base = (SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!S->base)
		{
			return OVERFLOW;
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

 //ɾ�� S ��ջ��Ԫ�أ����� e ������ֵ
Status Pop(SqStack *S,SElemType *e)          
{
	if(IsStackEmpty(S))
	{
		return OK;
	}
	*e = *--S->top;
	return ERROR;
}


int leftpri(char op)    
{
    int i;
    for (i=0; i<STACK_INIT_SIZE; i++)
        if (lpri[i].ch==op)
            return lpri[i].pri;
}//���������op�����ȼ�


int rightpri(char op)  
{
    int i;
    for (i=0; i<STACK_INIT_SIZE; i++)
        if (rpri[i].ch==op)
            return rpri[i].pri;
}//���������op�����ȼ�

  
Bool InOp(char ch)     //�ж��ַ�ch�Ƿ�Ϊ�����
{
	switch (ch)
	{
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':     
		return True;
	default:
		return False;
	}
}

int Precede(char op1,char op2) 
{
    if (leftpri(op1)==rightpri(op2))
        return 0;
    else if (leftpri(op1)<rightpri(op2))
        return -1;
    else
        return 1;
}

void trans(char *exp,char postexp[])     //��׺ת��׺���вο���
{
    struct
    {
        char data[STACK_SIZE]; //��������
        int top;            //ջָ��
    } op;               //���������ջ
    int i=0;                //i��Ϊpostexp���±�
    op.top=-1;
    op.top++;                  //��'='��ջ
    op.data[op.top]='=';
    while (*exp!='\0')      //exp���ʽδɨ����ʱѭ��
    {
        if (!InOp(*exp))        //Ϊ�����ַ������
        {
            while (*exp>='0' && *exp<='9') //�ж�Ϊ����
            {
                postexp[i++]=*exp;
                exp++;
            }
            postexp[i++]=' ';   //��#��ʶһ����ֵ������
        }
        else    //Ϊ����������
            switch(Precede(op.data[op.top],*exp))
            {
            case -1:           //ջ������������ȼ���:��ջ
                op.top++;
                op.data[op.top]=*exp;
                exp++;     //����ɨ�������ַ�
                break;
            case 0:        //ֻ�����������������
                op.top--;      //��(��ջ
                exp++;     //����ɨ�������ַ�
                break;
            case 1:             //��ջ�������postexp��
                postexp[i++]=op.data[op.top];
                op.top--;
                break;
            }
    } //while (*exp!='\0')
    while (op.data[op.top]!='=')
    //��ʱexpɨ�����,��ջ��'='Ϊֹ
    {
        postexp[i++]=op.data[op.top];
        op.top--;
    }
    postexp[i]='\0';    //��postexp���ʽ��ӽ�����ʶ
}

float compvalue(char exp[])          //�����׺���ʽ��ֵ(�вο���
{
    struct
    {
        float data[STACK_SIZE];     //�����ֵ
        int top;                   //ջָ��
    } st;                         //������ֵջ
    float d;
    char ch;
    int t=0;                   //t��Ϊexp���±�
    st.top=-1;
    ch=exp[t];
    t++;
    while (ch!='\0')    //exp�ַ���δɨ����ʱѭ��
    {
        switch (ch)
        {
        case'+':
            st.data[st.top-1]=st.data[st.top-1]+st.data[st.top];
            st.top--;
            break;
        case '-':
            st.data[st.top-1]=st.data[st.top-1]-st.data[st.top];
            st.top--;
            break;
        case '*':
            st.data[st.top-1]=st.data[st.top-1]*st.data[st.top];
            st.top--;
            break;
        case '/':
            if (st.data[st.top]!=0)
                st.data[st.top-1]=st.data[st.top-1]/st.data[st.top];
            else
            {
                printf("\n\t�������!\n");                  //�쳣�˳�
            }
            st.top--;
            break;
        default:
            d=0;                          //�������ַ�ת������ֵ��ŵ�d��
            while (ch>='0' && ch<='9')   //Ϊ�����ַ�
            {
                d=10*d+ch-'0';
                ch=exp[t];
                t++;
            }
            st.top++;
            st.data[st.top]=d;
        }
        ch=exp[t];
        t++;
    }
    return st.data[st.top];
}

int main()
{
	int i = 0;
    char exp[] = "(56-20)/(4+2)" ;
    char postexp[STACK_SIZE];
    trans(exp,postexp);
    printf("��׺���ʽ:%s\n",exp);
    printf("��׺���ʽ:%s\n",postexp);
    printf("���ʽ��ֵ:%g\n",compvalue(postexp));
    return 0;
}