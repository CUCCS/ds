#include "13.h"
int main()
{
	Lnode *p = ListCreat();//����Ҫ��ʼ������������   ʹ����β�巨���в���
	print_list(p);
	Lnode *p1;
	Lnode *p2;
	ApartList(p, &p1, &p2);//��������в�� ֻ��Ҫ����һ�β�� ��ʡ��ѭ����ʱ��
	printf("��ֺ�ĵ�һ������\n");
	print_circle_list(p1);//�����һ��ѭ��������
	printf("��ֺ�ĵڶ�������\n");
	print_circle_list(p2);//����ڶ���ѭ��������
	destory(&p1);//���ٵ�һ��ѭ������
	destory(&p2);//���ٵڶ���ѭ��������
	return 0;
}
//��ʼ��һ������ β�巨
Lnode * ListCreat()
{
	int i;
	int num;
	printf("�������ʼ����������ĳ���\n");
	scanf_s("%d", &num);
	Lnode *L;
	L = (Lnode *)malloc(sizeof(Lnode));   //����ͷ���ռ�  
	L->data = 1;
	L->next = NULL;                  //��ʼ��һ��������  
	Lnode *r;
	r = L;                          //rʼ��ָ���ն˽�㣬��ʼʱָ��ͷ��� 
	for (i = 2; i <= num; i++)
	{
		Lnode *p;
		p = (Lnode *)malloc(sizeof(Lnode));
		p->data = i;                     //���������ֵ   
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L;
}
//���������������� �������ѭ������
int ApartList(Lnode *t,Lnode **px, Lnode **py)
{//β�巨
	Lnode *p1;
	Lnode *p2;
	Lnode *temp1;
	Lnode *temp2;
	Lnode *temp;
	Lnode *p;
	p = t;
	p1 = (Lnode *)malloc(sizeof(Lnode));   //����ͷ���ռ�  
	p1->next = NULL;
	p2 = (Lnode *)malloc(sizeof(Lnode));   //����ͷ���ռ�
	temp1 = p1;
	temp2 = p2; 
	p2->next = NULL; 
	while (NULL != p)
	{
		temp = p;
		p = p->next;
		if (temp->data % 2 != 0)//���������
		{	 
			temp->next= temp1->next;//temp1�ƶ����������β����
			temp1->next = temp;
			temp1 = temp;
		}
		else
		{
			temp->next = temp2->next;//temp2�ƶ�
			temp2->next = temp;
			temp2 = temp;
		}
	}//�������ɵ�ʱ��
	p1->data = (temp1->data + 1) / 2;
	p2->data = temp2->data / 2;
	temp1->next = p1;
	temp2->next = p2;
	*px = p1;
	*py = p2;
	return 0;
}
//��ӡ��ʼ������
int print_list(Lnode *p)
{
	printf("��ʼ������Ϊ��\n");
	do
	{
		printf("%d ", p->data);
		p = p->next;
	}while (p!= NULL);
	printf("\n");
	return 1;
}
//��ӡѭ��������
int print_circle_list(Lnode *p)
{
	Lnode *t;
	printf("������Ϊ %d  \n", p->data);
    t = p;
	p = p->next;
	printf("Ԫ��Ϊ�� ");
	do
	{
		printf("%d ", p->data);
		p = p->next;
	} while (p != t);
	printf("\n\n");
	return 1;
}
//��������
int destory(Lnode **p)
{
	Lnode *t;	
	int i;
	int k = (*p)->data+1;
	for (i = 0; i < k; i++)
	{
    t = *p;
	(*p) = (*p)->next;
	free(t);
	}
	return 1;
}