#include "hello.h"
int main()
{
	srand(time(0));
	LinkList la, lb, lc;
	int a = LIST_NUM_A;
	int b = LIST_NUM_B;//la�ĳ��Ⱥ�lb�ĳ��Ⱦ�Ϊ�곣��
	CreatList(&la, a);
	output(la);
	CreatList(&lb, b);
	output(lb);
	MergeList(la, lb, &lc);
	output(lc);
	destoryList(lb);
	return 0;
}

//��������n��Ԫ�ص�ֵ������������
void CreatList(LinkList *L, int n)
{

	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	assign_value(a, n);
	LinkList p;
	(*L) = (LinkList)malloc(sizeof(LNode));//ͷ�ڵ�
	(*L)->next = NULL;
	for (i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		p->data = a[n - i];           //����Ԫ��ֵ   
		p->next = (*L)->next;
		(*L)->next = p; //���뵽��ͷ 
	}
	free(a);
}

//��֪���������Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ�����
//�ϲ������lc ��Ȼ��ֵ�ǵݼ�����
void MergeList(LinkList la, LinkList lb, LinkList *lc)
{
	LinkList  pa, pb, pc, l = NULL, lc_copy;
	pa = la->next;
	pb = lb->next;
	(*lc) = pc = la;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pc->next = NULL;

		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
			pc->next = NULL;
		}

		lc_copy = (*lc)->next;

		while (lc_copy != NULL)
		{
			printf("%d ", lc_copy->data);
			lc_copy = lc_copy->next;
		}
		printf("\n");

		//������  �ҵ��㷨��
	}
	pc->next = pa ? pa : pb;
	lc_copy = (*lc)->next;
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
	// ð�ݷ������������
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
		l = l->next;
	}
	printf("\n\n");
}
//������ִ������
void destoryList(LinkList  l)
{
	LinkList  p;

	while (NULL != l)
	{
		p = l->next;
		free(l);
		l = p;
	}

}