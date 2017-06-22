#include "AVLTree.h"
extern int flag;

int main()
{
	int i;
	BSTree *t = (BSTree*)malloc(sizeof(BSTree));
	Boolean taller = FALSE;
	Boolean lower = FALSE;
	*t = NULL;
	ElemType input[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	ElemType search[5] = { 13,8,5,20,6 };
	char d[4] = "\n";
	FILE*pfile = fopen("AVLOutput.txt", "a");
	for (i = 0; i < 12; i++)
	{
		InsertAVL(t, input[i], &taller);
	}
	PreOrderTraverse(*t,pfile);
	fputs(d, pfile);
	
	for (i = 0; i < 5; i++)
	{
		if (FALSE == SearchBST(*t, search[i]))
		{
			InsertAVL(t, search[i], &taller);
			flag = 0;
			PreOrderTraverse(*t,pfile);
			fputs(d, pfile);
		}
		else
		{
			DeleteAVL(t, search[i], &lower);
			flag = 0;
			PreOrderTraverse(*t,pfile);
			fputs(d, pfile);
		}
	}
}