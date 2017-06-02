#include<stdio.h>
#include <stdlib.h>
#include "BSTtraverse.h"

int main()
{
	BSTree T;
	T = NULL;
	bool n;
	int array[] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int find[] = { 13, 8, 5, 20, 6 };
	T = CreatBST(T, array);
	PrePrintBST(T); //打印当前查找表
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		n = SearchBST(T, find[i]);
		if (!n)                  //未找到目标节点
		{
			T = InsertBST(T, find[i]);//插入该结点
			/*printf("%d\n", find[i]);*/
			PrePrintBST(T);
			printf("\n");
		}
		else                     //找到目标节点
		{
			if (DeleteBST(&T, find[i]))//删除该结点
			{
				PrePrintBST(T);
			}
			printf("\n");
		}
	}
	return 0;
}