#include "s.h"
//���ҽ��
Status SearchBST(BiTree T, ElemType kval, BiTree f, BiTree  *p)
{
	if (!T)
	{ // ���������Ҳ��ɹ�
		(*p) = f;                                        //f�������ǳ�ʼ�� p����
		return FALSE;
	}
	else if (kval == T->data)
	{
		(*p) = T;
		return TRUE;   // ���ҳɹ�
	}
	else if (kval < T->data)     //���������С�Ļ�
	{ // ���������м�������
		return SearchBST(T->lchild, kval, T, p);
	}
	else 
	{ // ���������м�������
		return SearchBST(T->rchild, kval, T, p);
	}
}
//����Ԫ��
Status InsertBST(BiTree *T, ElemType e)
{
	// �������������в����ڹؼ��ֵ��� e.key ��
	// ����Ԫ��ʱ������Ԫ��ֵΪ e �Ľ�㣬����
	// �� TRUE; ���򣬲����в��벢����FALSE
	BiTree *p = (BiTree *)malloc(sizeof(BiTree));
	BiTree s;
	if (!SearchBST((*T), e, NULL, p))
	{
		_CRT_JIT_INTRINSIC		s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!(*p))
		{
			(*T) = s; // ���� s Ϊ�µĸ����
		}
		else if (e < (*p)->data)
		{
			(*p)->lchild = s; // ���� *s Ϊ *p ������
		}
		else
		{
			(*p)->rchild = s; // ���� *s Ϊ *p ���Һ���
		}
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//ɾ�����
Status DeleteBST(BiTree *T, ElemType kval)
{

	if (!(*T))
	{ // �����ڹؼ��ֵ���kval������Ԫ��
		return FALSE;
	}
	else
	{
		if (kval == (*T)->data)
		{ // �ҵ��ؼ��ֵ���key������Ԫ��
			Delete(T);
			return TRUE;
		}
		else if (kval < (*T)->data)
		{ // �������������н��в���
			return DeleteBST(&((*T)->lchild), kval);
		}
		else
		{ // �������������н��в���
			return DeleteBST(&((*T)->rchild), kval);
		}
	}
}

int  Delete(BiTree *p)
{
	// �Ӷ�����������ɾ����� p��
	// ���ؽ�������������������
	BiTree q;
	BiTree  s;

	if (!(*p)->rchild)
	{ // ������Ϊ������ֻ���ؽ�����������
		q = (*p);
		(*p) = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)
	{ // ������Ϊ������ֻ���ؽ�����������
		q = (*p);
		(*p) = (*p)->rchild;
		free(q);
	}
	else
	{  // ��������������
		q = (*p);
		s = (*p)->lchild;
		while (s->rchild) { // s ָ��ɾ����ǰ��
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != (*p)) 
		{
			q->rchild = s->lchild; // �ؽ�*q��������
		}
		else 
		{
			q->lchild = s->lchild; // �ؽ�*q��������
		}
		free(s);
	}
	return 1;
}

//�������
Status InOrder(BiTree T)
{
	if (T)
	{
	    out[k]=T->data  ;//ÿ���������ֵ 
		k++;
		InOrder(T->lchild);
		InOrder(T->rchild);
	}
	else
		return 1;
}
//���ڴ�ӡ�ض���ʽ�����
Status  print(BiTree T, FILE *fp)
{
	char x[4] = ", ";
	int i;
	for (i = 0; i < num; i++)
	{
		out[i] = -1;
	}
	InOrder(T);
	for (i = 0;; i++)
	{
	if (out[i] == -1)
	{
		break;
	}
	if (i != 0)
	{
		//printf(", ");
		fputs(x, fp);
	 }
	//printf("%d", out[i]);
	  fprintf(fp, "%d", out[i]);
	}
	return 0;
}
int main()
{
	FILE *fp;
	char z[4] = "\n";
	fp = fopen("BSTOutput.txt", "a");
	int  number[num_length] = { 8, 10,14, 3, 1,  6, 4, 7, 5, 19,  22, 30 };
	int search[s_length] = { 13, 8, 5, 20, 6 };
	BiTree T = NULL;
	int i;
	for (i = 0; i < 12; i++)
	{
		InsertBST(&T, number[i]);
		T->data;
	}
	print(T , fp);
	fputs(z, fp);
	//printf("\n");
	for (i = 0; i < 5; i++)
	{//�������ʧ��  �ͽ���ɾ������
		k = 0;//��ʼ������������
		if (!InsertBST(&T, search[i]))
		{
			DeleteBST(&T, search[i]);
		}
		print(T, fp);
		//printf("\n");
		fputs(z, fp);
	}

	fclose(fp);
	return 0;
}