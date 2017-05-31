#include "AVLTree.h"
int flag;
int InsertAVL(BSTree* T, ElemType e, bool* taller)
{
	//����ƽ��Ķ������������в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��
	//Ϊe���½�㣬������1�����򷵻�0/��������ʹ����������ʧȥƽ�⣬����ƽ��
	//��ת������������taller��ӳT�������
	if ((*T) == NULL)
	{                                             //�����½�㣬�������ߡ�����tallerΪTRUE
		(*T) = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else if (e == (*T)->data)                     //�����Ѵ�����e����ͬ�ؼ���Ľ��
	{
		*taller = false;                          //���ٲ���
		return 0;
	}
	else if (e < (*T)->data)                      //������*T���������н�������
	{
		if (!InsertAVL(&(*T)->lchild, e, taller))
			return 0;                             //δ����
		if (*taller)                              //�Ѳ��뵽*T�����������������������ߡ�
		{
			switch ((*T)->bf)                     //���*T��ƽ���
			{
			case LH:                              //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
				LeftBalance(T);
				*taller = false;
				break;
			case  EH:                             //ԭ����������һ���ߣ��������������߶�ʹ������
				(*T)->bf = LH;
				*taller = true;
				break;
			case RH:                              //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
				(*T)->bf = EH;
				*taller = false;
				break;
			}
		}
	}
	else
	{                                             //�������*T���������н�������
		if (!InsertAVL(&(*T)->rchild, e, taller)) //δ����
			return 1;
		if (*taller)                              //�Ѳ��뵽*T�����������������������ߡ�
		{
			switch ((*T)->bf)                     //���*T��ƽ���
			{
			case LH:                              //ԭ�����������������ߣ��������������ȸ�
				(*T)->bf = EH;
				*taller = false;
				break;
			case EH:                              //ԭ����������һ���ߣ��������������߶�ʹ������
				(*T)->bf = RH;
				*taller = true;
				break;
			case  RH:
				RightBalance(T);                  //ԭ�����������������ߣ���Ҫ����ƽ�⴦��
				*taller = false;
				break;
			}
		}
	}
	return 1;
}
//��������ƽ����
Status CreatBST(BSTree *T, int a[], int n)
{
	int i;
	bool *taller;
	*T = NULL;
	for (i = 0; i < n; i++)
	{
		InsertAVL(&(*T), a[i], &taller);
	}
	return OK;
};
//ɾ������ƽ����
bool Delete(BSTree *T)
{
	BSTree L, S;
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
bool DeleteAVL(BSTree *T, int key)
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
			return DeleteAVL(&(*T)->lchild, key);
		}
		else
		{
			return DeleteAVL(&(*T)->rchild, key);
		}
	}
};
void R_Rotate(BSTree* p)
{   //����*pΪ���Ķ�����������������������֮��pָ���µ������ڵ�
	//����ת����֮ǰ���������ĸ��ڵ�
	BSTree lc = (*p)->lchild;     //lcָ��*p�������������  
	(*p)->lchild = lc->rchild;    //lc���������ҽ�Ϊ*p��������  
	lc->rchild = *p;
	*p = lc;                      //pָ���µĸ����  
}

void L_Rotate(BSTree* p)
{   //����*pΪ���Ķ�����������������������֮��pָ���µ������ڵ�
	//����ת����֮ǰ���������ĸ��ڵ�
	BSTree rc = (*p)->rchild;     //rcָ��*p�������������  
	(*p)->rchild = rc->lchild;    //rc���������ҽ�Ϊ*p��������  
	rc->lchild = *p;
	*p = rc;                      //pָ���µĸ����  
}
/* ����ָ��TΪ�����Ķ���������ƽ����ת�������������ָ��Tָ���µĸ���� */
void LeftBalance(BSTree* T)
{
	BSTree lc, rd;
	lc = (*T)->lchild;  //lcָ��T�������������  
	switch (lc->bf)
	{ //���T����������ƽ������  
	case LH:           //�½����뵽T�����ӵ��������ϣ�Ҫ������������  
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:           //�½����뵽T�����ӵ��������ϣ�Ҫ��˫������  
		rd = lc->rchild;   //rdָ��T�����ӵ��������ĸ����  
		switch (rd->bf)     //�޸�T�������ӵ�ƽ������  
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;
	}
}
//����ָ��TΪ�����Ķ���������ƽ����ת�������������ָ��Tָ���µĸ���� 
void RightBalance(BSTree* T)
{
	BSTree lc, rd;
	lc = (*T)->rchild;
	switch (lc->bf)
	{
	case RH:
		(*T)->bf = lc->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		rd = lc->lchild;
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	}
}

//�ڶ������������Ԫ��key
//���ɹ�������true
//�����ɹ����������key��С�����������������ԣ�ȷ������������������������ʹ�õݹ��㷨����
bool SearchAVL(BSTree T, int key, BSTree f, BSTree *p)
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
			return SearchAVL(T->rchild, key, T, p);
		}
		else
		{
			return SearchAVL(T->lchild, key, T, p);
		}
	}
};
//��ӡ���ļ�txt��
int TraversePrint(BSTree T, FILE*pfile)
{
	if (T)
	{
		print(T->data, pfile);
		TraversePrint(T->lchild, pfile);
		TraversePrint(T->rchild, pfile);
	}
	else
		return 1;
};
//��ӡ���ļ�txt��
bool print(int data, FILE*pfile)
{

	char d[2] = { ", " };
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
int PreOrderTraverse(BSTree T)
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
