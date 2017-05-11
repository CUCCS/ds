#include"bitree.h"
status CreatBiTree(BiTree *t, char *x)
{
	ElemType ch, temp;
	ch = x[number];
	number++;
	if (ch == '*')
	{
		*t = NULL;
	}
	else
	{
		*t = (BiTree)malloc(sizeof(BitNode));//����ռ���д洢
		if (!(*t))//�������ʧ��
		{
			exit(-1);
		}
		(*t)->date = ch;//���ɸ��ڵ�
		CreatBiTree(&(*t)->lChild, x);//����������
		CreatBiTree(&(*t)->rChild, x);//����������	
	}
	return 1;
}
//�������Ҷ�ӽ�����
int Leafcount(BiTree T,int *m)
{
	if (T)
	{
		if (T->lChild == NULL &&T->rChild == NULL)
			(*m)++;
		Leafcount(T->lChild, m);
		Leafcount(T->rChild, m);
	}
	return *m;
}
//������������н��
int GetCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	return 1 + GetCount(T->lChild) + GetCount(T->rChild);//���������Ľ��
}
int main()
{
	BiTree t;
	ElemType  n[num];
	int  m = 0;//����Ҷ�ӽ���ͳ��
	int k;
	printf("��ѡ��Ҫ����ת�����ַ���������1Ϊabd*f***ce***������2Ϊabdg**eh***k**c*f**   *����Ϊ��\n");
	scanf("%d", &k);
	if (k == 1)
	{
		strcpy(n, "abd*f***ce***");
	}
	else
	{
		strcpy(n, "abdg**eh***k**c*f**");
	}
	printf("*�����\n");
	CreatBiTree(&t, n);//����������  
	Leafcount(t, &m);//Ҷ�ӽ��
	printf("\nҶ�ӽ��ĸ���Ϊ%d",m);
	printf("\n��Ҷ�ӽ��ĸ���Ϊ%d", GetCount(t)-m);
	return 0;
}
