//#include<stdio.h>
////ͷ�ļ�����׼�������
//#include<stdlib.h>
////�ڴ���亯��malloc��ͷ�ļ�
//typedef struct LNode
//{
//	int data;//����
//	struct LNode *next;//ָ����һ���ڵ��ָ��
//
//}LNode, *Linklist;
//Linklist CreatList(LNode *L, int n);//�����µ����Ա�ĺ���
//Linklist MergeList(LNode *l1, LNode  *L2, LNode *l3);//ʵ���������������γɵ���������
//void output(LNode *ll, int n);
#include "Source.h";


int main()
{
	Linklist la = NULL, lb = NULL, lc = NULL;//��������Linklist����
	//srand((unsigned)time(NULL));
	int a, b;
	a = rand() % 101;
	/*scanf("%d", &a);*/
	la = CreatList(la, a);//���ú���������һ�����Ա�
    b= rand() % 101;
	/*scanf("%d", &b);*/
	lb = CreatList(lb, b);
	lc = MergeList(la, lb, lc);//���ú���ʵ���������Ա�����
							   //lc = lc->next;
	output(lc, a + b);
	return 0;

}

Linklist CreatList(LNode *L, int n)
{
	LNode * p = NULL;
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
	/*	
		p->data = rand() % 101;*/
		p = (LNode *)malloc(sizeof(LNode));
	/*	scanf("%d", &p->data);*/
		p->data = rand() % 101; 
		p->next = L->next;
		L->next = p;
	}
	return L;
}


Linklist MergeList(LNode *l1, LNode *l2, LNode *l3)
{
	LNode * la = NULL;
	LNode * lb = NULL;
	LNode * lc = NULL;
	la = l1->next;
	lb = l2->next;
	l3 = lc = l1;
	while (la&&lb)//��la��lb����Ϊ��ʱ���в���
	{
		if (la->data <= lb->data)
		{
			lc->next = la;
			lc = la;
			la = la->next;
		}
		else
		{
			lc->next = lb;
			lc = lb;
			lb = lb->next;
		}
	}
	lc->next = (la ? la : lb);

	if (l2 != NULL)
		free(l2);//���ڶ������Ա�ռ�õ��ڴ��ͷ�

	return l3;
}

void output(LNode *ll, int n)
{
	int i;
	LNode *p = ll->next;
	for (i = n; i > 0; i--)

	{
		printf("%d", p->data);
		p = p->next;
	}

}