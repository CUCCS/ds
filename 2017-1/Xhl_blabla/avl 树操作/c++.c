#include "c.h"
//对节点p进行右旋处理
void R_Rotate(BSTree *p)
{
	BSTree  lc;
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = (*p);
	(*p) = lc;
}
//左旋处理   传入的p可以改变上一个节点的指向
void L_Rotate(BSTree *p)
{
	BSTree  rc;
	rc = (*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild = (*p);
	(*p) = rc;
}
void  RightBalance(BSTree *T)
{
	BSTree  lc;
	BSTree  rd;
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
		case RH:
			(*T)->bf = LH;//rh
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;//LH
			break;
		}
		rd->bf = EH;
		R_Rotate(&((*T)->rchild));
		L_Rotate(T);
		break;//
	}
}
void LeftBalance(BSTree *T)
{
	BSTree  lc;
	BSTree  rd;
	lc = (*T)->lchild;
	switch (lc->bf)
	{//因为传入的情况是只有左子树高的情况  所以子节点 左边高  要么右边高
	case LH:
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
	case RH:
		rd = lc->rchild;
		switch (rd->bf)
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
		L_Rotate(&((*T)->lchild));
		R_Rotate(T);
		break;
		}
}
status InsertAVL(BSTree *T, ElemType e, int *taller)
{//进行插入并检查是否失去平衡  TALLER   反应  t  是否长高
	if (!(*T))//如果没有节点  直接插入根节点
	{
		(*T) = (BSTree)malloc(sizeof(BSTNode));//插入根节点
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;//平衡因子 初始值  都是0 那么后面怎么进行改变
		(*taller) = 1;
	}
	else//如果有已有根节点
	{
		if (e == (*T)->data)//如果已有该节点  进行返回
		{
			(*taller) = 0;
			return 0;
		}
		if (e < (*T)->data)//如果小于根节点   继续在左子树进行查找
		{
			if (!InsertAVL(&((*T)->lchild), e, taller))//未插入返回0 
			{
				return 0;
			}
			if ((*taller)!=0)//如果插入成功则检查平衡因子
			{
				switch ((*T)->bf)
				{
				case LH:
					LeftBalance(T);//左平衡旋转处理
					(*taller) = 0;
					break;
				case EH:
					(*T)->bf = LH;
					(*taller) = 1;
					break;
				case RH:
					(*T)->bf = EH;
					(*taller) = 0;
					break;
				}
			}
		}
		else
		{
			if (!InsertAVL(&((*T)->rchild), e, taller))//未插入返回0
			{
				return 0;
			}
			if ((*taller)!=0)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					(*taller) = 0;
					break;
				case EH:
					(*T)->bf = RH;
					(*taller) = 1;
					break;
				case RH:
					RightBalance(T);
					(*taller) = 0;
					break;
				}
			}
		}

	}
	return 1;
}
//判断是不是平衡树
int  IsBalanced(BSTree  pRoot, int* pDepth)
{
	if (pRoot == NULL) 
	{
		*pDepth = 0;
		return 1;
	}
	int left, right;
	if (IsBalanced(pRoot->lchild, &left) && IsBalanced(pRoot->rchild, &right)) 
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1) {
			*pDepth = 1 + (left>right ? left : right);
			return 1;
		}
	}
	return 0;
}
int  Balanced(BSTree pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}
//end 判断是不是平衡树
//删除
int DeleteAVL(BSTree *T, int key, int *shorter)
{
	if (!(*T))
	{//No such key  
		(*shorter) = 0;
		return 0;
	}
	else//如果树不空
	{
		if (key == (*T)->data) //找到了需要删除的结点  
		{
			//如果该结点的lchild 和  
			//rchild 至少有一个为NULL  
			//则删除
			BSTree q = (*T);
			if (!((*T)->lchild))
			{//如果该结点的lchild 为NULL  
				q = (*T);
				(*T) = (*T)->rchild;
				free(q);
				(*shorter) = 1;
				return 1;
			}
			else if (!((*T)->rchild))
			{//如果该结点的rchild 为 NULL  
				q = (*T);
				(*T) = (*T)->lchild;
				free(q);
				(*shorter) = 1;
				return 1;
			}
			else
			{
				//删除一个左右孩子都不为空的结点  
				//使该结点的右子树的最左孩子代替
				BSTree s = (*T)->rchild;
				while (s->lchild)
				{
					s = s->lchild;//查找t的最左结点 ，用它的数值来代替根节点  并删除最右子树
				}
				(*T)->data = s->data;
				key = s->data;
			}
		}
		if (key < (*T)->data)                         //删除了等号
		{//这里与InsertAVL不同  
			if (!DeleteAVL(&((*T)->lchild), key, shorter))
			{
				return 0;
			}
			if ((*shorter))
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					(*shorter) = 1;
					break;
				case EH:
					(*T)->bf = RH;
					(*shorter) = 0;
					break;
				case RH:
					RightBalance(T);
					if ((*T)->rchild->bf == EH)
					{
						(*shorter) = 0;
					}
					else
						(*shorter) = 1;
					break;
				}
			}
		}
		else
		{
			if (!DeleteAVL(&((*T)->rchild), key, shorter))
			{
				return 0;
			}
			if ((*shorter))
			{
				switch ((*T)->bf)
				{
				case LH:
					LeftBalance(T);
					if ((*T)->lchild->bf == EH)
					{
						(*shorter) = 0;
					}
					else
						(*shorter) = 1;
					break;
				case EH:
					(*T)->bf = LH;
					(*shorter) = 0;
					break;
				case RH:
					(*T)->bf = EH;
					(*shorter) = 1;
					break;
				}
			}
		}

	}
	return 1;
}//Delete 
 //先序遍历
status InOrder(BSTree T)
{
	if (T)
	{
		out[k] = T->data;//每次输出结点的值 
		k++;
		InOrder(T->lchild);
		InOrder(T->rchild);
	}
	else
		return 1;
}
//用于打印特定形式的输出
status  print(BSTree  T, FILE *fp)
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
		fp = fopen("AVLOutput.txt", "a");
		int  number[num_length] = { 8, 10,14, 3, 1,  6, 4, 7, 5, 19,  22, 30 };
		int search[s_length] = { 13, 8, 5, 20, 6 };
		int i;
		BSTree  T = NULL;
		int  taller;//反映了树是否长高
		for (i = 0; i < 12; i++)
		{
			InsertAVL(&T, number[i], &taller);
		}
		//InOrder(T,out,k);
		print(T, fp);
		fputs(z, fp);
		for (i = 0; i < s_length; i++)
		{//如果插入失败  就进行删除操作
			k = 0;//初始化计数数字
			if (!InsertAVL(&T, search[i], &taller))
			{
				DeleteAVL(&T, search[i], &taller);
			}
			print(T, fp);
			fputs(z, fp);
			//用深度判断是否是平衡树
		 /*  int  result =Balanced(T);
		   printf("result = %s\n", result == 0 ? "false" : "true");*/
		}
		return 0;
	}
