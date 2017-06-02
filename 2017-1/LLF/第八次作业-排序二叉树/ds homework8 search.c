//�ڰ˴���ҵ ʵ�ֶ����������Ĳ��ҡ�ɾ�����������
#include <stdio.h>  
#include <stdlib.h>  

//������
typedef struct treeNode
{
	int data;
	struct treeNode *left;
	struct treeNode *right;

}treeNode;

//������СԪ��
treeNode* FindMin(treeNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->left)
		return FindMin(node->left);//���������ǿգ����������Ѱ����Сֵ
	else
		return node;
}

//�������Ԫ��
treeNode* FindMax(treeNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->right)
		FindMax(node->right);//���������ǿգ���������Ѱ�����ֵ
	else
		return node;
}

//��������
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
	if (data >(node->data))//�������������������
	{
		node->right = Insert(node->right, data);
	}
	else if (data < (node->data))//��С���������������
	{
		node->left = Insert(node->left, data);
	}
	return node;
}

//������
treeNode*  createTree(treeNode *node, int *a,int n)
{
	for (int i = 0; i < n;i++)
		node=Insert(node, a[i]);
	return node;
}

//ɾ���ؼ���
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

//���ҹؼ���
treeNode * Find(treeNode *node, int data)
{
	if (node == NULL)
	{
		//����Ϊ�գ���δ���ҵ�
		return NULL;
	}
	if (data > node->data)
	{
		//����������
		return Find(node->right, data);
	}
	else if (data < node->data)
	{
		//����������
		return Find(node->left, data);
	}
	else
	{
		//�ҵ��ؼ���
		return node;
	}
	
}

//�������
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

//�������
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

//�������
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
	//�����������������������
	treeNode *root = NULL;
	int s[] = { 8,10,14,3,1,6,4,7,5,19,22,30 };
	int n = 12;
	root=createTree(root, &s,n);
	PrintPreorder(root);
	printf("\n");
	//�����ҹؼ���
	int a[] = { 13,8,5,20,6 };
	treeNode * temp;
	for (int i = 0; i < 5; i++)
	{
		temp = Find(root, a[i]);
		printf("%d\n", a[i]);
		if (temp == NULL)
		{
			//��δ���ҵ���Ԫ�أ������
			Insert(root, a[i]);
			PrintPreorder(root);
			printf("\n");
		}
		else
		{
			//���ҵ���Ԫ�أ���ɾȥ
			Delete(root, a[i]);
			PrintPreorder(root);
			printf("\n");
		}
	}
	
}