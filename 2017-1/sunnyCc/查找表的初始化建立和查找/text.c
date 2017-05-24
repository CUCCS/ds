#include "Search.h"
extern int flag;
#define num 12
#define Search_num 5
int main()
{
	int a[num] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[Search_num] = { 13, 8, 5, 20, 6 };
	int i;
	bool m;
	char d = '\n';
	FILE *pfile;
	BiTree T, f, p;

	T = (BiTree)malloc(sizeof(BiTNode));
	p = (BiTree)malloc(sizeof(BiTree));
	f = (BiTree)malloc(sizeof(BiTree));

	pfile = fopen(" BSTOutput.txt ", "a");

	CreatBST(&T, a, num);
	preOrderTraverse(T, pfile);

	fwrite(&d, sizeof(d), 1, pfile);

	for (i = 0; i < Search_num; i++)
	{
		m = SearchBST(T, b[i], f, &p);
		printf("--------------------------------------------------------\n\n");
		printf("开始在二叉排序树中查找%d: ", b[i]);
		if (m == true)
		{
			printf("\n找到%d,在二叉排列树中删除%d\n", b[i], b[i]);
			DeleteBST(&T, b[i]);
		}
		else
		{
			printf("\n未找到%d,在二叉排列树中插入%d\n", b[i], b[i]);
			InsertBST(&T, b[i]);
		}
		printf("现在的二叉排列树为：", b[i]);
		PreOrderTraverse(T);
		printf("\n\n");
		flag = 0;
		preOrderTraverse(T, pfile);
		fwrite(&d, sizeof(d), 1, pfile);
	}

	return 0;
}