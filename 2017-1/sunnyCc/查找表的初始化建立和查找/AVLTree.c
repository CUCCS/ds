#include "AVLTree.h"
int flag;
int InsertAVL(BSTree* T, ElemType e, bool* taller)
{
	//若在平衡的二叉树排序树中不存在和e有相同关键字的结点，则插入一个数据元素
	//为e的新结点，并返回1，否则返回0/若因插入而使二叉排序树失去平衡，则作平衡
	//旋转处理，布尔变量taller反映T长高与否
	if ((*T) == NULL)
	{                                             //插入新结点，数“长高”，置taller为TRUE
		(*T) = (BSTree)malloc(sizeof(BSTNode));
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = true;
	}
	else if (e == (*T)->data)                     //树中已存在与e有相同关键点的结点
	{
		*taller = false;                          //不再插入
		return 0;
	}
	else if (e < (*T)->data)                      //继续在*T的左子树中进行搜索
	{
		if (!InsertAVL(&(*T)->lchild, e, taller))
			return 0;                             //未插入
		if (*taller)                              //已插入到*T的左子树中且左子树“长高”
		{
			switch ((*T)->bf)                     //检查*T的平衡度
			{
			case LH:                              //原本左子树比右子树高，需要做左平衡处理
				LeftBalance(T);
				*taller = false;
				break;
			case  EH:                             //原本左右子树一样高，现因左子树增高而使树增高
				(*T)->bf = LH;
				*taller = true;
				break;
			case RH:                              //原本右子树比左子树高，需要做右平衡处理
				(*T)->bf = EH;
				*taller = false;
				break;
			}
		}
	}
	else
	{                                             //因继续在*T的右子树中进行搜索
		if (!InsertAVL(&(*T)->rchild, e, taller)) //未插入
			return 1;
		if (*taller)                              //已插入到*T的右子树中且右子树“长高”
		{
			switch ((*T)->bf)                     //检查*T的平衡度
			{
			case LH:                              //原本左子树比右子树高，现在左右子树等高
				(*T)->bf = EH;
				*taller = false;
				break;
			case EH:                              //原本左右子树一样高，现因右子树增高而使树增高
				(*T)->bf = RH;
				*taller = true;
				break;
			case  RH:
				RightBalance(T);                  //原本右子树比左子树高，需要做右平衡处理
				*taller = false;
				break;
			}
		}
	}
	return 1;
}
//建立二叉平衡树
Status CreatBST(BSTree *T, int a[], int n)
{
	int i;
	bool *taller;
	*T = NULL;
	for (i = 0; i < n; i++)
	{
		InsertAVL(&(*T), a[i], &taller);
	}
	return OK;
};
//删除二叉平衡树
bool Delete(BSTree *T)
{
	BSTree L, S;
	if (!(*T)->lchild && !(*T)->rchild)//左右子树都为空
	{
		*T = NULL;
	}
	else if (!(*T)->lchild)// 左子树为空，重接它的右子树
	{
		L = *T;
		*T = (*T)->rchild;
		free(L);
	}
	else if (!(*T)->rchild) // 右子树为空，重接它的左子树
	{
		L = *T;
		*T = (*T)->lchild;
		free(L);
	}
	else//左右子树均不为空
	{
		L = *T;
		S = (*T)->lchild;
		while (S->rchild) // S 指向被删结点的前驱
		{
			L = S;
			S = S->rchild;
		}
		(*T)->data = S->data;
		if (L != *T)
		{
			L->rchild = S->lchild;// 重接*q的右子树
		}
		else
		{
			L->lchild = S->lchild;// 重接*q的左子树
		}
		free(S);
	}
	return true;
};
//删除值为key的结点
bool DeleteAVL(BSTree *T, int key)
{
	if (!T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			Delete(T);
			return true;
		}
		else if (key < (*T)->data)
		{
			return DeleteAVL(&(*T)->lchild, key);
		}
		else
		{
			return DeleteAVL(&(*T)->rchild, key);
		}
	}
};
void R_Rotate(BSTree* p)
{   //对以*p为根的二叉排序树作右旋处理，处理之后p指向新的树根节点
	//即旋转处理之前的左子树的根节点
	BSTree lc = (*p)->lchild;     //lc指向*p的左子树根结点  
	(*p)->lchild = lc->rchild;    //lc的右子树挂接为*p的左子树  
	lc->rchild = *p;
	*p = lc;                      //p指向新的根结点  
}

void L_Rotate(BSTree* p)
{   //对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根节点
	//即旋转处理之前的右子树的根节点
	BSTree rc = (*p)->rchild;     //rc指向*p的右子树根结点  
	(*p)->rchild = rc->lchild;    //rc的左子树挂接为*p的右子树  
	rc->lchild = *p;
	*p = rc;                      //p指向新的根结点  
}
/* 对以指针T为根结点的二叉树做左平衡旋转处理，处理结束后，指针T指向新的根结点 */
void LeftBalance(BSTree* T)
{
	BSTree lc, rd;
	lc = (*T)->lchild;  //lc指向T的左子树根结点  
	switch (lc->bf)
	{ //检查T的左子树的平衡因子  
	case LH:           //新结点插入到T的左孩子的左子树上，要做单右旋处理  
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:           //新结点插入到T的左孩子的右子树上，要做双旋处理  
		rd = lc->rchild;   //rd指向T的左孩子的右子树的根结点  
		switch (rd->bf)     //修改T及其左孩子的平衡因子  
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		L_Rotate(&(*T)->lchild);
		R_Rotate(T);
		break;
	}
}
//对以指针T为根结点的二叉树做右平衡旋转处理，处理结束后，指针T指向新的根结点 
void RightBalance(BSTree* T)
{
	BSTree lc, rd;
	lc = (*T)->rchild;
	switch (lc->bf)
	{
	case RH:
		(*T)->bf = lc->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		rd = lc->lchild;
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	}
}

//在二叉树里面查找元素key
//若成功，返回true
//若不成功，则根据其key大小结合排序二叉树的属性，确定在左子树还是在右子树中使用递归算法查找
bool SearchAVL(BSTree T, int key, BSTree f, BSTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else
	{
		if (key == T->data)
		{
			p = &T;
			return true;
		}
		else if (key > T->data)
		{
			return SearchAVL(T->rchild, key, T, p);
		}
		else
		{
			return SearchAVL(T->lchild, key, T, p);
		}
	}
};
//打印到文件txt中
int TraversePrint(BSTree T, FILE*pfile)
{
	if (T)
	{
		print(T->data, pfile);
		TraversePrint(T->lchild, pfile);
		TraversePrint(T->rchild, pfile);
	}
	else
		return 1;
};
//打印到文件txt中
bool print(int data, FILE*pfile)
{

	char d[2] = { ", " };
	if (NULL == pfile)
	{
		return false;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d", data);
		flag = 1;
		return true;
	}
}
//先序遍历输出T
int PreOrderTraverse(BSTree T)
{
	if (T)
	{
		printf("%d ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
		return 1;
};
