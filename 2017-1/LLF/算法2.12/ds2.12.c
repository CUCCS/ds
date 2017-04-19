#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
#define LEN sizeof(struct LNode)

//���嵥�����Ա�
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

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
	


//�����������Ա�
LNode* CreateList_L( int n)//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��
{
	LNode * L;
	int i;


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
		L->next = p;//���뵽��ͷ
	}
	
	return SelectSort(L);

}//CreateList_L


 //��֪�������Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ����С�
 //�鲢la��lb�õ��µĵ������Ա�lc��lc��Ԫ��Ҳ��ֵ�ǵݼ����С�
LNode* MergeList_L(LNode * La, LNode * Lb, LNode * Lc)
{
	struct LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	Lc = pc;//��la��ͷ�����Ϊlc��ͷ���
	while (pa&&pb)
	{
		if (pa->data <= pb->data) //��pa��ָ������ӵ�pc��ָ���֮��
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else       //��pb��ָ������ӵ�pc��ָ���֮��
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
  	pc->next = pa ? pa : pb; //����ʣ���
	free(Lb);     //�ͷ�lb��ͷ���
	return Lc;
}//MergeList_L

 //������
void Print_L(struct LNode *head)
{
	struct LNode *p;
	p = head->next;
	if (p != NULL)        //������ǿ�������������������нڵ�  
	{
		do
		{
			printf("%d ", p->data);//�������
			p = p->next;     //�Ƶ���һ���ڵ�  
		} while (p != NULL);
	}
	printf("\n");
}//Print_L

int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));//��ʱ������

	int n;
	n = (int)rand() % 20;//������ɸ���

	LNode * La, *Lb, *Lc;//��������

	La = CreateList_L(n);
	printf("La:  ");
	Print_L(La);//��ӡLa

	Lb = CreateList_L(n);
	printf("Lb:  ");
	Print_L(Lb);//��ӡLb

	Lc = NULL;

	Lc=MergeList_L(La, Lb, Lc);//����
	printf("Lc:  ");
	Print_L(Lc);//��ӡlc

	return 0;
}