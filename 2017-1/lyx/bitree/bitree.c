#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
    char data;
    struct BinaryTreeNode * leftChild;
    struct BinaryTreeNode * rightChild;
}BinaryTreeNode;

BinaryTreeNode* MakeBinaryTree(BinaryTreeNode* root)
{
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
{
    if (root != NULL)
	{
	    PostTraverse(root->leftChild);
        PostTraverse(root->rightChild);
        printf("%c ",root->data);
    }
}

int main()
{
    BinaryTreeNode* r = NULL;
    r = MakeBinaryTree(r);
    PostTraverse(r);
	printf("\n");
	getchar();
    return 0;
}