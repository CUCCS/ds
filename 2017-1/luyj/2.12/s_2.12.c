# include "2.12.h"

int main()
{
	LinkList La;
	LinkList Lb;
	LinkList L;
	La = (LinkList)malloc(sizeof(LNode));
	Lb = (LinkList)malloc(sizeof(LNode));
	L = (LinkList)malloc(sizeof(LNode));
	int n1 = 0, n2 = 0;
	int i;
	srand(time(0));
	n1 = rand() % 10 + 1;
	n2 = rand() % 10 + 1;
	printf("�������������\n%d,%d\n", n1, n2);//�����ȣ�
	srand(time(0));
	CreateList_L(La, n1);
	CreateList_L(Lb, n2);
	Order_L(La);
	Order_L(Lb);
	printf_s("����1��\n");
	output(La);
	printf_s("\n");
	printf_s("����2��\n");
	output(Lb);
	printf("\n\n");
	MergeList_L(La, Lb, &L);
	if (Lb)
	{
		free(Lb);
	}
	printf("\n�ϲ�����\n");
	output(L);
}