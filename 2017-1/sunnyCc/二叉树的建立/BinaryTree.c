#include"BinaryTree.h"
int count = 0;
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;
	ch = p[count];
	count++;
	if (ch == '#')        //if the tree has no child
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;              // creat root node
		CreateBiTree(&(*T)->lchild, p);   // creat left node,"&(*T)->lchild" is equal to "&((*T)->lchild)"
		CreateBiTree(&(*T)->rchild, p);   //creat right node
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

