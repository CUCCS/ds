#include "AVLTree.h"
extern int flag;
#define num 12
#define Search_num 5
int main()
{

	int a[num] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[Search_num] = { 13, 8, 5, 20, 6 };
	int i;
	bool taller, m;
	char d = '\n';
	FILE *pfile;
	BSTree T = NULL, pos, f, p;

	p = (BSTree)malloc(sizeof(BSTree));
	f = (BSTree)malloc(sizeof(BSTree));

	pfile = fopen(" AVLOutput.txt ", "a");


	CreatBST(&T, a, num);

	TraversePrint(T, pfile);
	fwrite(&d, sizeof(d), 1, pfile);

	for (i = 0; i < Search_num; i++)
	{
		m = SearchAVL(T, b[i], f, &p);
		printf("--------------------------------------------------------\n\n");
		printf("开始在二叉排序树中查找%d: ", b[i]);
		if (m == true)
		{
			printf("\n找到%d,在二叉排列树中删除%d\n", b[i], b[i]);
			DeleteAVL(&T, b[i]);
		}
		else
		{
			printf("\n未找到%d,在二叉排列树中插入%d\n", b[i], b[i]);
			InsertAVL(&T, b[i], &taller);
		}
		printf("现在的二叉排列树为：", b[i]);
		PreOrderTraverse(T);
		printf("\n\n");
		flag = 0;
		TraversePrint(T, pfile);
		fwrite(&d, sizeof(d), 1, pfile);
	}
	return 0;
}