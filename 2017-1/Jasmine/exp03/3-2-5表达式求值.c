#include<stdio.h>
#include<stdlib.h>   
#include<string.h>   
#include<math.h>  
#define true 1   
#define false 0   
#define OPSETSIZE 8   
typedef int Status;

unsigned char Prior[8][8] =
{ // ��������ȼ���   
  // '+' '-' '*' '/' '(' ')' '#' '^'   
	/*'+'*/'>','>','<','<','<','>','>','<',
	/*'-'*/'>','>','<','<','<','>','>','<',
	/*'*'*/'>','>','>','>','<','>','>','<',
	/*'/'*/'>','>','>','>','<','>','>','<',
	/*'('*/'<','<','<','<','<','=',' ','<',
	/*')'*/'>','>','>','>',' ','>','>','>',
	/*'#'*/'<','<','<','<','<',' ','=','<',
	/*'^'*/'>','>','>','>','<','>','>','>'
};

//StackChar���͵Ľ��SC�����������  
typedef struct StackChar
{
	char c;
	struct StackChar *next;
}SC;

//StackFloat���͵Ľ��SF������������  
typedef struct StackFloat
{
	float f;
	struct StackFloat *next;
}SF;

SC*PushC(SC *s, char c)//SC�����������ջPush������ջ��  
{
	SC *p = (SC*)malloc(sizeof(SC));
	p->c = c;
	p->next = s;
	return p;
}

SF *PushF(SF *s, float f)//SF������������ջPush������p  
{
	SF *p = (SF*)malloc(sizeof(SF));
	p->f = f;
	p->next = s;
	return p;
}

SC *PopC(SC *s)//SC���͵�ָ��Pop��ɾ��ջ�������Ԫ�ز�������ֵ
{
	SC *q = s;
	s = s->next;
	free(q);
	return s;
}

SF* PopF(SF *s)//SF���͵�ָ��Pop��ɾ��ջ��������Ԫ�ز�������ֵ
{
	SF *q = s;
	s = s->next;
	free(q);
	return s;
}

float Operate(float a, unsigned char theta, float b)//�ú�׺���ʽ���㺯��Operate  
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a*b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: return 0;
	}
}

char OPSET[OPSETSIZE] = { '+','-','*','/','(',')','#','^' };

Status In(char Test, char *TestOp)//�ж��Ƿ�Ϊ�����
{
	int Find = false;
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (Test == TestOp[i])
			Find = true;
	}
	return Find;
}

Status ReturnOpOrd(char op, char *TestOp)//�����ǵڼ��������
{
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (op == TestOp[i])
			return i;
	}
}

char precede(char Aop, char Bop)
{
	return Prior[ReturnOpOrd(Aop, OPSET)][ReturnOpOrd(Bop, OPSET)];
}

float EvaluateExpression(char* MyExpression)
{
	// �������ʽ��ֵ����������㷨  
	// ��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��OPΪ���������   
	SC *OPTR = NULL;       // �����ջ���ַ�Ԫ��   
	SF *OPND = NULL;       // ������ջ��ʵ��Ԫ��   
	char TempData[20];
	float Data, a, b;
	char theta, *c, Dr[] = { '#','\0' };
	OPTR = PushC(OPTR, '#');
	c = strcat(MyExpression, Dr);
	strcpy(TempData, "\0");//�ַ�����������   
	while (*c != '#' || OPTR->c != '#')
	{
		if (!In(*c, OPSET))
		{
			Dr[0] = *c;
			strcat(TempData, Dr);           //�ַ������Ӻ���   
			c++;
			if (In(*c, OPSET))
			{
				Data = atof(TempData);       //�ַ���ת������(double)   
				OPND = PushF(OPND, Data);
				strcpy(TempData, "\0");
			}
		}
		else    // ������������ջ   
		{
			switch (precede(OPTR->c, *c))
			{
			case '<': // ջ��Ԫ�����ȼ���   
				OPTR = PushC(OPTR, *c);
				c++;
				break;
			case '=': // �����Ų�������һ�ַ�   
				OPTR = PopC(OPTR);
				c++;
				break;
			case '>': // ��ջ������������ջ   
				theta = OPTR->c;OPTR = PopC(OPTR);
				b = OPND->f;OPND = PopF(OPND);
				a = OPND->f;OPND = PopF(OPND);
				OPND = PushF(OPND, Operate(a, theta, b));
				break;
			} //switch  
		}
	} //while   
	return OPND->f;
} //EvaluateExpression   

int main(void)
{
	char s[128];
	printf("��������ʽ:");
	gets(s);
	printf("�ñ��ʽ��ֵΪ:");
	printf("%s\b=%g\n", s, EvaluateExpression(s));
	return 0;
}