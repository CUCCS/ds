#include<stdio.h> 
#include"up1998.h"
int main(void)
{ 
LinkList La, Lb, Lc; 
LinkList test1，test2;
    int LENTH=5;
	La = (LinkList)malloc(sizeof(LNode)); //malloc() 返回的类型是void * 型, 不相同的类型不能进行赋值运算, 所以要进行强制类型转换
	CreateList_L(La, LENTH+rand()%5, test1);//创建list 
	printf("La:");//输出la
	TraverseList_L(La, print); //遍历La
	printf("\n"); 
	 
	Lb = (LinkList)malloc(sizeof(LNode)); //malloc() 返回的类型是void * 型, 不相同的类型不能进行赋值运算, 所以要进行强制类型转换
	CreateList_L(Lb, LENTH+rand()%5, test2); //创建list
	printf("Lb:"); //输出lb
	TraverseList_L(Lb, print);//遍历lb 
	printf("\n"); 
 
	MergeList_L(La, Lb, &Lc); //合并一个lc &Lc有问题
	printf("Lc:"); //输出lc
	TraverseList_L(Lc, print);//遍历lc 
	printf("\n"); 
	return 0; 
}
