#include<stdio.h> 
#include"up1998.h"
int main(void)
{ 
LinkList La, Lb, Lc; 
LinkList test1��test2;
    int LENTH=5;
	La = (LinkList)malloc(sizeof(LNode)); //malloc() ���ص�������void * ��, ����ͬ�����Ͳ��ܽ��и�ֵ����, ����Ҫ����ǿ������ת��
	CreateList_L(La, LENTH+rand()%5, test1);//����list 
	printf("La:");//���la
	TraverseList_L(La, print); //����La
	printf("\n"); 
	 
	Lb = (LinkList)malloc(sizeof(LNode)); //malloc() ���ص�������void * ��, ����ͬ�����Ͳ��ܽ��и�ֵ����, ����Ҫ����ǿ������ת��
	CreateList_L(Lb, LENTH+rand()%5, test2); //����list
	printf("Lb:"); //���lb
	TraverseList_L(Lb, print);//����lb 
	printf("\n"); 
 
	MergeList_L(La, Lb, &Lc); //�ϲ�һ��lc &Lc������
	printf("Lc:"); //���lc
	TraverseList_L(Lc, print);//����lc 
	printf("\n"); 
	return 0; 
}
