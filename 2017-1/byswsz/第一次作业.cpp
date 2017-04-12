#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  LIST_numa  4;
#define  LIST_numb  4;//����洢�ռ�����޶�Ϊ4
typedef struct LNode
{
	int data;
	struct LNode *next;

}LNode, *LinkList;//���Ա�ĵ�������ṹ��
//�����溯����������
void CreatList(LinkList &L, int n);
void MergeList(LinkList&la, LinkList&lb, LinkList&c);
void output(LinkList l);
void assign_value(int a[], int n);



//������������
int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a =LIST_numa;
	int b =    LIST_numb ;//la�ĳ��Ⱥ�lb�ĳ��Ⱦ�Ϊ�곣������ǰ���Ѿ����޶�Ϊ��
	CreatList(la, a);
	output(la);
	CreatList(lb, b);
	output(lb);
	MergeList(la, lb, lc);
	if (lb != NULL)
	{
		free(lb);
	}

	output(lc);
	return 0;

}
//��������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ�����
void CreatList(LinkList &L, int n)
{

	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	assign_value(a, n);
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		p->data = a[n - i];           //����Ԫ��ֵ   
		p->next = L->next; L->next = p; //���뵽��ͷ 
	}

}
//��֪���������Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ�����
//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList(LinkList&la, LinkList&lb, LinkList&lc)
{	
	LinkList  pa, pb, pc, l = NULL, lc_copy;
	pa = la->next;
	pb = lb->next;
	lc = pc = la;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pc->next = NULL;

		}//����La�Ľ��й鲢����һ��ѭ��������һ��Ϊ�յ�ʱ��˵���鲢һ�����
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			pc->next = NULL;
		}

		lc_copy = lc->next;

		while (lc_copy != NULL)
		{
			printf("%d ", lc_copy->data);
			lc_copy = lc_copy->next;
		}
		printf("\n");//�ڶ����鲢��
	
		
	}
	pc->next = pa ? pa : pb;
	lc_copy = lc->next;
	while (lc_copy != NULL)
	{
		printf("%d ", lc_copy->data);
		lc_copy = lc_copy->next;
	}
	printf("\n");
}
//���������������������
void assign_value(int a[], int n)
{
	int i, j, temp;
	//���������
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 20 + 1;
	}
	// ð�����򷨶����������
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
		}
	}


}
//�������
void output(LinkList  l)
{
	l = l->next;
	printf("\nthe List is:\n");

	while (l != NULL)
	{
		printf("%d ", l->data);
		l= l->next;
	}
	printf("\n\n");
}