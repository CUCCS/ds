#include "BSTree.h"


 //�ڸ�ָ�� T ��ָ�����������еݹ�ز�����ؼ��ֵ��� key ������Ԫ�أ������ҳɹ���
 //�򷵻�ָ�� p ָ�������Ԫ�صĽ�㣬�����غ���ֵΪ TRUE; ����������Ҳ��ɹ�������
 //ָ�� p ָ�����·���Ϸ��ʵ����һ����㣬�����غ���ֵΪFALSE, ָ�� f ָ��ǰ����
 //�Ľ���˫�ף����ʼ����ֵΪNULL
Status SearchBST(BiTree T, ElemType key, BiTree f, BiTree *p)
{
	if (!T)                                               //���Ҳ��ɹ�
	{
		*p = f;
		return FALSE;
	}
	else if (EQ(key, T->data))               //���ҳɹ�
	{
		*p = T;
		return TRUE;
	}
	else if (LT(key, T->data))               //���������м�������
		return SearchBST(T->lchild, key, T, p);
	else                                                //���������м�������
		return SearchBST(T->rchild, key, T, p); 
}
// �������������в����ڹؼ��ֵ��� e.key ������Ԫ��ʱ������Ԫ��ֵΪ e �Ľ�㣬������ TRUE; ���򣬲����в��벢����FALSE
Status InsertBST(BiTree *T, ElemType e) 
{
	BiTree p = NULL, s = NULL;

	if (SearchBST(*T, e, NULL, &p)==FALSE) 
	{
		s = (BiTree)malloc(sizeof(BiTNode)); // Ϊ�½�����ռ�
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) 
		{
			*T = s; // ���� s Ϊ�µĸ����
		}
		else if (LT(e, p->data))
		{
			p->lchild = s; // ���� *s Ϊ *p ������
		}
		else
		{
			p->rchild = s; // ���� *s Ϊ *p ���Һ���
		}
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status PreOrderTraverse(BiTree T)    //�����������������  
{

	if (T)
	{
		visit[u++] = T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}


//�Ӷ�����������ɾ�����p�����ؽ��������������
Status Delete(BiTree *p)
{
	BiTree q = NULL, s = NULL;
	if (!(*p)->rchild)       //��������ֻ���ؽ�����������
	{    
		q = *p; 
		*p = (*p)->lchild; 
		free(q);
	}
	else if (!(*p)->lchild)     //������Ϊ��ֻ���ؽ�����������  
	{   
		q = *p; 
		*p = (*p)->rchild;
		free(q);
	}
	else      //������������Ϊ��  
	{  
		q = *p; 
		s = (*p)->lchild;
		while (s->rchild)     //ת��Ȼ�������ߵ���ͷ  
		{  
			q = s; 
			s = s->rchild;
		}
		(*p)->data = s->data;  //sָ��ɾ������ǰ��  
		if (q != *p) 
		{ 
			q->rchild = s->lchild;     //�ؽ�*q��������  
		} 
		else 
		{ 
			q->lchild = s->lchild;     //�ؽ�*q��������  
		}
		free(s);
	}
	return TRUE;
}
// ������������ T �д�����ؼ��ֵ��� key ������Ԫ�أ���ɾ��������Ԫ�ؽ�㣬�����غ���ֵ TRUE�����򷵻غ���ֵ FALSE
Status DeleteBST(BiTree *T, ElemType key)
{
	if (!(*T))    // �����ڹؼ��ֵ���key������Ԫ��
	{ 
		return FALSE;
	}
	else 
	{
		if (EQ(key, (*T)->data))  // �ҵ��ؼ��ֵ���key������Ԫ��
		{
			Delete(T);
			return TRUE;
		}
		else if (LT(key, (*T)->data)) // �������������н��в���
		{ 
			return DeleteBST(&(*T)->lchild, key);
		}
		else // �������������н��в���
		{ 
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

Status  print(BiTree T, FILE *fp)    //.txt��ʽ���
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
	print(T, fp);     //�������ұ�֮�����������ұ�
	fputs(c, fp);    //����
	for (i = 0; i < 5; i++)
	{
		u = 0;                     //��ʼ������������
		if (SearchBST(T, search[i], NULL, &p) == FALSE)   //��������ʧ�ܣ�������������
		{
			InsertBST(&T, search[i]);
		}
		else    //������ҳɹ�����ɾ���������
		{
			DeleteBST(&T, search[i]);
		}
		print(T, fp);
		fputs(c, fp);
	}

	fclose(fp);
	return 0;
}