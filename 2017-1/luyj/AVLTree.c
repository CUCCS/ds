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
	//�������������ƽ�����������T�в����ں�e��ͬ�Ĺؼ��ֽ�㣬�����һ������Ԫ��
	//Ϊe���½�㡣������ʹ������ʧ�⣬����ת����taller��ӳT�������
	//�ô˺�������ƽ�������������
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
			//�������ҹؼ���С�ڽ��,������������
			if (FALSE == InsertAVL(&(*t)->lchild, e, taller))
			{
				return FALSE;
			}
			if (*taller)//����������ƽ��
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
			if (*taller==TRUE)//����������ƽ��
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
	BSTree lc = (*t)->lchild;//lcָ��*t�������������
	BSTree rd = (BSTree)malloc(sizeof(BSTNode));
	if (NULL == lc)
	{
		return ERROR;
	}
	switch (lc->bf) //���*t��������ƽ��ȣ�����������Ӧ��ƽ�⴦��
	{
	case LH:
	{
		//�½�����*t�����ӵ��������ϣ�����������
		(*t)->bf = lc->bf = EH;
		R_Rotate(t);
		break;
	}
	case RH:
	{
		//�½�����*t���ӵ��������ϣ���˫������
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
	//����ָ��t��ָ���Ϊ���Ķ���������ƽ����ת�����㷨����ʱ��ָ��tָ���µĸ���㡣
	BSTree rc = (*t)->rchild;//rcָ��*t�������������
	BSTree ld = (BSTree)malloc(sizeof(BSTNode));
	if (NULL == rc)
	{
		return ERROR;
	}
	switch (rc->bf)//�����������ƽ��ȣ���������Ӧ��ƽ�⴦��
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
	if (NULL == (*p)->rchild)//���Һ���Ϊ�գ���ֱ��ɾ�����;
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
	//����ƽ�������t�д��ں�e��ͬ�Ĺؼ��ֽ�㣬��ɾ��������Ӧƽ�⴦��
	//lower�����ж����Ƿ�䰫
	BSTree p = (BSTree)malloc(sizeof(BSTree));
	if (NULL == *t)  //����Ϊ�գ�ֱ�ӷ���ERROR
	{
		return ERROR;
	}
	if (EQ(e.key,(*t)->data.key)) //���ؼ���������ͬ��ɾ�����
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
			case LH:    //ԭ�����������������ߣ�������ƽ�⴦��  
				LeftBalance(t);
				*lower = TRUE;
				break;
			case EH:    //ԭ�����������ȸߣ�������������������1  
				(*t)->bf = LH;
				*lower = FALSE;
				break;
			case RH:    //ԭ�����������������ߣ������������ȸ�  
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