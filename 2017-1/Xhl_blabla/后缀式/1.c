#include "1.h"
int main()
{
	char x[SUANSHUSHI_NUM];
	int t;
	scanf("%s", x);
	stack mystack;
	initstack(&mystack);
	rank_list(&mystack, x);
	printf("\n ������ɺ� \n");
	Traverse_Stack(mystack);//��һ�ν�������֮��
	printf("\n*********************************************************\n");
	t = cal_list(mystack);
	printf("��ʽ�ļ������� %d", t);
	free(mystack.base);
	return 0;
}
//��ʼ��ջ  
status initstack(stack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType));
	if (NULL == s->top)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	s->top = s->base;
	int k = DATE_NUM;
	s->top->date = (char*)malloc(sizeof(char) * k);
	s->top->date = "#\0";//��ô����ָ���
	s->base = s->top;//��ֹ����Ұָ��
	return 1;
}
//����ջ�Ƿ�Ϊ��  �Ƿ���0 �񷵻�1
status isStackempty(stack s)
{
	if (s.base == s.top)
	{
		return 0;
	}
	return 1;
}
//����ѹջ
status push(stack *s, char *e)
{
	ElemType *p = (ElemType*)malloc(sizeof(ElemType));
	if (NULL == p)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	int k = DATE_NUM;
	p->date = (char*)malloc(sizeof(char) *k);
	strcpy(p->date, e);
	p->pNext = s->top;  //��p��ָ����ָ����һ���ڵ�  
	s->top = p;        //��pTopָ��ָ��ջ��Ԫ��  
	return 1;
}
//�����ж������ֻ��ǽ��޷����������  �����־ͷ���0
status judgenumber(char x)
{
	int i;
	switch (x)
	{
	case '+':
	case'-':
	case'*':
	case'/':
		i = 1;//��������� 1
		break;
	case '(':
		i = 3;
		break;
	case')':
		i = 4; //���޷�����-1
		break;
	case'\0':
		i = -10;//���緵��-10
		break;
	case '#':
		i = 6;//����ǵ���ջ��
		break;
	default:
		i = 0; //���ַ���0
		break;
	}
	return i;
}
//�����ַ����Ĳ��,Ϊѹջ��׼��
char** conversion(char x[])
{
	int i = 0, j = 0, k = 0;
	int q = WEIDU_NUM;
	int p = DATE_NUM;
	char **y = (char**)malloc(sizeof(char*)*q);
	for (i = 0; i < q; i++)
	{
		y[i] = (char*)malloc(sizeof(char)*p);
	}
	//��̬�����ά������д洢
	i = 0;
	do
	{//��ʵ�˶ο��Խ��л��� ֻҪ�����ַ����Ļ���
		j = 0;
		if (judgenumber(x[i]) == 0)
		{
			while (judgenumber(x[i]) == 0 && x[i] != '\0')//��������ַ������� ���д洢
			{
				y[k][j] = x[i];
				i++;
				j++;
			}
			y[k][j] = '\0';
		}
		else
		{
			y[k][j] = x[i];
			y[k][1] = '\0';
			i++;
		}
		k++;
	} while (x[i] != '\0');
	y[k][0] = '\0';//��βԪ����ô���
	i = 0;
	printf("��������ַ������в�� \n");
	while (y[i][0] != '\0')
	{
		printf("%s  ", y[i]);
		i++;
	}
	return y;
}
//���ں�׺ʽ������ �����ֺ������
status rank_list(stack *s, char x[])
{
	stack print_out_stack;
	initstack(&print_out_stack);//���ڴ洢��ӡ�����ջ
	int i = 0;//j�������� ֻ������ջʱ���ѭ��  ���÷�Χ��С   i�������Ǽ�¼ͷβ������
	char**p = conversion(x);//��ֳɶ�����Ԫ��
	char *temp;//��ʱ�洢ֵ
	int q = WEIDU_NUM;//����p���ͷ�
	while (p[i][0] != '\0')
	{
		if (judgenumber(p[i][0]) == 0)//���
		{
			push(&print_out_stack, p[i]);//ֱ�Ӵ�ӡ
			printf("\n��������ֱ�Ӵ�ӡ  %s \n ", p[i]);
		}
		else if (judgenumber(p[i][0]) == 1)//����������
		{
			if (0==isStackempty(*s) || judge_pre(p[i][0]) >= judge_pre(s->top->date[0])|| s->top->date[0]=='(')//���ջΪ�ջ�Ԫ�ص����ȼ����ڵ���ջ��Ԫ�� ������ջ
			{
				printf("\n���ȼ��ϸ� ��ջ��Ϊ����  ��ջ  %s\n", p[i]);
				push(s, p[i]);
			}
			else//��������Ҫ���������ֽ��д�ӡ  �����µ����������ѹջ
			{
				//����ջ��Ԫ��  ֱ�����������Ż����������ȼ����͵�Ԫ�� ��ջ�� ��ջ��Ԫ�����ȼ�������  ��ջ
				while (0 != isStackempty(*s) && judgenumber(s->top->date[0]) != 3 && judge_pre(s->top->date[0]) >= judge_pre(p[i][0]))//�����ź������ŵ����ֲ�ͬ
				{
					
					Pop_Stack(s, &temp);
					push(&print_out_stack, temp);
					printf("\n%s���ȼ�����%s �� %s ��ջ��ӡ\n", p[i],temp,temp);
				}
				push(s, p[i]);//����ջ
			}
		}
		else  //�����������  ������ֱ�ӽ�ջ   �����Ž��д�ӡ���ֱ������������
		{
			if (judgenumber(p[i][0]) == 3)
			{
				printf("\n����������ջ\n");
				push(s, p[i]);
			}
			else//�����������  ���е���������һϵ�г�ջ����
			{
				printf("\n����������  ����������ǰ�Ĳ��������д�ӡ\n");
				while (judgenumber(s->top->date[0]) != 3)
				{
					Pop_Stack(s, &temp);
					push(&print_out_stack, temp);
					printf("\n��ӡ  %s\n", temp);
				}
				Pop_Stack(s, &temp);//����������
				printf("\n����������\n");
			}
		}
		i++;
	}
	//�Բ�ֹ����Ԫ��ռ���ڴ�����ͷ�
	while (isStackempty(*s))
	{
		Pop_Stack(s, &temp);
		push(&print_out_stack, temp);
		printf("\n��ӡ %s\n", temp);
	}
	//�ͷŽ�ȡ�ַ�ʱ���ڴ�
	for (i = 0; i < q; i++)//�ͷ���ʱ�Ķ���ָ��
	{
		free(p[i]);
	}
	free(p);
	while (isStackempty(print_out_stack))
	{
		Pop_Stack(&print_out_stack, &temp);
		push(s, temp);
	}
	free(print_out_stack.base);
	return 1;
}
//�ж�����������ȼ�
status judge_pre(char x)
{
	int i;
	switch (x)
	{
	case '+':
	case'-':
		i = 0;
		break;
	case'*':
	case'/':
		i = 1;//��������� 1
		break;
	default:
		i = 2;
		break;
	}
	return i;
}
//����ջ��
status Pop_Stack(stack *S, char ** val)
{
	ElemType* p = S->top;
	(*val) = (char*)malloc(sizeof(char) * 5);
	(*val) = S->top->date;
	S->top = S->top->pNext;  //ʹpTopָ��ָ��ջ��Ԫ�أ�  
	free(p);  //�ͷ�pָ����ָ����Ǹ��ڵ���ڴ棻  
	p = NULL;   //Ҫ���ɺõ�ϰ�ߣ�  
	return 1;
}
void Traverse_Stack(stack s)
{
	ElemType  *p = s.top;
	printf("\nջ�е�Ԫ���ǣ�\n");
	while (p != s.base)
	{
		printf("%s ", p->date);
		p = p->pNext;
	}
	printf("\n");
}
//���ڼ����׺ʽ
status cal_list(stack s)//���������
{
	stack mystack;//���ڼ����ջ
	initstack(&mystack);
	char * temp;//������ʱ�洢��ջ��Ԫ��
	while (s.top != s.base)
	{
		if(judgenumber(s.top->date[0]) == 0)//���������ֱ�ӽ���ѹջ
		{
			Pop_Stack(&s, &temp);
			push(&mystack, temp);
       }
		else
		{//���������������м���
			char *v;//����
			int a = (int)atof(mystack.top->date);//ת��ջ��Ԫ��
			int b = (int)atof(mystack.top->pNext->date);//ת���ڶ���Ԫ��
			int c = cal(a, b, s.top->date[0]);
			printf("\nȡ��ջ�е� %d %d ����%c�ļ���", a, b,s.top->date[0]);
			printf("  %d %c %d = %d\n", b, s.top->date[0], a, c);
			Pop_Stack(&mystack, &v);//������ɺ�����ݽ�����Ӧ�ĳ�ջ
			Pop_Stack(&mystack, &v);
			Pop_Stack(&s, &v);
			itoa(c, v, 10);
			push(&mystack, v);//��������������ջ
			free(v);//����ʱ������������ͷ�
		}
	}
	free(temp);
	int  c = (int)atof(mystack.top->date);
	free(mystack.top);
	return c;
}
int cal(int a, int b, char x)//���м���
{
	switch (x)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return b- a;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return b / a;
		break;
	}
}
//����ջ
status destory(stack *s)
{
	ElemType *p;
	while (s->top != s->base)
	{
		p = s->top;
		s->top = s->top->pNext;
		free(p);
	}
	free(s->base);
	return 1;
}
