#include "BSTree.h"


 //在根指针 T 所指二叉排序树中递归地查找其关键字等于 key 的数据元素，若查找成功，
 //则返回指针 p 指向该数据元素的结点，并返回函数值为 TRUE; 否则表明查找不成功，返回
 //指针 p 指向查找路径上访问的最后一个结点，并返回函数值为FALSE, 指针 f 指向当前访问
 //的结点的双亲，其初始调用值为NULL
Status SearchBST(BiTree T, ElemType key, BiTree f, BiTree *p)
{
	if (!T)                                               //查找不成功
	{
		*p = f;
		return FALSE;
	}
	else if (EQ(key, T->data))               //查找成功
	{
		*p = T;
		return TRUE;
	}
	else if (LT(key, T->data))               //在左子树中继续查找
		return SearchBST(T->lchild, key, T, p);
	else                                                //在右子树中继续查找
		return SearchBST(T->rchild, key, T, p); 
}
// 当二叉排序树中不存在关键字等于 e.key 的数据元素时，插入元素值为 e 的结点，并返回 TRUE; 否则，不进行插入并返回FALSE
Status InsertBST(BiTree *T, ElemType e) 
{
	BiTree p = NULL, s = NULL;

	if (SearchBST(*T, e, NULL, &p)==FALSE) 
	{
		s = (BiTree)malloc(sizeof(BiTNode)); // 为新结点分配空间
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) 
		{
			*T = s; // 插入 s 为新的根结点
		}
		else if (LT(e, p->data))
		{
			p->lchild = s; // 插入 *s 为 *p 的左孩子
		}
		else
		{
			p->rchild = s; // 插入 *s 为 *p 的右孩子
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status PreOrderTraverse(BiTree T)    //先序遍历二叉排序树  
{

	if (T)
	{
		visit[u++] = T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}


//从二叉排序树中删除结点p，并重接他的左或右子树
Status Delete(BiTree *p)
{
	BiTree q = NULL, s = NULL;
	if (!(*p)->rchild)       //右子树空只需重接它的左子树
	{    
		q = *p; 
		*p = (*p)->lchild; 
		free(q);
	}
	else if (!(*p)->lchild)     //左子树为空只需重接它的右子树  
	{   
		q = *p; 
		*p = (*p)->rchild;
		free(q);
	}
	else      //左右子树均不为空  
	{  
		q = *p; 
		s = (*p)->lchild;
		while (s->rchild)     //转左。然后向右走到尽头  
		{  
			q = s; 
			s = s->rchild;
		}
		(*p)->data = s->data;  //s指向被删除结点的前驱  
		if (q != *p) 
		{ 
			q->rchild = s->lchild;     //重接*q的右子树  
		} 
		else 
		{ 
			q->lchild = s->lchild;     //重接*q的左子树  
		}
		free(s);
	}
	return TRUE;
}
// 若二叉排序树 T 中存在其关键字等于 key 的数据元素，则删除该数据元素结点，并返回函数值 TRUE，否则返回函数值 FALSE
Status DeleteBST(BiTree *T, ElemType key)
{
	if (!(*T))    // 不存在关键字等于key的数据元素
	{ 
		return FALSE;
	}
	else 
	{
		if (EQ(key, (*T)->data))  // 找到关键字等于key的数据元素
		{
			Delete(T);
			return TRUE;
		}
		else if (LT(key, (*T)->data)) // 继续在左子树中进行查找
		{ 
			return DeleteBST(&(*T)->lchild, key);
		}
		else // 继续在右子树中进行查找
		{ 
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

Status  print(BiTree T, FILE *fp)    //.txt格式输出
{
	char x[4] = ", ";
	int i;
	for (i = 0; i < 25; i++)
	{
		visit[i] = -1;
	}
	PreOrderTraverse(T);
	for (i = 0;; i++)
	{
		if (visit[i] == -1)
		{
			break;
		}
		if (i != 0)
		{
			fputs(x, fp);
		}
		fprintf(fp, "%d", visit[i]);
	}
	return 0;
}

int main()
{
	FILE *fp;
	char c[4] = "\n";
	fp = fopen("BSTOutput.txt", "a");
	ElemType  input[25] = { 8, 10,14, 3, 1,  6, 4, 7, 5, 19,  22, 30 };
	ElemType search[10] = { 13, 8, 5, 20, 6 };
	BiTree T = NULL;
	BiTree  p = NULL;
	int i;
	for (i = 0; i < 12; i++)
	{
		InsertBST(&T, input[i]);
	}
	print(T, fp);     //建立查找表之后输出这个查找表
	fputs(c, fp);    //换行
	for (i = 0; i < 5; i++)
	{
		u = 0;                     //初始化计数的数字
		if (SearchBST(T, search[i], NULL, &p) == FALSE)   //若果查找失败，则插入这个数据
		{
			InsertBST(&T, search[i]);
		}
		else    //如果查找成功，则删除这个数据
		{
			DeleteBST(&T, search[i]);
		}
		print(T, fp);
		fputs(c, fp);
	}

	fclose(fp);
	return 0;
}