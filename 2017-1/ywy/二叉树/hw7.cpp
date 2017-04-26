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
		*T = NULL;//节点没有子树
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiNode))))
		{
			return OVERFLOW;//内存分配失败
		}
		(*T)->data = ch;//生成根节点              
		CreatBiTree(&(*T)->lchild, ar);//创建左子树   
		CreatBiTree(&(*T)->rchild, ar); //创建右子树  
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
	printf("创建二叉树 : ABCD$$$EF$$G$H$$I$J$$\n");
	printf("后序遍历   :  ");
	PostOrderTraverse(T);
	printf("\n");
	return 0;

}