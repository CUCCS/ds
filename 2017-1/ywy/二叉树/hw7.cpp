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
	if (ch == '$')        
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
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}
int main()
{
	BiTree T = NULL;
	//Status ret;
	ElemType str[80] = "ABCD$$$EF$$G$H$$I$J$$";
	
	 CreatBiTree(&T, str);//"ret" is used to text wether the operation of Create succeed or not
	printf("���������� : ABCD$$$EF$$G$H$$I$J$$\n");
	printf("�������   :  ");
	PostOrderTraverse(T);
	printf("\n");
	return 0;

}