#include <stdio.h>
#include <stdlib.h>
int count = 0;
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
	if(T==NULL)
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
int width(BiTree T)
{
	int static level[10];//���������10��
	int static max = 0;//�����
	int static j = 0;
	int static counter[20];
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

int main()
{
	BiTree T;
	ElemType str[30] = "ABDG###EH##I#K##C#F##";
	printf("���:    ");
	CreatBiTree( &T,  str);
	printf("������ABDG###EH##I#K##C#F##:\n");
	PostOrderTraverse(T);
	printf("���Ϊ��%d\n�����Ϊ��%d\n",depth(T),width(T));
	printf("\n");
	
}