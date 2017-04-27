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
	if (ch == '#')
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

int main()
{
	BiTree T = NULL;

	char*s1 = "ABDG###EH##I#K##C#F##";
	char*s2 = "ABD#F###CE###";

	printf("测试用例1:");
	puts(s1);
	CreateBiTree(&T, s1);
	printf("后序遍历: ");
	PostOrderTraverseTree(T);
	printf("\n");
	destoryBiTree(T);

	i = 0;
	printf("测试用例2:");
	puts(s2);
	CreateBiTree(&T, s2);
	printf("后序遍历: ");
	PostOrderTraverseTree(T);
	printf("\n");
	destoryBiTree(T);
	
	return 0;
}