#include"Homework.h"
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
		(*T)->data = ch;//生成根结点
		CreateBiTree(&(*T)->lchild, c);//构造左子树
		CreateBiTree(&(*T)->rchild, c);//构造右子树
	}
	return 1;
}
//后序遍历二叉树 
void  postorderTraversal(BiTree t)//后续遍历 
{
	if (t == NULL)
	{
		printf("*");
		return;
	}
	postorderTraversal(t->lchild);//访问左子树 
	postorderTraversal(t->rchild);//访问右子树 
	printf("%c ", t->data);
}
//二叉树的深度 
int TreeDepth(BiTree T)
{
	int depth = 0;
	if (T)
	{
		int leftdepth = TreeDepth(T->lchild);//查找左子树的的最深值  
		int rightdepth = TreeDepth(T->rchild);//查找右子树的最深值 
		depth = leftdepth >= rightdepth ? leftdepth + 1 : rightdepth + 1;
	}
	return depth;
}
int widthHouxu(BiTree t)//后续遍历 
{
	int i;
	int max = 0;//用于存储最大值 
	if (t == NULL)
	{
		return 0;
	}
	width[w]++;
	w++;
	widthHouxu(t->lchild);//访问左子树 
	widthHouxu(t->rchild);//访问右子树 
	w--;//当左子树和右子树均遍历了 返回上一层继续统计 
	for (i = 0; i < nwidth; i++)//找到最大值进行输出 
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
	
	scanf("%s", n);
	printf("*代表空\n");
	CreateBiTree(&t, n);//产生二叉树   
	printf("后序遍历的顺序为\n");
	postorderTraversal(t);//后序遍历二叉树 
	printf("\n树的深度为%d \n", TreeDepth(t));
	printf("\n树的宽度为%d \n", widthHouxu(t));
	return 0;
}