 #include "Algorithm 2.12.h"
void CreatList(SLinkList &L, int n)//��λ������n��Ԫ�ص�ֵ,��������ͷ���ĵ������Ա�L
{
	int i;
	int *a = (int*)malloc(sizeof(int)*n);
	A(a, n);
	SLinkList p;
	L = (SLinkList)malloc(sizeof(component));
	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (i = n; i > 0; --i)
	{
		p = (SLinkList)malloc(sizeof(component));//�����µĽ��
		p->data = a[n - i];//����Ԫ��ֵ
		p->next = L->next;
		L->next = p;//���뵽��ͷ
	}

}
void output(SLinkList b)
{

	b = b->next;
	printf("\nthe List is:\n");
	while (b != NULL)
	{
		printf("%d ", b->data);
		b = b->next;
	}
	printf("\n\n");
}
void MergeList_L(SLinkList &La, SLinkList &Lb, SLinkList &Lc) {
	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µĵ������Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	SLinkList l;
	SLinkList pa = La->next;
	SLinkList pb = Lb->next;
	SLinkList pc = Lc = La;
	while (pa&&pb) {//�ж�pa��pb�Ƿ�Ϊ��

		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa;
			pa = pa->next;//��Pa����Pc����Pa�ĵ�ַ��Pc,Paָ����һ�����ڽ��
		}
		else
		{
			pc->next = pb; pc = pb; pb = pb->next;//��Pb����Pc����Pa�ĵ�ַ��Pc,Pbָ����һ�����ڽ��
		}
		l = Lc->next;
		while (l != NULL)
		{
			printf("%d ", l->data);
			l = l->next;
		}
		printf("\n");
	}
	pc->next = pa ? pa : pb;//����ʣ���
	l = Lc->next;
	while (l != NULL)
	{
		printf("%d ", l->data);
		l = l->next;
	}
	printf("\n");
}//MergeList
void A(int a[], int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 + 1;//���������
	for (i = 0; i < n - 1; i++)//ð������
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
int main()
{
	srand(time(0));
	SLinkList La, Lb, Lc;
	int a = x;
	int b = y;
	CreatList(La, a);
	output(La);
	printf("\n");
	CreatList(Lb, a);
	output(Lb);
	printf("\n");
	MergeList_L(La, Lb, Lc);
	if (Lb != NULL)
	{
		free(Lb);
	}
	output(Lc);
	return 0;
}