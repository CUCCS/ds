#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "List.h"

#define length 5

int main(){
	LinkList La;
	LinkList Lb;
	LinkList Lc;

	printf("������ʼִ��\n\n");
	srand(time(0));

	La=(LinkList)malloc(sizeof(LNode));
	printf("��ʼ��������La\n");
	creatList(La,length+rand()%5);
	printf("������La���б���");
	printf("\nLa:");
	Traverse(La);
	printf("\n\n");

	Lb=(LinkList)malloc(sizeof(LNode));
	printf("��ʼ��������Lb\n");
	creatList(Lb,length+rand()%5);
	printf("������Lb���б���");
	printf("\nLb:");
	Traverse(Lb);
	printf("\n\n");

	printf("\n");
	MergeList(La,Lb,Lc);
	printf("�ϲ��������LcΪ:");
	Traverse(Lc);
	printf("\n");
	return 0;
}