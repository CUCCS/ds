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
	PrePrintBST(T); //��ӡ��ǰ���ұ�
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		n = SearchBST(T, find[i]);
		if (!n)                  //δ�ҵ�Ŀ��ڵ�
		{
			T = InsertBST(T, find[i]);//����ý��
			/*printf("%d\n", find[i]);*/
			PrePrintBST(T);
			printf("\n");
		}
		else                     //�ҵ�Ŀ��ڵ�
		{
			if (DeleteBST(&T, find[i]))//ɾ���ý��
			{
				PrePrintBST(T);
			}
			printf("\n");
		}
	}
	return 0;
}