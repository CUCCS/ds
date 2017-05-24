#include <stdio.h>
#include <stdlib.h>
int flag;

typedef enum
{
	true,
	false
}bool;

typedef enum status
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

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



//向二叉排序树插入一个新的结点
bool InsertBST(BiTree *T, int e)
{
	if (*T == NULL)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;;
		return true;
	}
	if (e == (*T)->data)
	{
		return false;
	}
	if (e < (*T)->data)
	{
		return InsertBST(&(*T)->lchild, e);
	}
	if (e > (*T)->data)
	{
		return InsertBST(&(*T)->rchild, e);
	}
};

//建立BST
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

bool Delete(BiTree *T)
{
	BiTree L, S;
	if (!(*T)->lchild && !(*T)->rchild)
	{
		*T = NULL;
	}
	else if (!(*T)->lchild)
	{
		L = *T;
		*T = (*T)->rchild;
		free(L);
	}
	else if (!(*T)->rchild)
	{
		L = *T;
		*T = (*T)->lchild;
		free(L);
	}
	else
	{
		L = *T;
		S = (*T)->lchild;
		while (S->rchild)
		{
			L = S;
			S = S->rchild;
		}
		(*T)->data = S->data;
		if (L != *T)
		{
			L->rchild = S->lchild;
		}
		else
		{
			L->lchild = S->lchild;
		}
		free(S);
	}
	return true;
};

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

Status print(int data, FILE*pfile)
{

	char *d = ", ";
	if (NULL == pfile)
	{
		return ERROR;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d", data);
		flag = 1;

	}
}

void preOrderTraverse(BiTree T, FILE*pfile)
{
	if (T)
	{
		print(T->data, pfile);
		preOrderTraverse(T->lchild, pfile);
		preOrderTraverse(T->rchild, pfile);
	}
};

int main()
{
	int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[5] = { 13, 8, 5, 20, 6 };
	int n = 12, i;
	bool m;
	char d = '\n';
	FILE *pfile;
	BiTree T, f, p;
	T = (BiTree)malloc(sizeof(BiTNode));
	p = (BiTree)malloc(sizeof(BiTree));
	f = (BiTree)malloc(sizeof(BiTree));
	pfile = fopen("output.txt", "a");
	CreatBST(&T, a, n);
	preOrderTraverse(T, pfile);
	fwrite(&d, sizeof(d), 1, pfile);
	for (i = 0; i < 5; i++)
	{
		m = SearchBST(T, b[i], f, &p);
		//printf("现在查找%d: ",b[i]);
		if (m == true)
		{
			//printf("找到%d,在二叉排列树中删除%d\n",b[i],b[i]);
			DeleteBST(&T, b[i]);
		}
		else
		{
			//printf("未找到%d,在二叉排列树中插入%d\n",b[i],b[i]);
			InsertBST(&T, b[i]);
		}
		//printf("查找过%d的二叉排列树为：",b[i]);
		flag = 0;
		preOrderTraverse(T, pfile);
		fwrite(&d, sizeof(d), 1, pfile);
	}
	return 0;
}







