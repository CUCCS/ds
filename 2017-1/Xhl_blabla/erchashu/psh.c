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
void  VisitHouxu(BiTree t)//��������
{
	if (t == NULL)
	{
		printf("*");
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
	printf("���������˳��Ϊ\n");
	VisitHouxu(t);//�������������
	return 0;
}
