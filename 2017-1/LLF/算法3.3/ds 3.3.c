//ʵ�ֱ��ʽ��ֵ   
//�ο���CSDN���ִ���
//�����û�����ո�ϵͳ�Զ�ɾ������ֻ�ܽ����������������㣬֧��С����  
//�Բ��������Ľ����������������������ȡ��  
//�Խ�����зֲ���ʾ
#include <stdio.h>  
#include <stdlib.h>  
#define OK      1  
#define ERROR   0  
#define TRUE    1  
#define FALSE   0  
#define STACK_INIT_SIZE 100  
#define STACKINCREMENT 10  
#define BUFFERSIZE 256  

typedef int Status; //��������״̬  
typedef int OPNDelem;  //������Ԫ������  
typedef struct //������ջ�ṹ���� 
{ 
	OPNDelem *base;
	OPNDelem *top;
	int Stacksize;
}OPNDStack;

typedef char OPTRelem;//������Ԫ������  

typedef struct //������ջ�ṹ����
{  
	OPTRelem *base;
	OPTRelem *top;
	int Stacksize;
}OPTRStack;

Status InitStack_OPND(OPNDStack *S);
//����һ����ջS  
Status Gettop_OPND(OPNDStack S, OPNDelem *e);
//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
Status Push_OPND(OPNDStack *S, OPNDelem e);
//����Ԫ��eΪ�µ�ջ��Ԫ��  
Status Pop_OPND(OPNDStack *S, OPNDelem *e);
//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  



Status InitStack_OPTR(OPTRStack *S);
//����һ����ջS  
OPTRelem Gettop_OPTR(OPTRStack S);
//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
Status Push_OPTR(OPTRStack *S, OPTRelem e);
//����Ԫ��eΪ�µ�ջ��Ԫ��  
Status Pop_OPTR(OPTRStack *S, OPTRelem *e);
//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  



void Standard(char *expression);
//�����ʽ��׼��  
OPNDelem EvalueateExpression(const char *expression);
//�������ʽ��ֵ  
Status IsOPerator(char c);
//�ж�c�Ƿ���һ��������  
char Precede(char OP1, char OP2);
//�ж�OP1��OP2���ȼ��ĸߵͣ�����'>','<','='  
OPNDelem OPerate(OPNDelem a, OPTRelem comp, OPNDelem b);
//�Բ�����a��b����comp����  
const char *getopND(const char *c, OPNDelem *OP);
//�����*c��ʼ�Ĳ����������غ�cΪ������  


