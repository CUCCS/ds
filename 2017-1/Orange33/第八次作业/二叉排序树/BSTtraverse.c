#include<stdio.h>
#include <stdlib.h>
#include "BSTtraverse.h"

BSTree InsertBST(BSTree T, int data) //插入结点
{
	BSTree t;
	if (!T)
	{
		t = (BSTree)malloc(sizeof(BSTNode));//分配空间
		t->data = data;
		t->lchild = NULL;
		t->rchild = NULL;
		return t;
	}
	else if (T->data < data)
	{
		T->rchild = InsertBST(T->rchild, data);
	}
	else if (T->data > data)
	{
		T->lchild = InsertBST(T->lchild, data);
	}
	return T;
}

BSTree CreatBST(BSTree T, int array[])//建立二叉树
{
	for (int i = 0; i < 12; i++)
	{
		T = InsertBST(T, array[i]); //逐个结点插入
	}
	return T;
}

bool SearchBST(BSTree T, int key) //查找二叉树中有无目标结点
{
	if (!T) //无此结点，返回FALSE
	{
		return false;
	}
	else if (T->data == key) //有此结点
	{
		/*printf("%d\n", T->data);*/
		return true;
	}
	else if (T->data > key)
	{
		return SearchBST(T->lchild, key);
	}
	else if (T->data < key)
	{
		return SearchBST(T->rchild, key);
	}
	return true;
}

void PrePrintBST(BSTree T) //先序遍历输出二叉树
{
	if (T)
	{
		printf("%d, ", T->data);
		PrePrintBST(T->lchild);
		PrePrintBST(T->rchild);
	}
}

bool DeleteBST(BSTree *T, int key)  //删除结点
{
	if (!*T)         //如果没有此结点返回FALSE。
		return false;
	else if (key == (*T)->data)//在以*T为根结点的树中，删除与key相同的结点
	{
		Delete(T);
		return true;
	}
	else if (key < (*T)->data)
	{
		return DeleteBST(&((*T)->lchild), key);
	}
	else
	{
		return DeleteBST(&((*T)->rchild), key);
	}
}

bool Delete(BSTree *T)  //删除*T指向的结点
{
	BSTree L;

	if (!(*T)->lchild && !(*T)->rchild)  //无左右孩子
		*T = NULL;

	else if (!(*T)->lchild)//只有右孩子
		*T = (*T)->rchild;

	else if (!(*T)->rchild)//只有左孩子
		*T = (*T)->lchild;

	else//既有左孩子，又有右孩子
	{
		L = (*T)->lchild; //指向被删除结点的左子树
		while (L->rchild) //寻找L的最右孩子
		{
			L = L->rchild;
		}
		L->rchild = (*T)->rchild; //把*T的右子树接到左子树最右孩子的右子树上

		*T = (*T)->lchild;      //把*T的左子树作为*T父结点的子树
	}
	return true;
}