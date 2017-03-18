#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

#define LEN 5

//����4���������ڲ��������������
int test1_iter(int k){
	static int b = 20;
	return b -= k;
}
void test1(ElemType *p){
	*p = test1_iter(rand() % 5+1);
}
int test2_iter(int k){
	static int b = 20;
	return b -= k;
}
void test2(ElemType *p){
	*p = test2_iter(rand() % 5+1);
}

int main(void){
	printf("����main����\n\n");
	LinkList La, Lb, Lc;
	srand(time(0));

	La = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ����������La\n");
	CreateList_L(La, LEN+rand()%5, test1);
	printf("�������\n�Ե�����La���б���\n");
	printf("La:");
	TraverseList_L(La, print);
	printf("\n�������\n\n");

	Lb = (LinkList)malloc(sizeof(LNode));
	printf("��ʼ����������Lb\n");
	CreateList_L(Lb, LEN + rand() % 5, test2);
	printf("�������\n�Ե�����Lb���б���\n");
	printf("Lb:");
	TraverseList_L(Lb, print);
	printf("\n�������\n\n");

	printf("��ʼ�鲢������La��Lb\n");
	MergeList_L(La, Lb, &Lc);
	printf("�鲢���\n�Ե�����Lc���б���\n");
	printf("Lc:");
	TraverseList_L(Lc, print);
	printf("\n�������\n\n");
	return 0;
}