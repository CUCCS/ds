#include "addtree.h"

int j=0;
Status CreateBiTree(BiTree *T, TElemType *p)
{
	TElemType ch;

	ch = p[j];
	j++;                     //用数组形式处理字符串，不用人为输入
	if (ch == '#')        //空孩子
	{
		*T = NULL;
	}
	else
	{
		if (!(*T = (BiTree)malloc(sizeof(BiTNode))))
		{
			return OVERFLOW;
		}
		(*T)->data = ch;              // 生成根结点
		CreateBiTree(&(*T)->lchild, p);   // 构造左子树
		CreateBiTree(&(*T)->rchild, p);   // 构造右子树
	}
	return OK;
}

ElemType Depth(BiTree T)     //计算二叉树的深度
{
	if(T == NULL)
	{
		return OVERFLOW;
	}
	return Depth(T->lchild) > Depth(T->rchild)
		? (Depth(T->lchild) + 1) : (Depth(T->rchild) + 1);
}

int  count[50];  //存放各层结点数
int max=0;    //最大宽度
 int i=0;       //计数变量
  
int  Width(BiTree T)   //计算二叉树最大宽度
{ 
    if(T == NULL)  
		return 0;  
	i++;
    count[i]++;  
    if(max < count[i]) 
		max = count[i];  
    Width(T->lchild);  
    Width(T->rchild); 
	i--;    //返回根结点
	return max;
}  

ElemType CountLeaf(BiTree T)   //计算二叉树叶子结点个数
{
	ElemType m, n;      //分别为左子树，右子树叶子结点个数
	if(T == NULL) 
		return 0;
    if(T->lchild == NULL && T->rchild == NULL)  //左右孩子都为空，说明该节点为叶子结点
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

ElemType Count(BiTree T)    //二叉树所有结点个数
{
	ElemType m, n;
	if (T == NULL)
		return 0;
    if (T->lchild == NULL && T->rchild == NULL)   //左右孩子都为空，说明该节点为叶子结点
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

ElemType NotCountLeaf(BiTree T)    //二叉树非叶子结点个数
{
	return Count(T)-CountLeaf(T);
}

int main()
{
	BiTree T = NULL;
	ElemType w1, w2;   //树1树2的宽度

	TElemType str1[50] = "ABDG###EH##I#K##C#F##";
	TElemType str2[50] = "ABD#F###CE###";

	printf("---------计算整个二叉树高度、最大宽度、叶子结点、非叶子结点---------\n\n");

	printf("第一个二叉树：  ");
	puts(str1);
	CreateBiTree(&T,str1);
	printf("高度为： %d",Depth(T)-1);
	w1 = Width(T);
	printf("\n最大宽度为： %d", w1);
	printf("\n叶子结点个数为： %d", CountLeaf(T));
	printf("\n非叶子结点个数为： %d\n\n", NotCountLeaf(T));

	j=0;   //重新计数
	printf("第二个二叉树：  ");
	puts(str2);
	CreateBiTree(&T,str2);
	printf("高度为： %d",Depth(T)-1);
	w2 = Width(T);
	printf("\n最大宽度为： %d", w2-w1);
	printf("\n叶子结点个数为： %d", CountLeaf(T));
	printf("\n非叶子结点个数为： %d\n\n", NotCountLeaf(T));
	return 0;
}
