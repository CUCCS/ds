#include "�㷨2.12.h"
void CreatList(Linklist *L, int n)//��λ������n��Ԫ�ص�ֵ,��������ͷ���ĵ������Ա�L
{
	int i;
	Linklist p;
	int *a = (int *)malloc(sizeof(int)*n);
	A(a, n);
	(*L) = (Linklist)malloc(sizeof(LNode));
	(*L)->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (i = n; i > 0; i--)
	{
		p = (Linklist )malloc(sizeof(LNode));//�����µĽ��
		p->data = a[n - i];
		p->next = (*L)->next;
		(*L)->next = p;//���뵽��ͷ
	}
	free(a);
}
void output(Linklist s)
{
	s = s->next;
	printf("\nthe List is:\n");
	while (s != NULL)
	{
		printf("%d ", s->data);
		s = s->next;
	}
	printf("\n\n");
}
void MergeList_L(Linklist La, Linklist Lb, Linklist *Lc)
{
	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µĵ������Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	Linklist l,pa,pb,pc;
	 pa = La->next;
	 pb = Lb->next;
	 (*Lc) = pc = La;
	while (pa&&pb) //�ж�pa��pb�Ƿ�Ϊ��
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;//��Pa����Pc����Pa�ĵ�ַ��Pc,Paָ����һ�����ڽ��
			pc->next = NULL;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;//��Pb����Pc����Pa�ĵ�ַ��Pc,Pbָ����һ�����ڽ��
			pc->next = NULL;

		}
		l = (*Lc)->next;
		while (l != NULL)
		{
			printf("%d ", l->data);
			l = l->next;
		}
		printf("\n");
	}
	pc->next = pa ? pa : pb;
	l = (*Lc)->next;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
}//MergeList


void A(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 + 1;//���������
	for (i = 0; i < n - 1; i++)//ð������,�����������
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
	}
}

void destroyList(Linklist s)
{
	Linklist l;
	while (s != NULL)
	{
		l = s->next;
		free(s);
		s = l;
	}
}
int main()
{
	srand(time(0));
	Linklist La, Lb, Lc;
	int a = x;
	int b = y;
	CreatList(&La, a);
	output(La);
	printf("\n");
	CreatList(&Lb, a);
	output(Lb);
	printf("\n");
	MergeList_L(La, Lb, &Lc);
	output(Lc);
	destroyList(Lb);
	return 0;
}