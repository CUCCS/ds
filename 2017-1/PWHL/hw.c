#include"hw.h"
status CreateBiTree(BiTree *T, char *c)
{

	ElemType ch;
	ch = c[number];
	number++;
	if (ch == '*')
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			exit(-1);
		}
		(*T)->data = ch;//���ɸ����
		CreateBiTree(&(*T)->lchild, c);//����������
		CreateBiTree(&(*T)->rchild, c);//����������
	}
	return 1;
}
//������������� 
void  postorderTraversal(BiTree t)//�������� 
{
	if (t == NULL)
	{
		printf("*");
		return;
	}
	postorderTraversal(t->lchild);//���������� 
	postorderTraversal(t->rchild);//���������� 
	printf("%c ", t->data);
}
//����������� 
int TreeDepth(BiTree T)
{
	int depth = 0;
	if (T)
	{
		int leftdepth = TreeDepth(T->lchild);//�����������ĵ�����ֵ  
		int rightdepth = TreeDepth(T->rchild);//����������������ֵ 
		depth = leftdepth >= rightdepth ? leftdepth + 1 : rightdepth + 1;
	}
	return depth;
}
int widthHouxu(BiTree t)//�������� 
{
	int i;
	int max = 0;//���ڴ洢���ֵ 
	if (t == NULL)
	{
		return 0;
	}
	width[w]++;
	w++;
	widthHouxu(t->lchild);//���������� 
	widthHouxu(t->rchild);//���������� 
	w--;//������������������������ ������һ�����ͳ�� 
	for (i = 0; i < nwidth; i++)//�ҵ����ֵ������� 
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
	ElemType  n[20];
	int k=0;
	printf("����1������1Ϊabc**d**ef***,����2Ϊabcd**ef***g**h*g**\n");

	scanf("%d",&k);
	if (k == 1)
	{
		strcpy(n, "abc**d**ef***");
	}
	else if (k == 2)
	{
		strcpy(n, "abcd**ef***g**h*g**");
	}
	printf("*�����\n");
	CreateBiTree(&t, n);//����������   
	printf("���������˳��Ϊ\n");
	postorderTraversal(t);//������������� 
	printf("\n�������Ϊ%d \n", TreeDepth(t));
	printf("\n���Ŀ��Ϊ%d \n", widthHouxu(t));
	return 0;
}