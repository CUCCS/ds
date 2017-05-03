#include "addtree.h"

int j=0;
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;

	ch = p[j];
	j++;                     //��������ʽ�����ַ�����������Ϊ����
	if (ch == '#')        //�պ���
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;              // ���ɸ����
		CreateBiTree(&(*T)->lchild, p);   // ����������
		CreateBiTree(&(*T)->rchild, p);   // ����������
	}
	return OK;
}

ElemType Depth(BiTree T)     //��������������
{
	if(T == NULL)
	{
		return OVERFLOW;
	}
	return Depth(T->lchild) > Depth(T->rchild)
		? (Depth(T->lchild) + 1) : (Depth(T->rchild) + 1);
}

int  count[50];  //��Ÿ�������
int max=0;    //�����
 int i=0;       //��������
  
int  Width(BiTree T)   //��������������
{ 
    if(T == NULL)  
		return 0;  
	i++;
    count[i]++;  
    if(max < count[i]) 
		max = count[i];  
    Width(T->lchild);  
    Width(T->rchild); 
	i--;    //���ظ����
	return max;
}  

ElemType CountLeaf(BiTree T)   //���������Ҷ�ӽ�����
{
	ElemType m, n;      //�ֱ�Ϊ��������������Ҷ�ӽ�����
	if(T == NULL) 
		return 0;
    if(T->lchild == NULL && T->rchild == NULL)  //���Һ��Ӷ�Ϊ�գ�˵���ýڵ�ΪҶ�ӽ��
	{ 
        return 1;
    } 
	else 
	{
        m = CountLeaf(T->lchild);  
        n = CountLeaf(T->rchild); 
        return m+n;   
    } 
}

ElemType Count(BiTree T)    //���������н�����
{
	ElemType m, n;
	if (T == NULL)
		return 0;
    if (T->lchild == NULL && T->rchild == NULL)   //���Һ��Ӷ�Ϊ�գ�˵���ýڵ�ΪҶ�ӽ��
	{
        return 1;
    } 
	else 
	{
        m = Count(T->lchild);  
        n = Count(T->rchild); 
        return m + n + 1;   
    }
}

ElemType NotCountLeaf(BiTree T)    //��������Ҷ�ӽ�����
{
	return Count(T)-CountLeaf(T);
}

int main()
{
	BiTree T = NULL;
	ElemType w1, w2;   //��1��2�Ŀ��

	TElemType str1[50] = "ABDG###EH##I#K##C#F##";
	TElemType str2[50] = "ABD#F###CE###";

	printf("---------���������������߶ȡ�����ȡ�Ҷ�ӽ�㡢��Ҷ�ӽ��---------\n\n");

	printf("��һ����������  ");
	puts(str1);
	CreateBiTree(&T,str1);
	printf("�߶�Ϊ�� %d",Depth(T)-1);
	w1 = Width(T);
	printf("\n�����Ϊ�� %d", w1);
	printf("\nҶ�ӽ�����Ϊ�� %d", CountLeaf(T));
	printf("\n��Ҷ�ӽ�����Ϊ�� %d\n\n", NotCountLeaf(T));

	j=0;   //���¼���
	printf("�ڶ�����������  ");
	puts(str2);
	CreateBiTree(&T,str2);
	printf("�߶�Ϊ�� %d",Depth(T)-1);
	w2 = Width(T);
	printf("\n�����Ϊ�� %d", w2-w1);
	printf("\nҶ�ӽ�����Ϊ�� %d", CountLeaf(T));
	printf("\n��Ҷ�ӽ�����Ϊ�� %d\n\n", NotCountLeaf(T));
	return 0;
}
