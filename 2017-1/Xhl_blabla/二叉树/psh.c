#include"bitree.h"
status CreatBiTree(BiTree *t,char *x)
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
		CreatBiTree(&(*t)->lChild,x);//����������
		CreatBiTree(&(*t)->rChild,x);//����������	
	}
	return 1;
}
void  VisitHouxu(BiTree t)//��������
{
	if (t == NULL)
	{
		return;
	}
		VisitHouxu(t->lChild);//����������
		VisitHouxu(t->rChild);//����������
		printf("%c ", t->date);
}
//�������������
int main()
{
	BiTree t;
	ElemType  n[num];
	printf("������Ҫ����ת�����ַ���   *����Ϊ��\n");
	scanf("%s", n);
	printf("*�����\n");
    CreatBiTree(&t ,n);//����������  
	printf("���������˳��Ϊ\n");
	VisitHouxu(t);//�������������
	return 0;
}
