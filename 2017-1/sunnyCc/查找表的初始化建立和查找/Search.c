#include "Search.h"
int flag;

//向二叉排序树插入元素e，根据e的大小分为三种情况
bool InsertBST(BiTree *T, int e)
{
	if (*T == NULL)//T为空树，插入e为根节点
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;;
		return true;
	}
	if (e == (*T)->data)// 当二叉排序树中存在元素等于e，返回FALSE
	{
		return false;
	}
	if (e < (*T)->data)//e值小于当前结点数值，插入e为左孩子
	{
		return InsertBST(&(*T)->lchild, e);
	}
	if (e > (*T)->data)//e值大于当前结点数值，插入e为右孩子
	{
		return InsertBST(&(*T)->rchild, e);
	}
};

//建立排序二叉树
Status CreatBST(BiTree *T, int a[], int n)
{
	int i;
	*T = NULL;
	for (i = 0; i < n; i++)
	{
		InsertBST(&(*T), a[i]);
	}
	return OK;
};

//在二叉树里面查找元素key
//若成功，返回true
//若不成功，则根据其key大小结合排序二叉树的属性，确定在左子树还是在右子树中使用递归算法查找
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else
	{
		if (key == T->data)
		{
			p = &T;
			return true;
		}
		else if (key > T->data)
		{
			return SearchBST(T->rchild, key, T, p);
		}
		else
		{
			return SearchBST(T->lchild, key, T, p);
		}
	}
};

//删除二叉排序树
bool Delete(BiTree *T)
{
	BiTree L, S;
	if (!(*T)->lchild && !(*T)->rchild)//左右子树都为空
	{
		*T = NULL;
	}
	else if (!(*T)->lchild)// 左子树为空，重接它的右子树
	{
		L = *T;
		*T = (*T)->rchild;
		free(L);
	}
	else if (!(*T)->rchild) // 右子树为空，重接它的左子树
	{
		L = *T;
		*T = (*T)->lchild;
		free(L);
	}
	else//左右子树均不为空
	{
		L = *T;
		S = (*T)->lchild;
		while (S->rchild) // S 指向被删结点的前驱
		{
			L = S;
			S = S->rchild;
		}
		(*T)->data = S->data;
		if (L != *T)
		{
			L->rchild = S->lchild;// 重接*q的右子树
		}
		else
		{
			L->lchild = S->lchild;// 重接*q的左子树
		}
		free(S);
	}
	return true;
};

//删除值为key的结点
bool DeleteBST(BiTree *T, int key)
{
	if (!T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			Delete(T);
			return true;
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
};
//打印到文件txt中
bool print(int data, FILE*pfile)
{

	char d[2] = { ", " };
	/*char *d =",";*/
	if (NULL == pfile)
	{
		return false;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d", data);
		flag = 1;
		return true;
	}
}

//先序遍历输出T
int PreOrderTraverse(BiTree T)
{
	if (T)
	{
		printf("%d ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
		return 1;
};
int preOrderTraverse(BiTree T, FILE*pfile)
{
	if (T)
	{
		print(T->data, pfile);
		preOrderTraverse(T->lchild, pfile);
		preOrderTraverse(T->rchild, pfile);
	}
	else
		return 1;
};