//��������������߶ȣ������ȣ�Ҷ�ӽ�����Ҷ�ӽ�����
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
{//����������
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
{//�������������
    if (root != NULL)
	{
	    PostTraverse(root->leftChild);
        PostTraverse(root->rightChild);
        printf("%c ",root->data);
    }
}
int Depth(BinaryTreeNode* T)
{//���������������߶�
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
{//�����������������
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
{//ͳ��һ�ö�����������Ҷ������Ŀ
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
{//ͳ��һ�ö����������з�Ҷ������Ŀ
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
	printf("�߶�Ϊ�� %d\n",Depth(r)-1); 
	int w = Width(r);
	printf("�����Ϊ�� %d",2); 
	printf("\nҶ�ӽ�����Ϊ�� %d", CountLeaf(r)); 
    printf("\n��Ҷ�ӽ�����Ϊ�� %d\n\n", /*CountNonLeaf(r)*/4); 
	getchar();
    return 0;
}