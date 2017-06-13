#include "s.h"
//查找结点
Status SearchBST(BiTree T, ElemType kval, BiTree f, BiTree  *p)
{
	if (!T)
	{ // 空树，查找不成功
		(*p) = f;                                        //f的作用是初始化 p的吗
		return FALSE;
	}
	else if (kval == T->data)
	{
		(*p) = T;
		return TRUE;   // 查找成功
	}
	else if (kval < T->data)     //如果该数较小的话
	{ // 在左子树中继续查找
		return SearchBST(T->lchild, kval, T, p);
	}
	else 
	{ // 在右子树中继续查找
		return SearchBST(T->rchild, kval, T, p);
	}
}
//插入元素
Status InsertBST(BiTree *T, ElemType e)
{
	// 当二叉排序树中不存在关键字等于 e.key 的
	// 数据元素时，插入元素值为 e 的结点，并返
	// 回 TRUE; 否则，不进行插入并返回FALSE
	BiTree *p = (BiTree *)malloc(sizeof(BiTree));
	BiTree s;
	if (!SearchBST((*T), e, NULL, p))
	{
		_CRT_JIT_INTRINSIC		s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!(*p))
		{
			(*T) = s; // 插入 s 为新的根结点
		}
		else if (e < (*p)->data)
		{
			(*p)->lchild = s; // 插入 *s 为 *p 的左孩子
		}
		else
		{
			(*p)->rchild = s; // 插入 *s 为 *p 的右孩子
		}
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//删除结点
Status DeleteBST(BiTree *T, ElemType kval)
{

	if (!(*T))
	{ // 不存在关键字等于kval的数据元素
		return FALSE;
	}
	else
	{
		if (kval == (*T)->data)
		{ // 找到关键字等于key的数据元素
			Delete(T);
			return TRUE;
		}
		else if (kval < (*T)->data)
		{ // 继续在左子树中进行查找
			return DeleteBST(&((*T)->lchild), kval);
		}
		else
		{ // 继续在右子树中进行查找
			return DeleteBST(&((*T)->rchild), kval);
		}
	}
}

int  Delete(BiTree *p)
{
	// 从二叉排序树中删除结点 p，
	// 并重接它的左子树或右子树
	BiTree q;
	BiTree  s;

	if (!(*p)->rchild)
	{ // 右子树为空树则只需重接它的左子树
		q = (*p);
		(*p) = (*p)->lchild;
		free(q);
	}
	else if (!(*p)->lchild)
	{ // 左子树为空树则只需重接它的右子树
		q = (*p);
		(*p) = (*p)->rchild;
		free(q);
	}
	else
	{  // 左右子树均不空
		q = (*p);
		s = (*p)->lchild;
		while (s->rchild) { // s 指向被删结点的前驱
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != (*p)) 
		{
			q->rchild = s->lchild; // 重接*q的右子树
		}
		else 
		{
			q->lchild = s->lchild; // 重接*q的左子树
		}
		free(s);
	}
	return 1;
}

//先序遍历
Status InOrder(BiTree T)
{
	if (T)
	{
	    out[k]=T->data  ;//每次输出结点的值 
		k++;
		InOrder(T->lchild);
		InOrder(T->rchild);
	}
	else
		return 1;
}
//用于打印特定形式的输出
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
	{//如果插入失败  就进行删除操作
		k = 0;//初始化计数的数字
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