#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

#define LEN 5

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
//以上4个函数用于产生有序测试数据

int main(void){
	LinkList La, Lb, Lc;
	srand(time(0));

	La = (LinkList)malloc(sizeof(LNode));
	CreateList_L(La, LEN+rand()%5, test1);
	printf("La:");
	TraverseList_L(La, print);
	printf("\n");

	Lb = (LinkList)malloc(sizeof(LNode));
	CreateList_L(Lb, LEN+rand() % 5, test2);
	printf("Lb:");
	TraverseList_L(Lb, print);
	printf("\n");

	MergeList_L(La, Lb, &Lc);
	printf("Lc:");
	TraverseList_L(Lc, print);
	printf("\n");
	return 0;
}