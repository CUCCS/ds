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
//后序遍历二叉树
void  VisitHouxu(BiTree t)//后续遍历
{
	if (t == NULL)
	{
		printf("*");
		return;
	}
	VisitHouxu(t->lChild);//访问左子树
	VisitHouxu(t->rChild);//访问右子树
	printf("%c ", t->date);
}
//二叉树的深度
int TreeDeep(BiTree T)
{
	int deep = 0;
	if (T)
	{
		int leftdeep = TreeDeep(T->lChild);//查找左子树的的最深值 
		int rightdeep = TreeDeep(T->rChild);//查找右子树的最深值
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
	return deep;
}
//后序遍历二叉树
int floor = 1;//用于计数层数
int width[width_num] = { 0 };//用于存储每层的结点个数
int   widthHouxu(BiTree t)//后续遍历
{
	int i;
	int max = 0;//用于存储最大值
	if (t == NULL)
	{
		return 0;
	}
	width[floor]++;
	floor++;
	widthHouxu(t->lChild);//访问左子树
	widthHouxu(t->rChild);//访问右子树
	floor--;//当左子树和右子树均遍历了 返回上一层继续统计
	for (i = 0; i < width_num; i++)//找到最大值进行输出
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
	printf("请选择要进行转化的字符串，输入1为abd*f***ce***，输入2为abdg***eh**i*k**c*f**  *代表为空\n");
	scanf("%d", &k);
	if (k == 1)
	{
		strcpy(n, "abd*f***ce***");
	}
	else
	{
		strcpy(n, "abdg***eh**i*k**c*f**");
	}
	printf("*代表空\n");
	CreatBiTree(&t, n);//产生二叉树  
	printf("后序遍历的顺序为\n");
	VisitHouxu(t);//后序遍历二叉树
	printf("\n树的深度为%d \n", TreeDeep(t));
	printf("\n树的宽度为%d \n", widthHouxu(t));
	return 0;
}
