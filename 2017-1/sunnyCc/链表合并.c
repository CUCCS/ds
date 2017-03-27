#include "happy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//规定了链表LA,LB的基本长度
#define LEN 2
int main()
{

	LinkList La, Lb, Lc;

	//使用随机函数生成链表测试数据
	srand(time(0));

	//生成随机链表LA,LB
	La = (LinkList)malloc(sizeof(LNode));
	CreateList_L(&La, LEN+rand()%5);
	Lb = (LinkList)malloc(sizeof(LNode));
	CreateList_L(&Lb, LEN+rand()%5);

	//打印LA,LB元素值
	printf("\nLa:");
	TraverseList_L(La);
	printf("\n");
	printf("Lb:");
	TraverseList_L(Lb);
	printf("\n\n");

	//合并为有序链表LC
	MergeList_L(La, Lb,&Lc);
	printf("Lc:");
	//打印合并LC
	TraverseList_L(Lc);
	printf("\n");
	return 0;
}