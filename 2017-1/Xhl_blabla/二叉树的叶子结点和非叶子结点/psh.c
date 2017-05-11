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
		*t = (BiTree)malloc(sizeof(BitNode));//分配空间进行存储
		if (!(*t))//如果分配失败
		{
			exit(-1);
		}
		(*t)->date = ch;//生成根节点
		CreatBiTree(&(*t)->lChild, x);//构造左子树
		CreatBiTree(&(*t)->rChild, x);//构造右子树	
	}
	return 1;
}
//求二叉树叶子结点个数
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
//求二叉树的所有结点
int GetCount(BiTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	return 1 + GetCount(T->lChild) + GetCount(T->rChild);//返回子数的结点
}
int main()
{
	BiTree t;
	ElemType  n[num];
	int  m = 0;//进行叶子结点的统计
	int k;
	printf("请选择要进行转化的字符串，输入1为abd*f***ce***，输入2为abdg**eh***k**c*f**   *代表为空\n");
	scanf("%d", &k);
	if (k == 1)
	{
		strcpy(n, "abd*f***ce***");
	}
	else
	{
		strcpy(n, "abdg**eh***k**c*f**");
	}
	printf("*代表空\n");
	CreatBiTree(&t, n);//产生二叉树  
	Leafcount(t, &m);//叶子结点
	printf("\n叶子结点的个数为%d",m);
	printf("\n非叶子结点的个数为%d", GetCount(t)-m);
	return 0;
}
