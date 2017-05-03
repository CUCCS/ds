#include "BinaryTrees.h"
int i = 0;
int high;
int wide[50] = { 0 };
int swide = 0;


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
		CreateBiTree(&(*T)->lchild, s); // 构造左子树
		CreateBiTree(&(*T)->rchild, s);// 构造右子树
							 
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



int Max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}



int getHigh(BiTree T)
{
	int high = 0;
	int lhigh;
	int rhigh;
	if (!T)
	{
		return 0;
	}
	else
	{
		
 		lhigh=getHigh(T->lchild);
		rhigh=getHigh(T->rchild);
		high = Max(lhigh, rhigh)+1;
		return high;
	}
	
}



int getWide(BiTree T, int level)
{
	if (T == NULL)
	{
		return 0;
	}
	wide[level]++;
	if (swide < wide[level])
	{
		swide = wide[level];
	}
	getWide(T->lchild, level + 1);
	getWide(T->rchild, level + 1);
	return swide;
}



void CountLeaf(BiTree T, int *count,int *ncounts)
{
	if (T)
	{
		(*ncounts)++;
		if ((T->lchild==NULL) && (T->rchild==NULL))
		{
			(*count)++;     // 对叶子结点计数
		}
		CountLeaf(T->lchild, count,ncounts);
		CountLeaf(T->rchild, count,ncounts);
	}
}