#include "Search.h"
int flag;

//���������������Ԫ��e������e�Ĵ�С��Ϊ�������
bool InsertBST(BiTree *T, int e)
{
	if (*T == NULL)//TΪ����������eΪ���ڵ�
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;;
		return true;
	}
	if (e == (*T)->data)// �������������д���Ԫ�ص���e������FALSE
	{
		return false;
	}
	if (e < (*T)->data)//eֵС�ڵ�ǰ�����ֵ������eΪ����
	{
		return InsertBST(&(*T)->lchild, e);
	}
	if (e > (*T)->data)//eֵ���ڵ�ǰ�����ֵ������eΪ�Һ���
	{
		return InsertBST(&(*T)->rchild, e);
	}
};

//�������������
Status CreatBST(BiTree *T, int a[], int n)
{
	int i;
	*T = NULL;
	for (i = 0; i < n; i++)
	{
		InsertBST(&(*T), a[i]);
	}
	return OK;
};

//�ڶ������������Ԫ��key
//���ɹ�������true
//�����ɹ����������key��С�����������������ԣ�ȷ������������������������ʹ�õݹ��㷨����
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else
	{
		if (key == T->data)
		{
			p = &T;
			return true;
		}
		else if (key > T->data)
		{
			return SearchBST(T->rchild, key, T, p);
		}
		else
		{
			return SearchBST(T->lchild, key, T, p);
		}
	}
};

//ɾ������������
bool Delete(BiTree *T)
{
	BiTree L, S;
	if (!(*T)->lchild && !(*T)->rchild)//����������Ϊ��
	{
		*T = NULL;
	}
	else if (!(*T)->lchild)// ������Ϊ�գ��ؽ�����������
	{
		L = *T;
		*T = (*T)->rchild;
		free(L);
	}
	else if (!(*T)->rchild) // ������Ϊ�գ��ؽ�����������
	{
		L = *T;
		*T = (*T)->lchild;
		free(L);
	}
	else//������������Ϊ��
	{
		L = *T;
		S = (*T)->lchild;
		while (S->rchild) // S ָ��ɾ����ǰ��
		{
			L = S;
			S = S->rchild;
		}
		(*T)->data = S->data;
		if (L != *T)
		{
			L->rchild = S->lchild;// �ؽ�*q��������
		}
		else
		{
			L->lchild = S->lchild;// �ؽ�*q��������
		}
		free(S);
	}
	return true;
};

//ɾ��ֵΪkey�Ľ��
bool DeleteBST(BiTree *T, int key)
{
	if (!T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			Delete(T);
			return true;
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
};
//��ӡ���ļ�txt��
bool print(int data, FILE*pfile)
{

	char d[2] = { ", " };
	/*char *d =",";*/
	if (NULL == pfile)
	{
		return false;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d", data);
		flag = 1;
		return true;
	}
}

//����������T
int PreOrderTraverse(BiTree T)
{
	if (T)
	{
		printf("%d ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
		return 1;
};
int preOrderTraverse(BiTree T, FILE*pfile)
{
	if (T)
	{
		print(T->data, pfile);
		preOrderTraverse(T->lchild, pfile);
		preOrderTraverse(T->rchild, pfile);
	}
	else
		return 1;
};