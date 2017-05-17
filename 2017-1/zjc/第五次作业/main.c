
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef char TElemType;
typedef struct BiTNode

{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;
int i = 0;
Status CreateBiTree(BiTree *T, char*s)
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
		CreateBiTree(&(*T)->lchild, s);
		CreateBiTree(&(*T)->rchild, s);
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