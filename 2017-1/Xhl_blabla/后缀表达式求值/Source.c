#include "Source.h"
int main()
{
	char x[SUANSHUSHI_NUM];
	int t;
	scanf("%s", x);
	stack mystack;
	initstack(&mystack);
	rank_list(&mystack, x);
	printf("\n ����������ɺ�  ��ֻ������������ַ�����  ������������ֺ��ַ����� �� ");
	Traverse_Stack(mystack);//��һ�ν�������֮��
	rank_list_more(&mystack);//��׺ʽ�������
	Traverse_Stack(mystack);
	printf("\n�ڶ��� �Ժ�׺ʽ���м���\n");
	t=cal_list(mystack);
	printf("��ʽ�ļ������� %d", t);
	destory(&mystack);
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
	s->base=s->top =NULL;//��ֹ����Ұָ��
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
	case')':
		i = -1; //���޷�����-1
		break;
	case'\0':
		i = -10;//���緵��-10
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
			while (judgenumber(x[i]) ==0&& x[i] != '\0')//��������ַ������� ���д洢
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
//���ں�׺ʽ�ĳ������� �����ֺ������
status rank_list(stack *s, char x[])
{
	int i = 0, j;//j�������� ֻ������ջʱ���ѭ��  ���÷�Χ��С   i�������Ǽ�¼ͷβ������
	int begin = 0, end = 0;//ѹջ�����ʼĩ
	int flag;//�����ж�
	char**p = conversion(x);//��ֳɶ�����Ԫ��
	int q = WEIDU_NUM;//����p���ͷ�
	p[0];
	char temp[DATE_NUM];//��ʱ�洢ֵ
	int  a, b;
	while (p[i][0] != '\0')
	{
		if (judgenumber(p[i][0]) == -1)//���������  �����ڲ�����  ����ջ    һ�ξͳ����ź�  �Ժ���һ������
		{//ȷ����ʼ��β  ����ѹջ
			push(s, p[i]);//��������ջ
			i++;
			begin = i;
			while (judgenumber(p[i][0]) != -1)//����������ʱѭ��
			{
				i++;
			}
			end = i;
			//ð�ݷ��������������
			for (a = begin; a < end-1 ; a++)
			{
				for (b = begin; b < end - 1 - a+begin; b++)
				{	
					int k = 0;
					if (judge_pre(p[b][0]) < judge_pre(p[b + 1][0]))//�����ȼ��Ƚ�����
					{
						strcpy(temp, p[b]);
						strcpy(p[b], p[b + 1]);
						strcpy(p[b + 1], temp);
					}	
				}
			}
			int de;
			printf("\n ����������ַ��������� \n");
			for ( de= begin; de< end;de++)
			{
				printf("%s  ", p[de]);
			}
			for (j = begin; j < end; j++)
			{
				push(s, p[j]);//��Ԫ�ؽ�����ջ
			}
			push(s, p[i]);//��������ջ
			i++;
			begin = i;
		}
		else	//�����������ֱ�ӽ������� ѹջ
		{//��������ֻ���������������������
			flag = 0;
			while (flag == 0 || judgenumber(p[i][0]) == 0)//�����ֻ��ߵ�һ�ν���
			{
				if (judgenumber(p[i][0]) != 0)//�����������
				{
					flag = 1;
					if (judgenumber(p[i + 1][0]) == 0)//������ֵ
					{
						strcpy(temp, p[i]);
						strcpy(p[i], p[i + 1]);
						strcpy(p[i + 1], temp);
						end = i + 1;
						i += 2;
					//���Խ���ѹջ��
					for (j = begin; j <= end; j++)
					{
						push(s, p[j]);//��Ԫ�ؽ�����ջ
					}
					begin = i;
                     i--;
					}
					else
					{
						push(s, p[i]);	
						begin = i+1;//��begin���и�
					}
					//ѹ��ջ�Ϳ�����������
				}
				else//���������ֱ����ջ
				{
					push(s, p[i]);
					begin++;//ѹջ֮���ֵ��������
				}
				i++;//������һ��
				//ʲô����
				for (a = begin; a < end - 1; a++)
				{
					for (b = begin; b < end - 1 - a + begin; b++)
					{
						int k = 0;
						if (judge_pre(p[b][0]) < judge_pre(p[b + 1][0]))//�����ȼ��Ƚ�����
						{
							strcpy(temp, p[b]);
							strcpy(p[b], p[b + 1]);
							strcpy(p[b + 1], temp);
						}
					}
				}
			}
		}	
	}
	for (i = 0; i < q; i++)//�ͷ���ʱ�Ķ���ָ��
	{
		free(p[i]);
	}
	free(p);
	return 1;
}
//�ж����ȼ� �����жϺ�׺ʽ��ʱ��ʹ��
status judge_pre2(char x)
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
	case '(':
	case')':
		i = 1;//��������� 1
		break;
	default:
		i = 1;//��ĸ�����ȼ�
		break;
	}
	return i;
}
//���ַ������ȼ�����  ���ȼ�Խ����ֵԽ�� ���ڳ�������
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
			case '(':
			case')':
				i = 1;//��������� 1
				break;
			default:
				i = 2;//��ĸ�����ȼ�
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
//��һ��ֻ���������
status rank_list_more(stack *s)
{
	//��һ��ֻ���������
	int i = 0, j, k = 0;
	int q = WEIDU_NUM;
	int p = DATE_NUM;
	char **y = (char**)malloc(sizeof(char*)*q);//��ʱ�洢Ҫ�����Ԫ��
	char**x = (char**)malloc(sizeof(char*)*q);//�洢���������ó�����Ԫ��
	for (i = 0; i < q; i++)
	{
		y[i] = (char*)malloc(sizeof(char)*p);
		x[i] = (char*)malloc(sizeof(char)*p);
	}
	//��̬�����ά������д洢
	ElemType *temp;
	temp = s->top;
	i = 0;
	j = 0;
	while (temp != s->base)
	{
		if (judgenumber(temp->date[0]) != -1)//�����������
		{
			strcpy(y[i], temp->date);
			i++;
			temp = temp->pNext;
		}
		else
		{
			strcpy(y[i], temp->date);//�����Ŵ��ȥ
			i++;
			temp = temp->pNext;//�������������Ĳ���
			while (judgenumber(temp->date[0]) != -1)
			{
				strcpy(x[j], temp->date);
				j++;
				temp = temp->pNext;
			}
			strcpy(x[j], temp->date);
			temp = temp->pNext;
		}
	}
	int end = i;
	int x_num = j + 1;
	//���������������
	char *tem = (char*)malloc(sizeof(char)*p);
	for (i = 0; i<end - 1; i++)
	{
		for (j = 0; j<end - 1 - i; j++)
		{
			if (judge_pre2(y[j][0]) > judge_pre2(y[j + 1][0]))//�����ȼ��Ƚ�����
			{
				strcpy(tem, y[j]);
				strcpy(y[j], y[j + 1]);
				strcpy(y[j + 1], tem);
			}
		}
	}//����������ȡ����Ԫ��
	free(tem);//�ͷ���ʱ������ڴ�
	printf("\n�����������׺ʽʱ δ��������ǰ\n");
	for (i = 0; i < end; i++)
	{
		printf("%s ", y[i]);
	}
	for (i = 0; i < end; i++)
	{
		if (judgenumber(y[i][0]) == -1)
		{
			for (j = 0; j < x_num; j++)
			{
				for (k = end - 1; k > i + j; k--)
				{
					strcpy(y[k + 1], y[k]);
				}
				strcpy(y[i + j + 1], x[j]);
				end++;
			}
			break;//�������ź��������
		}
	}
	//Ȼ������ջ
	printf("\n�����������׺ʽʱ �������ź�\n");
	for (i = 0; i < end; i++)
	{
		printf("%s ", y[i]);
	}
	i = end - 1;
	temp = s->top;
	while (temp != s->base)//���ź����������ջ
	{

		strcpy(temp->date, y[i]);
		temp = temp->pNext;
		i--;
	}
	for (i = 0; i < q; i++)
	{
		free(x[i]);
		free(y[i]);
	}
	free(x);
	free(y);
	return 1;
}
//���ڼ����׺ʽ
status cal_list(stack s)
{
	stack mystack;
	initstack(&mystack);
	ElemType *temp;
	temp = s.top;
	while (temp != s.base)
	{
		if (judgenumber(temp->date[0]) != -1)//����������žͽ���ѹջ
		{
			push(&mystack, temp->date);
			//�ж��Ƿ���Խ�������
			if ( judgenumber(mystack.top->date[0]) == 1)//�������
			{
				if (judgenumber(mystack.top->pNext->date[0]) == 0)//����
				{
					if (judgenumber(mystack.top->pNext->pNext->date[0]) == 0)//��������ת�������㲢ѹջ
					{
						char *v=(char*)malloc(sizeof(char)*DATE_NUM);//�õ�
						int a =(int) atof(mystack.top->pNext->date);
                        
						int b = (int)atof(mystack.top->pNext->pNext->date);
						
						int c = cal(a, b, mystack.top->date[0]);
						printf("\nȡ��ջ�е� %d %d ����%c�ļ���", a, b, mystack.top->date[0]);
						printf("  %d %c %d = %d\n", a, mystack.top->date[0], b, c);
						Pop_Stack(&mystack, &v);
						//printf("����%s \n", val);
						Pop_Stack(&mystack, &v);
						//printf("����%s \n", val);
						Pop_Stack(&mystack, &v);
					     itoa(c, v,10);
						push(&mystack, v);
					}
				}
			}
			temp = temp->pNext;
		}
		else
		{
         	temp = temp->pNext;
		}
	}
	return (int)atof(mystack.top->date);
}
int cal(int a, int b, char x)//���м���
{
	switch (x)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return b - a;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return b/a;
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
