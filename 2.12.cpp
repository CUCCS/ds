# include "LinkList.h"

int main()
{
	LinkList La;
	LinkList Lb;
	LinkList L;
	int n1=0, n2=0;
	int i;
	srand(time(0));
		n1 = rand()%10+ 1;
		n2 = rand()%10+ 1;
	printf("随机生成链表长度\n%d,%d\n",n1-1,n2-1 );//链表长度；
	CreateList_L(La, n1);
	CreateList_L(Lb, n2);
	Order_L(La);
	Order_L(Lb);
	printf_s("链表1：\n");
	output(La);
	printf_s("\n");
	printf_s("链表2：\n");
	output(Lb);
	printf("\n\n");
	MergeList_L(La, Lb, L);
	if (Lb)
	{
		free(Lb);
	}
	printf("\n合并链表：\n");
	output(L);
}