Status InitStack_OPND(OPNDStack *S)//����һ���ղ�����ջS  
{
	 
	S->base = (OPNDelem *)malloc(STACK_INIT_SIZE * sizeof(OPNDelem));
	if (!S->base)//����ʧ��  
	{
		printf("�����ڴ�ʧ��.\n");
		exit(0);
	}
	S->top = S->base;
	S->Stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Gettop_OPND(OPNDStack S, OPNDelem *e) {
	//��������ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�FALSE  
	if (S.top == S.base) {
		printf("ջΪ��.\n");
		return FALSE;
	}
	else {
		*e = *(S.top - 1);
		return OK;
	}
}

Status Push_OPND(OPNDStack *S, OPNDelem e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��  
	if (S->top - S->base >= S->Stacksize) {//ջ������׷�Ӵ洢�ռ�  
		S->base = (OPNDelem *)realloc(S->base, (S->Stacksize + STACKINCREMENT) * sizeof(OPNDelem));
		if (!S->base)
		{
			printf("��������ռ�ʧ��.\n");
			exit(0);
		}
		S->top = S->base + S->Stacksize;//����ջ��ָ��  
		S->Stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop_OPND(OPNDStack *S, OPNDelem *e) //��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  
{
	
	if (S->top == S->base) {//ջΪ��  
		printf("ջΪ��.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}


Status InitStack_OPTR(OPTRStack *S) //����һ���ղ�����ջS  
{
	
	S->base = (OPTRelem *)malloc(STACK_INIT_SIZE * sizeof(OPTRelem));
	if (!S->base)//����ʧ��  
	{
		printf("�����ڴ�ʧ��.\n");
		exit(0);
	}
	S->top = S->base;
	S->Stacksize = STACK_INIT_SIZE;
	return OK;
}

OPTRelem Gettop_OPTR(OPTRStack S)//��������ջ��Ϊ�գ��򷵻�S��ջ��Ԫ�أ�������OK�����򷵻�FALSE   
{
	
	OPTRelem e;
	if (S.top == S.base) {
		printf("ջΪ��.\n");
	}
	else {
		e = *(S.top - 1);
	}
	return e;
}

Status Push_OPTR(OPTRStack *S, OPTRelem e) //����Ԫ��eΪ�µ�ջ��Ԫ�� 
{
	 
	if (S->top - S->base >= S->Stacksize)//ջ������׷�Ӵ洢�ռ� 
	{ 
		S->base = (OPTRelem *)realloc(S->base, (S->Stacksize + STACKINCREMENT) * sizeof(OPTRelem));
		if (!S->base)
		{
			printf("��������ռ�ʧ��!\n");
			exit(0);
		}
		S->top = S->base + S->Stacksize;//����ջ��ָ��  
		S->Stacksize += STACKINCREMENT;
	}
	*S->top++ = e;
	return OK;
}

Status Pop_OPTR(OPTRStack *S, OPTRelem *e) {
	//��ջS��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK,���򷵻�ERROR  
	if (S->top == S->base) //ջΪ��
	{  
		printf("ջΪ��.\n");
		return ERROR;
	}
	*e = *(--S->top);
	return OK;
}


OPNDelem EvalueateExpression(const char *expression)	//��ֻ��������������������ʽ expression ��ֵ  
                                                    	//OPTR:������ջ��OPND:������ջ   
{
	const char *c = expression;
	OPNDStack OPND;
	OPTRStack OPTR;
	OPTRelem x, comp;
	OPNDelem a, b, num, result;
	InitStack_OPTR(&OPTR);//��ʼ��������ջ  
	InitStack_OPND(&OPND);//��ʼ��������ջ  
	Push_OPTR(&OPTR, '#');//���Ƚ�ƥ�����'#'��ջ  
	while (*c != '#' || Gettop_OPTR(OPTR) != '#')
	{
		if (*c == '\0')//�����س��˳�  
			break;
		if (FALSE == IsOPerator(*c)) {
			c = getopND(c, &num);
			Push_OPND(&OPND, num);
	}
		else
			switch (Precede(Gettop_OPTR(OPTR), *c))
			{
			case '<':
				Push_OPTR(&OPTR, *c);
				c++;
				break;
			case '=':
				Pop_OPTR(&OPTR, &x);
				c++;
				break;
			case '>':
				Pop_OPTR(&OPTR, &comp);
				Pop_OPND(&OPND, &b);
				Pop_OPND(&OPND, &a);
				result = OPerate(a, comp, b);
				//printf("temp result is:%d\n",result);  
				Push_OPND(&OPND, result);
				break;
			default:
				//printf("Precede:%c",Precede(Gettop_OPTR(OPTR),*c));  
				break;
			}//switch  
	}//while  
	Gettop_OPND(OPND, &result);
	return result;
}

void Standard(char *expression) //���ַ������ʽ��׼��Ϊ�������ʽ
{	  
	char *p = expression, *q;
	while (*p != '\0') //�����ַ��� 
	{ 
		if (*p == ' ') //����ǿո�ɾ��
		{  
			q = p;
			do 
			{
				*q = *(q + 1);
				q++;
			} while (*q != '\0');
		}
		p++;
	}
	*p++ = '#';
	*p = '\0';
}

const char *getopND(const char *c, OPNDelem *OP) //�����*c��ʼ�Ĳ����������غ�cΪ������  
{	
	int sum = 0, tmp;
	while (FALSE == IsOPerator(*c)) {//��c���ǲ�����  
		tmp = *c - '0';
		sum = sum * 10 + tmp;
		//printf("tmp=%d\n",tmp);  
		c++;
	}
	*OP = sum;
	//printf("getopND:%d\n",*OP);  
	return c;
}

Status IsOPerator(char c)//�ж�c�Ƿ���һ����������� 
{	  
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '#':
		return TRUE;
		break;
	default:
		return FALSE;
		break;
	}
}

char Precede(char OP1, char OP2)//�ж�OP1��OP2���ȼ��ĸߵͣ�����'>','<','='   
{
	
	switch (OP1) {
	case '+':
		switch (OP2) {
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '-':
		switch (OP2) {
		case '*':
		case '/':
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '*':
		switch (OP2) {
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '/':
		switch (OP2) {
		case '(':
			return '<';
			break;
		default:
			return '>';
			break;
		}
		break;
	case '(':
		switch (OP2) {
		case ')':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	case ')':
		switch (OP2) {
		default:
			return '>';
			break;
		}
		break;
	case '#':
		switch (OP2) {
		case '#':
			return '=';
			break;
		default:
			return '<';
			break;
		}
		break;
	default:
		return '<';
		break;
	}
}

OPNDelem OPerate(OPNDelem a, OPTRelem comp, OPNDelem b)//�Բ�����a��b����comp���㣬������������   
	                                                   //compֻ���������������
{
	
	int result;
	switch (comp) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		if (b == 0) {
			printf("ERROR:����Ϊ0!");
			exit(0);
		}
		result = a / b;
		break;
	default:
		printf("It's not a OPerator!\n");
		break;
	}
	printf("%d %c %d = %d\n", a, comp, b, result);
	return result;

}

int main()
{
	OPNDelem result = 0;
	char *expression = (char*)malloc(sizeof(char)*BUFFERSIZE);
	if (expression == NULL) {
		printf("Sorry!Memory initialize ERROR!\n");
		exit(0);
	}
	printf("Please input an expression:\n");
	gets(expression);
	Standard(expression);				
	result = EvalueateExpression(expression);
	printf("The result of the expression:%d\n", result);
	return 0;
}