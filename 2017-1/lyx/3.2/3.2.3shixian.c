#include"3.2.3.h"
Status LineEdit(SqStack *s,char *a)
{ //�ı��༭������
	char c,ch,l;//�����ַ���c��ch
	ch=getchar();//�����ַ���ch
	while (ch != EOF)//���ch��Ϊ��
	{
		while(ch != EOF&&ch != '\n')//���ch��Ϊ���Ҳ�Ϊ����
		{
			switch(ch)//switchѡ�����
			{
			case '#'://��chΪ#
				{
					Pop(s,&c);//ɾ��ջ��Ԫ�أ�c����ֵ
					SElemType*l = s->base;//����ջ��Ԫ��
					while (l != s->top)//l��Ϊջ��Ԫ��ʱ
					{
						printf("%c",*l);//���l
						l++;//l�Լ�
					}
					printf("\n");//����
					break;//����switch���
				}
			case '@'://��chΪ@
				{
					ClearStack(s);//���ջ
					SElemType*l = s->base;//����ջ��Ԫ��
					while (l != s->top)//l��Ϊջ��Ԫ��ʱ
					{
						printf("%c",*l);//���l
						l++;//l�Լ�
					}
					printf("\n");//����
					break;//����switch���
				}
			default://�������
				{
					Push(s,ch);//����sΪ�µ�ջ��Ԫ��
					SElemType*l = s->base;//����ջ��Ԫ��
					while (l != s->top)//l��Ϊջ��Ԫ��ʱ
					{
						printf("%c",*l);//���l
						l++;//l�Լ�
					}
					printf("\n");//����
				}//end default
			}//end switch
	
		ch = getchar();//����ch
	}//end while
	int i=0;//��������iΪ0
	while (s->top != s->base)//��ջ�ǿ�ʱ
	{
		a[i] = *(s->base);//a[i]Ϊջ��Ԫ��
		s->base++;//ջ��Ԫ��ָ����һ��
		i++;//i�Լ�
	}
	a[i] = '\0';//��ջ��Ԫ��Ϊ����ʱ
	printf("result:\n");//������
	puts(a);//���a[i]
	ClearStack(s);//���ջ
	if(ch != EOF)//��ch��Ϊ����ʱ
	{
		ch = getchar();	//����ch
	}
	}//end while
	DistoryStack(s);//����ջ
		return OK;//����OK �ɹ�
}// LineEdit

bool StackEmpty(SqStack *s)
{//��ջsΪ��ջ���򷵻�TRUE�����򷵻�FALSE
	if(s->base == s->top){//��ջ��ָ�����ջ��ָ��
		return true;//��ջsΪ��ջ
	}
	else{//��ջ��ָ�벻����ջ��ָ��
		return false;//��ջs���ǿ�ջ
	}
}//StackEmpty

Status ClearStack(SqStack *s)
{//��S��Ϊ��ջ
	s->top = s->base;//ջ��ָ�����ջ��ָ��
	return OK;//����OK
}//ClearStack

Status DistoryStack(SqStack *s)
{//����ջs��s���ٴ���
	while (!StackEmpty)//��ջ�ڻ���Ԫ��ʱ
	{
		s->top = NULL;//ջ��ָ��Ϊ��
		s->top--;//ջ��ָ���Լ�
	}
	s->base = NULL;//ջ��ָ��
	free(s->base);//�ͷ�ջ��ָ��
	free(s->top);//�ͷ�ջ��ָ��
	return OK;//����OK
}//DistoryStack

Status InitStack(SqStack *s)
{//����һ����ջ
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));//����洢�ռ�
	if(!s->base){//�����
		return OVERFLOW;
	}
	s->top = s->base;//ʹջ��ָ�����ջ��ָ��
	s->stacksize = STACK_INIT_SIZE;//�м������������ջ�Ĵ�С
	return OK;
}//InitStack

Status Push(SqStack *s,SElemType e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if(s->top - s->base > s->stacksize){//ջ����׷�Ӵ洢�ռ�
		s->base = (SElemType*)realloc(s->base,(s->stacksize + 2*STACK_INIT_SIZE)*sizeof(SElemType));//׷�Ӵ洢�ռ�
		if(!s->base){//�����
			return OVERFLOW;
		}
		s->top = s->base + s->stacksize;//����ջ��Ԫ��
		s->stacksize += 2 * STACK_INIT_SIZE;//׷�Ӵ洢�ռ�
	}
	*s->top = e;//����Ԫ��eΪ�µ�ջ��Ԫ��
	s->top++;//s���£�ָ��topԪ��
	return OK;
}//Push

Status Pop(SqStack *s,SElemType *e)
{//��ջ���գ���ɾ��s��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(s->top == s->base){//ջΪ��ջ
		return ERROR;//����ERROR
	}
	else{
		*e = * --s->top;//ջ��ָ���Լ���ָ����һ��Ԫ��
	}
}//Pop



