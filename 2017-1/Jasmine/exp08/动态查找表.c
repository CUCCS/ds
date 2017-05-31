#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct NODE
{
	ElemType elem; /*数据元素字段*/
	struct NODE *lc, *rc; /*左、右指针字段*/
}NodeType; /*二叉树结点类型*/

int SearchBST(NodeType *t, NodeType **p, NodeType **q, ElemType kx)
 /*在二叉排序树t 上查找数据元素等于 kx 的元素，若找到，返回1，且q 指向该结点，p 指向其父结点；*/
	/*否则，返回0，且p 指向查找失败的最后一个结点*/
{
	int flag = 0; 
	*q = t;
	while (*q!=NULL) /*从根结点开始查找*/ 
	{
		if (kx>(*q)->elem) /*kx 大于当前结点*q */
		{
			*p = *q; 
			*q = (*q)->rc;
		} /*将当前结点*q 的右孩子置为新根*/
		else
		{
			if (kx<(*q)->elem) /*kx 小于当前结点*q */
			{
				*p = *q; 
				*q = (*q)->lc;
			} /*将当前结点*q 的左子女置为新根*/
			else 
			{ 
				flag = 1;
				break; 
			} /*查找成功，返回*/
		}
	}/*while*/
	return flag;
}

int InsertBST(NodeType **t, ElemType kx)/*在二叉排序树*t 上插入数据为kx 的结点*/
{ 
	NodeType *p=*t, *q, *s;
	int flag = 0;
	if (!SearchBST(*t, &p, &q, kx)); /*在*t 为根的子树上查找*/
	{ 
		s = (NodeType*)malloc(sizeof(NodeType)); /*申请结点，并赋值*/
		s->elem = kx;
		s->lc = NULL;
		s->rc = NULL;
		flag = 1; /*设置插入成功标志*/
	if (!p) 
		*t = s; /*向空树中插入时*/
	else
	{
		if (kx>p->elem)
			p->rc = s; /*插入结点为p 的右子女*/
		else 
			p->lc = s; /*插入结点为p 的左子女*/
	}
	}
	return flag;
}

int DeleteBST(NodeType **t, ElemType kx)
{
	NodeType *p = *t, *q, *s, **f;
	int flag = 0;
	if (SearchBST(*t, &p, &q, kx))
	{ 
		flag = 1; /*查找成功，置删除成功标志*/
		if (p == q) 
		f = &(*t); /*待删结点为根结点时*/
	else /*待删结点非根结点时*/
	{
		f = &(p->lc); if (kx>p->elem) f = &(p->rc);
	} /*f 指向待删结点的父结点的相应指针域*/
	if (!q->rc) 
		*f = q->lc; /*若待删结点无右子树，以左子树替换待删结点*/
	else
	{
		if (!q->lc) 
			*f = q->rc; /*若待删结点无左子树，以右子树替换待删结点*/
		else /*既有左子树又有右子树*/
		{
			p = q->rc;s = p;
			while (p->lc) 
			{
				s = p;
				p = p->lc; 
			}/*在右子树上搜索待删结点的前驱p*/
			*f = p;
			p->lc = q->lc; /*替换待删结点q，重接左子树*/
			if (s != p)
			{
				s->lc = p->rc; /*待删结点的右子女有左子树时，还要重接右子树*/
				p->rc = q->rc;
			}
		}
	}
	free(q);
	}
	return flag;
}
void PreOrder(NodeType *t)//先序遍历输出
{
	if (t != NULL)
	{
		printf("%d ", t->elem);
		PreOrder(t->lc);
		PreOrder(t->rc);
		
	}
}

int main()
{
	int a[12] = { 8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30 };
	int b[5] = { 13, 8, 5, 20, 6 };
	NodeType *t=NULL;
	int i;
	for (i = 0;i < 12;i++)//建立二叉排序树
	{
		InsertBST(&t, a[i]);
	}
	PreOrder(t);//先序输出
	printf("\n");
	for (i = 0;i < 5;i++)//查找删除
	{
		if (!DeleteBST(&t, b[i]))
			InsertBST(&t, b[i]);
		PreOrder(t);
		printf("\n");
	}
}