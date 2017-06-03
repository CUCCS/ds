#include "c.h"
//�Խڵ�p������������
void R_Rotate(BSTree *p)
{
	BSTree  lc;
	lc = (*p)->lchild;
	(*p)->lchild = lc->rchild;
	lc->rchild = (*p);
	(*p) = lc;
}
//��������   �����p���Ըı���һ���ڵ��ָ��
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
	{//��Ϊ����������ֻ���������ߵ����  �����ӽڵ� ��߸�  Ҫô�ұ߸�
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
{//���в��벢����Ƿ�ʧȥƽ��  TALLER   ��Ӧ  t  �Ƿ񳤸�
	if (!(*T))//���û�нڵ�  ֱ�Ӳ�����ڵ�
	{
		(*T) = (BSTree)malloc(sizeof(BSTNode));//������ڵ�
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;//ƽ������ ��ʼֵ  ����0 ��ô������ô���иı�
		(*taller) = 1;
	}
	else//��������и��ڵ�
	{
		if (e == (*T)->data)//������иýڵ�  ���з���
		{
			(*taller) = 0;
			return 0;
		}
		if (e < (*T)->data)//���С�ڸ��ڵ�   ���������������в���
		{
			if (!InsertAVL(&((*T)->lchild), e, taller))//δ���뷵��0 
			{
				return 0;
			}
			if ((*taller)!=0)//�������ɹ�����ƽ������
			{
				switch ((*T)->bf)
				{
				case LH:
					LeftBalance(T);//��ƽ����ת����
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
			if (!InsertAVL(&((*T)->rchild), e, taller))//δ���뷵��0
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
//�ж��ǲ���ƽ����
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
//end �ж��ǲ���ƽ����
//ɾ��
int DeleteAVL(BSTree *T, int key, int *shorter)
{
	if (!(*T))
	{//No such key  
		(*shorter) = 0;
		return 0;
	}
	else//���������
	{
		if (key == (*T)->data) //�ҵ�����Ҫɾ���Ľ��  
		{
			//����ý���lchild ��  
			//rchild ������һ��ΪNULL  
			//��ɾ��
			BSTree q = (*T);
			if (!((*T)->lchild))
			{//����ý���lchild ΪNULL  
				q = (*T);
				(*T) = (*T)->rchild;
				free(q);
				(*shorter) = 1;
				return 1;
			}
			else if (!((*T)->rchild))
			{//����ý���rchild Ϊ NULL  
				q = (*T);
				(*T) = (*T)->lchild;
				free(q);
				(*shorter) = 1;
				return 1;
			}
			else
			{
				//ɾ��һ�����Һ��Ӷ���Ϊ�յĽ��  
				//ʹ�ý����������������Ӵ���
				BSTree s = (*T)->rchild;
				while (s->lchild)
				{
					s = s->lchild;//����t�������� ����������ֵ��������ڵ�  ��ɾ����������
				}
				(*T)->data = s->data;
				key = s->data;
			}
		}
		if (key < (*T)->data)                         //ɾ���˵Ⱥ�
		{//������InsertAVL��ͬ  
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
 //�������
status InOrder(BSTree T)
{
	if (T)
	{
		out[k] = T->data;//ÿ���������ֵ 
		k++;
		InOrder(T->lchild);
		InOrder(T->rchild);
	}
	else
		return 1;
}
//���ڴ�ӡ�ض���ʽ�����
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
		int  taller;//��ӳ�����Ƿ񳤸�
		for (i = 0; i < 12; i++)
		{
			InsertAVL(&T, number[i], &taller);
		}
		//InOrder(T,out,k);
		print(T, fp);
		fputs(z, fp);
		for (i = 0; i < s_length; i++)
		{//�������ʧ��  �ͽ���ɾ������
			k = 0;//��ʼ����������
			if (!InsertAVL(&T, search[i], &taller))
			{
				DeleteAVL(&T, search[i], &taller);
			}
			print(T, fp);
			fputs(z, fp);
			//������ж��Ƿ���ƽ����
		 /*  int  result =Balanced(T);
		   printf("result = %s\n", result == 0 ? "false" : "true");*/
		}
		return 0;
	}
