#include <stdio.h>
#include <malloc.h>

#define TElemType char
#define ElemType BiTNode *   // ���Ľ��

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
	root->lchild = CreatBiTree(z); //����������
	root->rchild = CreatBiTree(z); //����������
	return(root);
}

int CountLeaf(BiTNode *T) // ��Ҷ�ӽ�����
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

int Count(BiTNode *T) //�����н�����
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
	char z[] = "ABDG***EH**I*K**C*F**";  //��������
	BiTNode *T;
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T = CreatBiTree(z);

	printf("����������ABDG***EH**I*K**C*F** ��Ҷ�ӽڵ���Ϊ��%d\n\n",CountLeaf(T));
	printf("����������ABDG***EH**I*K**C*F** �ķ�Ҷ�ӽڵ���Ϊ��%d\n", Count(T)- CountLeaf(T));
	printf("\n");
}


