#include "BiSTree.h"
int flag = 0;

bool EQ(int k, int tk)
{
	if (k == tk)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool LT(int k, int tk)
{
	if (k < tk)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p)
{

	if (T==NULL)//����Ϊ�գ����ظ����;
	{
		*p = f;
		return false;
	}
	else if (EQ(key, T->data.key)==true)
	{
		*p = T;
		return true;
	}
	else if (LT(key, T->data.key)==true)//���ؼ���ֵС�ڸ����ֵ�������������ϲ���;
	{

		return (SearchBST(T->lchild, key, T, p));
	}
	else
	{
		return (SearchBST(T->rchild, key, T, p));//���ؼ���ֵ���ڸ���㣬�����������ϲ���;
	}
}


bool Delete(BiTree *p)
{
	if ((*p)->rchild==NULL)//���Һ���Ϊ�գ���ֱ��ɾ�����;
	{
		BiTree q = *p;
		(*p) = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild==NULL)
	{
		BiTree q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else
	{
		BiTree q = *p;  
		BiTree s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return true;
}

//����Ҫɾ���������λ��;
bool DeleteBST(BiTree *T, KeyType key)
{
	if (*T==NULL)
	{
		return false;
	}
	else
	{
		if (EQ(key, (*T)->data.key)==true)
		{
			return Delete(T);
		}
		else if (LT(key, (*T)->data.key)==true)
		{
			return DeleteBST(&((*T)->lchild), key);
		}
		else
		{
			return DeleteBST(&((*T)->rchild), key);
		}

	}
}


bool InsertBST(BiTree *T, ElemType e,BiTree p)
{
	BiTree s;
	s = (BiTNode*)malloc(sizeof(BiTNode));
	s->data = e;
	s->lchild = s->rchild = NULL;
	if (p == NULL)
	{
		*T = s;//������Ľ��*sΪ�µĸ����;
	}
	else if (LT(e.key, p->data.key)==true)
	{
		p->lchild = s;
	}
	else
	{
		p->rchild = s;
	}
	return true; 
}


bool searchInDelete(BiTree *T, ElemType e)
{
	BiTree p = (BiTree)malloc(sizeof(BiTree));
	if (SearchBST(*T, e.key, NULL, &p)==false)
	{
		InsertBST(T, e, p);
	}

	else
	{
		DeleteBST(T, e.key);
	}
	return true;
}


Status print(ElemType data,FILE*pfile)
{
	
	char *d = ", ";
	if (NULL == pfile)
	{
		return ERROR;
	}
	if (NULL != pfile)
	{
		if (flag == 1)
		{
			fwrite(d, sizeof(d), 1, pfile);
		}
		fprintf(pfile, "%d",data.key);
		flag = 1;
		
	} 
}


Status PreOrderTraverse(BiTree T,FILE*pfile)
{
	
	if (T==NULL)
	{
		return ERROR;
	}
	if (T!=NULL)
	{
		print(T->data,pfile);
		PreOrderTraverse(T->lchild,pfile);
		PreOrderTraverse(T->rchild,pfile);
	}
	
	return OK;
}




