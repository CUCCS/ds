#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;   //左右孩子的指针
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;         //状态

int i = 0;

Status CreateBiTree(BiTree *T, char*s) //创建二叉树
{
	char ch = s[i];
	i++;
	if (ch == ' ')
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTNode*)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild, s); //创建左孩子
		CreateBiTree(&(*T)->rchild, s); //创建右孩子

	}
	return OK;
}

void PostOrderTraverseTree(BiTree T)
{
	if (T)
	{
		PostOrderTraverseTree(T->lchild);
		PostOrderTraverseTree(T->rchild);
		printf("%c", T->data);
	}
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
		free(T);
	}
}
//以上重用第5次作业代码

int getMax(int x, int y)
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

int getHeight(BiTree T)
{
	int high = 0;
	if (!T)
	{
		return 0;
	}
	else
	{
		high = getMax(getHeight(T->lchild), getHeight(T->rchild)) + 1;
		return high;
	}
}

int wide[100];
int w = 0;
int getWidth(BiTree T, int l)
{
	if (!T)
	{
		return 0;
	}
	wide[l]++;
	if (w < wide[l])
	{
		w = wide[l];
	}
	getWidth(T->lchild, l + 1);
	getWidth(T->rchild, l + 1);
	return w;
}

void CountLeaf(BiTree T, int *count1, int *count2)//count1对叶子结点计数，count2对非叶子结点计数
{
	if (T)
	{
		if ((T->lchild == NULL) && (T->rchild == NULL))
		{
			(*count1)++;
		}
		else (*count2)++;
		CountLeaf(T->lchild, count1, count2);
		CountLeaf(T->rchild, count1, count2);
	}
}

