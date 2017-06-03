#include "AVLTree.h"
int flag = 0;
Bool EQ(int k, int tk)
{
	if (k == tk)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Bool LT(int k, int tk)
{
	if (k < tk)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Bool InsertAVL(BSTree *t, ElemType e, Boolean *taller)
{
	//插入操作，若在平衡二叉排序树T中不存在和e相同的关键字结点，则插入一个数据元素
	//为e的新结点。若插入使二叉树失衡，做旋转处理，taller反映T长高与否。
	//用此函数建立平衡排序二叉树。
	if (NULL == *t)
	{
		(*t) = (BSTree)malloc(sizeof(BSTNode));
		(*t)->data.key = e.key;
		(*t)->lchild = (*t)->rchild = NULL;
		(*t)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if (TRUE == EQ(e.key, (*t)->data.key))
		{
			*taller = FALSE;
			return FALSE;
		}
		
		if (TRUE == LT(e.key, (*t)->data.key))  
		{
			//若待查找关键字小于结点,在左子树查找
			if (FALSE == InsertAVL(&(*t)->lchild, e, taller))
			{
				return FALSE;
			}
			if (*taller)//调节左子树平衡
			{
				switch ((*t)->bf)
				{
				case LH:
				{
					LeftBalance(t);
					*taller = FALSE;
					break;
				}
				case EH:
				{
					(*t)->bf = LH;
					*taller = TRUE;
					break;
				}
				case RH:
				{
					(*t)->bf = EH;
					*taller = FALSE;
					break;
				}
				default:
					break;
				}
			}
		}
		else
		{
			if (FALSE == InsertAVL(&(*t)->rchild, e, taller))
			{
				return FALSE;
			}
			if (*taller==TRUE)//调节右子树平衡
			{
				switch ((*t)->bf)
				{
				case LH:
				{
					(*t)->bf = EH;
					*taller = FALSE;
					break;
				}
				case EH:
				{
					(*t)->bf = RH;
					*taller = TRUE;
					break;
				}
				case RH:
				{
					RightBalance(t);
					*taller = FALSE;
					break;
				}
				default:
					break;
				}
			}
		}
	}
  return TRUE;
}

Status LeftBalance(BSTree*t)
{
	BSTree lc = (*t)->lchild;//lc指向*t的左子树根结点
	BSTree rd = (BSTree)malloc(sizeof(BSTNode));
	if (NULL == lc)
	{
		return ERROR;
	}
	switch (lc->bf) //检测*t左子树的平衡度，并做并做相应的平衡处理
	{
	case LH:
	{
		//新结点插在*t的左孩子的左子树上，做右旋处理
		(*t)->bf = lc->bf = EH;
		R_Rotate(t);
		break;
	}
	case RH:
	{
		//新结点插在*t左孩子的右子树上，做双旋处理
		rd = lc->rchild;
		switch (rd->bf)
		{
		case LH:
		{
			(*t)->bf = RH;
			lc->bf = EH;
			break;
		}
		case EH:
		{
			(*t)->bf = lc->bf = EH;
			break;
		}
		case RH:
		{
			(*t)->bf = EH;
			lc->bf = LH;
			break;
		}
		
		default:
			break;
		}
		rd->bf = EH;
		L_Rotate(&(*t)->lchild);
		R_Rotate(t);
	}
	default:
		break;
	}
	return OK;
}


Status RightBalance(BSTree *t)
{
	//对以指针t所指结点为根的二叉树做右平衡旋转处理，算法结束时，指针t指向新的跟结点。
	BSTree rc = (*t)->rchild;//rc指向*t的右子树根结点
	BSTree ld = (BSTree)malloc(sizeof(BSTNode));
	if (NULL == rc)
	{
		return ERROR;
	}
	switch (rc->bf)//检测右子树的平衡度，并做出相应的平衡处理
	{
	case LH:
	{
		ld = rc->lchild;
		switch (ld->bf)
		{
		case LH:
		{
			(*t)->bf = EH;
			rc->bf = RH;
			break;
		}
		case EH:
		{
			(*t)->bf = rc->bf = EH;
			break;
		}
		case RH:
		{
			(*t)->bf = LH;
			rc->bf = EH;
			break;
		}
		default:
			break;
		}
		ld->bf = EH;
		R_Rotate(&(*t)->rchild);
		L_Rotate(t);
		break;
	}
	case RH:
	{
		(*t)->bf = rc->bf = EH;
		L_Rotate(t);
		break;
	}
	default:
		break;
		
	}
	return OK;
}

void R_Rotate(BSTree *p)
{
	BSTree lc = (*p)->lchild;
	if (NULL == lc->rchild)
	{
		(*p)->lchild = NULL;
	}
	else
	{
		(*p)->lchild = lc->rchild;
	}
	lc->rchild = *p;
	*p = lc;
}

void L_Rotate(BSTree*p)
{
	BSTree rc = (*p)->rchild;
	if (NULL == rc->lchild)
	{
		(*p)->rchild = NULL;
	}
	else
	{
		(*p)->rchild = rc->lchild;
	}
	rc->lchild = (*p);
	(*p) = rc;
}

Status PreOrderTraverse(BSTree t,FILE*pfile)
{

	if (NULL == t)
	{
		return ERROR;
	}
	if (NULL != t)
	{
		print(t->data, pfile);
		PreOrderTraverse(t->lchild, pfile);
		PreOrderTraverse(t->rchild, pfile);
	}

	return OK;
}

Bool SearchBST(BSTree t, ElemType e)
{
	while (t != NULL)
	{
		if (EQ( e.key, t->data.key))
		{
			return TRUE;
		}
		else if (LT(e.key, t->data.key))
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}
	return FALSE;

}
Bool Delete(BSTree *p)
{
	if (NULL == (*p)->rchild)//若右孩子为空，则直接删除结点;
	{
		BSTree q = *p;
		(*p) = (*p)->lchild;
		free(q);

	}
	else if (NULL == (*p)->lchild)
	{
		BSTree q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		BSTree q = *p;
		BSTree s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
		{
			q->rchild = s->lchild;
			q->bf = 1;
		}
		else
		{
			q->lchild = s->lchild;
			q->bf = -1;
		}
		free(s);
	}
	return TRUE;
}


Status DeleteAVL(BSTree *t, ElemType e, Boolean *lower)
{
	//若在平衡二叉树t中存在和e相同的关键字结点，则删除并作相应平衡处理
	//lower用于判断树是否变矮
	BSTree p = (BSTree)malloc(sizeof(BSTree));
	if (NULL == *t)  //若树为空，直接返回ERROR
	{
		return ERROR;
	}
	if (EQ(e.key,(*t)->data.key)) //若关键字与结点相同，删除结点
	{
		Delete(t);
		*lower = TRUE;
	}
	else if (LT(e.key, (*t)->data.key))
	{
		if (ERROR == DeleteAVL(&(*t)->lchild, e, lower))
		{
			return ERROR;
		}
		if (*lower)
		{
			switch ((*t)->bf)
			{
			case LH:
			{
				(*t)->bf = EH;
				*lower = TRUE;
				break;
			}
			case EH:
			{
				(*t)->bf = RH;
				*lower = FALSE;
				break;
			}
			case RH:
			{
				RightBalance(t);
				*lower = TRUE;
				break;
			}
			}
		}
	}
	else
	{
		if (ERROR == DeleteAVL(&(*t)->rchild, e, lower))
		{
			return ERROR;
		}
		if (*lower)
		{
			switch ((*t)->bf)
			{
			case LH:    //原本左子树比右子树高，则作左平衡处理  
				LeftBalance(t);
				*lower = TRUE;
				break;
			case EH:    //原本左右子树等高，现左子树比右子树高1  
				(*t)->bf = LH;
				*lower = FALSE;
				break;
			case RH:    //原本右子树比左子树高，现左左子树等高  
				(*t)->bf = EH;
				*lower = TRUE;
				break;

			}
		}
	}
	return OK;
}
Status print(ElemType data, FILE*pfile)
{

	char d[4] = ", ";
	if (NULL == pfile)
	{
		return ERROR;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fputs(d, pfile);
		}
		fprintf(pfile, "%d", data.key);
		flag = 1;

	}
}