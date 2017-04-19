#include"List.h"
int main() {
	srand(time(0));
	int n = rand() % 10 + 1;
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LinkList L1 = (LinkList)malloc(sizeof(LNode));
	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	CreateList(L, n);
	printf("随机创建：\n");
	PRINT(L);
	printf("\n按序列奇偶分离:\n");
	SperateList(L, L1, L2, n);
	printf("奇列：\n");
	PRINT(L1);
	printf("偶列：\n");
	PRINT(L2);
	//时间复杂度O(n),奇偶分离创建列表于一个函数
}