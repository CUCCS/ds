#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;   //���Һ��ӵ�ָ��
}BiTNode, *BiTree;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;         //״̬

int i = 0;

Status CreateBiTree(BiTree *T, char*s) //����������
{
	char ch = s[i];
	i++;
	if (ch == ' ')
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
		CreateBiTree(&(*T)->lchild, s); //��������
		CreateBiTree(&(*T)->rchild, s); //�����Һ���

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
//�������õ�5����ҵ����

int getMax(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int getHeight(BiTree T)
{
	int high = 0;
	if (!T)
	{
		return 0;
	}
	else
	{
		high = getMax(getHeight(T->lchild), getHeight(T->rchild)) + 1;
		return high;
	}
}

int wide[100];
int w = 0;
int getWidth(BiTree T, int l)
{
	if (!T)
	{
		return 0;
	}
	wide[l]++;
	if (w < wide[l])
	{
		w = wide[l];
	}
	getWidth(T->lchild, l + 1);
	getWidth(T->rchild, l + 1);
	return w;
}

void CountLeaf(BiTree T, int *count1, int *count2)//count1��Ҷ�ӽ�������count2�Է�Ҷ�ӽ�����
{
	if (T)
	{
		if ((T->lchild == NULL) && (T->rchild == NULL))
		{
			(*count1)++;
		}
		else (*count2)++;
		CountLeaf(T->lchild, count1, count2);
		CountLeaf(T->rchild, count1, count2);
	}
}

