//#include<stdio.h>
////ͷ�ļ�����׼�������
//#include<stdlib.h>
////�ڴ���亯��malloc��ͷ�ļ�
//typedef struct LNode
//{
//	int data;//����
//	struct LNode *next;//ָ����һ���ڵ��ָ��
//
//}LNode,*Linklist;
//void CreatList(Linklist &L, int n);//�����µ����Ա�ĺ���
//void MergeList(Linklist &l1, Linklist &L2, Linklist &l3);//ʵ���������������γɵ���������
//void output(Linklist ll, int n);//���γɵ����Ա�����
#include "Source.h"


int main()//�������������ƺ���
{
	Linklist la, lb, lc;//��������Linklist����
	int a, b;//��������int����
	scanf("%d", &a);//����Ҫ�����ĵ�һ�����Ա�ĳ���
	CreatList(la, a);//���ú���������һ�����Ա�
	scanf("%d", &b);//����ڶ������Ա�ĳ���
	CreatList(lb, b);//���ú��������ڶ������Ա�
	MergeList(la,lb,lc);//���ú���ʵ���������Ա�����
	lc=lc->next;//���Ա�lcָ����һ���ڵ�
	output(lc, a + b);//�������������Ա�
	return 0;

}

void CreatList(Linklist &L, int n)
{
	Linklist p;//����һ��Linklist��p��ʵ�ֶ�L�Ĳ���
	L = (Linklist)malloc(sizeof(LNode));//ΪL�����ڴ�ռ�
	L->next = NULL;//��Lָ���ָ��
	for (int i = n; i > 0; i--)//��ѭ���ṹ��������n������Ԫ���������
	{
		p = (Linklist)malloc(sizeof(LNode));//Ϊp�����ڴ�
		scanf("%d", &p->data);//������������Ԫ��
		p->next = L->next;//����p�Ĳ�����ֵ��L
		L->next = p;//�ƶ�ָ��p����һ���ڵ�
	}

}


void MergeList(Linklist &l1, Linklist &l2, Linklist &l3)
{
	Linklist la, lb, lc, l = NULL;//��������Linklist���������βν��в���
	la = l1->next;//��la���β�l1����
	lb = l2->next;//��lb���β�l2����
	l3 = lc = l1;//��lc���β�l3����,�ȸ�ֵ���ڵ�һ�����Ա�l1
	while (la&&lb)//��la��lb����Ϊ��ʱ���в���
	{
		if (la->data <= lb->data)//�����һ���������ݽϵڶ���С
		{
			lc->next = la;//����һ���������ݸ�ֵ��lC
			lc = la;
			la = la->next;//�ƶ�la����һ�����
		}
		else//���ڶ������Ա����ݸ�С
		{
			lc->next = lb; //���ڶ����������ݸ�ֵ��lc
			lc = lb;
			lb = lb->next;//�ƶ�lb����һ�����
		}
	}
	//���õ�һ�������Ա�İ���С����˳�����еĺϳ����Ա�
	lc->next = la ? la : lb;

	//�ж����յõ������Ա��ֵ��ԭ��������Ĺ�ϵ

	free(l);//���ڶ������Ա�ռ�õ��ڴ��ͷ�
}

void output(Linklist ll, int n)
{
	int i;
	for (i = n; i > 0; i--)

	{
		printf("%d", ll->data);//ѭ���ṹ����������Ա��еĸ�������Ԫ��
		ll = ll->next;//���ݽ�������

	}

}






