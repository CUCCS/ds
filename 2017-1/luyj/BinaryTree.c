#include "BinaryTree.h"

int i = 0;
char AbstractWord(char*s)
{

	char ch = s[i];
	i++;
	return ch;
}

Status CreateBiTree(BiTree *T,char *s)
{
	char ch;
	ch = AbstractWord(s);
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		if (!T)
		{
			return OVERFLOW;
		}

		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, s); // ����������
		CreateBiTree(&(*T)->rchild, s);// ����������
							 
	}
	return OK;
}

Status PostOrderTraverse(BiTree T)
{
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	} 
	return OK;
}

Status destoryBiTree(BiTree T)
{
	if (!T)
	{
		return ERROR;
	}
	else
	{
		destoryBiTree(T->lchild);
		destoryBiTree(T->rchild);
		free (T);
	}
}
