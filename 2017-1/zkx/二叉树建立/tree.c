#include "tree.h"

int i = 0;       //���ڼ�����ȫ�ֱ���
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;

	ch = p[i];
	i++;                     //��������ʽ�����ַ�����������Ϊ����
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

void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	
}

int main()
{
	BiTree T = NULL;
	Status ret;
	TElemType str1[50] = "ABDG###EH##I#K##C#F##";
	TElemType str2[50] = "ABD#F###CE###";

	printf("----------------�������Ľ����ͺ������----------------\n");

	ret = CreateBiTree(&T,str1);
	printf("�����һ�������� : ABDG###EH##I#K##C#F##\n");
	printf("����������Ϊ   :  ");
	PostOrderTraverse(T);

	i = 0;       //���½�����������Ϊ0�����еڶ����ַ����Ĵ���
	ret = CreateBiTree(&T, str2);
	printf("\n����ڶ��������� : ABD#F###CE###\n");
	printf("����������Ϊ   :  ");
	PostOrderTraverse(T);
	printf("\n");

	return 0;

}