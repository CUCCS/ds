#include <stdio.h>
#include <malloc.h>

#define TElemType char
#define ElemType BiTNode *   // 树的结点

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

BiTNode *CreatBiTree(char z[])
{
	static int i = -1;
	BiTNode *root;
	i++;
	if (z[i] == '*') return NULL;
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = z[i];
	root->lchild = CreatBiTree(z); //构造左子树
	root->rchild = CreatBiTree(z); //构造右子树
	return(root);
}

int CountLeaf(BiTNode *T) // 求叶子结点个数
{
	int m = 0, n = 0;
	if (!T)
	{
		return 0;
	}
	if (!T->lchild && !T->rchild)
	{
		return 1;
	}
	else 
	{
		m = CountLeaf(T->lchild);
		n = CountLeaf(T->rchild);
		return m + n;
	}
}

int Count(BiTNode *T) //求所有结点个数
{
	int m, n;
	if (!T) return 0;
	if (!T->lchild && !T->rchild)
	{
		return 1;
	}
	else 
	{
		m = Count(T->lchild);
		n = Count(T->rchild);
		return m + n + 1;
	}
}

void main()
{
	char z[] = "ABDG***EH**I*K**C*F**";  //测试用例
	BiTNode *T;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T = CreatBiTree(z);

	printf("测试用例：ABDG***EH**I*K**C*F** 的叶子节点数为：%d\n\n",CountLeaf(T));
	printf("测试用例：ABDG***EH**I*K**C*F** 的非叶子节点数为：%d\n", Count(T)- CountLeaf(T));
	printf("\n");
}


