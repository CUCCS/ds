#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW 0
#define OK 1

typedef int Status;
typedef char ElemType;
typedef struct BiTree
{
	ElemType data;
	struct BiTree *Lchild;
	struct BiTree *Rchild;
}BiTree,*Binary_Tree;
//����һ��������
Status CreateBiTree(Binary_Tree *T)
{
	char ch;
	*T=(Binary_Tree)malloc(sizeof(BiTree));
	if(!(*T))
		exit(OVERFLOW);
	scanf("%c",&ch);
	if(ch=='0')
		*T=NULL;
	else
	{
		(*T)->data=ch;
		CreateBiTree(&((*T)->Lchild));
		CreateBiTree(&((*T)->Rchild));
	}
	return OK;
}
//�ȱ���������
Status PreShowBiTree(Binary_Tree T)
{
	if(T!=NULL)
	{
		printf("%c  ",T->data);
		PreShowBiTree(T->Lchild);
		PreShowBiTree(T->Rchild);
	}
	return OK;
}

//�б���������
Status MidShowBiTree(Binary_Tree T)
{
	if(T!=NULL)
	{
		MidShowBiTree(T->Lchild);
		printf("%c  ",T->data);
		MidShowBiTree(T->Rchild);
	}
	return OK;
}

//�����������
Status BehShowBiTree(Binary_Tree T)
{
	if(T!=NULL)
	{
		BehShowBiTree(T->Lchild);
		BehShowBiTree(T->Rchild);
		printf("%c  ",T->data);
	}
	return OK;
}

int main()
{
	BiTree *T=NULL;
	printf("�봴��һ��������,0����� :\n");
	CreateBiTree(&T);
	printf("�������: \n");
	PreShowBiTree(T);
	printf("\n");
	printf("�������:  \n");
	MidShowBiTree(T);
	printf("\n");
	printf("�������: \n");
	BehShowBiTree(T);
	printf("\n");

}