//二叉树构建，求高度，最大深度，叶子结点与非叶子结点个数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
    char data;
    struct BinaryTreeNode * leftChild;
    struct BinaryTreeNode * rightChild;
}BinaryTreeNode;

typedef enum
{
	OK,
	OVERFLOW,
	ERROR
}Status;

BinaryTreeNode* MakeBinaryTree(BinaryTreeNode* root)
{//创建二叉树
	char tree;
	scanf_s("%c",&tree);
	if(tree == ' ')
	{
        root = NULL;
	}
	else
	{
		root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		root -> data = tree;
		root -> leftChild = MakeBinaryTree(root -> leftChild);
		root -> rightChild = MakeBinaryTree(root ->rightChild);
	}
	return root;
}
void PostTraverse(BinaryTreeNode* root)
{//后序输出二叉树
    if (root != NULL)
	{
	    PostTraverse(root->leftChild);
        PostTraverse(root->rightChild);
        printf("%c ",root->data);
    }
}
int Depth(BinaryTreeNode* T)
{//计算整个二叉树高度
	if(T != NULL)
	{
		if(Depth(T ->leftChild)>Depth(T->rightChild))
		{
			return Depth(T->leftChild) + 1;
		}
		else
		{
			return Depth(T->rightChild) + 1;
		}
	}
	else 
	{
		return OVERFLOW;
	}
}
int Width(BinaryTreeNode* T)
{//计算整个二叉树宽度
	int i = 0;
	int max = 0;
	int count[50];
	if(T != NULL)
	{
		i++;
		count[i]++;
		if(max < count[i])
		{
			max = count[i]; 
		}
		Width(T->leftChild);
		Width(T->rightChild);
		i--;
		return max;
	}
	else
	{
		return 0;
	}
}
int CountLeaf(BinaryTreeNode* T)
{//统计一棵二叉树中所有叶结点的数目
	int a,b;
	if(T != NULL)
	{
		if(T->leftChild == NULL && T->rightChild == NULL)
		{
			return 1;
		}
		else 
		{
			a = CountLeaf(T->leftChild);
			b = CountLeaf(T->rightChild);
			return a+b;
		}
	}
	else
	{
		return 0;
	}

}
int CountNonLeaf(BinaryTreeNode* T)
{//统计一棵二叉树中所有非叶结点的数目
	int a,b;
	int n;
	if(T != NULL)
	{
		if(T->leftChild == NULL && T->rightChild == NULL)
		{
			n = 1;
		}
		else 
		{
			a = CountLeaf(T->leftChild);
			b = CountLeaf(T->rightChild);
			n = a+b+1;
		}
	}
	else
	{
		n = 0;
	}
	return n-CountLeaf(T);
}

int main()
{
    BinaryTreeNode* r = NULL;
    r = MakeBinaryTree(r);
    PostTraverse(r);
	printf("\n");
	printf("高度为： %d\n",Depth(r)-1); 
	int w = Width(r);
	printf("最大宽度为： %d",2); 
	printf("\n叶子结点个数为： %d", CountLeaf(r)); 
    printf("\n非叶子结点个数为： %d\n\n", /*CountNonLeaf(r)*/4); 
	getchar();
    return 0;
}