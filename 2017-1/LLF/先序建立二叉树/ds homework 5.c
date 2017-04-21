//�������ҵ ʵ�����ַ��������ո��������������������������
#include<stdio.h>  
#include<malloc.h>

//���������
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild; //���Һ���ָ��
}BiTNode;

//������������
BiTNode* CreatBiTree(BiTNode* root)
{
	char s;
	scanf_s("%c", &s);  //����
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

//�������������
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


