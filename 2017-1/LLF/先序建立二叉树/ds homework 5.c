//第五次作业 实现以字符串（含空格）输入先序建立二叉树、后序输出
#include<stdio.h>  
#include<malloc.h>

//定义二叉树
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode;

//先序建立二叉树
BiTNode* CreatBiTree(BiTNode* root)
{
	char s;
	scanf_s("%c", &s);  //输入
	if (s == ' ')
	{
		root = NULL;
	}
	else
	{
		root = (BiTNode*)malloc(sizeof(BiTNode));
		root->data = s;
		root->lchild = CreatBiTree(root->lchild);
		root->rchild = CreatBiTree(root->rchild);
	}
	return root;
}

//后序遍历二叉树
int PostOrderTraverse(BiTNode *root)
{
	if (root)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%c ", root->data);
	}
	return 0;
}

int main()
{
	BiTNode *p = NULL;
	p = CreatBiTree(p);
	PostOrderTraverse(p);
	return 0;
}


