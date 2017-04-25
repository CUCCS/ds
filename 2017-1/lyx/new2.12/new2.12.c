#include<stdio.h>
#include<malloc.h>
#include<time.h>//���������
#include<stdlib.h>
#define LEN sizeof(struct LNode)

//���嵥�����Ա�
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;


//�����������Ա�
LNode* CreateList_L( int n)//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��
{
	LNode * L;
	int i;
	srand((unsigned)time(NULL));//��ʱ������

	if (n < 0)//���������Ϸ�������
	{
		exit(0);
	}
	LNode * p;
	L = (LNode *)malloc(LEN);
	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (i = n; i > 0; --i)
	{
		p = (LNode *)malloc(LEN);//�����½��;
		p->data = (int)rand() % 2000;//�������Ԫ��ֵ
		p->next = L->next;
		L->next = p;//���뵽��ͷ��λ��
	}
	
	return SelectSort(L);

}//CreateList_L


//�����������ݽ��зǵݼ�����
LNode* SelectSort(LNode *L)
{
	LNode *p, *q, *small;
	int temp;

	for (p = L->next; p->next != NULL; p = p->next)    /*ÿ��ѭ�����ҳ�һ����Сֵ������Сֵ��������һλ��Ȼ��ָ������ƶ�һλ*/
	{
		small = p;
		for (q = p->next; q; q = q->next)    /*��ǰ���������ҳ���С�Ľڵ�*/
		{
			if (q->data < small->data)
				small = q;
		}
		if (small != p)
		{
			temp = p->data;
			p->data = small->data;
			small->data = temp;
		}
	}
	return L;
}

 //��֪�������Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ����С�
 //�鲢la��lb�õ��µĵ������Ա�lc��lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
LNode* MergeList_L(LNode * La, LNode * Lb, LNode * L)
{
	struct LNode *pa, *pb, *p;
	pa = La->next;
	pb = Lb->next;
	p = La;
	L = p;//��la��ͷ�����Ϊlc��ͷ���
	while (pa&&pb)//papb���� ��=NULL����La->next,Lb->next != null,lalb����û�н���
	{
		if (pa->data <= pb->data) //��pa��ָ������ӵ�pc��ָ���֮��
		{
			p->next = pa;
			p = pa;
			pa = pa->next;
		}
		else       //��pb��ָ������ӵ�pc��ָ���֮��
		{
			p->next = pb;
			p = pb;
			pb = pb->next;
		}
	}
  	p->next = pa ? pa : pb; //����ʣ���
	free(Lb);     //�ͷ�lb��ͷ���
	return L;
}//MergeList_L

 //������
void Print_L(struct LNode *head)
{
	struct LNode *p;
	p = head->next;
	if (p != NULL)        //������ǿ�������������������нڵ�  
	{
		while (p != NULL);
		{
			printf("%d ", p->data);//�������
			p = p->next;     //�Ƶ���һ���ڵ�  
		} 
	}
	printf("\n");
}//Print_L

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));//���������
	
	int n = (int)rand() % 20;//������ɸ���

	LNode * La, *Lb, *L;//��������

	La = CreateList_L(n);
	printf("La:  ");
	Print_L(La);//��ӡLa

	Lb = CreateList_L(n);
	printf("Lb:  ");
	Print_L(Lb);//��ӡLb

	L = NULL;

	L=MergeList_L(La, Lb, L);//����
	printf("L:  ");
	Print_L(L);//��ӡlc

	return 0;
}