#include "BiSTree.h"
extern int flag;

int main()
{
	BiTree *T = (BiTree*)malloc(sizeof(BiTree));
	*T = NULL;
	int i;
	int j;
	int k;
	char d = '\n';
	ElemType input[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	ElemType found[5] = { 13, 8, 5, 20, 6 };
	FILE*pfile = fopen("BSTOutput.txt", "a");
	//½¨Á¢Ë³Ðò¶þ²æÊ÷;
	for (i = 0; i < 12; i++)
	{
		BiTree p = (BiTree)malloc(sizeof(BiTree));
		if (SearchBST(*T, input[i].key, NULL, &p) == false)
		{
			InsertBST(T, input[i], p);
		}
	}
	PreOrderTraverse(*T, pfile);
	fwrite(&d, sizeof(d), 1, pfile);
	for (i = 0; i < 5; i++)
	{
		searchInDelete(T, found[i]);
		flag = 0;
		PreOrderTraverse(*T, pfile);
		fwrite(&d, sizeof(d), 1, pfile);
	}
	fclose(pfile);
	pfile = NULL;
	return 0;
}