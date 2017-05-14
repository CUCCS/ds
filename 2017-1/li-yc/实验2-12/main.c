#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "List.h"

#define length 5

int main(){
	LinkList La;
	LinkList Lb;
	LinkList Lc;

	printf("函数开始执行\n\n");
	srand(time(0));

	La=(LinkList)malloc(sizeof(LNode));
	printf("开始创建链表La\n");
	creatList(La,length+rand()%5);
	printf("对链表La进行遍历");
	printf("\nLa:");
	Traverse(La);
	printf("\n\n");

	Lb=(LinkList)malloc(sizeof(LNode));
	printf("开始创建链表Lb\n");
	creatList(Lb,length+rand()%5);
	printf("对链表Lb进行遍历");
	printf("\nLb:");
	Traverse(Lb);
	printf("\n\n");

	printf("\n");
	MergeList(La,Lb,Lc);
	printf("合并后的数组Lc为:");
	Traverse(Lc);
	printf("\n");
	return 0;
}