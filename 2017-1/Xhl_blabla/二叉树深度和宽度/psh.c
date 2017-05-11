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
//�������������
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
//�����������
int TreeDeep(BiTree T)
{
	int deep = 0;
	if (T)
	{
		int leftdeep = TreeDeep(T->lChild);//�����������ĵ�����ֵ 
		int rightdeep = TreeDeep(T->rChild);//����������������ֵ
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
	return deep;
}
//�������������
int floor = 1;//���ڼ�������
int width[width_num] = {0};//���ڴ洢ÿ��Ľ�����
int   widthHouxu(BiTree t)//��������
{
	int i ;
	int max = 0;//���ڴ洢���ֵ
	if (t == NULL)
	{
		return 0;
	}
	width[floor]++;
	floor++;
	widthHouxu(t->lChild);//����������
	widthHouxu(t->rChild);//����������
	floor--;//������������������������ ������һ�����ͳ��
	for (i = 0; i < width_num; i++)//�ҵ����ֵ�������
	{
		if (max < width[i])
		{
			max = width[i];
		}
	}
	return max;
}
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
	printf ("\n�������Ϊ%d \n",TreeDeep(t));
	printf("\n���Ŀ��Ϊ%d \n", widthHouxu(t));
	return 0;
}
