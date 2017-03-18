#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

#define LEN 5

//以下4个函数用于产生有序测试数据
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
	printf("进入main函数\n\n");
	LinkList La, Lb, Lc;
	srand(time(0));

	La = (LinkList)malloc(sizeof(LNode));
	printf("开始创建单链表La\n");
	CreateList_L(La, LEN+rand()%5, test1);
	printf("创建完毕\n对单链表La进行遍历\n");
	printf("La:");
	TraverseList_L(La, print);
	printf("\n遍历完毕\n\n");

	Lb = (LinkList)malloc(sizeof(LNode));
	printf("开始创建单链表Lb\n");
	CreateList_L(Lb, LEN + rand() % 5, test2);
	printf("创建完毕\n对单链表Lb进行遍历\n");
	printf("Lb:");
	TraverseList_L(Lb, print);
	printf("\n遍历完毕\n\n");

	printf("开始归并单链表La与Lb\n");
	MergeList_L(La, Lb, &Lc);
	printf("归并完毕\n对单链表Lc进行遍历\n");
	printf("Lc:");
	TraverseList_L(Lc, print);
	printf("\n遍历完毕\n\n");
	return 0;
}