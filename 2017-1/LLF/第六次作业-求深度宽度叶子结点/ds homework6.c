//��������ҵ ʵ�������������ȡ���ȡ�Ҷ�ӽ��������Ҷ�ӽ����
#include<stdio.h>  
#include<stdlib.h>
#include <malloc.h>  
#define M 100

//���������
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild, *rchild; //���Һ���ָ��
}BiTNode, *BiTree;


//�����������ȵ�ָ�����
typedef struct Queue
{
	BiTNode *data[M];
	int f;
	int r;
}Queue;


typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;


//��ȡ�ַ�
int i = 0;
char getChar(char *s)
{

	char c;
	c = s[i];
	i++;
	return c;
}


//������������
Status CreatBiTree(BiTree *root, char *a)
{
	char s;
	s = getChar(a);
	if (s == ' ')
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode*)malloc(sizeof(BiTNode));
		if (!root)
		{
			return OVERFLOW;
		}
		(*root)->data = s;
		CreatBiTree(&(*root)->lchild, a);
		CreatBiTree(&(*root)->rchild, a);
	}
	return OK;
}


//�������������
Status PostOrderTraverse(BiTree root)
{
	if (root)
	{
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		printf("%c", root->data);
	}
	return OK;
}


//���ٶ�����
Status destoryBiTree(BiTree root)
{
	if (!root)
	{
		return ERROR;
	}
	else
	{
		destoryBiTree(root->lchild);
		destoryBiTree(root->rchild);
		free(root);
	}

}


//����������
int TreeDepth(BiTree root)
{
	int rightdep = 0;
	int leftdep = 0;

	if (root == NULL)
		return -1;

	if (root->lchild != NULL)
		leftdep = TreeDepth(root->lchild);
	else
		leftdep = -1;

	if (root->rchild != NULL)
		rightdep = TreeDepth(root->rchild);
	else
		rightdep = -1;

	return (rightdep>leftdep) ? rightdep + 1 : leftdep + 1;
}



//����������
int TreeWidth(BiTree T)
{
	if (T == NULL) return 0;
	int num = 0;
	int max = 0;
	Queue Q;
	Q.r = 0;
	Q.f = 0;//��ʼ������
	memset(Q.data, NULL, M);
	Q.data[Q.r++] = T;

	BiTNode *t = (BiTNode*)malloc(sizeof(BiTNode));
	t->data = ' ';
	t->lchild = NULL;
	t->rchild = NULL;
	Q.data[Q.r++] = t;//�������
	while (Q.r != Q.f)
	{
		t = Q.data[Q.f++];
		if (t->data == ' ')
		{
			if (max<num)
			{
				max = num;
				num = 0;
			}
			if (Q.data[Q.f] != NULL)
			{
				t = (BiTNode*)malloc(sizeof(BiTNode));
				t->data = ' ';
				t->lchild = NULL;
				t->rchild = NULL;
				Q.data[Q.r++] = t;
			}

		}
		else
		{
			++num;
			if (t->lchild) Q.data[Q.r++] = t->lchild;
			if (t->rchild) Q.data[Q.r++] = t->rchild;
		}
	}
	return max;
}

//��Ҷ�ӽ����
int LeafCount(BiTree root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if ((root->lchild == NULL) && (root->rchild == NULL))
	{
		return 1;
	}
	else
	{
		return LeafCount(root->lchild) + LeafCount(root->rchild);
	}
}

//�����н����
int NodeCount(BiTree root)
{
	if (root == NULL)
		return 0;
	else
		return (NodeCount(root->lchild) + NodeCount(root->rchild) + 1);
}

int main()
{
	BiTree p1 = NULL;
	char *ch1 = "ABDG   EH  I K  C F  ";
	printf("ch1 preorder: ");
	puts(ch1);
	printf("ch1 postorder: ");
	CreatBiTree(&p1, ch1);
	PostOrderTraverse(p1);
	printf("\nch1 depth is %d\n", TreeDepth(p1));
	printf("ch1 width is %d\n", TreeWidth(p1));
	printf("ch1 leaf node is %d\n", LeafCount(p1));
	printf("ch1 not leaf node is %d\n", NodeCount(p1) - LeafCount(p1));
	destoryBiTree(p1);
	printf("\n");
	i = 0;
	BiTree p2 = NULL;
	char *ch2 = "BCE G   DF    ";
	printf("ch2 preorder: ");
	puts(ch2);
	printf("ch2 postorder: ");
	CreatBiTree(&p2, ch2);
	PostOrderTraverse(p2);
	printf("\nch2 depth is %d\n", TreeDepth(p2));
	printf("ch2 width is %d\n", TreeWidth(p2));
	printf("ch2 leaf node is %d\n", LeafCount(p2));
	printf("ch2 not leaf node is %d\n", NodeCount(p2) - LeafCount(p2));
	destoryBiTree(p2);

	return 0;

}


