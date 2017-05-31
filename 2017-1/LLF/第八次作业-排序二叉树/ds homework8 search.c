//第八次作业 实现二叉排序树的查找、删除、插入操作
#include <stdio.h>  
#include <stdlib.h>  

//定义树
typedef struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;

}treeNode;

//查找最小元素
treeNode* FindMin(treeNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->left)
		return FindMin(node->left);//若左子树非空，则继续向左寻找最小值
	else
		return node;
}

//查找最大元素
treeNode* FindMax(treeNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->right)
		FindMax(node->right);//若右子树非空，继续向右寻找最大值
	else
		return node;
}

//插入数据
treeNode * Insert(treeNode *node, int data)
{
	if (node == NULL)
	{
		treeNode *temp;
		temp = (treeNode *)malloc(sizeof(treeNode));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (data >(node->data))//若大于则存在右子树中
	{
		node->right = Insert(node->right, data);
	}
	else if (data < (node->data))//若小于则存在左子树中
	{
		node->left = Insert(node->left, data);
	}
	return node;
}

//创建树
treeNode*  createTree(treeNode *node, int *a,int n)
{
	for (int i = 0; i < n;i++)
		node=Insert(node, a[i]);
	return node;
}

//删除关键字
treeNode * Delete(treeNode *node, int data)
{
	treeNode *temp;
	if (node == NULL)
	{
		printf("Element Not Found");
	}
	else if (data < node->data)
	{
		node->left = Delete(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delete(node->right, data);
	}
	else
	{
		if (node->right && node->left)
		{
			temp = FindMin(node->right);
			node->data = temp->data;
			node->right = Delete(node->right, temp->data);
		}
		else
		{
			temp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			free(temp); 
		}
	}
	return node;

}

//查找关键字
treeNode * Find(treeNode *node, int data)
{
	if (node == NULL)
	{
		//若树为空，则未查找到
		return NULL;
	}
	if (data > node->data)
	{
		//搜索右子树
		return Find(node->right, data);
	}
	else if (data < node->data)
	{
		//搜索左子树
		return Find(node->left, data);
	}
	else
	{
		//找到关键字
		return node;
	}
	
}

//中序遍历
void PrintInorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	PrintInorder(node->left);
	printf("%d ", node->data);
	PrintInorder(node->right);
}

//先序遍历
void PrintPreorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	printf("%d, ", node->data);
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

//后序遍历
void PrintPostorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	PrintPostorder(node->left);
	PrintPostorder(node->right);
	printf("%d ", node->data);
}

int main()
{
	//建立二叉树并插入测试数据
	treeNode *root = NULL;
	int s[] = { 8,10,14,3,1,6,4,7,5,19,22,30 };
	int n = 12;
	root=createTree(root, &s,n);
	PrintPreorder(root);
	printf("\n");
	//待查找关键字
	int a[] = { 13,8,5,20,6 };
	treeNode * temp;
	for (int i = 0; i < 5; i++)
	{
		temp = Find(root, a[i]);
		printf("%d\n", a[i]);
		if (temp == NULL)
		{
			//若未查找到该元素，则插入
			Insert(root, a[i]);
			PrintPreorder(root);
			printf("\n");
		}
		else
		{
			//若找到该元素，则删去
			Delete(root, a[i]);
			PrintPreorder(root);
			printf("\n");
		}
	}
	
}