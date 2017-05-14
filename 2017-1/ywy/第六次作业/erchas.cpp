#include <stdio.h>
#include <stdlib.h>
int count = 0;
int jiedian = 0;//�ܽڵ���
typedef char ElemType;
typedef struct BiNode
{
	ElemType      data;
	struct BiNode  *lchild, *rchild;
} BiNode, *BiTree;
typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

Status CreatBiTree(BiTree *T, ElemType *ar)
{
	ElemType ch;
	ch = ar[count];
	count++;
	if (ch == '#')
	{
		*T = NULL;//�ڵ�û������
	}
	else
	{
		jiedian++;
		if (!(*T = (BiTree)malloc(sizeof(BiNode))))
		{
			return OVERFLOW;//�ڴ����ʧ��
		}
		(*T)->data = ch;//���ɸ��ڵ�              
		CreatBiTree(&(*T)->lchild, ar);//����������   
		CreatBiTree(&(*T)->rchild, ar); //����������  
	}
	return OK;
}
void PostOrderTraverse(BiTree T)//������������
{
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
int depth(BiTree T)//�������
{
	int ldepth, rdepth;
	if (T == NULL)
	{
		return 0;
	}
	ldepth = depth(T->lchild);
	rdepth = depth(T->rchild);
	if (ldepth > rdepth)
	{
		return ldepth + 1;
	}
	else
	{
		return rdepth + 1;
	}
}
int j = 0;
int max = 0;//�����
int counter[20];//ÿ����
int width(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	j++;
	counter[j]++;
	if (max < counter[j])
	{
		max = counter[j];
	}
	width(T->lchild);
	width(T->rchild);
	j--;
	return max;
}
int leaf_num(BiTree T)//Ҷ�ӽڵ�
{
	int l, r;
	if (T == NULL)
	{
		return 0;
	}
	if (T->lchild == NULL&&T->rchild == NULL)
	{
		return 1;
	}
	else
	{
		l = leaf_num(T->lchild);
		r = leaf_num(T->rchild);
		return l + r;
	}
}

int main()
{
	BiTree T, R;
	ElemType str1[30] = "ABDG###EH##I#K##C#F##";
	ElemType str2[30] = "ABD#F###CE###";
	CreatBiTree(&T, str1);

	printf("����-1��ABDG###EH##I#K##C#F##:\n");
	printf("���Ϊ��%d\n�����Ϊ��%d\n", depth(T), width(T));
	printf("���:    ");
	PostOrderTraverse(T);
	printf("\n");
	printf("Ҷ�ӽڵ�����%d\n", leaf_num(T));
	printf("��Ҷ�ӽڵ�����%d", jiedian - leaf_num(T));
	printf("\n\n");

	count = 0;
	jiedian = 0;
	max = 0;
	int g;
	for (g = 0; g < 20; g++)
	{
		counter[g] = 0;
	}
	CreatBiTree(&R, str2);
	printf("����-2��ABD#F###CE###:\n");
	printf("���Ϊ��%d\n�����Ϊ��%d\n", depth(R), width(R));
	printf("���:    ");
	PostOrderTraverse(R);
	printf("\n");
	printf("Ҷ�ӽڵ�����%d\n", leaf_num(R));
	printf("��Ҷ�ӽڵ�����%d", jiedian - leaf_num(R));
	printf("\n");
}