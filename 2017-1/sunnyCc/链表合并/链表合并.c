#include "happy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//�涨������LA,LB�Ļ�������
#define LEN 2
int main()
{

	LinkList La, Lb, Lc;

	//ʹ������������������������
	srand(time(0));

	//�����������LA,LB
	La = (LinkList)malloc(sizeof(LNode));
	CreateList_L(&La, LEN+rand()%5);
	Lb = (LinkList)malloc(sizeof(LNode));
	CreateList_L(&Lb, LEN+rand()%5);

	//��ӡLA,LBԪ��ֵ
	printf("\nLa:");
	TraverseList_L(La);
	printf("\n");
	printf("Lb:");
	TraverseList_L(Lb);
	printf("\n\n");

	//�ϲ�Ϊ��������LC
	MergeList_L(La, Lb,&Lc);
	printf("Lc:");
	//��ӡ�ϲ�LC
	TraverseList_L(Lc);
	printf("\n");
	return 0;
}